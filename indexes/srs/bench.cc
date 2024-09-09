#include <chrono>
#include <fstream>
#include <iostream>
#include <map>

#include "include/rs/multi_map.h"

using namespace std;

namespace rs_manual_tuning {

// Returns <num_radix_bits, max_error>
pair<uint64_t, uint64_t> GetTuning(const string& data_filename,
                                   uint32_t size_scale) {
  assert(size_scale >= 1 && size_scale <= 10);

  string dataset = data_filename;

  // Cut the prefix of the filename
  size_t pos = dataset.find_last_of('/');
  if (pos != string::npos) {
    dataset.erase(dataset.begin(), dataset.begin() + pos + 1);
  }

  using Configs = const vector<pair<size_t, size_t>>;

  if (dataset == "normal_200M_uint32") {
    Configs configs = {{10, 6}, {15, 1}, {16, 1}, {18, 1}, {20, 1},
                       {21, 1}, {24, 1}, {25, 1}, {26, 1}, {26, 1}};
    return configs[10 - size_scale];
  }

  if (dataset == "normal_200M_uint64") {
    Configs configs = {{14, 2}, {16, 1}, {16, 1}, {20, 1}, {22, 1},
                       {24, 1}, {26, 1}, {26, 1}, {28, 1}, {28, 1}};
    return configs[10 - size_scale];
  }

  if (dataset == "lognormal_200M_uint32") {
    Configs configs = {{12, 20}, {16, 3}, {16, 2}, {18, 1}, {20, 1},
                       {22, 1},  {24, 1}, {24, 1}, {26, 1}, {28, 1}};
    return configs[10 - size_scale];
  }

  if (dataset == "lognormal_200M_uint64") {
    Configs configs = {{12, 3}, {18, 1}, {18, 1}, {20, 1}, {22, 1},
                       {24, 1}, {26, 1}, {26, 1}, {28, 1}, {28, 1}};
    return configs[10 - size_scale];
  }

  if (dataset == "uniform_dense_200M_uint32") {
    Configs configs = {{4, 2},  {16, 2}, {18, 1}, {20, 1}, {20, 1},
                       {22, 2}, {24, 1}, {26, 3}, {26, 3}, {28, 2}};
    return configs[10 - size_scale];
  }

  if (dataset == "uniform_dense_200M_uint64") {
    Configs configs = {{4, 2},  {16, 1}, {16, 1}, {20, 1}, {22, 1},
                       {24, 1}, {24, 1}, {26, 1}, {28, 1}, {28, 1}};
    return configs[10 - size_scale];
  }

  if (dataset == "uniform_dense_200M_uint64") {
    Configs configs = {{4, 2},  {16, 1}, {16, 1}, {20, 1}, {22, 1},
                       {24, 1}, {24, 1}, {26, 1}, {28, 1}, {28, 1}};
    return configs[10 - size_scale];
  }

  if (dataset == "uniform_sparse_200M_uint32") {
    Configs configs = {{12, 220}, {14, 100}, {14, 80}, {16, 30}, {18, 20},
                       {20, 10},  {20, 8},   {20, 5},  {24, 3},  {26, 1}};
    return configs[10 - size_scale];
  }

  if (dataset == "uniform_sparse_200M_uint64") {
    Configs configs = {{12, 150}, {14, 70}, {16, 50}, {18, 20}, {20, 20},
                       {20, 9},   {20, 5},  {24, 3},  {26, 2},  {28, 1}};
    return configs[10 - size_scale];
  }

  // Books (or amazon in the paper)
  if (dataset == "books_200M_uint32") {
    Configs configs = {{14, 250}, {14, 250}, {16, 190}, {18, 80}, {18, 50},
                       {22, 20},  {22, 9},   {22, 8},   {24, 3},  {28, 2}};
    return configs[10 - size_scale];
  }

  if (dataset == "books_200M_uint64") {
    Configs configs = {{12, 380}, {16, 170}, {16, 110}, {20, 50}, {20, 30},
                       {22, 20},  {22, 10},  {24, 3},   {26, 3},  {28, 1}};
    return configs[10 - size_scale];
  }

  if (dataset == "books_400M_uint64") {
    Configs configs = {{16, 220}, {16, 220}, {18, 160}, {20, 60}, {20, 40},
                       {22, 20},  {22, 7},   {26, 3},   {28, 2},  {28, 1}};
    return configs[10 - size_scale];
  }

  if (dataset == "books_600M_uint64") {
    Configs configs = {{18, 330}, {18, 330}, {18, 190}, {20, 70}, {22, 50},
                       {22, 20},  {24, 7},   {26, 3},   {28, 2},  {28, 1}};
    return configs[10 - size_scale];
  }

  if (dataset == "books_800M_uint64") {
    Configs configs = {{18, 320}, {18, 320}, {18, 200}, {22, 80}, {22, 60},
                       {22, 20},  {24, 9},   {26, 3},   {28, 3},  {28, 3}};
    return configs[10 - size_scale];
  }

  // Facebook
  if (dataset == "fb_200M_uint64") {
    Configs configs = {{8, 140}, {8, 140}, {8, 140}, {8, 140}, {10, 90},
                       {22, 90}, {24, 70}, {26, 80}, {26, 7},  {28, 80}};
    return configs[10 - size_scale];
  }

  // OSM
  if (dataset == "osm_cellids_200M_uint64") {
    Configs configs = {{20, 160}, {20, 160}, {20, 160}, {20, 160}, {20, 80},
                       {24, 40},  {24, 20},  {26, 8},   {26, 3},   {28, 5}};
    return configs[10 - size_scale];
  }

  if (dataset == "osm_cellids_400M_uint64") {
    Configs configs = {{20, 190}, {20, 190}, {20, 190}, {20, 190}, {22, 80},
                       {24, 20},  {26, 20},  {26, 10},  {28, 6},   {28, 2}};
    return configs[10 - size_scale];
  }

  if (dataset == "osm_cellids_600M_uint64") {
    Configs configs = {{20, 190}, {20, 190}, {20, 190}, {22, 180}, {22, 100},
                       {24, 20},  {26, 20},  {28, 7},   {28, 5},   {28, 3}};
    return configs[10 - size_scale];
  }

  if (dataset == "osm_cellids_800M_uint64") {
    Configs configs = {{22, 190}, {22, 190}, {22, 190}, {22, 190}, {24, 190},
                       {26, 30},  {26, 20},  {28, 7},   {28, 5},   {28, 1}};
    return configs[10 - size_scale];
  }

  // Wiki
  if (dataset == "wiki_ts_200M_uint64") {
    Configs configs = {{14, 100}, {14, 100}, {16, 60}, {18, 20}, {20, 20},
                       {20, 9},   {20, 5},   {22, 3},  {26, 2},  {26, 1}};
    return configs[10 - size_scale];
  }

  cerr << "No tuning config for this dataset" << endl;
  throw;
}
}  // namespace rs_manual_tuning

namespace util {

// Loads values from binary file into vector.
template <typename T>
static vector<T> load_data(const string& filename, bool print = true) {
  vector<T> data;
  ifstream in(filename, ios::binary);
  if (!in.is_open()) {
    cerr << "unable to open " << filename << endl;
    exit(EXIT_FAILURE);
  }
  // Read size.
  uint64_t size;
  in.read(reinterpret_cast<char*>(&size), sizeof(uint64_t));
  data.resize(size);
  // Read values.
  in.read(reinterpret_cast<char*>(data.data()), size * sizeof(T));

  return data;
}

// Generates deterministic values for keys.
template <class KeyType>
static vector<pair<KeyType, uint64_t>> add_values(const vector<KeyType>& keys) {
  vector<pair<KeyType, uint64_t>> result;
  result.reserve(keys.size());

  for (uint64_t i = 0; i < keys.size(); ++i) {
    pair<KeyType, uint64_t> row;
    row.first = keys[i];
    row.second = i;

    result.push_back(row);
  }
  return result;
}

}  // namespace util

namespace {
template <class KeyType, class ValueType>
class NonOwningMultiMap {
 public:
  using element_type = pair<KeyType, ValueType>;

  NonOwningMultiMap(const vector<element_type>& elements,
                    size_t num_radix_bits = 18, size_t max_error = 32)
      : data_(elements) {
    assert(elements.size() > 0);

    // Create spline builder.
    const auto min_key = data_.front().first;
    const auto max_key = data_.back().first;
    srs::Builder<KeyType, ValueType> rsb(min_key, max_key, num_radix_bits, max_error);

    // Build the radix spline.
    rs_ = rsb.BulkLoadPair(data_.data(), data_.size());
  }

