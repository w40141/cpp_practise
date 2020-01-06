#include <algorithm>
#include <iostream>
<<<<<<< HEAD
#include <vector>
using namespace std::literals ;

for (i = 0; i < count; ++i) {
    
}
    
}

int input(){
    int num;
    std::cin >> num;
    return num;
}

std::vector<int> while_input(){
    int x;
    std::vector<int> v;
    while ((x = input()) != 0) {
        v.push_back(x);
    }
    return v;
}

std::vector<int> sort(std::vector<int> v){
    std::size_t size = v.size();
    return v;
}

void output(std::vector<int> v){
    for (std::size_t i = 0; i < v.size(); ++i) {
        std::cout << v.at(i) << "\n"s;
    }
}

int main(){
    for (i=0; condition; inc-expression) {
    statements
    }
    std::vector<int> v = while_input();
    output(v);
=======
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
>>>>>>> 9543329c70d24f7dc96ed0467e3b0cdaa7e98e1d
}
