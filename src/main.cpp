#include <iostream>

#include "playfair.h"
#include "transposition.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

std::string read_file(std::string filename){
  std::ifstream file(filename);
  std::string str((std::istreambuf_iterator<char>(file)),
                 std::istreambuf_iterator<char>());
  return str;
}

int main() {

  auto plain_text = read_file("plain-text.txt");
  std::cout << "=====================PLAYFAIR CIPHER=====================\n\n";

  std::string key = "RAYQUAZA";
  auto matrix = crypt::playfair::generate_matrix(key);
  std::string cipher_text =
      crypt::playfair::encrypt(plain_text, matrix);
  std::string pl_text = crypt::playfair::decrypt(cipher_text, matrix);
  crypt::playfair::print(matrix, key, plain_text);

  std::cout << "\n============================================================\n\n";

  std::cout << "\n=====================MATRIX TRANSPOSITION CIPHER============\n\n";
  
  auto t = crypt::matrix_transposition::encrypt(plain_text, {3, 4, 1, 2});
  crypt::matrix_transposition::decrypt(t, {3, 4, 1, 2});
  
  std::cout << "\n============================================================\n\n";
}