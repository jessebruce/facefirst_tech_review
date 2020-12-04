#include "excel_column.h"

#include <stdlib.h> // malloc

// Get number of characters needed to represent column name
static int findNumDigits(int x)
{
    int ret = 0;
    while(x > 26)
    {
        x /= 26;
        ret++;
    }
    return ret+1;
}

static void generateColumnName(char** str, int col, int strLen)
{
    for (int i = strLen-1; i >= 0; i--)
    {
        int rem = col % 26;
        if (rem == 0)
        {
            (*str)[i] = 'Z';
            col = (col / 26)-1;
        }
        else
        {
            (*str)[i] = (char)((rem) + 64);
            col /= 26;
        }
    }
}

static char* generateColumnName_recurse(char** str, int col, int i)
{
    if (i == 0)
        return *str;

    int rem = col % 26;
    if (rem == 0)
    {
        (*str)[i-1] = 'Z';
        col = (col / 26)-1;
    }
    else
    {
        (*str)[i-1] = (char)((rem) + 64);
        col /= 26;
    }

    return generateColumnName_recurse(str, col, --i);
}

/// Iteratively finds column name from int col
/// NOTE: User __MUST__ free returned value when finished
string excelColumnName(int col)
{
    char* ret;
    int numDigits = findNumDigits(col);
    ret = (char*)malloc(numDigits + 1);
    ret[numDigits] = '\0';

    generateColumnName(&ret, col, numDigits);

    return ret;
}

/// Recursively finds column name from int col
/// NOTE: User __MUST__ free returned value when finished
string excelColumnName_recurse(int col)
{
    char* ret;
    int numDigits = findNumDigits(col);
    ret = (char*)malloc(numDigits + 1);
    ret[numDigits] = '\0';

    generateColumnName_recurse(&ret, col, numDigits);

    return ret;
}