#include "altseq.h"
#include "excel_column.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>


static void testBothExcelColumnName(int col, char* str)
{
    assert(strcmp(excelColumnName(col), str) == 0);
    assert(strcmp(excelColumnName_recurse(col), str) == 0);
}

void main()
{
    for (int i = 1; i < 8; i++)
        assert(i == altseq(i));
    for (int i = 8; i < 15; i++)
        assert(14-i == altseq(i));
    assert(1 == altseq(15));
    assert(2 == altseq(16));
    assert(3 == altseq(17));
    assert(2 == altseq(18));
    assert(1 == altseq(19));
    assert(0 == altseq(20));
    assert(-1 == altseq(21));
    assert(0 == altseq(22));
    assert(3 == altseq(25));
    assert(5 == altseq(27));
    assert(4 == altseq(28));
    assert(5 == altseq(29));
    assert(6 == altseq(30));
    assert(2 == altseq(68));
    assert(1 == altseq(69));
    assert(0 == altseq(70));
    assert(1 == altseq(71));
    assert(0 == altseq(72));
    assert(2 == altseq(100));

    printf("altseq tests passed.\n");


    for (int i = 1; i < 26; i++)
    {
        char expected[2];
        expected[0] = i+64;
        expected[1] = '\0';

        testBothExcelColumnName(i, expected);
    }

    testBothExcelColumnName(27, "AA");
    testBothExcelColumnName(28, "AB");
    testBothExcelColumnName(29, "AC");
    testBothExcelColumnName(51, "AY");
    testBothExcelColumnName(52, "AZ");
    testBothExcelColumnName(53, "BA");
    testBothExcelColumnName(77, "BY");
    testBothExcelColumnName(78, "BZ");
    testBothExcelColumnName(79, "CA");
    testBothExcelColumnName(100, "CV");
    testBothExcelColumnName(1000, "ALL");
    testBothExcelColumnName(10000, "NTP");
    testBothExcelColumnName(100000, "EQXD");
    testBothExcelColumnName(1000000, "BDWGN");

    printf("excelColumnName tests passed.\n");
}