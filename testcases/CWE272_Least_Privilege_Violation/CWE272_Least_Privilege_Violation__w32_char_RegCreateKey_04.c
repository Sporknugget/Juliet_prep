/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE272_Least_Privilege_Violation__w32_char_RegCreateKey_04.c
Label Definition File: CWE272_Least_Privilege_Violation__w32.label.xml
Template File: point-flaw-04.tmpl.c
*/
/*
 * @description
 * CWE: 272 Least Privilege Violation
 * Sinks: RegCreateKey
 *    GoodSink: Create a registry key using RegCreateKeyA() and HKEY_CURRENT_USER
 *    BadSink : Create a registry key using RegCreateKeyA() and HKEY_LOCAL_MACHINE
 * Flow Variant: 04 Control flow: if(STATIC_CONST_TRUE) and if(STATIC_CONST_FALSE)
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#pragma comment( lib, "advapi32" )

/* The two variables below are declared "const", so a tool should
   be able to identify that reads of these will always return their
   initialized values. */
static const int STATIC_CONST_TRUE = 1; /* true */
static const int STATIC_CONST_FALSE = 0; /* false */

#ifndef OMITBAD

void CWE272_Least_Privilege_Violation__w32_char_RegCreateKey_04_bad()
{

    {
        {
            char * keyName = "TEST\\TestKey";
            HKEY hKey;
            /* FLAW: Call RegCreateKeyA() with HKEY_LOCAL_MACHINE violating the least privilege principal */
            if (RegCreateKeyA(
                        HKEY_LOCAL_MACHINE,
                        keyName,
                        &hKey) != ERROR_SUCCESS)
            {
                printLine("Registry key could not be created");
            }
            else
            {
                printLine("Registry key created successfully");
                RegCloseKey(hKey);
            }
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD










    {
        {
            char * keyName = "TEST\\TestKey";
            HKEY hKey;
            /* FIX: Call RegCreateKeyA() with HKEY_CURRENT_USER */
            if (RegCreateKeyA(
                        HKEY_CURRENT_USER,
                        keyName,
                        &hKey) != ERROR_SUCCESS)
            {
                printLine("Registry key could not be created");
            }
            else
            {
                printLine("Registry key created successfully");
                RegCloseKey(hKey);
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
            HKEY hKey;
            /* FIX: Call RegCreateKeyA() with HKEY_CURRENT_USER */
            if (RegCreateKeyA(
                        HKEY_CURRENT_USER,
                        keyName,
                        &hKey) != ERROR_SUCCESS)
            {
                printLine("Registry key could not be created");
            }
            else
            {
                printLine("Registry key created successfully");
                RegCloseKey(hKey);
            }
        }
    }
}

void CWE272_Least_Privilege_Violation__w32_char_RegCreateKey_04_good()
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
    CWE272_Least_Privilege_Violation__w32_char_RegCreateKey_04_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE272_Least_Privilege_Violation__w32_char_RegCreateKey_04_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
