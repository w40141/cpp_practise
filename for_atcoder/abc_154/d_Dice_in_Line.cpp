#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <ostream>
#include <string>
#include <vector>
#include <numeric>

int main(int argc, char *argv[])
{
    int N, K;
    std::cin >> N >> K;
    std::vector<int> num_li(K-1, 0);
    std::vector<int> sum_li;
    for(int i = 0; i < N; ++i){
        int tmp;
        std::cin >> tmp;
        num_li.push_back(tmp+1);
        auto start = std::next(num_li.begin(), i);
        auto end = std::next(start, K);
        int sum = std::accumulate(start, end, 0);
        sum_li.push_back(sum);
    }
    std::sort(sum_li.begin(), sum_li.end());
    double ans = sum_li.back() / 2.0;
    std::cout << ans << std::endl;
    return 0;
}
