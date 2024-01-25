#include "include/functions.h"
#include <cmath>
#include <numeric>
#include <algorithm>
#include <stdexcept>
#include <vector>
#include <cstdint>
#include <unordered_map>

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

    bool contains_any_of(std::vector<char> chars, std::string num_str) {
        for (int i = 0; i < static_cast<int>(chars.size()); i++) {
            if (num_str.find(chars[i]) != std::string::npos) {
                return true;
            }
        }
        return false;
    }

    std::vector<int64_t> candidate_primes_less_than(int64_t n) {
        std::vector<char> char_vec = {'0', '2', '4', '6', '8'};
        std::vector<int64_t> candidate_primes_less_than_n = {2};
        for (int64_t i = 3; i < n; i+=2) {
            if (is_prime(i) && !contains_any_of(char_vec, std::to_string(i))) { //&& !contains(0,2,4,5,6,8).
                candidate_primes_less_than_n.push_back(i);
            }
        }
        return candidate_primes_less_than_n;
    }

    int new_index(int current_index, int string_length) {
        return (current_index + 1) % string_length;
    }

    std::vector<int64_t> all_rotations_of(int64_t num) {
        std::vector<int64_t> all_rotations = {num};
        std::string start_num = std::to_string(num);

        for (int k = 0; k < static_cast<int>(start_num.length()) - 1; k++) {
            std::unordered_map<int, char> index_char_pairs;
            std::string next_rotation = "";
        
            for (int i = 0; i < static_cast<int>(start_num.length()); i++) {
                index_char_pairs[new_index(i, static_cast<int>(start_num.length()))] = start_num[i];
            }
        
            for (int j = 0; j < static_cast<int>(start_num.length()); j++) {
                next_rotation.push_back(index_char_pairs.at(j));
            }

            all_rotations.push_back(std::stoll(next_rotation));
            start_num = next_rotation;
        }

        return all_rotations;
    }

    int64_t circular_primes_less_than(int64_t n) {
        int64_t circular_prime_count = 0;
        std::vector<int64_t> candidates = candidate_primes_less_than(n);

        for (std::size_t i = 0; i < candidates.size(); i++) {
            int64_t current_candidate = candidates[i];
            std::vector<int64_t> all_rotations_of_current = all_rotations_of(current_candidate);
            bool all_rotations_prime = true;

            for (std::size_t j = 1; j < all_rotations_of_current.size(); j++) {
                if (std::find(candidates.begin(), candidates.end(), all_rotations_of_current[j]) != candidates.end()) {
                    continue;
                } else {
                    all_rotations_prime = false;
                }
            }

            if (all_rotations_prime) {
                circular_prime_count++;
            }
        }

        return circular_prime_count;
    }
}