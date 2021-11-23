/* Mamdani Fuzzy Inference System.
 *
 * Copyright (c) 2021, Augusto Damasceno.
 * All rights reserved.
 */ 

#include "export.h"
#include "mamdani.h"
#include <stdlib.h>
#include <stdio.h>


/* Writes in the standard output a CSV with n evenly 
   spaced points from all Membership Functions in a interval [a, b].
   The Membership Functions are configured to be centralized.

   The first line is the name of the columns:
    x, Membership_Function_1, Membership_Function_2 ... 
*/
void printCSV(float a, float b, unsigned int n){
    float middle = (b-a)/2.0;
    float third = (1.0/3.0)*(b-a);
    Triangle * triang = newTriangle(a, (b-a)/2.0, b);
    Trapezoidal * trapez = newTrapezoidal(a, third, 2.0*third,b);
    Gaussian * gauss = newGaussian(middle, 0.25);

    float step = (b-a) / (float) n;
    float x = a;
    printf("x,Triangle,Trapezoidal,Gaussian\n");
    int counter;
    for (counter=0; counter<n; counter++){
        printf("%.6f,%.6f,%.6f,%.6f\n"
            ,x
            ,mfTriangle(triang, x)
            ,mfTrapezoidal(trapez, x)
            ,mfGaussian(gauss, x));
        x += step;
    }

    free(triang);
    free(trapez);
    free(gauss);
}

/* Writes the file GENERATE_CSV_FILENAME with n evenly 
   spaced points from all Membership Functions in a interval [a, b].
   The Membership Functions are configured to be centralized.

   The first line is the name of the columns:
    x, Membership_Function_1, Membership_Function_2 ... 

   Return:
     1 if success
     0 if error opening the file in write mode.
*/
int generateCSV(float a, float b, unsigned int n){
    FILE * pCSV = fopen(GENERATE_CSV_FILENAME, "w");
    if (pCSV == NULL){
        printf("Error trying to open the file %s\n"
            , GENERATE_CSV_FILENAME);
        return 0;
    } else {
        float middle = (b-a)/2.0;
        float third = (1.0/3.0)*(b-a);
        Triangle * triang = newTriangle(a, (b-a)/2.0, b);
        Trapezoidal * trapez = newTrapezoidal(a, third, 2.0*third,b);
        Gaussian * gauss = newGaussian(middle, 0.25);

        float step = (b-a) / (float) n;
        float x = a;
        fprintf(pCSV, "x,Triangle,Trapezoidal,Gaussian\n");
        int counter;
        for (counter=0; counter<n; counter++){
            fprintf(pCSV, "%.6f,%.6f,%.6f,%.6f\n"
                ,x
                ,mfTriangle(triang, x)
                ,mfTrapezoidal(trapez, x)
                ,mfGaussian(gauss, x));
            x += step;
        }

        fclose(pCSV);
        free(triang);
        free(trapez);
        free(gauss);
        return 1;
    }
}