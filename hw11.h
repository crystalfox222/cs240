#ifndef HW11_H
#define HW11_H

#include <stdint.h>
#include <inttypes.h>
#include <stddef.h>
#include <signal.h>
#include <setjmp.h>

#define NOT_IN_LIST             (-1)
#define LL_SUCCESS              (-2)
#define GEN_LL_ERR              (-3)
#define NOT_IMPLEMENTED_ERR     (0xdeadbeef)

extern int g_segv_trip;
extern jmp_buf env;

struct s_point {
  double x;
  double y;
  double z;
};

typedef struct s_point point;
typedef struct s_point vector;
typedef int (*func)(int64_t[], size_t);

double student_mag(point v);
uint64_t fib(int32_t n);
uint64_t fact(int32_t n);
int32_t run_safely(func f, int64_t argv[], size_t argc);

#endif // HW11_H






