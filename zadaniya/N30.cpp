#include <iostream>
#include <string>
#include <math.h>

void N29(char *str, char *out) {
	int n[128];
	for(int i = 0; i < 128; i++)
		n[i] = 0;
	for(int i = 0; str[i] != '\0'; i++){
		n[str[i]]++;
	}
	int max = 1;
	char maxs = 0;
	for(int i = 0; i < 128; i++)
		if(n[i] > max){
			max = n[i];
			maxs = i;
		}
	int i;
	for(i = 0; str[i] != '\0'; i++){
		out[i] = str[i];
		if (str[i] == maxs)
			out[i] = ' ';
	}
	out[++i] = 0;
}
int main() {
	char str1[] = "Hello World!";
	char str_1[50];
	N29(str1, str_1);
	std::cout << str_1 << "\n";

	char str2[] = "abcdacbdabbbbbcd";
	char str_2[50];
	N29(str2, str_2);
	std::cout << str_2 << "\n";

	char str3[] = "abcdefgh";
	char str_3[50];
	N29(str3, str_3);
	std::cout << str_3 << "\n";
}