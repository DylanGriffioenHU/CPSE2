//
// Created by dylan on 12-3-2020.
//

#include <iostream>
#include "stl.hpp"


int main() {
    auto stl_obj = stl();
    stl_obj.chars_from_file_to_vect();
    stl_obj.count_chars_in_vect();
    stl_obj.count_lines_in_vect();
    stl_obj.count_alfab_chars();
    stl_obj.chars_to_lower_case();
    stl_obj.count_all_letters();
    stl_obj.print_letter_set();
    stl_obj.ten_common_words();
    stl_obj.print_word_set();
//    stl_obj.print_vect();
}
