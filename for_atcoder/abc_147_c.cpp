#include <iostream>
#include <vector>


using pint = std::pair<int, int>;
int N;
std::vector<std::vector<pint> > v;

bool check(int bit){
    for (int i = 0; i < N; ++i) {
        if (!(bit & (1 << i))) continue;

        for (pint xy: v[i]) {
            int x = xy.first;
            int y = xy.second;

            if (y == 1 && !(bit & (1 << x))) return false;
            if (y == 0 && (bit & (1 <<x))) return false;
        }
    }

    return true;
}

int main(){
    std::cin >> N;
    v.resize(N);
    for(int i = 0; i < N; ++i){
        int shougen;
        std::cin >> shougen;
        v[i].resize(shougen);
        for(int j = 0; j < shougen; ++j) {
            std::cin >> v[i][j].first >> v[i][j].second;
            --v[i][j].first;
        }
    }

    int honest = 0;
    for (int bit = 0; bit < (1 << N); ++bit) {
        if (check(bit)) {
            int tmp_honest = 0;
            for (int i = 0; i < N; ++i) if (bit & (1 << i)) ++tmp_honest;
            honest = std::max(honest, tmp_honest);
        }
    }

    std::cout << honest << std::endl;
}
