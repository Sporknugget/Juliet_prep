/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__int_min_predec_13.c
Label Definition File: CWE191_Integer_Underflow__int.label.xml
Template File: sources-sinks-13.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: min Set data to the minimum value for int
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: decrement
 *    GoodSink: Ensure there will not be an underflow before decrementing data
 *    BadSink : Decrement data, which can cause an Underflow
 * Flow Variant: 13 Control flow: if(GLOBAL_CONST_FIVE==5) and if(GLOBAL_CONST_FIVE!=5)
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE191_Integer_Underflow__int_min_predec_13_bad()
{
    int data;
    /* Initialize data */
    data = 0;

    {
        /* POTENTIAL FLAW: Use the minimum value for this type */
        data = INT_MIN;
    }

    {
        {
            /* POTENTIAL FLAW: Decrementing data could cause an underflow */
            --data;
            int result = data;
            printIntLine(result);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G1() - use badsource and goodsink by changing the second GLOBAL_CONST_FIVE==5 to GLOBAL_CONST_FIVE!=5 */
static void goodB2G1()
{
    int data;
    /* Initialize data */
    data = 0;

    {
        /* POTENTIAL FLAW: Use the minimum value for this type */
        data = INT_MIN;
    }






    {
        /* FIX: Add a check to prevent an underflow from occurring */
        if (data > INT_MIN)
        {
            --data;
            int result = data;
            printIntLine(result);
        }
        else
        {
            printLine("data value is too large to perform arithmetic safely.");
        }
    }
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second if */
static void goodB2G2()
{
    int data;
    /* Initialize data */
    data = 0;

    {
        /* POTENTIAL FLAW: Use the minimum value for this type */
        data = INT_MIN;
    }

    {
        /* FIX: Add a check to prevent an underflow from occurring */
        if (data > INT_MIN)
        {
            --data;
            int result = data;
            printIntLine(result);
        }
        else
        {
            printLine("data value is too large to perform arithmetic safely.");
        }
    }
}

/* goodG2B1() - use goodsource and badsink by changing the first GLOBAL_CONST_FIVE==5 to GLOBAL_CONST_FIVE!=5 */
static void goodG2B1()
{
    int data;
    /* Initialize data */
    data = 0;






    {
        /* FIX: Use a small, non-zero value that will not cause an integer underflow in the sinks */
        data = -2;
    }

    {
        {
            /* POTENTIAL FLAW: Decrementing data could cause an underflow */
            --data;
            int result = data;
            printIntLine(result);
        }
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first if */
static void goodG2B2()
{
    int data;
    /* Initialize data */
    data = 0;

    {
        /* FIX: Use a small, non-zero value that will not cause an integer underflow in the sinks */
        data = -2;
    }

    {
        {
            /* POTENTIAL FLAW: Decrementing data could cause an underflow */
            --data;
            int result = data;
            printIntLine(result);
        }
    }
}

void CWE191_Integer_Underflow__int_min_predec_13_good()
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
    CWE191_Integer_Underflow__int_min_predec_13_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE191_Integer_Underflow__int_min_predec_13_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
