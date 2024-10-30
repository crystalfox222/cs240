#ifndef HW3_H
#define HW3_H

/* Included Libraries */

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Constant Definitions */

#define MAX_NAME_LEN            (128)

/* Error Codes */

#define NO_SUCH_SPECIES         (-1)
#define BAD_POPULATION          (-2)
#define C_NO_SUCH_SPECIES       ("NO SUCH SPECIES")
#define NOT_IMPLEMENTED_ERR                     (-3)

/* Function Prototypes */

FILE * open_file(const char *, bool);
int get_current_population(FILE *, const char *);
int get_population_growth(FILE *, const char *);
char * get_species_origin(FILE *, const char *);
void set_largest_smallest_growth(FILE *, FILE *);

/* Global Variables */

extern char g_min_growth_species[MAX_NAME_LEN];
extern char g_max_growth_species[MAX_NAME_LEN];
extern char g_min_growth_country[MAX_NAME_LEN];
extern char g_max_growth_country[MAX_NAME_LEN];
extern int g_min_growth;
extern int g_max_growth;

#pragma GCC poison access

#endif


