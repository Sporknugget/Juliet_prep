/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE457_Use_of_Uninitialized_Variable__int_array_malloc_partial_init_17.c
Label Definition File: CWE457_Use_of_Uninitialized_Variable.c_array.label.xml
Template File: sources-sinks-17.tmpl.c
*/
/*
 * @description
 * CWE: 457 Use of Uninitialized Variable
 * BadSource: partial_init Initialize part, but not all of the array
 * GoodSource: Initialize data
 * Sinks: use
 *    GoodSink: Initialize then use data
 *    BadSink : Use data
 * Flow Variant: 17 Control flow: for loops
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE457_Use_of_Uninitialized_Variable__int_array_malloc_partial_init_17_bad()
{

    int * data;

    if (data == NULL) {exit(-1);}

    {
        /* POTENTIAL FLAW: Partially initialize data */
        {
            int i;
            for(i=0; i<(10/2); i++)
            {
                data[i] = i;
            }
        }
    }

    {
        /* POTENTIAL FLAW: Use data without initializing it */
        {
            int i;
            for(i=0; i<10; i++)
            {
                printIntLine(data[i]);
            }
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G() - use badsource and goodsink in the for statements */
static void goodB2G()
{

    int * data;

    if (data == NULL) {exit(-1);}

    {
        /* POTENTIAL FLAW: Partially initialize data */
        {
            int i;
            for(i=0; i<(10/2); i++)
            {
                data[i] = i;
            }
        }
    }

    {
        /* FIX: Ensure data is initialized before use */
        {
            int i;
            for(i=0; i<10; i++)
            {
                data[i] = i;
            }
        }
        {
            int i;
            for(i=0; i<10; i++)
            {
                printIntLine(data[i]);
            }
        }
    }
}

/* goodG2B() - use goodsource and badsink in the for statements */
static void goodG2B()
{

    int * data;
    data = (int *)malloc(10*sizeof(int));
    if (data == NULL) {exit(-1);}

    {
        /* FIX: Completely initialize data */
        {
            int i;
            for(i=0; i<10; i++)
            {
                data[i] = i;
            }
        }
    }

    {
        /* POTENTIAL FLAW: Use data without initializing it */
        {
            int i;
            for(i=0; i<10; i++)
            {
                printIntLine(data[i]);
            }
        }
    }
}

void CWE457_Use_of_Uninitialized_Variable__int_array_malloc_partial_init_17_good()
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
    CWE457_Use_of_Uninitialized_Variable__int_array_malloc_partial_init_17_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE457_Use_of_Uninitialized_Variable__int_array_malloc_partial_init_17_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif