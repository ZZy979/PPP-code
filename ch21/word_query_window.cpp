#include "word_query_window.h"

#include <algorithm>
#include <fstream>
#include <iterator>
#include <sstream>
#include <string>

#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_File_Chooser.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Menu_Item.H>
#include <FL/Fl_Text_Display.H>

static Fl_Menu_Item MENU_ITEMS[] = {
    {"&File", 0, 0, 0, FL_SUBMENU},
    {"&Open File...", FL_COMMAND + 'o', [](Fl_Widget*, void* w) { static_cast<Word_query_window*>(w)->open_file(); }},
    {"E&xit", FL_COMMAND + 'q', [](Fl_Widget*, void*) { exit(0); }},
    {0},

    {0}
};

Word_query_window::Word_query_window(int w, int h, const char* title) :Fl_Window(w, h, title) {
    Fl_Menu_Bar* menu_bar = new Fl_Menu_Bar(0, 0, w, 30);
    menu_bar->box(FL_THIN_UP_BOX);
    menu_bar->copy(MENU_ITEMS, this);

    Fl_Box* header = new Fl_Box(0, 30, w, 40, "Word Query");
    header->labelsize(20);

    text_content_buf_ = new Fl_Text_Buffer();
    Fl_Text_Display* text_content = new Fl_Text_Display(20, 90, (w - 60) * 3 / 4, h - 320, "Text content");
    text_content->buffer(text_content_buf_);
    text_content->wrap_mode(Fl_Text_Display::WRAP_AT_BOUNDS, 0);

    query_result_buf_ = new Fl_Text_Buffer();
    Fl_Text_Display* query_result = new Fl_Text_Display(text_content->w() + 40, 90, (w - 60) / 4, h - 320, "Query result");
    query_result->buffer(query_result_buf_);
    query_result->wrap_mode(Fl_Text_Display::WRAP_AT_BOUNDS, 0);

    Fl_Button* word_count_button = new Fl_Button(20, h - 220, 200, 25, "Word count");
    word_count_button->callback([](Fl_Widget*, void* w) { static_cast<Word_query_window*>(w)->get_word_count(); }, this);
    word_count_input_ = new Fl_Input(230, h - 220, 100, 25);
    word_count_output_ = new Fl_Output(340, h - 220, 100, 25);

    Fl_Button* most_frequent_words_button = new Fl_Button(20, h - 185, 200, 25, "Most frequent words");
    most_frequent_words_button->callback([](Fl_Widget*, void* w) { static_cast<Word_query_window*>(w)->get_most_frequent_words(); }, this);

    Fl_Button* longest_words_button = new Fl_Button(20, h - 150, 200, 25, "Longest words");
    longest_words_button->callback([](Fl_Widget*, void* w) { static_cast<Word_query_window*>(w)->get_longest_words(); }, this);

    Fl_Button* shortest_words_button = new Fl_Button(20, h - 115, 200, 25, "Shortest words");
    shortest_words_button->callback([](Fl_Widget*, void* w) { static_cast<Word_query_window*>(w)->get_shortest_words(); }, this);

    Fl_Button* words_start_with_button = new Fl_Button(20, h - 80, 200, 25, "Words Starting with");
    words_start_with_button->callback([](Fl_Widget*, void* w) { static_cast<Word_query_window*>(w)->get_words_start_with(); }, this);
    word_start_input_ = new Fl_Input(230, h - 80, 100, 25);

    Fl_Button* words_of_length_button = new Fl_Button(20, h - 45, 200, 25, "Words of length");
    words_of_length_button->callback([](Fl_Widget*, void* w) { static_cast<Word_query_window*>(w)->get_words_by_length(); }, this);
    word_length_input_ = new Fl_Int_Input(230, h - 45, 100, 25);
}

void Word_query_window::open_file() {
    if (const char* filename = fl_file_chooser("Choose a text file", "Text Files (*.txt)", "")) {
        std::ifstream ifs(filename);
        if (!ifs)
            return;

        std::istreambuf_iterator<char> iit(ifs), eos;
        std::string text(iit, eos);
        text_content_buf_->text(text.c_str());

        query_.open(filename);
    }
}

void Word_query_window::get_word_count() {
    std::string word = word_count_input_->value();
    if (word.empty())
        return;
    int count = query_.get_word_count(word);
    word_count_output_->value(std::to_string(count).c_str());
}

void Word_query_window::get_most_frequent_words() {
    set_query_result(query_.get_most_frequent_words().first);
}

void Word_query_window::get_longest_words() {
    set_query_result(query_.get_longest_words());
}

void Word_query_window::get_shortest_words() {
    set_query_result(query_.get_shortest_words());
}

void Word_query_window::get_words_start_with() {
    std::string input = word_start_input_->value();
    if (input.empty())
        return;
    set_query_result(query_.get_words_start_with(input[0]));
}

void Word_query_window::get_words_by_length() {
    std::string input = word_length_input_->value();
    if (input.empty())
        return;
    set_query_result(query_.get_words_by_length(std::stoul(input)));
}

template<class Iter>
void Word_query_window::set_query_result(Iter first, Iter last) {
    std::ostringstream oss;
    std::ostream_iterator<std::string> oit(oss, "\n");
    std::copy(first, last, oit);
    query_result_buf_->text(oss.str().c_str());
}

void Word_query_window::set_query_result(const std::set<std::string>& result) {
    set_query_result(result.begin(), result.end());
}
