#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_INPUT_SIZE 256

size_t create_output(char *input, char **output)
{
    size_t len = strlen(input);
    *output = malloc(sizeof(char) * len);
    (*output)[len] = '\0';

    return len;
}

void encrypt(char *input, int key, char **output) 
{
    size_t len = create_output(input, output);

    for (size_t i = 0; i < len; i++) {
        char ch = input[i];
        if (isalpha(ch)) { /* Only affecting alphabetic characters. */
            ch += key;
            if (!isalpha(ch))
                ch -= 26;
        }

        (*output)[i] = ch;
    }
}

void decrypt(char *input, int key, char **output)
{
    size_t len = create_output(input, output);

    for (size_t i = 0; i < len; i++) {
        char ch = input[i];
        if (isalpha(ch)) {
            ch -= key;
            if (!isalpha(ch))
                ch += 26;
        }
        
        (*output)[i] = ch;
    }
}

/* Simple caesar cipher encryption program. */
int main()
{
    /* input should be alphabetic */
    char target[MAX_INPUT_SIZE];
    printf("Type input to encrypt: \n");
    scanf("%[^\n]%*c", target);

    int key = 0;
    do {
        printf("What is the key?: ");
        scanf("%d", &key);
    } while (key <= 0 || key > 25);


    char operation;
    while (operation != 'e' && operation != 'd') {
        printf("Encrypt or decrypt? (e/d): ");
        scanf(" %c", &operation);
        operation = tolower(operation);
    } 

    char *output;
    if (operation == 'e') {
        encrypt(target, key, &output);
    } else {
        decrypt(target, key, &output);
    }

    printf("%s\n", output);
    free(output);

    return EXIT_SUCCESS;
}
