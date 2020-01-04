#include <stdio.h>

int main(int argc, char *argv[])
{
    int num;
    scanf("%d", &num);
    int *vect = new int[num];
    int i;
    for (i = 0; i < num; i++) {
        printf("%d\n", i[vect]);
    }
    delete[] vect
    return 0;
}
