/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE284_Improper_Access_Control__w32_wchar_t_CreateWindowStation_14.c
Label Definition File: CWE284_Improper_Access_Control__w32.label.xml
Template File: point-flaw-14.tmpl.c
*/
/*
 * @description
 * CWE: 284 Improper Access Control
 * Sinks: CreateWindowStation
 *    GoodSink: Create a windows station using CreateWindowStationW() without excessive privileges
 *    BadSink : Create a windows station using CreateWindowStationW() with excessive privileges
 * Flow Variant: 14 Control flow: if(globalFive==5) and if(globalFive!=5)
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#pragma comment( lib, "user32" )

#ifndef OMITBAD

void CWE284_Improper_Access_Control__w32_wchar_t_CreateWindowStation_14_bad()
{

    {
        {
            HWINSTA hWinStation;
            wchar_t * wStationName = L"WindowsStationExample";
            /* FLAW: Call CreateWindowStationW() with GENERIC_ALL as the 3rd parameter */
            hWinStation = CreateWindowStationW(
                              wStationName,
                              0,
                              GENERIC_ALL,
                              NULL);
            if (hWinStation == NULL)
            {
                printLine("Windows station could not be created");
            }
            else
            {
                printLine("Windows Station created successfully");
                CloseWindowStation(hWinStation);
            }
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD










    {
        {
            HWINSTA hWinStation;
            wchar_t * wStationName = L"WindowsStationExample";
            /* FIX: Call CreateWindowStationW() without GENERIC_READ as the 3rd parameter to limit access */
            hWinStation = CreateWindowStationW(
                              wStationName,
                              0,
                              GENERIC_READ,
                              NULL);
            if (hWinStation == NULL)
            {
                printLine("Windows station could not be created");
            }
            else
            {
                printLine("Windows Station created successfully");
                CloseWindowStation(hWinStation);
            }
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{

    {
        {
            HWINSTA hWinStation;
            wchar_t * wStationName = L"WindowsStationExample";
            /* FIX: Call CreateWindowStationW() without GENERIC_READ as the 3rd parameter to limit access */
            hWinStation = CreateWindowStationW(
                              wStationName,
                              0,
                              GENERIC_READ,
                              NULL);
            if (hWinStation == NULL)
            {
                printLine("Windows station could not be created");
            }
            else
            {
                printLine("Windows Station created successfully");
                CloseWindowStation(hWinStation);
            }
        }
    }
}

void CWE284_Improper_Access_Control__w32_wchar_t_CreateWindowStation_14_good()
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
    CWE284_Improper_Access_Control__w32_wchar_t_CreateWindowStation_14_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE284_Improper_Access_Control__w32_wchar_t_CreateWindowStation_14_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
