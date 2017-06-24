#include <stdlib.h>
#include <stdio.h>

int main()
{
    unsigned int nums[100];
    nums[0] = 0;
    nums[1] = 1;
    
    unsigned int sum = 0;
    unsigned int i = 2;
    for (; i < 100; i++) {
        nums[i] = nums[i-1] + nums[i-2];
        if (nums[i] >= 4000000)
            break;

        if (nums[i] % 2 == 0)
            sum += nums[i];
    }

    printf("%u\n", sum);

    return EXIT_SUCCESS;
}
