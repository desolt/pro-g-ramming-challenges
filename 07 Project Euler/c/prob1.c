#include <stdlib.h>
#include <stdio.h>

int main()
{
    size_t sum = 0;
    for (size_t i = 0; i < 1000; ++i) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }


    printf("The sum is %lu.\n", sum);

    return EXIT_SUCCESS;
}
