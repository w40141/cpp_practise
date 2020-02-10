#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    std::string s, t;
    std::cin >> s >> t;
    int s_n, t_n;
    std::cin >> s_n >> t_n;
    std::string u;
    std::cin >> u;
    if(s == u) {
        --s_n;
    } else {
        --t_n;
    }
    std::cout << s_n << ' '<< t_n << std::endl;
    return 0;
}
