#include <iostream>
#include <unordered_set>
#include "playfair.h"

namespace crypt{

void playfair::generate_matrix(std::string secret_key){
    this->secret_key = secret_key;
    std::unordered_set<char> seen;

    size_t i = 0;
    for(auto& row: matrix){
        size_t count = 0;
        while(count < 5u){
            auto& val = row[count];
            if (i < secret_key.length()){
                if (seen.find(secret_key[i]) == seen.end()){
                    val = secret_key[i];
                    seen.insert(val);
                    ++count;
                }
                ++i;
            }
            else{
                val = '_';
                ++count;
            }
        }
    }
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