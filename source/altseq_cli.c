#include "altseq.h"

#include <stdio.h>

// Assumes valid input
void main()
{
    int x = 0;
    while(1)
    {
        printf("Enter index: ");
        scanf("%d", &x);
        printf("altseq(%d) = %d\n", x, altseq(x));
    }
}