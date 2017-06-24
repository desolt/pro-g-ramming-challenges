#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    printf("Fahrenheit or Celcius? (f/c): ");
    
    int ch;
    do {
        ch = getchar();
    } while (tolower(ch) != 'f' && tolower(ch) != 'c');

    printf("What is the temperature?: ");
    float temp;
    scanf("%f", &temp);
    if (tolower(ch) == 'f') {
        temp = (5 * (temp - 32)) / 9.0;
    } else {
        temp = ((temp * 9) / 5.0) + 32.0;
    }

    printf("Your converted temperature is %f.\n", temp);

    return EXIT_SUCCESS;
}
