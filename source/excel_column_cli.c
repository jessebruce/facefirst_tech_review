#include "excel_column.h"

#include <stdlib.h>
#include <stdio.h>

// Assumes valid input
void main()
{
    int x = 0;
    while(1)
    {
        printf("Enter column number: ");
        scanf("%d", &x);

        char* colName = excelColumnName(x);
        printf("Column name I: %s\n", colName);
        free(colName);

        colName = excelColumnName_recurse(x);
        printf("Column name R: %s\n", colName);
        free(colName);
    }
}