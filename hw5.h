#ifndef HW5_H
#define HW5_H

/* Included Libraries */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/* Constant Definitions */

#define MAX_NAME_LEN (128)

/* Error Codes */

#define MALFORMED_TABLE (-1)

/* Structs Definition */

struct s_point {
    double x;
    double y;
    double z;
};

struct s_array_3d {
    double v[3];
};

union u_vec_type {
    struct s_array_3d array;
    struct s_point point;
};

typedef union u_vec_type vec_type;

enum gender_t {
    MALE,
    FEMALE,
    OTHER
};

struct s_user {
    unsigned long int id;;
    char user_name[MAX_NAME_LEN];
    enum gender_t gender;
    vec_type movie_ratings;
};

typedef struct s_user user;

/* Function Prototypes */

double cosine_sim(vec_type, vec_type);
int read_file(char *);
double compare_users(user, user);
double estimate_rating(int, double[]);
void estimate_all_ratings(double[], char *);

/* Global Variables */

extern unsigned long int g_num_users;
extern user * g_user_database;

#pragma GCC poison access

#endif // HW5_H

