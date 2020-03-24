//
// Created by dylan on 12-3-2020.
//

#ifndef STL_OPDRACHT_ASSIGMENTS_HPP
#define STL_OPDRACHT_ASSIGMENTS_HPP

#include <sstream>
#include "fstream"
#include "vector"
#include "iostream"
#include "algorithm"
#include "cctype"
#include "map"
#include "set"
#include "functional"
class assignment{
private:
    std::vector<char> the_bible = {};
    std::map<char,int> letter_map;
    std::map<std::string, int> word_counts;
    ///check if char is a letter
    static bool isLetter( char c){
        return (c > 'A' && c < 'Z') || (c > 'a' && c < 'z');
    }
    /// convert chars to spaces and turn it ito lower case
    static char convert_to_space_and_lower(char c){
        if( c == '.' || c =='\t' || c == ',' || c == ';' || c == ':' || c == '}' || c == '{'){
            return ' ';
        }
        return(tolower(c));
    }
public:
    assignment(){};
    /// read the chars in from a file
    void chars_from_file_to_vect(){
        std::ifstream stream("bible.txt");
        char c;
        while(stream.get(c)){
            the_bible.push_back(c);
        } stream.close();
    }
    /// Print the size of the vector bible
    void count_chars_in_vect(){
        std::cout << "amount of characters: " << the_bible.size() << "\n";
    }
    /// Print the lines in the vector bible
    void count_lines_in_vect(){
        int lines = std::count(the_bible.begin(), the_bible.end(), '\n');
        std::cout << "amount of lines: " << lines << "\n";
    }
    /// Print the amount of characters that are in the alfabet
    void count_alfab_chars(){
        int alpha_chars = std::count_if(the_bible.begin(), the_bible.end(), isLetter);
        std::cout << "amount of letters: " << alpha_chars << "\n";
    }

    /// turn chars to lower case
    void chars_to_lower_case(){
        std::transform(the_bible.begin(), the_bible.end(), the_bible.begin(),[](char c){return std::tolower(c);});
    }

    /// count all letters that are found in a string
    void count_all_letters(){
        std::string letters = "abcdefghijklmnopqrstuvwxyz";
        for(char c : letters){
            int occurence = std::count(the_bible.begin(), the_bible.end(), c);
            letter_map[c] = occurence;
        }
    }
    ///print the vector for debug purpouses
    void print_vect(){
        for(auto i : the_bible){
            std::cout << i;
        }
    }

    /// Print the letter set and turn it into a set and print it
    void print_letter_set(){
        typedef std::function<bool(std::pair<char,int>, std::pair<char,int>)> sorter;
        sorter sort = [](std::pair<char,int> first_elem, std::pair<char, int> second_elem){
            return first_elem.second > second_elem.second;
        };
        std::set<std::pair<char,int>, sorter> letterSet(letter_map.begin(), letter_map.end(), sort);
        auto print = [] (const std::pair<char,int> & pair){ std::cout << pair.first <<':' <<" " << pair.second << "\n"; };
        std::for_each(letterSet.begin(), letterSet.end(), print);
    }
    /// print the set of words that are found in bible and turn it into a set to be printed
    void print_word_set(){
        typedef std::function<bool(std::pair<std::string,int>, std::pair<std::string,int>)> sorter;
        sorter sort = [](std::pair<std::string, int> first_elem, std::pair<std::string, int> second_elem){
            return first_elem.second > second_elem.second;
        };
        std::set<std::pair<std::string, int>, sorter> wordSet(word_counts.begin(), word_counts.end(), sort);
        auto print = [] (const std::pair<std::string,int> & pair){ std::cout << pair.first <<':' <<" " << pair.second << "\n"; };
        std::for_each(wordSet.begin(), wordSet.end(), print);

    }
    /// count the amount of words in bible.txt
    void ten_common_words(){
        std::fstream in("bible.txt");
        while(!in.eof()){
            std::string temp_str;
            in >> temp_str;
            if(!temp_str.empty()){
                std::transform(temp_str.begin(), temp_str.end(), temp_str.begin(), convert_to_space_and_lower);
                std::stringstream ss(temp_str);

                std::string word;
                ss >> word;
                if(!word.empty()){
                    auto occurrence = word_counts.find(word);
                    if(occurrence == word_counts.end()){
                        word_counts[word] = 1;
                    } else{
                        occurrence->second++;
                    }
                }


            }
        }
    }

};
#endif //STL_OPDRACHT_ASSIGMENTS_HPP