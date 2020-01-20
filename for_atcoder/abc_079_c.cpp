#include <iostream>
#include <vector>
#include <string>


std::string num;
int N = 4;
std::vector<int> v(N);

bool check (int bit) {
    int num = v[0];
    for (int i = 1; i < N; ++i) {
        if (bit & (1 << (i - 1))) num += v[i];
        else num -= v[i];
    }
    if (num == 7) return true;
    else return false;
}

int main(){
    std::cin >> num;
    for (int i = 0; i < N; ++i) v[i] = num[i] - '0';
    for (int bit = 0; bit < (1 << (N - 1)); ++bit) {
        if (check(bit)) {
            std::cout << v[0];
            for (int i = 1; i < N; ++i) {
                if (bit & (1 << (i - 1))) std::cout << '+';
                else std::cout << '-';
                std::cout << v[i];
            }
            std::cout << "=7";
            break;
        }
    }
}
