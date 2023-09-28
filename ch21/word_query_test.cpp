#include <gtest/gtest.h>
#include <unordered_set>

#include "word_query.h"

class WordQueryTest : public ::testing::Test {
protected:
    void SetUp() override {
        query_.set_text(text_);
    }

    std::string text_ =
            "Write a program to “clean up” a text file for use in a word query program; that is, replace punctuation with whitespace, "
            "put words into lower case, replace don’t with do not (etc.), and remove plurals (e.g., ships becomes ship). Don’t be too "
            "ambitious. For example, it’s hard to determine plurals in general, so just remove an s if you find both ship and ships. Use "
            "that program on a real-world text file with at least 5000 words (e.g., a research paper).";
    Word_query query_;
};

TEST_F(WordQueryTest, GetWordCount) {
    struct Test_case {
        std::string word;
        int expected;
    } test_cases[] = {
        {"ship", 4},
        {"find", 1},
        {"foobar", 0}
    };
    for (const Test_case& t : test_cases)
        EXPECT_EQ(query_.get_word_count(t.word), t.expected);
}

TEST_F(WordQueryTest, GetMostFrequentWords) {
    auto p = query_.get_most_frequent_words();
    std::set<std::string> expected = {"a"};
    EXPECT_EQ(p.first, expected);
    EXPECT_EQ(p.second, 5);
}

TEST_F(WordQueryTest, GetLongestWords) {
    std::set<std::string> expected = {"punctuation"};
    EXPECT_EQ(query_.get_longest_words(), expected);
}

TEST_F(WordQueryTest, GetShortestWords) {
    std::set<std::string> result = query_.get_shortest_words(), expected = {"a", "e", "g", "s"};
    EXPECT_EQ(result, expected);
}

TEST_F(WordQueryTest, GetWordsStartWith) {
    struct Test_case {
        char c;
        std::set<std::string> expected;
    } test_cases[] = {
        {'b', {"be", "becomes", "both"}},
        {'w', {"whitespace", "with", "word", "world", "write"}},
        {'z', {}}
    };
    for (const auto& t : test_cases)
        EXPECT_EQ(query_.get_words_start_with(t.c), t.expected);
}

TEST_F(WordQueryTest, GetWordsByLength) {
    struct Test_case {
        size_t n;
        std::set<std::string> expected;
    } test_cases[] = {
        {3, {"and", "etc", "for", "not", "put", "too", "use", "you"}},
        {10, {"whitespace"}},
        {20, {}}
    };
    for (const auto& t : test_cases)
        EXPECT_EQ(query_.get_words_by_length(t.n), t.expected);
}

TEST_F(WordQueryTest, NormalizeQuotes) {
    struct Test_case {
        std::string text, expected;
    } test_cases[] = {
        {"", ""},
        {"Write a program to “clean up” a text file", R"(Write a program to "clean up" a text file)"},
        {"replace don’t with do not (etc.)", "replace don't with do not (etc.)"}
    };
    for (Test_case t : test_cases) {
        normalize_quotes(t.text);
        EXPECT_EQ(t.text, t.expected);
    }
}

TEST_F(WordQueryTest, RemoveContractions) {
    struct Test_case {
        std::string text, expected;
    } test_cases[] = {
        {"", ""},
        {"replace don't with do not (etc.)", "replace do not with do not (etc.)"},
        {"it's hard to determine plurals in general", "it is hard to determine plurals in general"}
    };
    for (Test_case t : test_cases) {
        remove_contractions(t.text);
        EXPECT_EQ(t.text, t.expected);
    }
}

TEST_F(WordQueryTest, RemovePunctuations) {
    struct Test_case {
        std::string text, expected;
    } test_cases[] = {
        {"", ""},
        {"remove plurals (e.g., ships becomes ship).", "remove plurals  e g  ships becomes ship "},
        {R"("And what is the use of a book," thought Alice "without pictures or conversations?")",
                " And what is the use of a book  thought Alice  without pictures or conversations "}
    };
    for (Test_case t : test_cases) {
        remove_punctuations(t.text);
        EXPECT_EQ(t.text, t.expected);
    }
}

TEST_F(WordQueryTest, ToLower) {
    struct Test_case {
        std::string text, expected;
    } test_cases[] = {
        {"", ""},
        {"For example, It’s HARD to determine plurals in general",
                "for example, it’s hard to determine plurals in general"}
    };
    for (Test_case t : test_cases) {
        to_lower(t.text);
        EXPECT_EQ(t.text, t.expected);
    }
}

TEST_F(WordQueryTest, StemWords) {
    struct Test_case {
        std::string text, expected;
    } test_cases[] = {
        {"", ""},
        {"remove plurals ships becomes ship", "remove plurals ship becomes ship"},
        {"He knows I know he knows", "He know I know he know"}
    };
    for (Test_case t : test_cases) {
        stem_words(t.text);
        EXPECT_EQ(t.text, t.expected);
    }
}
