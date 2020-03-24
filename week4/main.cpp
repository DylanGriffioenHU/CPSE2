//
// Created by dylan on 12-3-2020.
//

#include <iostream>
#include "assignment.hpp"


int main() {
    auto as = assignment();
    as.chars_from_file_to_vect();
    as.count_chars_in_vect();
    as.count_lines_in_vect();
    as.count_alfab_chars();
    as.chars_to_lower_case();
    as.count_all_letters();
    as.print_letter_set();
    as.ten_common_words();
    as.print_word_set();
    as.print_vect();
}
