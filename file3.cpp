#include "middle_str.h"

bool itc_isIp(string str)
{
	if (str == "")
		return 0;
	str += '.';
	int num = 0;
	int check_count = 0;
	string str1 = "";
	for (int i = 0; i < itc_len(str); i++) {
		if (str[i] >= '0' && str[i] <= '9')
			str1 += str[i];
		if (str[i] == '.') {
			for (int k = itc_len(str1) - 1; k >= 0; k--) {
				num += itc_pow(10, 2 - k) * (str1[k] - 48);
			}
			if (num >= 0 && num <= 255)
				check_count++;
			str1 = "";
			num = 0;
		}
	}
	if (check_count == 4)
		return 1;
	return 0;
}

string itc_DecToBin(string str)
 {
     return "smth";
 }

string itc_decToBase(int num, int base)
{
    return "smth";
}
