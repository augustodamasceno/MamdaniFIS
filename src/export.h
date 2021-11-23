/* Mamdani Fuzzy Inference System.
 *
 * Copyright (c) 2021, Augusto Damasceno.
 * All rights reserved.
 */ 

#ifndef _EXPORT_H
#define _EXPORT_H

#define GENERATE_CSV_FILENAME "membershipFunctions.csv"


/* Writes in the standard output a CSV with n evenly 
   spaced points from all Membership Functions in a interval [a, b].
   The Membership Functions are configured to be centralized.

   The first line is the name of the columns:
    x, Membership_Function_1, Membership_Function_2 ... 
*/
void printCSV(float a, float b, unsigned int n);

/* Writes the file GENERATE_CSV_FILENAME with n evenly 
   spaced points from all Membership Functions in a interval [a, b].
   The Membership Functions are configured to be centralized.

   The first line is the name of the columns:
    x, Membership_Function_1, Membership_Function_2 ... 

   Return:
     1 if success
     0 if error opening the file in write mode.
*/
int generateCSV(float a, float b, unsigned int n);

#endif /* _EXPORT_H */

