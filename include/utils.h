//
// Created by alexander on 12/4/21.
//

#ifndef SUBSTRINGSEARCH_UTILS_H
#define SUBSTRINGSEARCH_UTILS_H

#include <tuple>
#include <iostream>
enum Algorithms
{
    RabinKarp = 1,
    KnuthMorrisPratt = 2,
};

std::string gen_random(int len);
std::tuple<std::string, std::string> get_input_data_from_user();
#endif //SUBSTRINGSEARCH_UTILS_H
