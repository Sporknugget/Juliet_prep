/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__new_delete_wchar_t_14.cpp
Label Definition File: CWE415_Double_Free__new_delete.label.xml
Template File: sources-sinks-14.tmpl.cpp
*/
/*
 * @description
 * CWE: 415 Double Free
 * BadSource:  Allocate data using new and Deallocae data using delete
 * GoodSource: Allocate data using new
 * Sinks:
 *    GoodSink: do nothing
 *    BadSink : Deallocate data using delete
 * Flow Variant: 14 Control flow: if(globalFive==5) and if(globalFive!=5)
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE415_Double_Free__new_delete_wchar_t_14
{

#ifndef OMITBAD

void bad()
{
    wchar_t * data;
    /* Initialize data */
    data = NULL;

    {
        data = new wchar_t;
        /* POTENTIAL FLAW: delete data in the source - the bad sink deletes data as well */
        delete data;
    }

    {
        /* POTENTIAL FLAW: Possibly deleting memory twice */
        delete data;
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G1() - use badsource and goodsink by changing the second globalFive==5 to globalFive!=5 */
static void goodB2G1()
{
    wchar_t * data;
    /* Initialize data */
    data = NULL;

    {
        data = new wchar_t;
        /* POTENTIAL FLAW: delete data in the source - the bad sink deletes data as well */
        delete data;
    }






    {
        /* do nothing */
        /* FIX: Don't attempt to delete the memory */
        ; /* empty statement needed for some flow variants */
    }
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second if */
static void goodB2G2()
{
    wchar_t * data;
    /* Initialize data */
    data = NULL;

    {
        data = new wchar_t;
        /* POTENTIAL FLAW: delete data in the source - the bad sink deletes data as well */
        delete data;
    }

    {
        /* do nothing */
        /* FIX: Don't attempt to delete the memory */
        ; /* empty statement needed for some flow variants */
    }
}

/* goodG2B1() - use goodsource and badsink by changing the first globalFive==5 to globalFive!=5 */
static void goodG2B1()
{
    wchar_t * data;
    /* Initialize data */
    data = NULL;






    {
        data = new wchar_t;
        /* FIX: Do NOT delete data in the source - the bad sink deletes data */
    }

    {
        /* POTENTIAL FLAW: Possibly deleting memory twice */
        delete data;
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first if */
static void goodG2B2()
{
    wchar_t * data;
    /* Initialize data */
    data = NULL;

    {
        data = new wchar_t;
        /* FIX: Do NOT delete data in the source - the bad sink deletes data */
    }

    {
        /* POTENTIAL FLAW: Possibly deleting memory twice */
        delete data;
    }
}

void good()
{
    goodB2G1();
    goodB2G2();
    goodG2B1();
    goodG2B2();
}

#endif /* OMITGOOD */

} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE415_Double_Free__new_delete_wchar_t_14; /* so that we can use good and bad easily */

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif