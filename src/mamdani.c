/* Mamdani Fuzzy Inference System.
 *
 * Copyright (c) 2021, Augusto Damasceno.
 * All rights reserved.
 */ 

#include "mamdani.h"
#include <math.h>
#include <stdlib.h>


/* Create Objects of Membership Functions */
Triangle * newTriangle(float a, float b, float c){
    Triangle * triang = (Triangle *) malloc(sizeof(Triangle));
    triang->a = a;
    triang->b = b;
    triang->c = c;

    return triang;
}

Trapezoidal * newTrapezoidal(float a, float b, float c, float d){
    Trapezoidal * trapez = (Trapezoidal *) malloc(sizeof(Trapezoidal));
    trapez->a = a;
    trapez->b = b;
    trapez->c = c;
    trapez->d = d;

    return trapez;
}

Gaussian * newGaussian(float mean, float std){
    Gaussian * gauss = (Gaussian *) malloc(sizeof(Gaussian));
    gauss->mean = mean;
    gauss->std = std;

    return gauss;
}


/* Membership Functions Processors */
float mfTriangle(Triangle * triang, float x){
    float degree = 0;
    if (x >= triang->a && x <= triang->c){
        /* By the slope*/
        if (x <= triang->b){
            degree = (x-triang->a) / (triang->b-triang->a);
        } else {
            degree = (triang->c-x) / (triang->c-triang->b);
        }
    }
    return degree;
}

float mfTrapezoidal(Trapezoidal * trapez, float x){
    float degree = 0;
    if (x >= trapez->a && x <= trapez->d){
        if (x >= trapez->b && x <= trapez->c){
            degree = 1;
        } else if (x <= trapez->b){
            degree = (x-trapez->a) / (trapez->b-trapez->a);
        } else {
            degree = (trapez->d-x) / (trapez->d-trapez->c);
        }
    }
    return degree;
}

float mfGaussian(Gaussian * gauss, float x){
    return exp( -1.0*pow(x-gauss->mean, 2.0)
        / (2.0*pow(gauss->std, 2.0)) );
}


/* Logical Operators Processors */
float orMax(float xA, float xB){
    return max(xA, xB);
}   

float andMin(float xA, float xB){
    return min(xA, xB);
}   

float not(float x){
    return 1.0-x;
}

float orSumProd(float xA, float xB){
    return xA*xB
};

float andProd(float xA, float xB){}

float orProbabilistic(float xA, float xB){
    return xA+xB - xA*xB;
}
