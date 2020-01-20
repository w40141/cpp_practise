#include <iostream>
#include <vector>
#include <utility>

const int INF = 1001001001;

int main(int argc, char *argv[]) {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::pair<int, int> > key;
    for (int i = 0; i < m; ++i) {
        int a, b;
        std::cin >> a >> b;
        int s = 0;
        for (int j = 0; j < b; ++j) {
            int c;
            std::cin >> c;
            --c;
            s |= (1<<c);
        }
        key.emplace_back(s, a); 
    }


    std::vector<int> dp((1 << n), INF);
    dp[0] = 0;
    for (int i = 0; i < (1 << n); ++i) {
        for (int j = 0; j < m; ++j) {
            int t = i | key[j].first;
            int cost = dp[i] + key[j].second;
            dp[t] = std::min(cost, dp[t]);
        }
    }

    int ans = dp.back();
    if (ans == INF) ans = -1;
    std::cout << ans << std::endl;

    return 0;
}
