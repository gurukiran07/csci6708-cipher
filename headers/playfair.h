#ifndef PLAYFAIR_CIPHER_CSCI6708_H
#define PLAYFAIR_CIPHER_CSCI6708_H

#include <array>
#include <string>
#include <utility>
#include <vector>

namespace crypt {

namespace playfair{
const std::string ALPHABETS = "ABCDEFGHIKLMNOPQRSTUVWXYZ";
const std::string PUNCTUATION = " !\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~\n";
const char REPEATED_CHAR_Q = 'Q';
const char REPEATED_CHAR_X = 'X';
const char ODD_LENGTH_STR = 'Z';

inline bool is_removable_char(unsigned char chr) {
  return (PUNCTUATION.find(chr) != std::string::npos);
}

using idx_pair_t = std::array<std::pair<int, int>, 2>;
using digraph_t = std::vector<std::pair<char, char>>;
using matrix_t = std::array<std::array<char, 5>, 5>;

idx_pair_t idx_pair(std::pair<char, char>, matrix_t &);
matrix_t generate_matrix(std::string);
digraph_t make_digraphs(std::string);
std::string encrypt(std::string, matrix_t);
std::string decrypt(std::string, matrix_t);
void print(matrix_t, std::string, std::string);
}

} // namespace crypt

#endif