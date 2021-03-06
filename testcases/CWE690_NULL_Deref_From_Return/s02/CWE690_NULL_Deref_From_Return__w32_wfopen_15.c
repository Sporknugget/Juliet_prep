/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__w32_wfopen_15.c
Label Definition File: CWE690_NULL_Deref_From_Return.fclose.label.xml
Template File: source-sinks-15.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * BadSource: w32_wfopen Open data with wfopen()
 * Sinks: 0
 *    GoodSink: Check data for NULL
 *    BadSink : Do not check data for NULL
 * Flow Variant: 15 Control flow: switch(6)
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE690_NULL_Deref_From_Return__w32_wfopen_15_bad()
{
    FILE * data;
    /* Initialize data */
    data = NULL;
    /* POTENTIAL FLAW: Open a file without checking the return value for NULL */
    data = _wfopen(L"file.txt", L"w+");



        /* FLAW: if the fopen failed, data will be NULL here */
        fclose(data);






}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G1() - use badsource and goodsink by changing the switch to switch(5) */
static void goodB2G1()
{
    FILE * data;
    /* Initialize data */
    data = NULL;
    /* POTENTIAL FLAW: Open a file without checking the return value for NULL */
    data = _wfopen(L"file.txt", L"w+");







        /* FIX: check the return value */
        if (data != NULL)
        {
            fclose(data);
        }


}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the switch */
static void goodB2G2()
{
    FILE * data;
    /* Initialize data */
    data = NULL;
    /* POTENTIAL FLAW: Open a file without checking the return value for NULL */
    data = _wfopen(L"file.txt", L"w+");



        /* FIX: check the return value */
        if (data != NULL)
        {
            fclose(data);
        }






}

void CWE690_NULL_Deref_From_Return__w32_wfopen_15_good()
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
    CWE690_NULL_Deref_From_Return__w32_wfopen_15_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE690_NULL_Deref_From_Return__w32_wfopen_15_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
