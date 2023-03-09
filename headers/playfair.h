#include <string>
#include <array>

namespace crypt{
    const std::string ALPHABETS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

class playfair{
    std::string cipher_text;
    std::string secret_key;
    std::array<std::array<char, 5>, 5> matrix;

    public:
    playfair(){}

    void generate_matrix(std::string secret_key);
    void print();
};

}