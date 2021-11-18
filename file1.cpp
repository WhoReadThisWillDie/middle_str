#include "middle_str.h"

bool itc_isDigit(unsigned char c)
{
    if (c >= 48 && c <= 57)
        return true;
    return false;
}

unsigned char itc_toUpper(unsigned char c)
{
    if (c >= 97 && c <= 122)
        c -= 32;
    return c;
}

unsigned char itc_changeCase(unsigned char c)
{
    if (c >= 97 && c <= 122)
        return itc_toUpper(c);
    else if (c >= 65 && c <= 90)
        c += 32;
        return c;
    return c;
}

bool itc_compare(string s1, string s2)
{
    if (s1 == "" || s2 == "")
        return false;
    int num = 0;
    while (s1[num] != '\0' || s2[num] != '\0') {
        if (s1[num] != s2[num])
            return false;
        num++;
    }
    return true;
}

int itc_countWords(string str)
{
    if (str == "")
        return 0;
    int word_count = 0;
    int symb_count = 0;
    bool is_word = true;
    str += ' ';
    while (str[symb_count] != '\0') {
        if (is_word == true && ((str[symb_count] >= 65 && str[symb_count] <= 90) || (str[symb_count] >= 97 && str[symb_count] <= 122)))
            is_word = true;
        else if (str[symb_count] == ' ' && is_word == true)
            word_count++;
        else if (str[symb_count] == ' ' && is_word == false)
            is_word = true;
        else
            is_word = false;
        symb_count++;
    }
    return word_count;
}
