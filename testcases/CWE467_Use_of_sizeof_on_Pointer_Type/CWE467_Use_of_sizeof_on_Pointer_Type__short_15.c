/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE467_Use_of_sizeof_on_Pointer_Type__short_15.c
Label Definition File: CWE467_Use_of_sizeof_on_Pointer_Type.label.xml
Template File: point-flaw-15.tmpl.c
*/
/*
 * @description
 * CWE: 467 Use of sizeof() on a Pointer Type
 * Sinks: short
 *    GoodSink: Use sizeof() the data type
 *    BadSink : Use sizeof() the pointer and not the data type
 * Flow Variant: 15 Control flow: switch(6)
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE467_Use_of_sizeof_on_Pointer_Type__short_15_bad()
{



    {
        short * badShort = NULL;
        /* FLAW: Using sizeof the pointer and not the data type in malloc() */
        badShort = (short *)malloc(sizeof(badShort));
        if (badShort == NULL) {exit(-1);}
        *badShort = 5;
        printShortLine(*badShort);
        free(badShort);
    }






}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() changes the switch to switch(5) */
static void good1()
{







    {
        short * goodShort = NULL;
        /* FIX: Using sizeof the data type in malloc() */
        goodShort = (short *)malloc(sizeof(*goodShort));
        if (goodShort == NULL) {exit(-1);}
        *goodShort = 6;
        printShortLine(*goodShort);
        free(goodShort);
    }


}

/* good2() reverses the blocks in the switch */
static void good2()
{



    {
        short * goodShort = NULL;
        /* FIX: Using sizeof the data type in malloc() */
        goodShort = (short *)malloc(sizeof(*goodShort));
        if (goodShort == NULL) {exit(-1);}
        *goodShort = 6;
        printShortLine(*goodShort);
        free(goodShort);
    }






}

void CWE467_Use_of_sizeof_on_Pointer_Type__short_15_good()
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
    CWE467_Use_of_sizeof_on_Pointer_Type__short_15_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE467_Use_of_sizeof_on_Pointer_Type__short_15_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
