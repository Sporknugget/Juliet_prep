/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE457_Use_of_Uninitialized_Variable__struct_03.c
Label Definition File: CWE457_Use_of_Uninitialized_Variable.c.label.xml
Template File: sources-sinks-03.tmpl.c
*/
/*
 * @description
 * CWE: 457 Use of Uninitialized Variable
 * BadSource: no_init Don't initialize data
 * GoodSource: Initialize data
 * Sinks: use
 *    GoodSink: Initialize then use data
 *    BadSink : Use data
 * Flow Variant: 03 Control flow: if(5==5) and if(5!=5)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE457_Use_of_Uninitialized_Variable__struct_03_bad()
{
    twoIntsStruct data;

    {
        /* POTENTIAL FLAW: Don't initialize data */
        ; /* empty statement needed for some flow variants */
    }

    {
        /* POTENTIAL FLAW: Use data without initializing it */
        printIntLine(data.intOne);
        printIntLine(data.intTwo);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G1() - use badsource and goodsink by changing the second 5==5 to 5!=5 */
static void goodB2G1()
{
    twoIntsStruct data;

    {
        /* POTENTIAL FLAW: Don't initialize data */
        ; /* empty statement needed for some flow variants */
    }






    {
        /* FIX: Ensure data is initialized before use */
        data.intOne = 1;
        data.intTwo = 2;
        printIntLine(data.intOne);
        printIntLine(data.intTwo);
    }
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second if */
static void goodB2G2()
{
    twoIntsStruct data;

    {
        /* POTENTIAL FLAW: Don't initialize data */
        ; /* empty statement needed for some flow variants */
    }

    {
        /* FIX: Ensure data is initialized before use */
        data.intOne = 1;
        data.intTwo = 2;
        printIntLine(data.intOne);
        printIntLine(data.intTwo);
    }
}

/* goodG2B1() - use goodsource and badsink by changing the first 5==5 to 5!=5 */
static void goodG2B1()
{
    twoIntsStruct data;






    {
        /* FIX: Initialize data */
        data.intOne = 1;
        data.intTwo = 2;
    }

    {
        /* POTENTIAL FLAW: Use data without initializing it */
        printIntLine(data.intOne);
        printIntLine(data.intTwo);
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first if */
static void goodG2B2()
{
    twoIntsStruct data;

    {
        /* FIX: Initialize data */
        data.intOne = 1;
        data.intTwo = 2;
    }

    {
        /* POTENTIAL FLAW: Use data without initializing it */
        printIntLine(data.intOne);
        printIntLine(data.intTwo);
    }
}

void CWE457_Use_of_Uninitialized_Variable__struct_03_good()
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
    CWE457_Use_of_Uninitialized_Variable__struct_03_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE457_Use_of_Uninitialized_Variable__struct_03_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
