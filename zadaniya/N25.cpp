#include <stdio.h>
#include <ctype.h>
#include <iostream>

int find_word(const char* s) {
    char t = 127;
    int n = 0;
    for (int i = 0; s[i+1] != 0; i++) {
        if (s[i-1] == ' ' || i == 0) {
            if (s[i] >= 'a' && s[i] <= 'z' && t > s[i]) {
                t = s[i];
                n = i;
            }
        }
    }
    return t == 127 ? -1 : n;
}

int main(void) {
    char s[] = "Apl, Ada, Aorth, Aisp";

    int i = find_word(s);
    if (i != -1) {
        std::cout << "index: " << i << '\n';
        std::cout << "simbol: " <<s[i] << '\n';
    }
    else
        std::cout << "not found" << '\n';

    char s2[] = "Apl, Ada, aorth";

    i = find_word(s2);
    if (i != -1) {
        std::cout << "index: " << i << '\n';
        std::cout << "simbol: " << s2[i] << '\n';
    }
    else
        std::cout << "not found" << '\n';

    char s3[] = "bvsdv Hvfvfd Hfdv j c";

    i = find_word(s3);
    if (i != -1) {
        std::cout << "index: " << i << '\n';
        std::cout << "simbol: " << s3[i] << '\n';
    }
    else
        std::cout << "not found" << '\n';

    return 0;
}