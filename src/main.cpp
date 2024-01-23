#include "include/functions.h"
#include <iostream>
#include <cstdint>
#include <vector>
#include <stdexcept>
#include <string>

/*
The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.

There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.

How many circular primes are there below one million?
*/

int main() {
    /* try {
        std::vector<int64_t> result = func::candidate_primes_less_than(1000000);
        int64_t prime_count = static_cast<int64_t>(result.size());
        std::cout << "Candidate primes below 1e6: " << prime_count << '\n';
    } catch (const std::invalid_argument& ex) {
        std::cerr << ex.what() << '\n';
    } catch (const std::exception& ex) {
        std::cerr << ex.what() << '\n';
    } */
    /* std::vector<char> char_vec = {'0', '2', '4', '5', '6', '8'};
    std::string num_str = "132";
    std::cout << "Does num_str contain any of the characters in char_vec?: " << std::boolalpha << func::contains_any_of(char_vec, num_str) << '\n'; */
    int64_t start_number = 197;
    std::vector<int64_t> all_rotations_result = func::all_rotations_of(start_number);
    for (std::size_t i = 0; i < all_rotations_result.size(); i++) {
        std::cout << (i + 1) << " rotation: " << all_rotations_result[i] << '\n';
    }

    return 0;
}