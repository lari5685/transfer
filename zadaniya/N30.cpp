#include <iostream>
#include <string>
#include <math.h>

void N29(char *str) {
	int n[128]; // массив количества каждого символа в строке 
	for(int i = 0; i < 128; i++)// обнуляем массив
		n[i] = 0;
	for(int i = 0; str[i] != '\0'; i++){ // заполняем 
		n[str[i]]++; 					// количеством символов
	}
	int max = 1;
	char maxs = 0;
	for(int i = 0; i < 128; i++) // ищем какого элемента было больше
		if(n[i] > max){
			max = n[i];
			maxs = i;
		}
	for(int i = 0; str[i] != '\0'; i++){ // заменяем на пробел
		if (str[i] == maxs)
			str[i] = ' ';
	}
}
int main() {
	char str1[] = "Hello World!";
	std::cout << str1 << "\n";
	N29(str1);
	std::cout << str1 << "\n";

	char str2[] = "abcdacbdabbbbbcd";
	std::cout << str2 << "\n";
	N29(str2);
	std::cout << str2 << "\n";

	char str3[] = "abcdefgh";
	std::cout << str3 << "\n";
	N29(str3);
	std::cout << str3 << "\n";
}