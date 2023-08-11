#include <algorithm>
#include <gtest/gtest.h>
#include <sstream>

#include "simple_text_editor.h"

class SimpleTextEditorTest : public ::testing::Test {
protected:
    void SetUp() override {
        std::istringstream iss(text_);
        iss >> document_;
    }

    Document document_;
    std::string text_ =
            "To be, or not to be: that is the question:\n"
            "Whether 'tis nobler in the mind to suffer\n"
            "The slings and arrows of outrageous fortune,\n"
            "Or to take arms against a sea of troubles,\n"
            "And by opposing end them? To die: to sleep;\n";
};

TEST_F(SimpleTextEditorTest, Input) {
    std::string input = "No more; and by a sleep to say we end\n";
    std::string expected = text_ + input;
    std::istringstream iss(input);
    iss >> document_;
    EXPECT_EQ(std::string(document_.begin(), document_.end()), expected);
}

TEST_F(SimpleTextEditorTest, Output) {
    std::ostringstream oss;
    oss << document_;
    EXPECT_EQ(oss.str(), text_);
}

TEST_F(SimpleTextEditorTest, EraseLine) {
    erase_line(document_, -1);
    EXPECT_EQ(std::string(document_.begin(), document_.end()), text_);

    erase_line(document_, 5);
    EXPECT_EQ(std::string(document_.begin(), document_.end()), text_);
    
    std::string expected =
            "To be, or not to be: that is the question:\n"
            "Whether 'tis nobler in the mind to suffer\n"
            "The slings and arrows of outrageous fortune,\n"
            "And by opposing end them? To die: to sleep;\n";
    erase_line(document_, 3);
    EXPECT_EQ(std::string(document_.begin(), document_.end()), expected);
}

TEST_F(SimpleTextEditorTest, FindTxt) {
    std::string s = "question";
    auto it = find_txt(document_.begin(), document_.end(), s);
    EXPECT_NE(it, document_.end());
    EXPECT_EQ(std::string(it, std::next(it, s.length())), s);

    it = find_txt(std::next(it, s.length()), document_.end(), s);
    EXPECT_EQ(it, document_.end());

    s = "suffer\nThe";
    it = find_txt(document_.begin(), document_.end(), s);
    EXPECT_NE(it, document_.end());
    EXPECT_EQ(std::string(it, std::next(it, s.length())), s);

    it = find_txt(document_.begin(), document_.end(), "are");
    EXPECT_EQ(it, document_.end());
}

TEST_F(SimpleTextEditorTest, Iterator) {
    EXPECT_TRUE(std::equal(document_.begin(), document_.end(), text_.begin()));
    EXPECT_EQ(std::count(document_.begin(), document_.end(), 'e'), 20);

    auto it = std::find(document_.begin(), document_.end(), '?');
    EXPECT_NE(it, document_.end());
    EXPECT_EQ(*it, '?');
}

