#include "middle_str.h"

bool itc_isIp(string str)
{
	if (str == "")
		return 0;
	str += '.';
	int num = 0;
	int check_count = 0;
	string str1 = "";
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] >= '0' && str[i] <= '9')
			str1 += str[i];
		else if (str[i] == '.') {
			for (int k = 0; k < itc_len(str1); k++) {
				num += str1[k] - '0';
				if (k < itc_len(str1) - 1)
					num *= 10;
			}
			if (num >= 0 && num <= 255)
				check_count++;
			str1 = "";
			num = 0;
		}
		else
			return 0;
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
