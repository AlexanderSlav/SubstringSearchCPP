#include "utils.h"
#include <numeric>
#include <string.h>
#include <math.h>

# define r 2


int main(int argc, char *argv[] )
{
    // define variables
    long elapsed_time;
    std::vector<int> answers;
    std::string algorithm_name;
    std::string source_string, pattern;
    int algorithm_number = atoi(argv[1]);

    std::vector<std::tuple<std::string, std::string>> data;

    if (argc > 2)
    {
        // Benchmark algorithm
        if (strcmp(argv[2], "auto") == 0) // This compares what the pointers point to
        {
            std::vector<int> data_size;
            int cur_size;
            for (int i = 4; i < 20; i++)
            {
                cur_size = 2 * pow(r, i);
                tie(source_string, pattern) = gen_random(cur_size, cur_size / 10);
                data.emplace_back(source_string, pattern);
            }
        }
    }
    else {
        tie(source_string, pattern) = get_input_data_from_user();
    }
    for (auto&& tuple: data)
    {
        std::tie(source_string, pattern ) = tuple;
        tie(elapsed_time, answers)  = run_benchmark(algorithm_number, source_string, pattern);
        if (algorithm_number == 1)
        {
            algorithm_name = "Rabin-Karp ";
        }
        else if (algorithm_number == 2)
        {
            algorithm_name = "Knuth-Morris-Pratt ";
        }
        std::cout << algorithm_name << "finished work with: "<< elapsed_time << " microseconds" << std::endl;

        for (auto answer : answers)
            std::cout << algorithm_name << "found match with start index: " << answer << std::endl;
    }

    return 0;
}