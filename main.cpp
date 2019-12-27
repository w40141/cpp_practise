#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
int main(){
    auto print = [](auto value){std::cout << value << "\n";};
    std::vector<int> v = {1, 2, 3, 4, 5};
    auto gen_zero = [](auto value){return &value;};
    std::generate(std::begin(v), std::end(v), gen_zero);
    std::for_each(std::begin(v), std::end(v), print);
    // std::for_each(std::begin(v), std::end(v), print);
    // std::vector<int> s = std::for_each(std::begin(v), std::end(v), gen_tra);
    // std::for_each(std::begin(v), std::end(v), [](auto value){std::cout<< value << ", "s;});
    // std::for_each(std::begin(v), std::end(v), [](auto &value){value = value + 3;});
}
