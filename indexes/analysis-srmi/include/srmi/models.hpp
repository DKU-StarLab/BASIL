#pragma once

#include <cmath>
#include <x86intrin.h>
#include "util/fn.hpp"

namespace srmi {

/**
 * A model that fits a linear segment from the first first to the last data point.
 *
 * We assume that x-values are sorted in ascending order and y-values are handed implicitly where @p offset and @p
 * offset + distance(first, last) are the first and last y-value, respectively. The y-values can be scaled by
 * providing a @p compression_factor.
 */
class LinearSpline
{
    private:
    double slope_;     ///< The slope of the linear segment.
    double intercept_; ///< The y-intercept of the lienar segment.

    public:
    /**
     * Default contructor.
     */
    LinearSpline() = default;

    /**
     * Builds a linaer segment between the first and last data point.
     * @param first, last iterators to the first and last x-value the linear segment is fit on
     * @param offset first y-value the linear segment is fit on
     * @param compression_factor by which the y-values are scaled
     */
    template<typename RandomIt>
    LinearSpline(RandomIt first, RandomIt last, std::size_t offset = 0, double compression_factor = 1.f) {
        std::size_t n = std::distance(first, last);

        if (n == 0) {
            slope_ = 0.f;
            intercept_ = 0.f;
            return;
        }
        if (n == 1) {
            slope_ = 0.f;
            intercept_ = static_cast<double>(offset) * compression_factor;
            return;
        }

        double numerator = static_cast<double>(n); 
        double denominator = static_cast<double>((*(last - 1)).key - (*first).key);

        slope_ = denominator != 0.0 ? numerator/denominator * compression_factor : 0.0;
        intercept_ = offset * compression_factor - slope_ * (*first).key;
    }

    /**
     * Returns the estimated y-value of @p x.
     * @param x to estimate a y-value for
     * @return the estimated y-value for @p x
     */
    template<typename X>
    double predict(const X x) const { return std::fma(slope_, static_cast<double>(x), intercept_); }

    /**
     * Returns the slope of the linear segment.
     * @return the slope of the linear segment
     */
    double slope() const { return slope_; }

    /**
     * Returns the y-intercept of the linear segment.
     * return the y-intercept of the linear segment
     */
    double intercept() const { return intercept_; }

    /**
     * Returns the size of the linear segment in bytes.
     * @return segment size in bytes.
     */
    std::size_t size_in_bytes() { return 2 * sizeof(double); }

    /**
     * Writes the mathematical representation of the linear segment to an output stream.
     * @param out output stream to write the linear segment to
     * @param m the linear segment
     * @returns the output stream
     */
    friend std::ostream & operator<<(std::ostream &out, const LinearSpline &m) {
        return out << m.slope() << " * x + " << m.intercept();
    }
};


/**
 * A linear regression model that fits a straight line to minimize the mean squared error.
 *
 * We assume that x-values are sorted in ascending order and y-values are handed implicitly where @p offset and @p
 * offset + distance(first, last) are the first and last y-value, respectively. The y-values can be scaled by
 * providing a @p compression_factor.
 */
class LinearRegression
{
    private:
    double slope_;     ///< The slope of the linear function.
    double intercept_; ///< The y-intercept of the lienar function.

    public:
    /*
     * Default constructor.
     */
    LinearRegression() = default;

    /**
     * Builds a linaer regression model between on the given data points.
     * @param first, last iterators to the first and last x-value the linear regression is fit on
     * @param offset first y-value the linear regression is fit on
     * @param compression_factor by which the y-values are scaled
     */
    template<typename RandomIt>
    LinearRegression(RandomIt first, RandomIt last, size_t interval, std::size_t offset = 0, double compression_factor = 1.f) {
        std::size_t n = std::distance(first, last);

        if (n == 0) {
            slope_ = 0.f;
            intercept_ = 0.f;
            return;
        }

        if (n <= interval) {
            slope_ = 0.f;
            intercept_ = static_cast<double>(offset) * compression_factor;
            return;
        }

        double mean_x = 0.0;
        double mean_y = 0.0;
        double c = 0.0;
        double m2 = 0.0;

        auto x = (*(first)).key;
        std::size_t y = 0;
        double dx = 0.0;
        double dx2 = 0.0;
        
        std::size_t i = 0;
        std::size_t cnt = 0;

        for (; i < n - 1; i += interval, ++cnt) {
            x = (*(first + i)).key;
            y = offset + i;

            dx = x - mean_x;
            mean_x += dx / (cnt + 1);
            mean_y += (y - mean_y) / (cnt + 1);
            c += dx * (y - mean_y);

            dx2 = x - mean_x;
            m2 += dx * dx2;
        }

        x = (*(first + n-1)).key;
        y = offset + n-1;

        dx = x - mean_x;
        mean_x += dx / (cnt + 1);
        mean_y += (y - mean_y) / (cnt + 1);
        c += dx * (y - mean_y);

        dx2 = x - mean_x;
        m2 += dx * dx2;

        double cov = c / (cnt);
        double var = m2 / (cnt);

        if (var == 0.f) {
            slope_  = 0.f;
            intercept_ = mean_y;
            return;
        }

        slope_ = cov / var * compression_factor;
        intercept_ = mean_y * compression_factor - slope_ * mean_x;
    }

    /**
     * Returns the estimated y-value of @p x.
     * @param x to estimate a y-value for
     * @return the estimated y-value for @p x
     */
    template<typename X>
    double predict(const X x) const { return std::fma(slope_, static_cast<double>(x), intercept_); }

    /**
     * Returns the slope of the linear regression model.
     * @return the slope of the linear regression model
     */
    double slope() const { return slope_; }

    /**
     * Returns the y-intercept of the linear regression model.
     * return the y-intercept of the linear regression model
     */
    double intercept() const { return intercept_; }

    /**
     * Returns the size of the linear regression model in bytes.
     * @return model size in bytes.
     */
    std::size_t size_in_bytes() { return 2 * sizeof(double); }

    /**
     * Writes the mathematical representation of the linear regression model to an output stream.
     * @param out output stream to write the linear regression model to
     * @param m the linear regression model
     * @returns the output stream
     */
    friend std::ostream & operator<<(std::ostream &out, const LinearRegression &m) {
        return out << m.slope() << " * x + " << m.intercept();
    }
};

} // namespace srmi
