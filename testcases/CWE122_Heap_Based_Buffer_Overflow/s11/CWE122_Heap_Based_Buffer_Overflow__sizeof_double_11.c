/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__sizeof_double_11.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__sizeof.label.xml
Template File: sources-sink-11.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Initialize the source buffer using the size of a pointer
 * GoodSource: Initialize the source buffer using the size of the DataElementType
 * Sink:
 *    BadSink : Print then free data
 * Flow Variant: 11 Control flow: if(globalReturnsTrue()) and if(globalReturnsFalse())
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE122_Heap_Based_Buffer_Overflow__sizeof_double_11_bad()
{
    double * data;
    /* Initialize data */
    data = NULL;

    {
        /* INCIDENTAL: CWE-467 (Use of sizeof() on a pointer type) */
        /* FLAW: Using sizeof the pointer and not the data type in malloc() */
        data = (double *)malloc(sizeof(data));
        if (data == NULL) {exit(-1);}
        *data = 1.7E300;
    }
    /* POTENTIAL FLAW: Attempt to use data, which may not have enough memory allocated */
    printDoubleLine(*data);
    free(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B1() - use goodsource and badsink by changing the globalReturnsTrue() to globalReturnsFalse() */
static void goodG2B1()
{
    double * data;
    /* Initialize data */
    data = NULL;






    {
        /* FIX: Using sizeof the data type in malloc() */
        data = (double *)malloc(sizeof(*data));
        if (data == NULL) {exit(-1);}
        *data = 1.7E300;
    }
    /* POTENTIAL FLAW: Attempt to use data, which may not have enough memory allocated */
    printDoubleLine(*data);
    free(data);
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the if statement */
static void goodG2B2()
{
    double * data;
    /* Initialize data */
    data = NULL;

    {
        /* FIX: Using sizeof the data type in malloc() */
        data = (double *)malloc(sizeof(*data));
        if (data == NULL) {exit(-1);}
        *data = 1.7E300;
    }
    /* POTENTIAL FLAW: Attempt to use data, which may not have enough memory allocated */
    printDoubleLine(*data);
    free(data);
}

void CWE122_Heap_Based_Buffer_Overflow__sizeof_double_11_good()
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
    CWE122_Heap_Based_Buffer_Overflow__sizeof_double_11_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE122_Heap_Based_Buffer_Overflow__sizeof_double_11_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif