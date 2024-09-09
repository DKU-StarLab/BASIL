#pragma once

class Competitor {
 public:
  bool applicable(bool _unique, const std::string& data_filename) const {
    return true;
  }

  std::string variant() const { return NULL; }
};
