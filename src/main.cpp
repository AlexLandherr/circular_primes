#include "include/functions.h"
#include <iostream>
#include <cstdint>
#include <vector>
#include <stdexcept>

/*
The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.

There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.

How many circular primes are there below one million?
*/

int main() {
    try {
        std::vector<int64_t> result = func::all_primes_less_than(1000000);
        int64_t prime_count = static_cast<int64_t>(result.size());
        std::cout << "Primes below 1e6: " << prime_count << '\n';
    } catch (const std::invalid_argument& ex) {
        std::cerr << ex.what() << '\n';
    } catch (const std::exception& ex) {
        std::cerr << ex.what() << '\n';
    }

    return 0;
}