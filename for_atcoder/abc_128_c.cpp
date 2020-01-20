#include <iostream>
#include <vector>


int N;
int M;
std::vector<std::vector<int> > light;
std::vector<int> p;


bool check(int bit) {
    for (int i = 0; i < M; ++i) {
        int num = 0;
        for (auto l: light[i]) if ((bit & (1 << (l-1)))) ++num;

        if (num % 2 != p[i]) return false;
    }
    return true;
}


int count_num(int bit) {
    int num = 0;
    for (int i = 0; i < N; ++i) if (bit & (1 << i)) ++num;
    return num;
}


int main(){
    std::cin >> N >> M;
    light.resize(M);
    p.resize(M);
    for(int i = 0; i < M; ++i){
        int kosu;
        std::cin >> kosu;
        light[i].resize(kosu);
        for (int j = 0; j < kosu; ++j) std::cin >> light[i][j];
    }
    for (int i = 0; i < M; ++i) std::cin >> p[i];

    int hikaru = 0;
    for (int bit = 0; bit < (1 << N); ++bit) {
        if (check(bit)) ++hikaru;
    }

    std::cout << hikaru << std::endl;
}
