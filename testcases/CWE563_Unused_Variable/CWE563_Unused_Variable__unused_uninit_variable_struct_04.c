/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE563_Unused_Variable__unused_uninit_variable_struct_04.c
Label Definition File: CWE563_Unused_Variable__unused_uninit_variable.label.xml
Template File: source-sinks-04.tmpl.c
*/
/*
 * @description
 * CWE: 563 Unused Variable
 * BadSource:  Initialize data
 * Sinks:
 *    GoodSink: Initialize, then use data
 *    BadSink : Do nothing
 * Flow Variant: 04 Control flow: if(STATIC_CONST_TRUE) and if(STATIC_CONST_FALSE)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

/* The two variables below are declared "const", so a tool should
   be able to identify that reads of these will always return their
   initialized values. */
static const int STATIC_CONST_TRUE = 1; /* true */
static const int STATIC_CONST_FALSE = 0; /* false */

#ifndef OMITBAD

void CWE563_Unused_Variable__unused_uninit_variable_struct_04_bad()
{
    twoIntsStruct data;
    /* POTENTIAL FLAW: Do not initialize or use data */
    ; /* empty statement needed for some flow variants */

    {
        /* FLAW: Do not use the variable */
        /* do nothing */
        ; /* empty statement needed for some flow variants */
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G1() - use badsource and goodsink by changing STATIC_CONST_TRUE to STATIC_CONST_FALSE */
static void goodB2G1()
{
    twoIntsStruct data;
    /* POTENTIAL FLAW: Do not initialize or use data */
    ; /* empty statement needed for some flow variants */






    {
        /* FIX: Initialize then use data */
        data.intOne = 0;
        data.intTwo = 0;
        printStructLine(&data);
    }
}

/* goodB2G2() - use badsource and goodsink by reversing statements in if  */
static void goodB2G2()
{
    twoIntsStruct data;
    /* POTENTIAL FLAW: Do not initialize or use data */
    ; /* empty statement needed for some flow variants */

    {
        /* FIX: Initialize then use data */
        data.intOne = 0;
        data.intTwo = 0;
        printStructLine(&data);
    }
}

void CWE563_Unused_Variable__unused_uninit_variable_struct_04_good()
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
    CWE563_Unused_Variable__unused_uninit_variable_struct_04_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE563_Unused_Variable__unused_uninit_variable_struct_04_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
