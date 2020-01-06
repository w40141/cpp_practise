#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;

template <typename T>
void output(vector<T> vec) {
}

vector<pair<string, int> > get_shops(const int n) {
    vector<pair<string, int> > shops;
    for (int i = 0; i < n; ++i) {
        string name;
        int point;
        cin >> name >> point;
        shops.push_back(make_pair(name, point));
    }
    return shops;
}

int main() {
    int n;
    cin >> n;
    auto shops = get_shops(n);
    // std::cout << alice - bob << std::endl;
}
