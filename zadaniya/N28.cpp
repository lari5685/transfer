#include <iostream>
#include <string>
#include <math.h>

void N28(char *str, int n, char *out) {
	int a, p=0;
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] > 47 && str[i] < 58) {  //первая цифра
			a = str[i] - 48;
			i++;
			while (str[i] > 47 && str[i] < 58) { //еще цифры
				a = a * 10 + str[i] - 48;
				i++;
			}
			for (int j = 0; j < a; j++) {//пишем а раз символ
					out[p] = str[i];
					p++;
				}
			i++;
		}
		out[p++] = str[i];
	}
	out[p] ='\0';
}
int main() {
	char str1[] = "He2lo W3orld!";
	char str_1[50];
	N28(str1, 18, str_1);
	std::cout << str_1 << "\n";

	char str2[] = "1A 2b 3C 4d 5E 6f 7G 8h";
	char str_2[50];
	N28(str2, 18, str_2);
	std::cout << str_2 << "\n";

	char str3[] = "a2 b c 4d e f";
	char str_3[50];
	N28(str3, 18, str_3);
	std::cout << str_3 << "\n";
}