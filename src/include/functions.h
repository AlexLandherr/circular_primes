#include <cstdint>
#include <vector>

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

namespace func {
    bool is_prime(int64_t n);
    std::vector<int64_t> all_primes_less_than(int64_t n);
}

#endif