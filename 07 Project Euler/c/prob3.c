#include <stdio.h>
#include <stdlib.h>

int isprime(int num)
{
    for (int i = 2; i < num; i++) {
        if (num % i == 0)
            return 0;
    }

    return 1;
}

unsigned long largest_prime_factor(unsigned long num)
{
    for (unsigned long i = 2; i < num; i++) {
        if (num % i == 0 && isprime(i)) {
            num /= i;
        }
    }

    return num;
}

int main()
{
    unsigned long factor = largest_prime_factor(600851475143);
    printf("%lu\n", factor);

    return EXIT_SUCCESS;
}
