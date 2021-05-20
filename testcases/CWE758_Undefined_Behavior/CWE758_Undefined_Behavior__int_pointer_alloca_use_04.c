/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE758_Undefined_Behavior__int_pointer_alloca_use_04.c
Label Definition File: CWE758_Undefined_Behavior.alloc.label.xml
Template File: point-flaw-04.tmpl.c
*/
/*
 * @description
 * CWE: 758 Undefined Behavior
 * Sinks: alloca_use
 *    GoodSink: Initialize then use data
 *    BadSink : Use data from alloca without initialization
 * Flow Variant: 04 Control flow: if(STATIC_CONST_TRUE) and if(STATIC_CONST_FALSE)
 *
 * */

#include "std_testcase.h"

/* The two variables below are declared "const", so a tool should
   be able to identify that reads of these will always return their
   initialized values. */
static const int STATIC_CONST_TRUE = 1; /* true */
static const int STATIC_CONST_FALSE = 0; /* false */

#ifndef OMITBAD

void CWE758_Undefined_Behavior__int_pointer_alloca_use_04_bad()
{

    {
        {
            int * * pointer = (int * *)ALLOCA(sizeof(int *));
            int * data = *pointer; /* FLAW: the value pointed to by pointer is undefined */
            printIntLine(*data);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD










    {
        {
            int * data;
            int * * pointer = (int * *)ALLOCA(sizeof(int *));
            /* initialize both the pointer and the data pointed to */
            data = (int *)malloc(sizeof(int));
            if (data == NULL) {exit(-1);}
            *data = 5;
            *pointer = data; /* FIX: Assign a value to the thing pointed to by pointer */
            {
                int * data = *pointer;
                printIntLine(*data);
            }
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{

    {
        {
            int * data;
            int * * pointer = (int * *)ALLOCA(sizeof(int *));
            /* initialize both the pointer and the data pointed to */
            data = (int *)malloc(sizeof(int));
            if (data == NULL) {exit(-1);}
            *data = 5;
            *pointer = data; /* FIX: Assign a value to the thing pointed to by pointer */
            {
                int * data = *pointer;
                printIntLine(*data);
            }
        }
    }
}

void CWE758_Undefined_Behavior__int_pointer_alloca_use_04_good()
{
    good1();
    good2();
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
    CWE758_Undefined_Behavior__int_pointer_alloca_use_04_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE758_Undefined_Behavior__int_pointer_alloca_use_04_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif