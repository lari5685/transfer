#include <iostream>
#include <string>

void N15(char *in, int n, char *out) {
    int i, k=0;
    for (i = 0; i < n; i++) {
        out[k++] = in[i];
        while (in[i] == ' ' && in[i+1] == ' ')
            i++;
    }
    out[k] = '\0';
}

int main()
{
    char str1[] = "Hello      World!";
    char str_1[20];
    N15(str1, 17, str_1);
    std::cout << str_1 << "\n";

    char str2[] = "Hello   World!    Hello   World! Hello    World!  ";
    char str_2[50];
    N15(str2, 50, str_2);
    std::cout << str_2 << "\n";

    char str3[] = " a b  c   d    e ";
    char str_3[30];
    N15(str3, 17, str_3);
    std::cout << str_3 << "\n";
}