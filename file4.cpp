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

int itc_find_str(string str1, string str2)
{
    int num = 0;
    int count_num = 0;
    int res_num = 0;
    for (int i = 0; i < itc_len(str1); i++) {
        if (str1[i] == str2[num]) {
            if (num == 0)
                res_num = i;
            num++;
            count_num++;
            if (count_num == itc_len(str2))
                return res_num;
        }
        else {
            num = 0;
            count_num = 0;
        }
    }
    return -1;
}
