ENCRYPT_EXECUTABLE = encrypt

DECRYPT_EXECUTABLE = decrypt

ENCRYPT_SRC = encrypt.c

DECRYPT_SRC = decrypt.c

all: encrypt \
	decrypt

encrypt:
	cc -Wall -Wextra -Werror $(ENCRYPT_SRC) -o $(ENCRYPT_EXECUTABLE)

decrypt:
	cc -Wall -Wextra -Werror $(DECRYPT_SRC) -o $(DECRYPT_EXECUTABLE)

clean:
	/bin/rm -f $(ENCRYPT_EXECUTABLE) $(DECRYPT_EXECUTABLE)

re: clean \
	all
