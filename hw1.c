
/*
 * CS 240 - Fall 2023 - Suresh Jagannathan
 *
 * Please type your name in place of <YOUR NAME HERE> to verify that you will
 * not cheat on this homework.
 *
 * Academic Honesty Pledge:
 * I certify that this code is of my own original work, and not that of other
 * students, online services, or other dishonesty. If I need help on homework,
 * I will ask a TA or the professor.
 *
 * Signed, <Edythe Thompson>
 */

/* Add any includes here */

#include "hw1.h"
#include <stddef.h>
/* Define any global variables here */

/* Define your functions here */

/*
 * Returns the sum of all elements in the array, up to size
 */

int sum(const int arr[], int size){

    int total = 0;
    for(int i = 0; i < size; i++){
        int cur = arr[i];
        total = total + cur;
    }
    return total;
} /* sum() */


/*
 * Returns the length of a C-style string
 */

int cs240strlen(char *str){
    int length = 0;
    for (int i = 0; str[i] != NULL; i++){
        length = length + 1;
    }
    return length;
} /* cs240strlen() */


/*
 * Changes every uppercase letter in a string to lowercase
 * This function modifies the original string and has no return value
 */

void cs240lower(char *str){

    for (int i = 0; str[i] != NULL; i++) {
        if (str[i] >= 65 && str[i] <= 90) {
            char new = str[i] + 32;
            str[i] = new;
        } else {
        }
        return;
    } /* cs240lower() */
