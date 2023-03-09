#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <set>
#include "playfair.h"

namespace crypt{

void playfair::generate_matrix(std::string secret_key){
    secret_key.erase(std::remove_if(secret_key.begin(), secret_key.end(), is_removable_char), secret_key.end());
    std::cout << secret_key << "\n";
    this->secret_key = secret_key;
    std::set<char> alphabets(ALPHABETS.begin(), ALPHABETS.end());

    size_t i = 0;
    for(auto& row: matrix){
        size_t count = 0;
        while(count < 5u){
            auto& val = row[count];
            if (i < secret_key.length()){
                if (alphabets.find(secret_key[i]) != alphabets.end()){
                    val = secret_key[i] == 'J' ? 'I' : secret_key[i];
                    ++count;
                    alphabets.erase(val);
                }
                ++i;
            }
            else{
                val = *(alphabets.begin());
                alphabets.erase(val);
                ++count;
            }
        }
    }
}

void playfair::make_digraphs(std::string plain_text){

}

void playfair::print(){
    std::cout << "MATRIX\n";
    for(auto& row: matrix){
        for(auto& val: row){
            std::cout << val << " ";
        }
        std::cout << "\n";
    }
}

}