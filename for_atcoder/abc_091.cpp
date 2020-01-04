#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;


vector<string> get_cards(const int n) {
    vector<string> cards(n);
    for (int i = 0; i < n; ++i) cin >> cards.at(i);
    return cards;
}

map<string, int> check_cards(const vector<string> cards) {
    map<string, int> word_value;
    for (string first: cards) {
        auto iter = word_value.find(first);
        if (iter == word_value.end()) word_value[first] = 0;
        else continue;
        for (string s: cards) if (s == first) ++word_value[first];
    }
    return word_value;
}

int main() {
    int n;
    cin >> n;
    auto blue = get_cards(n);
    auto kuroji = check_cards(blue);

    int m;
    cin >> m;
    auto red = get_cards(m);
    auto akaji = check_cards(red);

    map<string, int> goukei;
    for (auto i = kuroji.begin(); i != kuroji.end(); ++i) {
        auto key = i->first;
        auto card = akaji.find(key);
        if (card == akaji.end()) goukei[key] = i->second;
        else goukei[key] = kuroji[key] - akaji[key];
    }

    int num = 0;
    for (auto i = goukei.begin(); i != goukei.end(); ++i) {
        int value = i->second;
        if (num < value) num = value;
    }

    std::cout << num << std::endl;
}
