#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
using namespace std;


vector<int> get_cards(const int n) {
    vector<int> cards(n);
    for (int i = 0; i < n; ++i) cin >> cards.at(i);
    return cards;
}

int main() {
    int n;
    cin >> n;
    auto cards = get_cards(n);
    int alice = 0;
    int bob = 0;
    sort(cards.begin(), cards.end(), greater<int>());
    for (int i = 0; i < cards.size(); ++i) {
        if (i % 2 == 0) alice += cards.at(i);
        else bob += cards.at(i);
    }
    std::cout << alice - bob << std::endl;
}
