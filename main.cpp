#include <algorithm>
#include <iostream>
#include <iterator>
#include <string.h>
#include <vector>

struct IntLike {
    int data;
    int value=10;

    IntLike(int data, int value=1)
        : data(data), value(value)
    {}

    IntLike operator +(IntLike const &other){
        return  IntLike{data + other.data};
}
};


int main(){
    IntLike x{1};
    IntLike y{2, 4};
    auto z = x + y;
    std::cout << z.data << "\n"s;
    std::cout << x.value << "\n"s;
    std::cout << y.value << "\n"s;
    std::cout << z.value;
}
