//
// Created by alexander on 12/4/21.
//

#include "rabin-karp.h"
#include <cmath>

// number of characters in alphabet
# define p 256


std::vector<int> SubstringSearchRabinKarp(std::string source_text, std::string pattern, int r)
{
    std::vector<int> answers;
    unsigned long n = source_text.length();
    unsigned long m = pattern.length();
    int pattern_hash = 0;
    int source_text_hash = 0;
    int h = 1;
    h = pow(p, m - 1)  ;
    h = h % r;

    for (auto i = 0; i < m; i ++)
    {
        pattern_hash = (p * pattern_hash + pattern[i]) % r;
        source_text_hash = (p * source_text_hash + source_text[i]) % r;
    }

    for (auto i = 0; i <= n - m; i ++)
    {
        if (pattern_hash == source_text_hash)
        {
            bool per_char_equal = true;
            for (auto j = 0; j < m; j++)
            {
                if (source_text[i+j] != pattern[j])
                {
                    per_char_equal = false;
                    break;
                }
            }
            if (per_char_equal)
            {
                answers.push_back(i);
            }
        }
        if (i < n - m)
        {
            // We will calculate hash using modular arithmetic
            // Example with simple string: Len of pattern is 3. The search string is "12345"
            // 1. We found hash for "123" = 123
            // 2. For “234” we will do (123 – 1*100)*10 + 4 and get 234.
            // 3. So we can say that we remove the first char, made a shift and concat with new char
            source_text_hash = (p * (source_text_hash - source_text[i] * h) + source_text[i+m]) % r;
            if (source_text_hash < 0)
            {
                source_text_hash += r;
            }
        }
    }
    return answers;
}