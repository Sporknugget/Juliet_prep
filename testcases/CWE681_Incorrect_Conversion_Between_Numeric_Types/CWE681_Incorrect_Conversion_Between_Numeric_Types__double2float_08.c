/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE681_Incorrect_Conversion_Between_Numeric_Types__double2float_08.c
Label Definition File: CWE681_Incorrect_Conversion_Between_Numeric_Types.label.xml
Template File: point-flaw-08.tmpl.c
*/
/*
 * @description
 * CWE: 681 Incorrect Conversion Between Numeric Types
 * Sinks: double2float
 *    GoodSink: check for conversion error
 *    BadSink : explicit cast
 * Flow Variant: 08 Control flow: if(staticReturnsTrue()) and if(staticReturnsFalse())
 *
 * */

#include "std_testcase.h"

#include <float.h>
#define CHAR_ARRAY_SIZE 256

/* The two function below always return the same value, so a tool
   should be able to identify that calls to the functions will always
   return a fixed value. */
static int staticReturnsTrue()
{
    return 1;
}

static int staticReturnsFalse()
{
    return 0;
}

#ifndef OMITBAD

void CWE681_Incorrect_Conversion_Between_Numeric_Types__double2float_08_bad()
{

    {
        {
            char inputBuffer[CHAR_ARRAY_SIZE];
            double doubleNumber = 0;
            /* Enter: 1e-50, result should be 0.0 (for bad case)
             *
             * Note: alternate input
             * 999999999999999999999999999999999999999999999999999999999999999
             */
            if (fgets(inputBuffer, CHAR_ARRAY_SIZE, stdin) != NULL)
            {
                /* Read a double */
                doubleNumber = atof(inputBuffer);
            }
            else
            {
                printLine("fgets() failed.");
            }
            /* FLAW: should not cast without checking if conversion is safe */
            printFloatLine((float)doubleNumber);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD










    {
        {
            char inputBuffer[CHAR_ARRAY_SIZE];
            double doubleNumber = 0;
            /* Enter: 1e-50, result should be 0.0 (for bad case)
             *
             * Note: alternate input
             * 999999999999999999999999999999999999999999999999999999999999999
             */
            if (fgets(inputBuffer, CHAR_ARRAY_SIZE, stdin) != NULL)
            {
                /* Read a double */
                doubleNumber = atof(inputBuffer);
            }
            else
            {
                printLine("fgets() failed.");
            }
            /* FIX: check to make sure conversion is safe */
            if (doubleNumber > FLT_MAX || doubleNumber < FLT_MIN)
            {
                printLine("Value is too small or large to be represented as a float");
            }
            else
            {
                printFloatLine((float)doubleNumber);
            }
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{

    {
        {
            char inputBuffer[CHAR_ARRAY_SIZE];
            double doubleNumber = 0;
            /* Enter: 1e-50, result should be 0.0 (for bad case)
             *
             * Note: alternate input
             * 999999999999999999999999999999999999999999999999999999999999999
             */
            if (fgets(inputBuffer, CHAR_ARRAY_SIZE, stdin) != NULL)
            {
                /* Read a double */
                doubleNumber = atof(inputBuffer);
            }
            else
            {
                printLine("fgets() failed.");
            }
            /* FIX: check to make sure conversion is safe */
            if (doubleNumber > FLT_MAX || doubleNumber < FLT_MIN)
            {
                printLine("Value is too small or large to be represented as a float");
            }
            else
            {
                printFloatLine((float)doubleNumber);
            }
        }
    }
}

void CWE681_Incorrect_Conversion_Between_Numeric_Types__double2float_08_good()
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
    CWE681_Incorrect_Conversion_Between_Numeric_Types__double2float_08_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE681_Incorrect_Conversion_Between_Numeric_Types__double2float_08_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
