//
// Created by alexander on 12/4/21.
//

#include "utils.h"
#include "knuth_morris_pratt.h"
#include "rabin-karp.h"




// Data utils
std::tuple<std::string, std::string> gen_random(int source_string_len, int pattern_len) {
    static const char alphanum[] =
            "0123456789 "
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";
    std::string source_string;
    std::string pattern;
    source_string.reserve(source_string_len);
    pattern.reserve(pattern_len);

    for (int i = 0; i < source_string_len; ++i) {
        source_string += alphanum[rand() % (sizeof(alphanum) - 1)];
    }
// generate pattern randomly is not the best option
//    for (int i = 0; i < pattern_len; ++i) {
//        pattern += alphanum[rand() % (sizeof(alphanum) - 1)];
//    }
// choose random substring
    pattern = source_string.substr(0, pattern_len);

    return {source_string, pattern};
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


// Benchmark Utils
std::tuple<long, std::vector<int>> run(const std::string& source_string,
                                       const std::string& pattern,
                                       const std::function<std::vector<int>
                                               (std::string,std::string)>& algorithm)
{
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    std::vector<int> answers = algorithm(source_string, pattern);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    long elapsed_time = std::chrono::duration_cast<std::chrono:: microseconds>(end - begin).count();
    return {elapsed_time, answers};
}


std::tuple<long, std::vector<int>> run_benchmark(int algorithm_name, const std::string& input_string, const std::string& pattern)
{
    long elapsed_time;
    std::vector<int> answers;

    switch(algorithm_name)
    {
        case KnuthMorrisPratt:
            tie(elapsed_time, answers) = run(input_string, pattern, SubstringSearchKnuthMorrisPratt);
            return {elapsed_time, answers};
        case RabinKarp:
            tie(elapsed_time, answers) = run(input_string, pattern, SubstringSearchRabinKarp);
            return {elapsed_time, answers};
        default:
        {
            throw std::invalid_argument("algorithm_name arguments must be 1 or 2");
        }

    }
}