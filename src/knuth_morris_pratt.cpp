//
// Created by alexander on 12/4/21.
//
#include "knuth_morris_pratt.h"


std::vector<int> SubstringSearchKnuthMorrisPratt(std::string source_text, std::string pattern)
{
    std::vector<int> answers;
    int source_chars_amount = source_text.length();
    int pattern_chars_amount = pattern.length();

    int prefix_vector[pattern_chars_amount];

    // prefix vector generation O(n) n - len of pattern
    prefix_vector[0] = 0;
    int j = 0;
    int i = 1;
    // for i element we set the max len of equal prefix and suffix of pattern substring
    while(i <= pattern_chars_amount)
    {
        if(pattern[i] == pattern[j])
        {
            prefix_vector[i] = j + 1;
            i += 1;
            j += 1;
        }
        else if (j == 0)
        {
            prefix_vector[i] = 0;
            i += 1;
        }
        else
        {
            j = prefix_vector[j-1];
        }
    }

    // substring search O(m) - m len of source text
    int source_index = 0;
    int pattern_index = 0;
    while(source_index < source_chars_amount)
    {
        if (source_text[source_index] == pattern[pattern_index])
        {
            source_index += 1;
            pattern_index += 1;
        }
        if (pattern_index == pattern_chars_amount)
        {
            answers.push_back(source_index - pattern_index);
            pattern_index = prefix_vector[pattern_index - 1];

        }
        // element doesn't match after pattern_index time matches
        else if (source_index < source_chars_amount && pattern[pattern_index] != source_text[source_index])
        {
            if (pattern_index != 0)
            {
                // move on size of suffix back
                pattern_index = prefix_vector[pattern_index - 1];
            }
            else
            {
                source_index+=1;
            }
        }
    }
    return answers;
}