  typename vector<element_type>::const_iterator lower_bound(KeyType key) const {
    srs::SearchBound bound = rs_.GetSearchBound(key);
    return ::lower_bound(data_.begin() + bound.begin, data_.begin() + bound.end,
                         key, [](const element_type& lhs, const KeyType& rhs) {
                           return lhs.first < rhs;
                         });
  }

  uint64_t sum_up(KeyType key) const {
    uint64_t result = 0;
    auto iter = lower_bound(key);
    while (iter != data_.end() && iter->first == key) {
      result += iter->second;
      ++iter;
    }
    return result;
  }

  size_t GetSizeInByte() const { return rs_.GetSize(); }

 private:
  const vector<element_type>& data_;
  srs::sRadixSpline<KeyType> rs_;
};

template <class KeyType>
struct Lookup {
  KeyType key;
  uint64_t value;
};

template <class KeyType>
void Run(const string& data_file, const string lookup_file) {
  // Load data
  vector<KeyType> keys = util::load_data<KeyType>(data_file);
  vector<pair<KeyType, uint64_t>> elements = util::add_values(keys);
  vector<Lookup<KeyType>> lookups =
      util::load_data<Lookup<KeyType>>(lookup_file);

  for (uint32_t size_config = 1; size_config <= 10; ++size_config) {
    // Get the config for tuning
    auto tuning = rs_manual_tuning::GetTuning(data_file, size_config);

    // Build RS
    auto build_begin = chrono::high_resolution_clock::now();
    srs::Builder<KeyType, uint64_t> srsb(elements.front().first, elements.back().first, 
                                        tuning.first, tuning.second);
    srs::sRadixSpline<KeyType> srs = srsb.BulkLoadPair(elements.data(), elements.size());
    auto build_end = chrono::high_resolution_clock::now();
    uint64_t build_ns =
        chrono::duration_cast<chrono::nanoseconds>(build_end - build_begin)
            .count();

    // Run queries
    auto lookup_begin = chrono::high_resolution_clock::now();
    for (const Lookup<KeyType>& lookup_iter : lookups) {
          srs::SearchBound bound = srs.GetSearchBound(lookup_iter.key);
          auto iter = std::lower_bound(elements.begin() + bound.begin, elements.begin() + bound.end,
                                  lookup_iter.key, [](const std::pair<KeyType, uint64_t>& lhs, const KeyType& rhs) {
                                                return lhs.first < rhs;});
          auto iter2 = std::lower_bound(elements.begin(), elements.end(),
                        lookup_iter.key, [](const std::pair<KeyType, uint64_t>& lhs, const KeyType& rhs) {
                                      return lhs.first < rhs;});
      if (iter->first != iter2->first) {
        std::cout << iter - iter2 << std::endl;
        // cerr << "wrong result!" << endl;
        // throw "error";
      }
    }
    auto lookup_end = chrono::high_resolution_clock::now();
    uint64_t lookup_ns =
        chrono::duration_cast<chrono::nanoseconds>(lookup_end - lookup_begin)
            .count();

    cout << "RESULT:"
         << " data_file: " << data_file << " lookup_file: " << lookup_file
         << " radix_bit_count: " << tuning.first
         << " spline_error: " << tuning.second
         << " size_config: " << size_config
         << " used_memory[MB]: " << (srs.GetSize() / 1000) / 1000.0
         << " build_time[s]: " << (build_ns / 1000 / 1000) / 1000.0
         << " ns/lookup: " << lookup_ns / lookups.size() << endl;
  }
}

}  // namespace

int main(int argc, char** argv) {
  if (argc != 3) {
    cerr << "usage: " << argv[0] << " <data_file> <lookup_file>" << endl;
    throw;
  }
  const string data_file = argv[1];
  const string lookup_file = argv[2];

  if (data_file.find("32") != string::npos) {
    Run<uint32_t>(data_file, lookup_file);
  } else {
    Run<uint64_t>(data_file, lookup_file);
  }

  return 0;
}
