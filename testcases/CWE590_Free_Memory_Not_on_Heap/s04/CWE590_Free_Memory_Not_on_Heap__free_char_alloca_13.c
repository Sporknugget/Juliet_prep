/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Memory_Not_on_Heap__free_char_alloca_13.c
Label Definition File: CWE590_Free_Memory_Not_on_Heap__free.label.xml
Template File: sources-sink-13.tmpl.c
*/
/*
 * @description
 * CWE: 590 Free Memory Not on Heap
 * BadSource: alloca Data buffer is allocated on the stack with alloca()
 * GoodSource: Allocate memory on the heap
 * Sink:
 *    BadSink : Print then free data
 * Flow Variant: 13 Control flow: if(GLOBAL_CONST_FIVE==5) and if(GLOBAL_CONST_FIVE!=5)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE590_Free_Memory_Not_on_Heap__free_char_alloca_13_bad()
{
    char * data;
    data = NULL; /* Initialize data */

    {
        {
            /* FLAW: data is allocated on the stack and deallocated in the BadSink */
            char * dataBuffer = (char *)ALLOCA(100*sizeof(char));
            memset(dataBuffer, 'A', 100-1); /* fill with 'A's */
            dataBuffer[100-1] = '\0'; /* null terminate */
            data = dataBuffer;
        }
    }
    printLine(data);
    /* POTENTIAL FLAW: Possibly deallocating memory allocated on the stack */
    free(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B1() - use goodsource and badsink by changing the GLOBAL_CONST_FIVE==5 to GLOBAL_CONST_FIVE!=5 */
static void goodG2B1()
{
    char * data;
    data = NULL; /* Initialize data */






    {
        {
            /* FIX: data is allocated on the heap and deallocated in the BadSink */
            char * dataBuffer = (char *)malloc(100*sizeof(char));
            if (dataBuffer == NULL)
            {
                printLine("malloc() failed");
                exit(1);
            }
            memset(dataBuffer, 'A', 100-1); /* fill with 'A's */
            dataBuffer[100-1] = '\0'; /* null terminate */
            data = dataBuffer;
        }
    }
    printLine(data);
    /* POTENTIAL FLAW: Possibly deallocating memory allocated on the stack */
    free(data);
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the if statement */
static void goodG2B2()
{
    char * data;
    data = NULL; /* Initialize data */

    {
        {
            /* FIX: data is allocated on the heap and deallocated in the BadSink */
            char * dataBuffer = (char *)malloc(100*sizeof(char));
            if (dataBuffer == NULL)
            {
                printLine("malloc() failed");
                exit(1);
            }
            memset(dataBuffer, 'A', 100-1); /* fill with 'A's */
            dataBuffer[100-1] = '\0'; /* null terminate */
            data = dataBuffer;
        }
    }
    printLine(data);
    /* POTENTIAL FLAW: Possibly deallocating memory allocated on the stack */
    free(data);
}

void CWE590_Free_Memory_Not_on_Heap__free_char_alloca_13_good()
{
    goodG2B1();
    goodG2B2();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE590_Free_Memory_Not_on_Heap__free_char_alloca_13_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE590_Free_Memory_Not_on_Heap__free_char_alloca_13_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
