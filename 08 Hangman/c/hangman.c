#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

const char *easy_words[] = {
    "pizza",
    "dog",
    "house",
    "roof",
    "door",
    "laundry"
};

const char *medium_words[] = {
    "doorbell",
    "fizzbuzz",
    "jazz",
    "jinx",
    "fuzz"
};

const char *hard_words[] = {
    "postgraduate",
    "esoterically",
    "stupefacient",
    "genotypical"
};

const char *frames[7] = {
        "  ---- \n"
        " |/   |\n"
        " |\n"
        " |\n"
        " |\n"
        " |\n"
        " |\n"
        "---       ",

        "  ---- \n"
        " |/   |\n"
        " |   ( )\n"
        " |\n"
        " |\n"
        " |\n"
        " |\n"
        "---       ",

        "  ---- \n"
        " |/   |\n"
        " |   ( )\n"
        " |    |\n"
        " |    |\n"
        " |\n"
        " |\n"
        "---      ",

        "  ---- \n"
        " |/   |\n"
        " |   ( )\n"
        " |   /|\n"
        " |    |\n"
        " |\n"
        " |\n"
        "---      ",

        "  ---- \n"
        " |/   |\n"
        " |   ( )\n"
        " |   /|\\\n"
        " |    |\n"
        " |\n"
        " |\n"
        "---      ",

        "  ---- \n"
        " |/   |\n"
        " |   ( )\n"
        " |   /|\\\n"
        " |    |\n"
        " |   /\n"
        " |\n"
        "---\n   ",

        "  ---- \n"
        " |/   |\n"
        " |   ( )\n"
        " |   /|\\\n"
        " |    |\n"
        " |   / \\\n"
        " |\n"
        "---      ",
};

int main(void)
{
    char mode;
    do {
        printf("Easy, medium, or hard? (e/m/h): ");
        scanf(" %c", &mode);
        mode = tolower(mode);
    } while (mode != 'e' && mode != 'm' && mode != 'h');

    srand(time(NULL));
    int random = rand();
    const char *word;

    if (mode == 'e') {
        word = easy_words[random % (sizeof(easy_words) / sizeof(char *))];
    } else if (mode == 'm') {
        word = medium_words[random % (sizeof(medium_words) / sizeof(char *))];
    } else {
        word = hard_words[random % (sizeof(hard_words) / sizeof(char *))];
    }

    char *wcpy = malloc(sizeof(char) * (strlen(word) + 1));
    wcpy[strlen(word)] = '\0';
    for (size_t i = 0; i < strlen(word); i++) {
        wcpy[i] = '_';
    }

    int dead = 0, frame = 0;
    while (1) {
        printf("%s%s\n", frames[frame], wcpy);

        char ch;
        while (1) {
            printf("Enter a letter: ");
            scanf(" %c", &ch);
            ch = tolower(ch);

            if (strchr(wcpy, ch) == NULL)
                break;
            printf("You already guessed that character!\n");
        }

        if (strchr(word, ch) != NULL) {
            for (size_t i = 0; i < strlen(word); i++) {
                if (word[i] == ch)
                    wcpy[i] = ch;
            }
        } else {
            frame++;
        }

        if (frame == 6) {
            dead = 1;
            break;
        } else if (!strcmp(word, wcpy)) {
            break;
        }
    }

    if (!dead) {
        printf("You win!");
    } else {
        printf("You lose!");
    }
    printf(" The word was %s!\n", word);

    free(wcpy);
    return EXIT_SUCCESS;
}
