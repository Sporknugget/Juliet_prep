/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE272_Least_Privilege_Violation__w32_char_SHRegOpenUSKey_07.c
Label Definition File: CWE272_Least_Privilege_Violation__w32.label.xml
Template File: point-flaw-07.tmpl.c
*/
/*
 * @description
 * CWE: 272 Least Privilege Violation
 * Sinks: SHRegOpenUSKey
 *    GoodSink: Open a registry key using SHRegOpenUSKeyA() and HKEY_CURRENT_USER
 *    BadSink : Open a registry key using SHRegOpenUSKeyA() and HKEY_LOCAL_MACHINE
 * Flow Variant: 07 Control flow: if(staticFive==5) and if(staticFive!=5)
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#include <shlwapi.h>
#pragma comment( lib, "shlwapi" )

/* The variable below is not declared "const", but is never assigned
   any other value so a tool should be able to identify that reads of
   this will always give its initialized value. */
static int staticFive = 5;

#ifndef OMITBAD

void CWE272_Least_Privilege_Violation__w32_char_SHRegOpenUSKey_07_bad()
{

    {
        {
            char * keyName = "TEST\\TestKey";
            HUSKEY hKey;
            /* FLAW: Call SHRegOpenUSKeyA() with HKEY_LOCAL_MACHINE (fIgnoreHKCU == TRUE) violating the least privilege principal */
            if (SHRegOpenUSKeyA(
                        keyName,
                        KEY_WRITE,
                        NULL,
                        &hKey,
                        TRUE) != ERROR_SUCCESS)
            {
                printLine("Registry key could not be opened");
            }
            else
            {
                printLine("Registry key opened successfully");
                SHRegCloseUSKey(hKey);
            }
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD










    {
        {
            char * keyName = "TEST\\TestKey";
            HUSKEY hKey;
            /* FIX: Call SHRegOpenUSKeyA() with HKEY_CURRENT_USER (fIgnoreHKCU == FALSE) */
            if (SHRegOpenUSKeyA(
                        keyName,
                        KEY_WRITE,
                        NULL,
                        &hKey,
                        FALSE) != ERROR_SUCCESS)
            {
                printLine("Registry key could not be opened");
            }
            else
            {
                printLine("Registry key opened successfully");
                SHRegCloseUSKey(hKey);
            }
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{

    {
        {
            char * keyName = "TEST\\TestKey";
            HUSKEY hKey;
            /* FIX: Call SHRegOpenUSKeyA() with HKEY_CURRENT_USER (fIgnoreHKCU == FALSE) */
            if (SHRegOpenUSKeyA(
                        keyName,
                        KEY_WRITE,
                        NULL,
                        &hKey,
                        FALSE) != ERROR_SUCCESS)
            {
                printLine("Registry key could not be opened");
            }
            else
            {
                printLine("Registry key opened successfully");
                SHRegCloseUSKey(hKey);
            }
        }
    }
}

void CWE272_Least_Privilege_Violation__w32_char_SHRegOpenUSKey_07_good()
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
    CWE272_Least_Privilege_Violation__w32_char_SHRegOpenUSKey_07_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE272_Least_Privilege_Violation__w32_char_SHRegOpenUSKey_07_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
