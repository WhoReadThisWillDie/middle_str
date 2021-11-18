#include "middle_str.h"

string itc_maxCharWord(string str)
{
	int i = 0;
	int word_count = 0;
	string word;
	string res;
	string str1 = "";
	bool is_word = true;
	str += ' ';
	while (str[i] != '\0') {
		if (str[i] == ' ')
			word_count++;
		i++;
	}
	i = 0;
	if (word_count < 2)
		return "error";
	while (str[i] != '\0') {
		if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122) && is_word == true) {
			str1 += str[i];
		}
        else if (str[i] == ' ') {
			if (is_word == true) {
				word = str1;
				str1 = "";
			}
			else
				is_word = true;
		}
		else {
			str1 = "";
			is_word = false;
		}
		if (itc_len(word) > itc_len(res))
			res = word;
		i++;
	}
	if (res == "")
		return "error";
	return res;
}

char itc_sameChar(string str)
{
	int count1 = 0;
	int count2 = 0;
	char ch1 = 'a';
	char ch2 = 'z';
	while (str[count1] != '\0') {
		ch1 = str[count1];
		while (str[count2] != '\0') {
			ch2 = str[count2];
			if (ch1 == ch2 && count1 != count2)
				return ch1;
			count2++;
		}
		count1++;
	}
	return ' ';
}

bool itc_isFirstInSecond(string s1, string s2)
{
	if (s1 == "" || s2 == "")
		return 0;
	if (itc_find_str(s2, s1) == -1)
		return 0;
	return 1;
}

string itc_Cezar(string str, int k)
{
	if (str == "")
		return "";
	int i = 0;
	int symb_code = 0;
	string res_str = "";
	string ch = "";
	string lower = "abcdefghijklmnopqrstuvwxyz";
	string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for (int i = 0; i < itc_len(str); i++) {
		if (str[i] >= 65 && str[i] <= 90) {
			ch = str[i];
			res_str += upper[(itc_find_str(upper, ch) + (k % 26) - 25) % 26 + 25];
		}
		else if (str[i] >= 97 && str[i] <= 122) {
			ch = str[i];
			res_str += lower[(itc_find_str(lower, ch) + (k % 26) - 25) % 26 + 25];
		}
		else
			res_str += str[i];
	}
	return res_str;
}

string itc_rmFreeSpace(string str)
{
	if (str == "")
		return "";
	int i = 0;
	string res_str = "";
	string res_str2 = "";
	while(str[i] != '\0') {
		if (str[i] == ' ' and i <= 1)
			res_str = res_str;
		else if (str[i] == ' ' and str[i - 1] != ' ')
			res_str += str[i];
		else if (str[i] != ' ')
			res_str += str[i];
		i++;
	}
	for (int k = 0; k < itc_len(res_str) - 1; k++) {
		res_str2 += res_str[k];
	}
	return res_str2;
}
