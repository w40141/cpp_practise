#include <iostream>
#include <vector>

typedef long long ll;


int next_combination(int sub) {
    int x = sub & -sub, y = sub + x;
    return (((sub & ~y) / x) >> 1) | y;
}


int main(int argc, char *argv[])
{
    int girls, boys, sub_girls, sub_boys, choco;
    std::cin >> girls >> boys >> sub_girls >> sub_boys >> choco;
    std::vector<std::vector<int> > choco_to_you(girls, std::vector<int>(boys)); 
    for (int i = 0; i < choco; ++i) {
        int x, y, z;
        std::cin >> x >> y >> z;
        --x;
        --y;
        choco_to_you[x][y] = z;
    }

    int ans = 0;
    ll bit_girl = (1 << sub_girls) - 1;
    for (; bit_girl < (1 << girls); bit_girl = next_combination(bit_girl)) {

        ll bit_boy = (1 << sub_boys) - 1;
        for (; bit_boy < (1 << boys); bit_boy = next_combination(bit_boy)) {

            // std::cout << bit_girl << " " << bit_boy << std::endl;
            int tmp_ans = 0;
            int girl;
            if (bit_girl & 1) girl = 0;
            else girl = (bit_girl & ~bit_girl) / 2;
            for (; girl < girls; ++girl) {
                int boy;
                if (bit_boy & 1) boy = 0;
                else boy = (bit_boy & ~bit_boy) / 2;
                for (; boy < boys; ++boy) {
                    if ((bit_girl & (1 << girl)) && (bit_boy & (1 << boy))) {
                        // std::cout << girl << " " << boy << std::endl;
                        tmp_ans += choco_to_you[girl][boy];
                    }
                }
            }
            ans = std::max(ans, tmp_ans);
        }
    }
    std::cout << ans << std::endl;
    return 0;
}
