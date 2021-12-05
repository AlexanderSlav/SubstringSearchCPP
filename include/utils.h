//
// Created by alexander on 12/4/21.
//

#ifndef SUBSTRINGSEARCH_UTILS_H
#define SUBSTRINGSEARCH_UTILS_H

#include <tuple>
#include <iostream>
#include <fstream>
#include <chrono>
#include <functional>
#include <vector>

enum Algorithms
{
    RabinKarp = 1,
    KnuthMorrisPratt = 2,
};

std::tuple<std::string, std::string> gen_random(int source_string_len, int pattern_len);

std::tuple<std::string, std::string> get_input_data_from_user();

std::tuple<long, std::vector<int>> run(const std::string& source_string,
                                       const std::string& pattern,
                                       const std::function<std::vector<int>
                                               (std::string,std::string)>& algorithm);

std::tuple<long, std::vector<int>> run_benchmark(int algorithm_name, const std::string& input_string, const std::string& pattern);

#endif //SUBSTRINGSEARCH_UTILS_H
