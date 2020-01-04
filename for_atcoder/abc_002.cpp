#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    std::map<int, vector<int> > member;
    for (int i = 0; i < M; ++i) {
        int x, y;
        std::cin >> x >> y;
        auto iter = member.find(x);
        if (iter != member.end()) {
            member[x].push_back(y);
        } else {
            bool flag = false;
            for (auto j = member.begin(); j != member.end(); ++j) {
                auto key = j -> first;
                auto value = j -> second;
                for (auto k = value.begin(); k != value.end(); ++k) {
                    if (*k == x || *k == y) {
                        member[key].push_back(y);
                        member[key].push_back(x);
                        flag = true;
                        break;
                    }
                }
                if (flag) break;
            }
            if (! flag) member[x].push_back(y);
        }
    }

    int count_max = 1;
    for (auto j = member.begin(); j != member.end(); ++j) {
        auto vec = j -> second;
        std::sort(vec.begin(), vec.end());
        vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
        if (count_max < vec.size() + 1) count_max = vec.size() + 1;
    }
    std::cout << count_max << std::endl;
}
