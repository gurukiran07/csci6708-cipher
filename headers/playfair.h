#include <string>
#include <array>
#include <vector>
#include <utility>

namespace crypt{

const std::string ALPHABETS = "ABCDEFGHIKLMNOPQRSTUVWXYZ";
const std::string PUNCTUATION = " !\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";

inline bool is_removable_char(unsigned char chr){
    return (PUNCTUATION.find(chr) != std::string::npos);
}
class playfair{
    std::string cipher_text;
    std::string secret_key;
    std::vector<std::pair<char, char>> digraphs;
    std::array<std::array<char, 5>, 5> matrix;

    public:
    playfair(){}

    void generate_matrix(std::string secret_key);
    void make_digraphs(std::string plain_text);
    void print();
};

}