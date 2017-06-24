#include <stdlib.h>
#include <stdio.h>
#include <time.h>

const char *first_names[] = {
    "Kevin",
    "Billy",
    "John",
    "Sam",
    "Jake",
    "Michael"
};

const char *last_names[] = {
    "Lee",
    "Smith",
    "Adams",
    "Henderson",
    "Shakespeare",
    "Anderson",
    "Burns"
};

int main()
{
    srand(time(NULL));
    size_t first_name = rand() % (sizeof(first_names) / sizeof(const char *));
    srand(time(NULL) + 1);
    size_t last_name = rand() % (sizeof(last_names) / sizeof(const char *));

    printf("Your name is %s %s!\n", first_names[first_name], last_names[last_name]);

    return EXIT_SUCCESS;
}
