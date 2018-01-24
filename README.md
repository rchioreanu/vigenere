# Criptare Vigenere

Implementare simplă a cifrului vigenere

# Cuprins

1. [Despre metoda de criptare vigenere](#despre-metoda-de-criptare)
2. [Structura proiectului](#structura-proiectului)
3. [Alegerea implementării](#alegerea-implementării)
4. [Compilare și executare](#compilare-și-executare)

## Despre metoda de criptare

Cifrul Vigenère este o metodă de criptare care folosește o serie de cifruri Cezar diferite bazate pe literele unui cuvânt-cheie.

Este numită după după Blaise de Vigenere.

Funcționalitatea acesteia este după cum urmează:

Ana are mere + alfabet => ayf asi fecj

|Fraza de criptat|Cheia de criptare|Rezultat|
|---|---|---|
|A|a|a|
|n|l|y|
|a|f|f|
| | ||
|a|a|a|
|r|b|s|
|e|e|i|
| | ||
|m|t|f|
|e|a|e|
|r|l|c|
|e|f|j|

## Structura proiectului

.\
├── LICENSE\
├── Makefile\
├── README.md\
├── decrypt.c\
├── encrypt.c

## Alegerea implementării

Programul(atât cel de criptare, cât și cel de decriptare) va rula după următorul model:

> ./vigenere <șirul> \<cheia de criptare>

>     while (av[1][i]) {
>        if (!isspace(av[1][i])) {
>            av[1][i] = encryptLetter(av[1][i], av[2][j]);
>            j++;
>        }
>        if (!av[2][j])
>            j = 0;
>        i++;
>    }

Programul parcurge șirul care trebuie criptat și apelează funcția de criptare/decriptare
pentru fiecare caracter care nu este spațiu cu caracterul aferent cheii. Resetează cheia
dacă a ajuns la final.

### Criptare

>       return ((letter + keyLetter) % 26 + 'A');

Rezultatul încriptării este egal cu litera din alfabet mutată cu poziția literei cheie în față.

>        return (tolower((letter + keyLetter) % 26 + 'A'));

Case-senzitive

### Decriptare

>        if ((letter - keyLetter) % 26 < 0)
>            return ((letter - keyLetter) % 26 + 'A' + 26);
>        else
>            return ((letter - keyLetter) % 26 + 'A');

Litera decriptată este egală cu poziția diferenței dintre litera încriptată și cheie.
În cazul în care rezultatul e negativ, se mai adaugă 26(dimensiunea alfabetului).

## Compilare și Executare

Pentru a compila proiectul:

> make

Pentru a compila doar o parte a proiectului:

> make encrypt

> make decrypt

Pentru recompilare:

> make re

Pentru ștergerea executabilelor:

> make clean

Pentru rularea programului de încriptare:

> ./encrypt <șirul de încriptat> \<cheia>

Pentru rularea programului de decriptare:

> ./decrypt <șirul de decriptat> \<cheia>