TEST_F(SimpleTextEditorTest, Insert) {
    const std::string text = "aaaaa\nbbbbb\nccccc";
    const std::string s0, s1 = "AA", s2 = "AA\nBB", s3 = "AA\nBB\nCC";

    struct Test_case {
        std::string text;
        Text_iterator::difference_type pos;
        std::string s, expected_text;
    } test_cases[] = {
        // insert empty line
        {text, 0, s0, text},
        {text, 8, s0, text},
        {text, 17, s0, text},
        {"", 0, s0, ""},
        // insert single line
        {text, 0, s1, "AAaaaaa\nbbbbb\nccccc"},
        {text, 0, s1 + '\n', "AA\naaaaa\nbbbbb\nccccc"},
        {text, 8, s1, "aaaaa\nbbAAbbb\nccccc"},
        {text, 8, s1 + '\n', "aaaaa\nbbAA\nbbb\nccccc"},
        {text, 11, s1, "aaaaa\nbbbbbAA\nccccc"},
        {text, 11, s1 + '\n', "aaaaa\nbbbbbAA\n\nccccc"},
        {text, 17, s1, "aaaaa\nbbbbb\ncccccAA"},
        {text, 17, s1 + '\n', "aaaaa\nbbbbb\ncccccAA\n"},
        {text + '\n', 18, s1, "aaaaa\nbbbbb\nccccc\nAA"},
        {text + '\n', 18, s1 + '\n', "aaaaa\nbbbbb\nccccc\nAA\n"},
        {"", 0, s1, s1},
        // insert two lines
        {text, 6, s2, "aaaaa\nAA\nBBbbbbb\nccccc"},
        {text, 6, s2 + '\n', "aaaaa\nAA\nBB\nbbbbb\nccccc"},
        {text, 4, s2, "aaaaAA\nBBa\nbbbbb\nccccc"},
        {text, 4, s2 + '\n', "aaaaAA\nBB\na\nbbbbb\nccccc"},
        {text, 11, s2, "aaaaa\nbbbbbAA\nBB\nccccc"},
        {text, 11, s2 + '\n', "aaaaa\nbbbbbAA\nBB\n\nccccc"},
        {text, 17, s2, "aaaaa\nbbbbb\ncccccAA\nBB"},
        {text, 17, s2 + '\n', "aaaaa\nbbbbb\ncccccAA\nBB\n"},
        {text + '\n', 18, s2, "aaaaa\nbbbbb\nccccc\nAA\nBB"},
        {text + '\n', 18, s2 + '\n', "aaaaa\nbbbbb\nccccc\nAA\nBB\n"},
        {"", 0, s2 + '\n', s2 + '\n'},
        // insert multiple lines
        {text, 0, s3, "AA\nBB\nCCaaaaa\nbbbbb\nccccc"},
        {text, 0, s3 + '\n', "AA\nBB\nCC\naaaaa\nbbbbb\nccccc"},
        {text, 2, s3, "aaAA\nBB\nCCaaa\nbbbbb\nccccc"},
        {text, 2, s3 + '\n', "aaAA\nBB\nCC\naaa\nbbbbb\nccccc"},
        {text, 5, s3, "aaaaaAA\nBB\nCC\nbbbbb\nccccc"},
        {text, 5, s3 + '\n', "aaaaaAA\nBB\nCC\n\nbbbbb\nccccc"},
        {text, 17, s3, "aaaaa\nbbbbb\ncccccAA\nBB\nCC"},
        {text, 17, s3 + '\n', "aaaaa\nbbbbb\ncccccAA\nBB\nCC\n"},
        {text + '\n', 18, s3, "aaaaa\nbbbbb\nccccc\nAA\nBB\nCC"},
        {text + '\n', 18, s3 + '\n', "aaaaa\nbbbbb\nccccc\nAA\nBB\nCC\n"},
        {"", 0, s3, s3},
    };

    for (const auto& t : test_cases) {
        Document d = create_document(t.text);
        auto it = d.insert(std::next(d.begin(), t.pos), t.s);

        std::string tmp = t.text;
        tmp.insert(t.pos, t.s);

        EXPECT_EQ(std::string(d.begin(), d.end()), t.expected_text);
        EXPECT_EQ(tmp, t.expected_text);
        EXPECT_EQ(std::distance(d.begin(), it), t.pos);
    }
}

TEST_F(SimpleTextEditorTest, Erase) {
    const std::string text = "aaaaa\nbbbbb\nccccc\nddddd\neeeee\n\nfffff\n";

    struct Test_case {
        std::string text;
        Text_iterator::difference_type first, last;
        std::string expected_text;
    } test_case[] = {
        // erase single line
        {text, 8, 8, text},
        {text, 37, 37, text},
        {text, 1, 3, "aaa\nbbbbb\nccccc\nddddd\neeeee\n\nfffff\n"},
        {text, 12, 17, "aaaaa\nbbbbb\n\nddddd\neeeee\n\nfffff\n"},
        {text, 33, 36, "aaaaa\nbbbbb\nccccc\nddddd\neeeee\n\nff\n"},
        // erase two adjacent lines
        {text, 8, 14, "aaaaa\nbbccc\nddddd\neeeee\n\nfffff\n"},
        {text, 6, 12, "aaaaa\nccccc\nddddd\neeeee\n\nfffff\n"},
        {text, 11, 17, "aaaaa\nbbbbb\nddddd\neeeee\n\nfffff\n"},
        {text, 26, 30, "aaaaa\nbbbbb\nccccc\nddddd\nee\nfffff\n"},
        {text, 30, 31, "aaaaa\nbbbbb\nccccc\nddddd\neeeee\nfffff\n"},
        {text, 30, 34, "aaaaa\nbbbbb\nccccc\nddddd\neeeee\nff\n"},
        {text, 33, 37, "aaaaa\nbbbbb\nccccc\nddddd\neeeee\n\nff"},
        // erase multiple lines
        {text, 1, 21, "add\neeeee\n\nfffff\n"},
        {text, 6, 24, "aaaaa\neeeee\n\nfffff\n"},
        {text, 3, 36, "aaa\n"},
        {text, 3, 37, "aaa"},
        {text, 27, 37, "aaaaa\nbbbbb\nccccc\nddddd\neee"},
        {text, 18, 37, "aaaaa\nbbbbb\nccccc\n"},
        {text, 0, 37, ""},
    };

    for (const auto& t : test_case) {
        Document d = create_document(t.text);
        auto it = d.erase(std::next(d.begin(), t.first), std::next(d.begin(), t.last));

        std::string tmp = t.text;
        tmp.erase(tmp.begin() + t.first, tmp.begin() + t.last);

        EXPECT_EQ(std::string(d.begin(), d.end()), t.expected_text);
        EXPECT_EQ(tmp, t.expected_text);
        EXPECT_EQ(std::distance(d.begin(), it), t.first);
    }
}

TEST_F(SimpleTextEditorTest, Replace) {
    struct Test_case {
        std::string text, target, replacement, expected_text;
        int expected_count;
    } test_cases[] = {
        {"AAA\nBBB\n", "foo", "bar", "AAA\nBBB\n", 0},
        {"AAfooA\nBBB\n", "foo", "bar", "AAbarA\nBBB\n", 1},
        {"AAfooA\nBfooBB\n", "foo", "foobar", "AAfoobarA\nBfoobarBB\n", 2},
        {"AAfooA\nBBB\n", "foo", "bar\nbaz", "AAbar\nbazA\nBBB\n", 1},
        {"AAfooA\nBBB\n", "foo", "", "AAA\nBBB\n", 1},
        {"AAfoo\nbarBB\n", "foo\nbar", "baz", "AAbazBB\n", 1},
        {"AAfoo\nbarBB\n", "foo\nbar", "baz\nqux\n", "AAbaz\nqux\nBB\n", 1},
        {"AAfoo\nbarBB\n", "foo\nbar", "", "AABB\n", 1},
        {"AAA\nBBB\n", "AAA\n", "aaa", "aaaBBB\n", 1},
        {"AAA\nBBB\n", "B", "b", "AAA\nbbb\n", 3},
        {"AAA\nBBB\n", "BBB\n", "bbb\n", "AAA\nbbb\n", 1},
    };

    for (const auto& t : test_cases) {
        Document d = create_document(t.text);
        EXPECT_EQ(d.replace_all(t.target, t.replacement), t.expected_count);
        EXPECT_EQ(std::string(d.begin(), d.end()), t.expected_text);
    }
}

TEST_F(SimpleTextEditorTest, CharacterCount) {
    struct Test_case {
        std::string text;
        int expected;
    } test_cases[] = {
        {text_, static_cast<int>(text_.length())},
        {"aaa\nbbb", 7},
        {"", 0},
    };

    for (const auto& t : test_cases) {
        Document d = create_document(t.text);
        EXPECT_EQ(character_count(d.begin(), d.end()), t.expected);
    }
}

TEST_F(SimpleTextEditorTest, WordCount) {
    struct Test_case {
        std::string text;
        int expected1, expected2, expected3;
    } test_cases[] = {
        {"", 0, 0, 0},
        {text_, 43, 43, 1},
        {"alpha.numeric", 1, 2, 1},
        {"as12b", 1, 2, 1},
        {"He's my friend.", 3, 4, 1},
        {"/home/zzy/document/foo.txt", 1, 5, 4},
        {R"(C:\Program Files\Internet Explorer\iexplore.exe)", 3, 7, 4},
    };

    auto non_alpha = [](char c) -> bool { return !isalpha(c); };
    const std::string custom_whitespace = "/\\";
    for (const auto& t : test_cases) {
        Document d = create_document(t.text);
        EXPECT_EQ(word_count(d.begin(), d.end()), t.expected1);
        EXPECT_EQ(word_count(d.begin(), d.end(), non_alpha), t.expected2);
        EXPECT_EQ(word_count(d.begin(), d.end(), custom_whitespace), t.expected3);
    }
}
