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
