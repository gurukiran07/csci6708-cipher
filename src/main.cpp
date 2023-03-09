#include <iostream>
#include "playfair.h"

int main(){
    crypt::playfair a;
    a.generate_matrix("RAYQUAZA");
    a.print();
}