#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char    decrypt(char letter, char keyLetter) {
    if (isupper(letter)) {
        keyLetter = toupper(keyLetter);
        if ((letter - keyLetter) % 26 < 0)
            return ((letter - keyLetter) % 26 + 'A' + 26);
        else
            return ((letter - keyLetter) % 26 + 'A');
    } else {
        keyLetter = toupper(keyLetter);
        letter = toupper(letter);
        if ((letter - keyLetter) % 26 < 0)
            return (tolower((letter - keyLetter) % 26 + 'A' + 26));
        else
            return (tolower((letter - keyLetter) % 26 + 'A'));
    }
}

int main(int ac, char **av) {
    int    i;
    size_t j;

    if (ac != 3) {
        puts("Usage: ./decrypt <string> <key>");
        exit(0);
    }
    i = 0;
    j = 0;
    while (av[1][i]) {
        if (!isspace(av[1][i])) {
            av[1][i] = decrypt(av[1][i], av[2][j]);
            j++;
        }
        if (!av[2][j])
            j = 0;
        i++;
    }
    puts(av[1]);
    return 0;
}
