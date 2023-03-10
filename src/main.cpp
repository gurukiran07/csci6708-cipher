#include <iostream>

#include "playfair.h"

int main() {
  auto matrix = crypt::generate_matrix("MICROSOFT");
  std::string cipher_text =
      crypt::encrypt("NEXT VERSION BEING RELEASED", matrix);
  std::string plain_text = crypt::decrypt(cipher_text, matrix);
  crypt::print(matrix, "MICROSOFT", "NEXT VERSION BEING RELEASED");
}