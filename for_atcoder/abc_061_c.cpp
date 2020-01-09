#include <algorithm>
#include <bitset>
#include <cmath>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;

int main() {
    string number;
    cin >> number;
    int bit = number.size() - 1;
    int num_plus  = pow(2, bit);
    long ans = 0;
    for (int i = 0; i < num_plus; ++i) {
        long element = number.at(0) - '0';
        for (int j = 0; j < bit; ++j) {
            if (i & (1 << j)) {
                ans += element;
                element = 0;
            }
            element = element * 10 + number.at((j+1)) - '0';
        }
        ans += element;
    }

    cout << ans << endl;
}
