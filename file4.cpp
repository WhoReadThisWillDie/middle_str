#include "middle_str.h"

long long itc_len(string str)
{
    long long len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

int itc_pow(int num1, int num2)
{
    int num3 = num1;

    if (num2 > 0) {
        for (int i = 1; i < num2; i++) {
            num1 = num1 * num3;
        }
        return num1;
    }
    else if (num2 == 0)
        return 1;
}
