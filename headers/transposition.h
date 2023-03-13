#ifndef MATRIX_TRANSPOSITION_CSCI_6708_H
#define MATRIX_TRANSPOSITION_CSCI_6708_H

#include <string>
#include <vector>
#include <algorithm>

namespace crypt{

namespace matrix_transposition{
    
const char SPACE_CHAR = '%';

inline void remove_special_chars(std::string& text){
    std::replace(text.begin(), text.end(), ' ', '%');
}

std::string encrypt(std::string, std::vector<int>);
std::string decrypt(std::string, std::vector<int>);

}


}

#endif