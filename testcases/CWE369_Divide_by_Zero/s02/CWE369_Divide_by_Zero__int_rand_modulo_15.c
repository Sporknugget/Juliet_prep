/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_by_Zero__int_rand_modulo_15.c
Label Definition File: CWE369_Divide_by_Zero__int.label.xml
Template File: sources-sinks-15.tmpl.c
*/
/*
 * @description
 * CWE: 369 Divide by Zero
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Non-zero
 * Sinks: modulo
 *    GoodSink: Check for zero before modulo
 *    BadSink : Modulo a constant with data
 * Flow Variant: 15 Control flow: switch(6) and switch(7)
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE369_Divide_by_Zero__int_rand_modulo_15_bad()
{
    int data;
    /* Initialize data */
    data = -1;



        /* POTENTIAL FLAW: Set data to a random value */
        data = RAND32();









        /* POTENTIAL FLAW: Possibly divide by zero */
        printIntLine(100 % data);






}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G1() - use badsource and goodsink by changing the second switch to switch(8) */
static void goodB2G1()
{
    int data;
    /* Initialize data */
    data = -1;



        /* POTENTIAL FLAW: Set data to a random value */
        data = RAND32();













        /* FIX: test for a zero denominator */
        if( data != 0 )
        {
            printIntLine(100 % data);
        }
        else
        {
            printLine("This would result in a divide by zero");
        }


}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second switch */
static void goodB2G2()
{
    int data;
    /* Initialize data */
    data = -1;



        /* POTENTIAL FLAW: Set data to a random value */
        data = RAND32();









        /* FIX: test for a zero denominator */
        if( data != 0 )
        {
            printIntLine(100 % data);
        }
        else
        {
            printLine("This would result in a divide by zero");
        }






}

/* goodG2B1() - use goodsource and badsink by changing the first switch to switch(5) */
static void goodG2B1()
{
    int data;
    /* Initialize data */
    data = -1;







        /* FIX: Use a value not equal to zero */
        data = 7;





        /* POTENTIAL FLAW: Possibly divide by zero */
        printIntLine(100 % data);






}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first switch */
static void goodG2B2()
{
    int data;
    /* Initialize data */
    data = -1;



        /* FIX: Use a value not equal to zero */
        data = 7;









        /* POTENTIAL FLAW: Possibly divide by zero */
        printIntLine(100 % data);






}

void CWE369_Divide_by_Zero__int_rand_modulo_15_good()
{
    goodB2G1();
    goodB2G2();
    goodG2B1();
    goodG2B2();
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
    CWE369_Divide_by_Zero__int_rand_modulo_15_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE369_Divide_by_Zero__int_rand_modulo_15_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
