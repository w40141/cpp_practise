#include <iostream>
#include <vector>

int N;
long K;
std::vector<long> v;

int main() {
    std::cin >> N >> K;
    v.resize(N);
    for (int i = 0; i < N; ++i) std::cin >> v[i];
    int weight = 0;
    for (int bit = 0; bit < (1 << N); ++bit) {
        int tmp_weight = 0;
        for (int i = 0; i < N; ++i) if (bit & (1 << i)) tmp_weight += v[i];

        if (tmp_weight <= K) weight = std::max(weight, tmp_weight);
    }
    std::cout << weight << std::endl;

    return 0;
}
