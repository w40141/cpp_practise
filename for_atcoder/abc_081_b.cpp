#include <iostream>
#include <vector>


int main(){
    int N;
    std::cin >> N;
    int number = 0;
    int tmp;
    for(int i = 0; i < N; ++i){
        std::cin >> tmp;
        number |= tmp;
    }
    int lsb = 0;
    while(!(number & 1)){
        ++lsb;
        number >>= 1;
    }
    std::cout << lsb << std::endl;
}
