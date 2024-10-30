#ifndef HW4_H
#define HW4_H

/* Included Libraries */

#include <math.h>
#include <stdio.h>

/* Constant Definitions */

#define VEC_NOT_IMPLEMENTED_ERR ((point){-999, -999, -999})
#define PT_NOT_IMPLEMENTED_ERR  ((vector){-999, -999, -999})
#define DBL_NOT_IMPLEMENTED_ERR (-999)

/* Structs Definition */

struct s_point {
    double x;
    double y;
    double z;
};

typedef struct s_point point;
typedef struct s_point vector;

/* Function Prototypes */

point add(point p1, point p2);
point multiply(point p, double f);
double dot(vector v1, vector v2);
vector cross(vector v1, vector v2);
double magnitude(point p);
vector project(vector v1, vector v2);
vector unit_vec(point p1, point p2);
double cosine_sim(vector v1, vector v2);

/* Global Variables */

#pragma GCC poison access

#endif


