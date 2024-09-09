#pragma once

#include <cstddef>
#include <cstdint>

namespace scht {

struct SearchBound {
  size_t begin;
  size_t end;  // Exclusive.
};

}  // namespace scht
