//
// Created by alexander on 12/4/21.
//
#include <gtest/gtest.h>
#include "rabin-karp.h"
#include "knuth_morris_pratt.h"


// TODO add fixture usage  in order to avoid code duplication


TEST(BasicTests, KnuthMorrisPratt)
{
    // simple test with one pattern match
    std::vector<int> gt_answers;
    gt_answers.push_back(1);
    EXPECT_EQ(gt_answers, SubstringSearchKnuthMorrisPratt("ABCD", "BC"));

    // several pattern match
    gt_answers.insert(gt_answers.end(), {4, 7});
    EXPECT_EQ(gt_answers, SubstringSearchKnuthMorrisPratt("ABCDBCgBC", "BC"));

    std::vector<int> empty_answers;
    EXPECT_EQ(empty_answers, SubstringSearchKnuthMorrisPratt("ABCDBCgBC", "empty"));
}

TEST(BasicTests, RabinKarp)
{
    std::vector<int> gt_answers;
    gt_answers.push_back(1);
    EXPECT_EQ(gt_answers, SubstringSearchRabinKarp("ABCD", "BC"));
    // several pattern match
    gt_answers.insert(gt_answers.end(), {4, 7});
    EXPECT_EQ(gt_answers, SubstringSearchKnuthMorrisPratt("ABCDBCgBC", "BC"));

    std::vector<int> empty_answers;
    EXPECT_EQ(empty_answers, SubstringSearchKnuthMorrisPratt("ABCDBCgBC", "empty"));
}


