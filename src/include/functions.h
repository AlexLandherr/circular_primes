#include <cstdint>
#include <vector>
#include <string>

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

namespace func {
    bool is_prime(int64_t n);
    bool contains_any_of(std::vector<char> chars, std::string num_str);
    std::vector<int64_t> candidate_primes_less_than(int64_t n);
}

#endif