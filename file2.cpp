#include "middle_str.h"

string itc_maxCharWord(string str)
{
	int i = 0, k = 0;
	int word_count = 0;
	string res;
	string str1 = "";
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
		if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122))
			str1 += str[i];
		else
			str1 = "";
		if (itc_len(str1) > itc_len(res))
			res = str1;
		i++;
	}
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
	return 'a';
}

bool itc_isFirstInSecond(string s1, string s2)
{
	int num = 0;
	int count_num = 0;
	int res_num = 0;
	for (int i = 0; i < itc_len(s2); i++) {
		if (s1[num] == s2[i]) {
			if (num == 0)
				res_num = i;
			num++;
			count_num++;
			if (count_num == itc_len(s1))
				return 1;
		}
		else {
			num = 0;
			count_num = 0;
		}
	}
	return 0;
}

string itc_Cezar(string str, int k)
{
	int i = 0;
	int symb_code = 0;
	string res_str = "";
	while (str[i] != '\0') {
		if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122)) {
			symb_code = 97;
			if (str[i] >= 65 && str[i] <= 90)
				symb_code = 65;
			if (str[i] - symb_code + k >= 0)
				res_str += symb_code + (str[i] - symb_code + k) % 25;
			else
				res_str += symb_code + 25 - (25 + str[i] - symb_code) % 25;
		}
		else
			res_str += str[i];
		i++;
	}
	return res_str;
}

string itc_rmFreeSpace(string str)
{
	int i = 0;
	string res_str = "";
	while(str[i] != '\0') {
		if (str[i] == ' ' and str[i - 1] != ' ')
			res_str += str[i];
		else if (str[i] != ' ')
			res_str += str[i];
		i++;
	}
	return res_str;
}
