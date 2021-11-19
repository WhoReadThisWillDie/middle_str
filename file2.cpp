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
	if (s1 == "" && s2 == "")
		return true;
	else if (s1 == "")
		return true;
	else if (s2 == "")
		return false;
	if (itc_find_str(s2, s1) == -1)
		return false;
	return true;
}

string itc_Cezar(string str, int k)
{
	if (str == "")
		return "";
	k = (k + 26) % 26;
	string res_str = "";
	for (int i = 0; i < itc_len(str); i++) {
		if (str[i] >= 65 && str[i] <= 90) {
			res_str += (str[i] - 65 + k) % 26 + 65;
		}
		else if (str[i] >= 97 && str[i] <= 122) {
			res_str += (str[i] - 97 + k) % 26 + 97;
		}
		else
			res_str += str[i];
	}
	return res_str;
}

string itc_Cezar1(string str, int k)
{
	if (str == "")
		return "";
	k = (k + 26) % 26;
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
		str[i] = str[i] - 'a' + k;
		str[i] = str[i] % 26 + 'a';
	}
	else if (str[i] >= 'A' && str[i] <= 'Z')
	{
		str[i] = str[i] - 'A' + k;
		str[i] = str[i] % 26 + 'A';
		}
	}
	return str;
}

string itc_rmFreeSpace(string str)
{
	if (str == "")
		return "";
	string res_str = "";
	string res_str2 = "";
	int begin = 0;
	res_str += str[0];
	for (int i = 1; str[i] != '\0'; i++) {
		if (!(str[i] == ' ' and str[i - 1] == ' '))
			res_str += str[i];
		else if (str[i] != ' ')
			res_str += str[i];
	}
	int len = itc_len(res_str);
	if (res_str[len - 1] == ' ')
		len--;
	if (res_str[0] == ' ')
		begin++;
		for (int k = begin; k < len; k++) {
			res_str2 += res_str[k];
		}
	return res_str2;
}
