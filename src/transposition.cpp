#include "transposition.h"

#include <string>
#include <vector>
#include <iostream>

namespace crypt{

namespace matrix_transposition{

std::string encrypt(std::string text, std::vector<int> key){
    std::cout << "PLAIN TEXT: " << text << "\n\n";
    std::cout << "SECRET KEY: {";
    for (auto i: key){
        std::cout << i << ", ";
    }
    std::cout << "\b\b}\n\n";
    auto matrix = generate_matrix(text, key);
    std::string cipher_text;
    for (auto idx: key){
        cipher_text += get_col(matrix, idx);
    }
    std::cout << "ENCRYPTED TEXT: " << cipher_text << "\n";
    return cipher_text;
}

int idx_key(std::vector<int>& key, int val){
    for (size_t i = 0; i < key.size(); ++i){
        if (key[i] == val){
            return i;
        }
    }
    return -1;
}

std::string decrypt(std::string text, std::vector<int> key){
    auto matrix = decrypt_matrix(text, key);
    decltype(matrix) plain_text_matrix;
    auto tkey = key;
    std::sort(tkey.begin(), tkey.end());
    std::string plain_text;
    for (auto idx: tkey){
        auto i = idx_key(key, idx);
        plain_text_matrix.push_back(matrix[i]);
    }

    auto rows = plain_text_matrix[0].size();
    for (size_t i = 1; i <= rows; ++i ){
        plain_text += get_col(plain_text_matrix, i);
    }
    std::cout << "\n";
    std::cout << "DECRYPTED TEXT: " << plain_text << "\n";
    return plain_text;
}

std::vector<std::vector<char>> decrypt_matrix(std::string text, std::vector<int> key){
    replace_space_chars(text);
    std::vector<std::vector<char>> matrix;
    const int rows = key.size();
    const int cols = text.length() / rows;

    for (int i = 0; i < rows; ++i){
        int idx = (i * cols);
        std::vector<char> row(text.begin() + idx, text.begin() + idx + cols);
        matrix.push_back(row); 
    }
    return matrix;
}

std::vector<std::vector<char>> generate_matrix(std::string text, std::vector<int> key){
    replace_space_chars(text);
    std::vector<std::vector<char>> matrix;
    const int rows = key.size();
    const int rem = (rows - (text.length() % rows)) * ((text.length() % rows) > 0);
    const int cols = (text.length() + rem) / rows;
    text.append(rem, '%');

    for (int i = 0; i < cols; ++i){
        int idx = (i * rows);
        std::vector<char> row(text.begin() + idx, text.begin() + idx + rows);
        matrix.push_back(row);
    }
    return matrix;
}

std::string get_col(std::vector<std::vector<char>>& matrix, int idx){
    std::string col_str;
    for (auto& row: matrix){
        col_str += row[idx - 1];
    }
    return col_str;
}

}

}

