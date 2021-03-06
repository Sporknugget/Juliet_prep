/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE667_Improper_Locking__basic_15.c
Label Definition File: CWE667_Improper_Locking__basic.label.xml
Template File: point-flaw-15.tmpl.c
*/
/*
 * @description
 * CWE: 667 Improper Locking
 * Sinks:
 *    GoodSink: Acquire a lock before releasing it
 *    BadSink : Release the lock before acquiring it
 * Flow Variant: 15 Control flow: switch(6)
 *
 * */

#include "std_testcase.h"

#include "std_thread.h"

#ifndef OMITBAD

void CWE667_Improper_Locking__basic_15_bad()
{



    {
        static stdThreadLock badLock = NULL;
        printLine("Creating lock...");
        if (!stdThreadLockCreate(&badLock))
        {
            printLine("Could not create lock");
            exit(1);
        }
        printLine("Acquiring lock...");
        stdThreadLockAcquire(badLock);
        /* FLAW: Do not release the lock */
    }






}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() changes the switch to switch(5) */
static void good1()
{







    {
        static stdThreadLock goodLock = NULL;
        printLine("Creating lock...");
        if (!stdThreadLockCreate(&goodLock))
        {
            printLine("Could not create lock");
            exit(1);
        }
        printLine("Acquiring lock...");
        stdThreadLockAcquire(goodLock);
        /* FIX: Release and destroy the lock */
        printLine("Releasing lock...");
        stdThreadLockRelease(goodLock);
        printLine("Destroying lock...");
        stdThreadLockDestroy(goodLock);
    }


}

/* good2() reverses the blocks in the switch */
static void good2()
{



    {
        static stdThreadLock goodLock = NULL;
        printLine("Creating lock...");
        if (!stdThreadLockCreate(&goodLock))
        {
            printLine("Could not create lock");
            exit(1);
        }
        printLine("Acquiring lock...");
        stdThreadLockAcquire(goodLock);
        /* FIX: Release and destroy the lock */
        printLine("Releasing lock...");
        stdThreadLockRelease(goodLock);
        printLine("Destroying lock...");
        stdThreadLockDestroy(goodLock);
    }






}

void CWE667_Improper_Locking__basic_15_good()
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
    CWE667_Improper_Locking__basic_15_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE667_Improper_Locking__basic_15_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
