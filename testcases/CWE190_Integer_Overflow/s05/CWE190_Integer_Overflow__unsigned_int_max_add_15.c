/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__unsigned_int_max_add_15.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-15.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: max Set data to the max value for unsigned int
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: add
 *    GoodSink: Ensure there will not be an overflow before adding 1 to data
 *    BadSink : Add 1 to data, which can cause an overflow
 * Flow Variant: 15 Control flow: switch(6) and switch(7)
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE190_Integer_Overflow__unsigned_int_max_add_15_bad()
{
    unsigned int data;
    data = 0;



        /* POTENTIAL FLAW: Use the maximum size of the data type */
        data = UINT_MAX;









    {
        /* POTENTIAL FLAW: Adding 1 to data could cause an overflow */
        unsigned int result = data + 1;
        printUnsignedLine(result);
    }






}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G1() - use badsource and goodsink by changing the second switch to switch(8) */
static void goodB2G1()
{
    unsigned int data;
    data = 0;



        /* POTENTIAL FLAW: Use the maximum size of the data type */
        data = UINT_MAX;













        /* FIX: Add a check to prevent an overflow from occurring */
        if (data < UINT_MAX)
        {
            unsigned int result = data + 1;
            printUnsignedLine(result);
        }
        else
        {
            printLine("data value is too large to perform arithmetic safely.");
        }


}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second switch */
static void goodB2G2()
{
    unsigned int data;
    data = 0;



        /* POTENTIAL FLAW: Use the maximum size of the data type */
        data = UINT_MAX;









        /* FIX: Add a check to prevent an overflow from occurring */
        if (data < UINT_MAX)
        {
            unsigned int result = data + 1;
            printUnsignedLine(result);
        }
        else
        {
            printLine("data value is too large to perform arithmetic safely.");
        }






}

/* goodG2B1() - use goodsource and badsink by changing the first switch to switch(5) */
static void goodG2B1()
{
    unsigned int data;
    data = 0;







        /* FIX: Use a small, non-zero value that will not cause an overflow in the sinks */
        data = 2;





    {
        /* POTENTIAL FLAW: Adding 1 to data could cause an overflow */
        unsigned int result = data + 1;
        printUnsignedLine(result);
    }






}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first switch */
static void goodG2B2()
{
    unsigned int data;
    data = 0;



        /* FIX: Use a small, non-zero value that will not cause an overflow in the sinks */
        data = 2;









    {
        /* POTENTIAL FLAW: Adding 1 to data could cause an overflow */
        unsigned int result = data + 1;
        printUnsignedLine(result);
    }






}

void CWE190_Integer_Overflow__unsigned_int_max_add_15_good()
{
    goodB2G1();
    goodB2G2();
    goodG2B1();
    goodG2B2();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE190_Integer_Overflow__unsigned_int_max_add_15_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__unsigned_int_max_add_15_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif