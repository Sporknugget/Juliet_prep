/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_by_Zero__int_rand_divide_06.c
Label Definition File: CWE369_Divide_by_Zero__int.label.xml
Template File: sources-sinks-06.tmpl.c
*/
/*
 * @description
 * CWE: 369 Divide by Zero
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Non-zero
 * Sinks: divide
 *    GoodSink: Check for zero before dividing
 *    BadSink : Divide a constant by data
 * Flow Variant: 06 Control flow: if(STATIC_CONST_FIVE==5) and if(STATIC_CONST_FIVE!=5)
 *
 * */

#include "std_testcase.h"

/* The variable below is declared "const", so a tool should be able
   to identify that reads of this will always give its initialized
   value. */
static const int STATIC_CONST_FIVE = 5;

#ifndef OMITBAD

void CWE369_Divide_by_Zero__int_rand_divide_06_bad()
{
    int data;
    /* Initialize data */
    data = -1;

    {
        /* POTENTIAL FLAW: Set data to a random value */
        data = RAND32();
    }

    {
        /* POTENTIAL FLAW: Possibly divide by zero */
        printIntLine(100 / data);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G1() - use badsource and goodsink by changing the second STATIC_CONST_FIVE==5 to STATIC_CONST_FIVE!=5 */
static void goodB2G1()
{
    int data;
    /* Initialize data */
    data = -1;

    {
        /* POTENTIAL FLAW: Set data to a random value */
        data = RAND32();
    }






    {
        /* FIX: test for a zero denominator */
        if( data != 0 )
        {
            printIntLine(100 / data);
        }
        else
        {
            printLine("This would result in a divide by zero");
        }
    }
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second if */
static void goodB2G2()
{
    int data;
    /* Initialize data */
    data = -1;

    {
        /* POTENTIAL FLAW: Set data to a random value */
        data = RAND32();
    }

    {
        /* FIX: test for a zero denominator */
        if( data != 0 )
        {
            printIntLine(100 / data);
        }
        else
        {
            printLine("This would result in a divide by zero");
        }
    }
}

/* goodG2B1() - use goodsource and badsink by changing the first STATIC_CONST_FIVE==5 to STATIC_CONST_FIVE!=5 */
static void goodG2B1()
{
    int data;
    /* Initialize data */
    data = -1;






    {
        /* FIX: Use a value not equal to zero */
        data = 7;
    }

    {
        /* POTENTIAL FLAW: Possibly divide by zero */
        printIntLine(100 / data);
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first if */
static void goodG2B2()
{
    int data;
    /* Initialize data */
    data = -1;

    {
        /* FIX: Use a value not equal to zero */
        data = 7;
    }

    {
        /* POTENTIAL FLAW: Possibly divide by zero */
        printIntLine(100 / data);
    }
}

void CWE369_Divide_by_Zero__int_rand_divide_06_good()
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
    CWE369_Divide_by_Zero__int_rand_divide_06_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE369_Divide_by_Zero__int_rand_divide_06_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif