#pragma once

#include <FL/Fl_Input.H>
#include <FL/Fl_Int_Input.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Text_Buffer.H>
#include <FL/Fl_Window.H>

#include "word_query.h"

// A window to "clean up" a text file for use in word query.
class Word_query_window : public Fl_Window {
public:
    Word_query_window(int w, int h, const char* title = nullptr);

    void open_file();
    void get_word_count();
    void get_most_frequent_words();
    void get_longest_words();
    void get_shortest_words();
    void get_words_start_with();
    void get_words_by_length();

private:
    template<class Iter>
    void set_query_result(Iter first, Iter last);

    void set_query_result(const std::set<std::string>& result);

    // widgets
    Fl_Text_Buffer* text_content_buf_;
    Fl_Text_Buffer* query_result_buf_;
    Fl_Input* word_count_input_;
    Fl_Output* word_count_output_;
    Fl_Input* word_start_input_;
    Fl_Int_Input* word_length_input_;

    // data
    Word_query query_;
};
