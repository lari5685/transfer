#include <iostream>
#include <string>
#include <math.h>

int OctToDec(int a) {
    int res = 0, i = 0;
    while (a > 0) {
        res += a % 10 * pow(8, i);
        a /= 10;
        i++;
    }
    return res;
}

void N24(char *str, int n, char *out) {
    int i, k=0, a;
    for (i = 0; i < n; i++) {
        if (str[i] > 47 && str[i] < 58) {  // если цифра
            a = str[i] - 48; // запишим
            i++;
            while (str[i] > 47 && str[i] < 58) { // если еще цифрв
                a = a * 10 + str[i] - 48; // еще запишим
                i++;
            }
            a = OctToDec(a); // переведем в десятичную
            out[k++] = a;  // пишем символ ASCII
        }
        out[k++] = str[i]; //пишем не цифры
    }
    out[k] = '\0';
}

int main()
{
    char str1[] = "Hello  101 World!";
    char str_1[20];
    N24(str1, 18, str_1);
    std::cout << str_1 << "\n";

    char str2[] = "Hello 127o162l144!";
    char str_2[20];
    N24(str2, 18, str_2);
    std::cout << str_2 << "\n";

    char str3[] = "Hello 0 World!";
    char str_3[20];
    N24(str3, 18, str_3);
    std::cout << str_3 << "\n";
}