#include <stdio.h>


/* Add any includes here */

#include "hw3.h"

/* Define any global variables here */

char g_min_growth_species[MAX_NAME_LEN] = "";
char g_max_growth_species[MAX_NAME_LEN] = "";
char g_min_growth_country[MAX_NAME_LEN] = "";
char g_max_growth_country[MAX_NAME_LEN] = "";
int g_min_growth = INT_MAX;
int g_max_growth = INT_MIN;

/* Define your functions here */

/*
 * Open file in read mode if read is true, in write mode otherwise.
 * Return NULL if any error occurs.
 */

FILE *open_file(const char *input_filename, bool read) {
    if (read == true) {
        FILE *file = fopen(input_filename, "r");
        if (file == NULL) {
            return NULL;
        }

        return file;

    } else {
        FILE *file = fopen(input_filename, "w+");
        return file;
    }
} /* open_file() */

/*
 * Return the number of population in 2020 of specified species from the file.
 * Return the appropriate error code, otherwise.
 */

int get_current_population(FILE *infile, const char *species) {
    int pop;
    char spec[MAX_NAME_LEN];
    rewind(infile);
    while (fscanf(infile, "%[^;]; %*[^;]; %*d%*c %d%*c", spec, &pop) == 2) {
        printf("%s\n", spec);
        char *cor = spec;
        if (strcmp(species, cor) == 0) {
            if (pop <= 0) {
                fclose(infile);
                return BAD_POPULATION;
            }
            fclose(infile);
            return pop;
        }
    }
    fclose(infile);
    return NO_SUCH_SPECIES;
} /* get_current_population() */


/*
 * Return change in population between 2018 and 2020 of specified species from the file.
 */

int get_population_growth(FILE *infile, const char *species) {
    char spec[MAX_NAME_LEN];
    int past;
    int cur;
    int growth;
    rewind(infile);
    while (fscanf(infile, "%[^;];%*[^;];%d%*c%d%*c", spec, &past, &cur) == 3) {
        char *cor = spec;
        if (strcmp(species, cor) == 0) {
            if (past < 0 || cur < 0) {
                fclose(infile);
                return BAD_POPULATION;
            }
            growth = cur - past;
            fclose(infile);
            return growth;
        }
    }
    fclose(infile);
    return (int) NO_SUCH_SPECIES;
} /* get_population_growth() */

/*
 * Return the country of origin of the specified species from the file.
 * Return C_NO_SUCH_SPECIES if species is not found.
 */

char *get_species_origin(FILE *infile, const char *species) {
    char org[MAX_NAME_LEN];
    char spec[MAX_NAME_LEN];
    rewind(infile);
    while (fscanf(infile, "%[^;];%[^;];%*d%*c%*d%*c", spec, org) == 2) {
        char *cor = spec;
        if (strcmp(species, cor) == 0) {
            fclose(infile);
            return strdup(org);
        }
    }
    fclose(infile);
    return C_NO_SUCH_SPECIES;
} /* get_species_origin() */


/*
 * Write in the outfile the country with the most and least population of a species
 * between 2018 to 2020 from the infile.
 */

void set_largest_smallest_growth(FILE *infile, FILE *outfile) {
    int past;
    int cur;
    int growth;
    char spec[MAX_NAME_LEN];
    char country[MAX_NAME_LEN];
    rewind(infile);
    while (fscanf(infile, "%[^;];%[^;];%d%*c%d%*c", spec, country, &past, &cur) == 4) {
        growth = cur - past;
        if (growth < g_min_growth) {
            g_min_growth = growth;
            strcpy(g_min_growth_species, spec);
            strcpy(g_min_growth_country, country);
        }
        if (growth > g_max_growth) {
            g_max_growth = growth;
            strcpy(g_max_growth_species, spec);
            strcpy(g_max_growth_country, country);
        }
    }
    fprintf(outfile, "min_growth: %d %s %s\n", g_min_growth, g_min_growth_species, g_min_growth_country);
    fprintf(outfile, "max_growth: %d %s %s", g_max_growth, g_max_growth_species, g_max_growth_country);

    fclose(infile);
    fclose(outfile);
} /* set_largest_smallest_growth() */

int main() {
    printf("Hello, World!\n");
    FILE *file = open_file("faildata.txt", true);
    int pop = get_current_population(file, "Dolphin");
    printf("%d\n", pop);
    file = open_file("faildata.txt", true);
    char *org = get_species_origin(file, "Porcupine");
    printf("%s\n", org);
    file = open_file("faildata.txt", true);
    int popchange = get_population_growth(file, "Crocodile");
    printf("%d\n", popchange);
    file = open_file("faildata.txt", true);

    FILE *out = open_file("output.txt", false);
    set_largest_smallest_growth(file, out);
    return 0;
}
