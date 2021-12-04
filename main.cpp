#include "rabin-karp.h"
#include "utils.h"
#include "knuth_morris_pratt.h"

#include <chrono>
#include <tuple>
#include <functional>


std::tuple<long, std::vector<int>> run(const std::string& source_string,
                                       const std::string& pattern,
                                       const std::function<std::vector<int>
                                       (std::string,std::string)>& algorithm)
{
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    std::vector<int> answers = algorithm(source_string, pattern);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    long elapsed_time = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
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

int main()
{
    // could be any prime number
    std::string source_string, pattern;
    getline(std::cin, source_string);
    getline(std::cin, pattern);
    long elapsed_time;
    std::vector<int> answers;

    tie(elapsed_time, answers)  = run_benchmark(1, source_string, pattern);
    std::cout << "Algorithm finished work with: "<< elapsed_time << " microseconds" << std::endl;
    for (auto answer : answers)
        std::cout << "Algorithm Found match with start index: " << answer << std::endl;
    return 0;
}
