/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE197_Numeric_Truncation_Error__short_fscanf_08.c
Label Definition File: CWE197_Numeric_Truncation_Error__short.label.xml
Template File: sources-sink-08.tmpl.c
*/
/*
 * @description
 * CWE: 197 Numeric Truncation Error
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Less than CHAR_MAX
 * Sink:
 *    BadSink : Convert data to a char
 * Flow Variant: 08 Control flow: if(staticReturnsTrue()) and if(staticReturnsFalse())
 *
 * */

#include "std_testcase.h"

/* The two function below always return the same value, so a tool
 * should be able to identify that calls to the functions will always
 * return a fixed value.
 */
static int staticReturnsTrue()
{
    return 1;
}

static int staticReturnsFalse()
{
    return 0;
}

#ifndef OMITBAD

void CWE197_Numeric_Truncation_Error__short_fscanf_08_bad()
{
    short data;
    /* Initialize data */
    data = -1;

    {
        /* FLAW: Use a number input from the console using fscanf() */
        fscanf (stdin, "%hd", &data);
    }
    {
        /* POTENTIAL FLAW: Convert data to a char, possibly causing a truncation error */
        char charData = (char)data;
        printHexCharLine(charData);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B1() - use goodsource and badsink by changing the staticReturnsTrue() to staticReturnsFalse() */
static void goodG2B1()
{
    short data;
    /* Initialize data */
    data = -1;






    {
        /* FIX: Use a positive integer less than CHAR_MAX*/
        data = CHAR_MAX-5;
    }
    {
        /* POTENTIAL FLAW: Convert data to a char, possibly causing a truncation error */
        char charData = (char)data;
        printHexCharLine(charData);
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the if statement */
static void goodG2B2()
{
    short data;
    /* Initialize data */
    data = -1;

    {
        /* FIX: Use a positive integer less than CHAR_MAX*/
        data = CHAR_MAX-5;
    }
    {
        /* POTENTIAL FLAW: Convert data to a char, possibly causing a truncation error */
        char charData = (char)data;
        printHexCharLine(charData);
    }
}

void CWE197_Numeric_Truncation_Error__short_fscanf_08_good()
{
    goodG2B1();
    goodG2B2();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE197_Numeric_Truncation_Error__short_fscanf_08_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE197_Numeric_Truncation_Error__short_fscanf_08_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
