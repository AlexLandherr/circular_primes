#include "include/functions.h"
#include <cmath>
#include <numeric>
#include <algorithm>
#include <stdexcept>
#include <vector>
#include <cstdint>

/*
The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.

There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.

How many circular primes are there below one million?
*/

namespace func {
    bool is_prime(int64_t n) {
        //Checks if a single signed 64-bit integer is a prime number.
        if (n > std::numeric_limits<int64_t>::max() || n < std::numeric_limits<int64_t>::min()) {
            throw std::invalid_argument("Argument 'n' is out of range for 'int64_t' type.");
        }
        if (n <= 1) {
            return false;
        } else if (n == 2) {
            return true;
        } else if (n > 2 && n % 2 == 0) {
            return false;
        }

        int64_t max_divisor = std::ceil(std::sqrt((long double) n));
        for (int64_t d = 3; d < max_divisor + 1; d+=2) {
            if (n % d == 0) {
                return false;
            }
        }

        return true;
    }

    std::vector<int64_t> candidate_primes_less_than(int64_t n) {
        std::vector<int64_t> all_primes_less_than_n = {2};
        for (int64_t i = 3; i < n; i+=2) {
            if (is_prime(i)) {
                all_primes_less_than_n.push_back(i);
            }
        }
        return all_primes_less_than_n;
    }
}