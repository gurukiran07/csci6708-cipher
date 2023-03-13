#include "playfair.h"

#include <algorithm>
#include <iostream>
#include <set>

namespace crypt {

namespace playfair{

matrix_t generate_matrix(std::string secret_key) {
  secret_key.erase(
      std::remove_if(secret_key.begin(), secret_key.end(), is_removable_char),
      secret_key.end());
  std::set<char> alphabets(ALPHABETS.begin(), ALPHABETS.end());
  matrix_t matrix{};
  size_t i = 0;
  for (auto &row : matrix) {
    size_t count = 0;
    while (count < 5u) {
      auto &val = row[count];
      if (i < secret_key.length()) {
        if (alphabets.find(secret_key[i]) != alphabets.end()) {
          val = secret_key[i] == 'J' ? 'I' : secret_key[i];
          ++count;
          alphabets.erase(val);
        }
        ++i;
      } else {
        val = *(alphabets.begin());
        alphabets.erase(val);
        ++count;
      }
    }
  }
  return matrix;
}

digraph_t make_digraphs(std::string plain_text) {
  plain_text.erase(
      std::remove_if(plain_text.begin(), plain_text.end(), is_removable_char),
      plain_text.end());
  size_t idx = 0;
  digraph_t digraphs{};

  while (idx < (plain_text.length() - 1)) {
    char first = plain_text.at(idx);
    char second = plain_text.at(idx + 1);

    if (first != second) {
      digraphs.push_back({first, second});
      idx += 2;
    } else {
      digraphs.push_back({first, first == REPEATED_CHAR_Q ? REPEATED_CHAR_X
                                                          : REPEATED_CHAR_Q});
      ++idx;
    }
  }

  if (idx < plain_text.length()) {
    digraphs.push_back({plain_text[idx], ODD_LENGTH_STR});
  }
  return digraphs;
}

std::string encrypt(std::string plain_text, matrix_t matrix) {
  std::string cipher;
  digraph_t digraphs = make_digraphs(plain_text);
  for (auto &digraph : digraphs) {
    auto idx = idx_pair(digraph, matrix);
    // std::cout << digraph.first << " index: " << idx[0].first << " " <<
    // idx[0].second << "\n"; std::cout << digraph.second << " index: " <<
    // idx[1].first << " " << idx[1].second << "\n";

    if (idx[0].first == idx[1].first) {
      cipher += matrix[idx[0].first][(idx[0].second + 1) % 5];
      cipher += matrix[idx[1].first][(idx[1].second + 1) % 5];
    } else if (idx[0].second == idx[1].second) {
      cipher += matrix[(idx[0].first + 1) % 5][idx[0].second];
      cipher += matrix[(idx[1].first + 1) % 5][idx[1].second];
    } else {
      cipher += matrix[idx[0].first][idx[1].second];
      cipher += matrix[idx[1].first][idx[0].second];
    }
  }
  return cipher;
}

std::string decrypt(std::string cipher_text, matrix_t matrix) {
  cipher_text.erase(
      std::remove_if(cipher_text.begin(), cipher_text.end(), is_removable_char),
      cipher_text.end());
  std::string cipher = "";
  size_t i = 0;

  while (i < cipher_text.length()) {
    auto idx = idx_pair({cipher_text[i], cipher_text[i + 1]}, matrix);
    // std::cout << cipher_text[i] << " index: " << idx[0].first << " " <<
    // idx[0].second << "\n"; std::cout << cipher_text[i + 1] << " index: " <<
    // idx[1].first << " " << idx[1].second << "\n";

    if (idx[0].first == idx[1].first) {
      auto cdx = (idx[0].second - 1) < 0 ? (5 + (idx[0].second - 1))
                                         : (idx[0].second - 1);
      auto cdx1 = (idx[1].second - 1) < 0 ? (5 + (idx[1].second - 1))
                                          : (idx[1].second - 1);
      cipher += matrix[idx[0].first][cdx];
      cipher += matrix[idx[1].first][cdx1];
    } else if (idx[0].second == idx[1].second) {
      auto cdx =
          (idx[0].first - 1) < 0 ? 5 + (idx[0].first - 1) : (idx[0].first - 1);
      auto cdx1 =
          (idx[1].first - 1) < 0 ? 5 + (idx[1].first - 1) : (idx[1].first - 1);
      cipher += matrix[cdx][idx[0].second];
      cipher += matrix[cdx1][idx[1].second];
    } else {
      cipher += matrix[idx[0].first][idx[1].second];
      cipher += matrix[idx[1].first][idx[0].second];
    }
    i += 2;
  }

  return cipher;
}

idx_pair_t idx_pair(std::pair<char, char> digraph, matrix_t &matrix) {
  idx_pair_t idx{};
  digraph.first = digraph.first == 'J' ? 'I' : digraph.first;
  digraph.second = digraph.second == 'J' ? 'I' : digraph.second;

  for (size_t i = 0; i < 5u; ++i) {
    for (size_t j = 0; j < 5u; ++j) {
      if (digraph.first == matrix[i][j]) {
        idx[0] = {i, j};
      } else if (digraph.second == matrix[i][j]) {
        idx[1] = {i, j};
      }
    }
  }
  return idx;
}

void print(matrix_t matrix, std::string secret_key, std::string plain_text) {
  auto cipher_text = encrypt(plain_text, matrix);
  std::cout << "MATRIX:\n";
  for (auto &row : matrix) {
    for (auto &val : row) {
      std::cout << val << " ";
    }
    std::cout << "\n";
  }
  std::cout << "\n";

  std::cout << "PLAIN TEXT: " << plain_text << "\n";
  std::cout << "SECRET KEY: " << secret_key << "\n\n";

  std::cout << "DIGRAPHS:\n";
  for (auto &p : make_digraphs(plain_text)) {
    std::cout << p.first << p.second << " ";
  }
  std::cout << "\n";
  for (auto &p : make_digraphs(cipher_text)) {
    std::cout << p.first << p.second << " ";
  }
  std::cout << "\n\n";
  std::cout << "ENCRYPTED TEXT: " << cipher_text << "\n";
  std::cout << "DECRYPTED TEXT: " << decrypt(cipher_text, matrix) << "\n";
}

}

} // namespace crypt