/* Mamdani Fuzzy Inference System.
 *
 * Copyright (c) 2021, Augusto Damasceno.
 * All rights reserved.
 */ 

#ifndef _MAMDANI_H
#define _MAMDANI_H

/* For all the implementations:
    Consider that x is a value that belongs to the universal set.
    The Fuzzy Sets are Type-1.
    Height is always 1.
*/

/* Membership Functions */
#define MF_TRIANGLE 0
#define MF_TRAPEZOIDAL 1
#define MF_GAUSSIAN 2


/* Logical Operators */
#define LO_OR_MAX 100
#define LO_AND_MIN 101
#define LO_NOT 102
#define LO_OR_SUM_PROD 103
#define LO_AND_PROD 104
#define LO_OR_PROBABILISTIC 105
#define max(A, B) ((A) > (B) ? (A) : (B))
#define min(A, B) ((A) < (B) ? (A) : (B))


/* Structs and Data Types for the Membership Functions */
/*
The point:
    a is the left,
    b the middle and
    c the rigth.
Support: ]a, c[
Core: b
*/
struct triangle {
    float a;
    float b;
    float c;
};
typedef struct triangle Triangle;

/*
The point:
    a is the bottom left,
    b the top left,
    c the top rigth and
    d the bottom rigth.
Support: ]a, d[
Core: [b, c]
*/
struct trapezoidal {
    float a;
    float b;
    float c;
    float d;
};
typedef struct trapezoidal Trapezoidal;

/*
The gaussian funcion is:
    e^( (-(x-mean)^2) / (2*std^2) )
Support(approximately): [mean-3*std, mean+3*std]
Core: mean
*/
struct gaussian {
    float mean;
    float std;
};
typedef struct gaussian Gaussian;


/* Create Objects of Membership Functions */
Triangle * newTriangle(float a, float b, float c);
Trapezoidal * newTrapezoidal(float a, float b, float c, float d);
Gaussian * newGaussian(float mean, float std);


/* Membership Functions Processors */
float mfTriangle(Triangle * triang, float x);
float mfTrapezoidal(Trapezoidal * trapez, float x);
float mfGaussian(Gaussian * gauss, float x);


/* Logical Operators Processors */
float orMax(float xA, float xB);
float andMin(float xA, float xB);
float not(float x);
float orSumProd(float xA, float xB);
float andProd(float xA, float xB);
float orProbabilistic(float xA, float xB);

#endif /* _MAMDANI_H */
