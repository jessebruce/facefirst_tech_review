#include "altseq.h"

#include <assert.h>

static int contains7(int i)
{
    while (i > 0)
    {
        // Is there a 7 in the ones place?
        if ((i % 10) && (i % 10) % 7 == 0)
            return 1;
        i /= 10;
    }
    return 0;
}

static int isMultiple7(int i)
{
    return (i % 7 == 0);
}

int altseq(int n)
{
    assert(n > 0);
    int ret = 0;
    int modifier = 1;

    for (int i = 1; i <= n; i++)
    {
        ret += modifier;
        if (isMultiple7(i))
            modifier *= -1;
        else if (i > 10 && contains7(i))
            modifier *= -1;
    }

    return ret;
}

