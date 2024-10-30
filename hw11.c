/*
 * CS 240 - Fall 2023 - Suresh Jagannathan
 * Please type your name in place of <Edythe Thompson> to verify that you will
 * not cheat on this homework.
 *
 * Academic Honesty Pledge:
 * I certify that this code is of my own original work, and not that of other
 * students. online services, or other dishonesty. If I need help on homework,
 * I will ask a TA or the professor.
 *
 * Signed, <Edythe Thompson>
 */

/* Put your #define macros here */

#define mag(v) (sqrt((v).x*(v).x + (v).y*(v).y + (v).z*(v).z));

/* Put your #include statements here */
#include <math.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <signal.h>
#include <setjmp.h>
#include <stddef.h>
#include <inttypes.h>
#include <stdio.h>
#include "hw11.h"
#include ".hw11_secret.h"

/* Note: The mag() test will not work if you define it after this point */

int g_segv_trip = -1;
jmp_buf env;

/*Recursively finds the fibonacci number of n for n < 92*/
uint64_t fib(int n) {
  if (n <= 0) {
    return 0;
  }
  if (n > 92) {
    return UINT64_MAX;
  } else {
    if (n == 1 || n == 2) {
      return 1;
    } else {
      int fib_total = fib(n - 1) + fib(n - 2);
      return fib_total;

    }
  }
} /*fib*/

/*Recursively finds the factorial of n if n < 20*/
uint64_t fact(int n) {
  if (n < 0) {
    return 0;
  }
  if (n > 20) {
    return UINT64_MAX;
  } else {
    if (n == 0) {
      return 1;
    } else {
      uint64_t total = n * fact(n - 1);
      return total;
    }
  }
} /*fact*/


/*Segmentation fault handler*/
void sig_segv_handler(int s) {
  g_segv_trip = 1;
  sigsignal(SIGSEGV, SIG_DFL);
  longjmp(env, 1);
} /*sig_segv_handler*/

/*Function to run math functions safely without seg faulting*/
int32_t run_safely(func f, int64_t argv[], size_t argc) {
  g_segv_trip = 0;
  sigsetjmp(env, 1);
  signal(SIGSEGV, sig_segv_handler);
  if (g_segv_trip == 1) {
    return -1;
  } else {
    return f(argv, argc);
  }
} /*run_safely*/





