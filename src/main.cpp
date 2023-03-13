#include <iostream>

#include "playfair.h"
#include "transposition.h"

int main() {
  auto matrix = crypt::playfair::generate_matrix("MICROSOFT");
  std::string cipher_text =
      crypt::playfair::encrypt("NEXT VERSION BEING RELEASED", matrix);
  std::string plain_text = crypt::playfair::decrypt(cipher_text, matrix);
  crypt::playfair::print(matrix, "MICROSOFT", "NEXT VERSION BEING RELEASED");

  std::string s = "abc def ghi jkl";
  crypt::matrix_transposition::remove_special_chars(s);
  std::cout << s << "\n";

}