/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__int64_t_rand_add_18.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-18.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: add
 *    GoodSink: Ensure there will not be an overflow before adding 1 to data
 *    BadSink : Add 1 to data, which can cause an overflow
 * Flow Variant: 18 Control flow: goto statements
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE190_Integer_Overflow__int64_t_rand_add_18_bad()
{
    int64_t data;
    data = 0LL;


    /* POTENTIAL FLAW: Use a random value */
    data = (int64_t)RAND64();


    {
        /* POTENTIAL FLAW: Adding 1 to data could cause an overflow */
        int64_t result = data + 1;
        printLongLongLine(result);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G() - use badsource and goodsink by reversing the blocks on the second goto statement */
static void goodB2G()
{
    int64_t data;
    data = 0LL;


    /* POTENTIAL FLAW: Use a random value */
    data = (int64_t)RAND64();


    /* FIX: Add a check to prevent an overflow from occurring */
    if (data < LLONG_MAX)
    {
        int64_t result = data + 1;
        printLongLongLine(result);
    }
    else
    {
        printLine("data value is too large to perform arithmetic safely.");
    }
}

/* goodG2B() - use goodsource and badsink by reversing the blocks on the first goto statement */
static void goodG2B()
{
    int64_t data;
    data = 0LL;


    /* FIX: Use a small, non-zero value that will not cause an overflow in the sinks */
    data = 2;


    {
        /* POTENTIAL FLAW: Adding 1 to data could cause an overflow */
        int64_t result = data + 1;
        printLongLongLine(result);
    }
}

void CWE190_Integer_Overflow__int64_t_rand_add_18_good()
{
    goodB2G();
    goodG2B();
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
    CWE190_Integer_Overflow__int64_t_rand_add_18_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__int64_t_rand_add_18_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
