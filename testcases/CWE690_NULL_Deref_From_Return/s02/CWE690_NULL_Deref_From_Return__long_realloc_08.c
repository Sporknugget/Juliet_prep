/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__long_realloc_08.c
Label Definition File: CWE690_NULL_Deref_From_Return.free.label.xml
Template File: source-sinks-08.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * BadSource: realloc Allocate data using realloc()
 * Sinks:
 *    GoodSink: Check to see if the data allocation failed and if not, use data
 *    BadSink : Don't check for NULL and use data
 * Flow Variant: 08 Control flow: if(staticReturnsTrue()) and if(staticReturnsFalse())
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

/* The two function below always return the same value, so a tool
   should be able to identify that calls to the functions will always
   return a fixed value. */
static int staticReturnsTrue()
{
    return 1;
}

static int staticReturnsFalse()
{
    return 0;
}

#ifndef OMITBAD

void CWE690_NULL_Deref_From_Return__long_realloc_08_bad()
{
    long * data;
    data = NULL; /* Initialize data */
    /* POTENTIAL FLAW: Allocate memory without checking if the memory allocation function failed */
    data = (long *)realloc(data, 1*sizeof(long));

    {
        /* FLAW: Initialize memory buffer without checking to see if the memory allocation function failed */
        data[0] = 5L;
        printLongLine(data[0]);
        free(data);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G1() - use badsource and goodsink by changing staticReturnsTrue() to staticReturnsFalse() */
static void goodB2G1()
{
    long * data;
    data = NULL; /* Initialize data */
    /* POTENTIAL FLAW: Allocate memory without checking if the memory allocation function failed */
    data = (long *)realloc(data, 1*sizeof(long));






    {
        /* FIX: Check to see if the memory allocation function was successful before initializing the memory buffer */
        if (data != NULL)
        {
            data[0] = 5L;
            printLongLine(data[0]);
            free(data);
        }
    }
}

/* goodB2G2() - use badsource and goodsink by reversing statements in if  */
static void goodB2G2()
{
    long * data;
    data = NULL; /* Initialize data */
    /* POTENTIAL FLAW: Allocate memory without checking if the memory allocation function failed */
    data = (long *)realloc(data, 1*sizeof(long));

    {
        /* FIX: Check to see if the memory allocation function was successful before initializing the memory buffer */
        if (data != NULL)
        {
            data[0] = 5L;
            printLongLine(data[0]);
            free(data);
        }
    }
}

void CWE690_NULL_Deref_From_Return__long_realloc_08_good()
{
    goodB2G1();
    goodB2G2();
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
    CWE690_NULL_Deref_From_Return__long_realloc_08_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE690_NULL_Deref_From_Return__long_realloc_08_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
