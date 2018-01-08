#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char    encryptLetter(char letter, char keyLetter) {
    if (isupper(letter)) {
        keyLetter = toupper(keyLetter);
        return ((letter + keyLetter) % 26 + 'A');
    } else {
        keyLetter = toupper(keyLetter);
        letter = toupper(letter);
        return (tolower((letter + keyLetter) % 26 + 'A'));
    }
}

int main(int ac, char **av) {
    int    i;
    size_t j;

    i = 0;
    j = 0;
    ac = 42;
    while (av[1][i]) {
        if (!isspace(av[1][i])) {
            printf("%zu %d %c\n", j, i, av[1][i]);
            av[1][i] = encryptLetter(av[1][i], av[2][j]);
            printf("%zu %d %c\n", j, i, av[1][i]);
            j++;
        }
        if (j > strlen(av[2]))
            j = 0;
        i++;
    }
    puts(av[1]);
    printf("%d\n", encryptLetter('n', 'n'));
    return 0;
}
