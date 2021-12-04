#include "rabin-karp.h"
#include "knuth_morris_pratt.h"
#include <chrono>

int main()
{
    // could be any prime number
    int q = 11;
    std::string source_string, pattern;
    getline(std::cin, source_string);
    getline(std::cin, pattern);

    std::chrono::steady_clock::time_point begin_rk = std::chrono::steady_clock::now();
    std::vector<int> rk_answers = SubstringSearchRabinKarp(source_string, pattern, q);
    std::chrono::steady_clock::time_point end_rk = std::chrono::steady_clock::now();
    long elapsed_rk_time = std::chrono::duration_cast<std::chrono::microseconds>(end_rk - begin_rk).count();
    std::cout << "Rabin Karp finished work with: "<< elapsed_rk_time << " microseconds" << std::endl;

    for (auto answer : rk_answers)
        std::cout << "RK Found match with start index: " << answer << std::endl;

    std::chrono::steady_clock::time_point begin_kmp = std::chrono::steady_clock::now();
    std::vector<int> kmp_answers = SubstringSearchKnuthMorrisPratt(source_string, pattern);
    std::chrono::steady_clock::time_point end_kmp = std::chrono::steady_clock::now();
    long elapsed_kmp_time = std::chrono::duration_cast<std::chrono::microseconds>(end_kmp - begin_kmp).count();
    std::cout << "KMP finished work with: "<< elapsed_kmp_time << " microseconds" << std::endl;
    for (auto answer : kmp_answers)
        std::cout << "KMP Found match with start index: " << answer << std::endl;
    return 0;
}
