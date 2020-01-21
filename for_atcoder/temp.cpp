#include <iostream>


int get_leng(unsigned int s) {
    int num = 0;
    while (s != 0) {
        ++num;
        s = s >> 1;
    }
    if (num % 4 != 0) num = num +  4 - (num % 4);
    return num;
}


int main(int argc, char *argv[])
{
    unsigned int s;
    std::cin >> s;
    int size = get_leng(s);
    int point;
    int counter = 0;
    while (size > 0) {
        point = 1 << (size - 1);
        if (s & point) {
            int num = 1;
            while (counter) {
                num = num << 1;
                --counter;
                --size;
                point = 1 << (size - 1);
                if (point & s) num += 1;
            }
            --num;
            std::cout << num << std::endl;
        } else {
            ++counter;
        }
        std::cout << "size: " << size << std::endl;
        std::cout << "counter: " << counter << std::endl;
        --size;
    }
    return 0;
}
