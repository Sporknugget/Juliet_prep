/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__char_min_predec_12.c
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-12.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: min Set data to the min value for char
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: decrement
 *    GoodSink: Ensure there will not be an underflow before decrementing data
 *    BadSink : Decrement data, which can cause an Underflow
 * Flow Variant: 12 Control flow: if(globalReturnsTrueOrFalse())
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE191_Integer_Underflow__char_min_predec_12_bad()
{
    char data;
    data = ' ';

    {
        /* POTENTIAL FLAW: Use the minimum size of the data type */
        data = CHAR_MIN;
    }






    {
        {
            /* POTENTIAL FLAW: Decrementing data could cause an underflow */
            --data;
            char result = data;
            printHexCharLine(result);
        }
    }














}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G() - use badsource and goodsink by changing the first "if" so that
   both branches use the BadSource and the second "if" so that both branches
   use the GoodSink */
static void goodB2G()
{
    char data;
    data = ' ';

    {
        /* POTENTIAL FLAW: Use the minimum size of the data type */
        data = CHAR_MIN;
    }






    {
        /* FIX: Add a check to prevent an underflow from occurring */
        if (data > CHAR_MIN)
        {
            --data;
            char result = data;
            printHexCharLine(result);
        }
        else
        {
            printLine("data value is too large to perform arithmetic safely.");
        }
    }














}

/* goodG2B() - use goodsource and badsink by changing the first "if" so that
   both branches use the GoodSource and the second "if" so that both branches
   use the BadSink */
static void goodG2B()
{
    char data;
    data = ' ';

    {
        /* FIX: Use a small, non-zero value that will not cause an underflow in the sinks */
        data = -2;
    }






    {
        {
            /* POTENTIAL FLAW: Decrementing data could cause an underflow */
            --data;
            char result = data;
            printHexCharLine(result);
        }
    }









}

void CWE191_Integer_Underflow__char_min_predec_12_good()
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
    CWE191_Integer_Underflow__char_min_predec_12_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE191_Integer_Underflow__char_min_predec_12_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
