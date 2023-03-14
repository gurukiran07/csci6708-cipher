#ifndef MATRIX_TRANSPOSITION_CSCI_6708_H
#define MATRIX_TRANSPOSITION_CSCI_6708_H

#include <string>
#include <vector>
#include <algorithm>

namespace crypt{

namespace matrix_transposition{
    
const char SPACE_CHAR = '%';

inline void replace_space_chars(std::string& text){
    std::replace(text.begin(), text.end(), ' ', '%');
    std::replace(text.begin(), text.end(), '\n', '%');
    std::replace(text.begin(), text.end(), '\t', '%');
}

std::string encrypt(std::string, std::vector<int>);
std::string decrypt(std::string, std::vector<int>);
std::vector<std::vector<char>> generate_matrix(std::string, std::vector<int>);
std::vector<std::vector<char>> decrypt_matrix(std::string text, std::vector<int> key);
std::string get_col(std::vector<std::vector<char>>& matrix, int idx);
int idx_key(std::vector<int>&, int);
}
}

#endif