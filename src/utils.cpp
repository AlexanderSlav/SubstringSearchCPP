//
// Created by alexander on 12/4/21.
//

#include "utils.h"

std::string gen_random(const int len) {
    static const char alphanum[] =
            "0123456789 "
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";
    std::string tmp_s;
    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i) {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    return tmp_s;
}

std::tuple<std::string, std::string> get_input_data_from_user()
{
    std::string source_string, pattern;
    std::cout <<"Please enter the source string: "<< std::endl;
    getline(std::cin, source_string);
    std::cout <<"Please enter the pattern to search: "<< std::endl;
    getline(std::cin, pattern);
    return {source_string, pattern};

}