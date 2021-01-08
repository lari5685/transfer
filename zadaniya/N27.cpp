#include <iostream>
#include <string>
#include <math.h>


void N27(char *str, int n, char *out) {
    int i, k=0, a;
    int digits[16] = {48,49,50,51,52,53,54,55,56,57,65,66,67,68,69,70};//0-9 & A-F
    for (i = 0; i < n; i++) {
        if (str[i] > 64 && str[i] < 92) {  // если большая буква
            a = str[i]; // запишим ее код
            out[k++] = '0';
            out[k++] = 'x';
            k++;
            out[k++] = digits[a % 16]; //сначала еденицы
			a /= 16;
			out[k-2] = digits[a % 16]; //потом десятки
			i++;
        }
        out[k++] = str[i]; //пишем не цифры
    }
    out[k] = '\0';
}

int main()
{
    char str1[] = "Hello World!";
    char str_1[20];
    N27(str1, 18, str_1);
    std::cout << str_1 << "\n";

    char str2[] = "A b C d E f G h";
    char str_2[20];
    N27(str2, 18, str_2);
    std::cout << str_2 << "\n";

    char str3[] = "a b c d e f";
    char str_3[20];
    N27(str3, 18, str_3);
    std::cout << str_3 << "\n";
}