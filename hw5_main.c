#include "hw5.h"

#include <stdio.h>

int clean_stdin() {
    while (getchar() != '\n') {
    }
    return(1);
}

int main() {
    int func = 0;
    char nl = 0;

    while (func != 5) {
        printf("Choose a function to test:\n");
        printf("  1) cosine_sim()\n");
        printf("  2) read_file()\n");
        printf("  3) compare_users()\n");
        printf("  4) estimate_rating()\n");
        printf("  5) exit\n");

        scanf("%d%c", &func, &nl);

        if (func == 1) {
            vec_type v1, v2;

            printf("Enter a double to the hundredth for the 0th value in vector 1: ");
            scanf ("%lf%c", &(v1.array.v[0]), &nl);
            printf("Enter a double to the hundredth for the 1st value in vector 1: ");
            scanf ("%lf%c", &(v1.array.v[1]), &nl);
            printf("Enter a double to the hundredth for the 2nd value in vector 1: ");
            scanf ("%lf%c", &(v1.array.v[2]), &nl);

            printf("Enter a double to the hundredth for the 0th value in vector 2: ");
            scanf ("%lf%c", &(v2.array.v[0]), &nl);
            printf("Enter a double to the hundredth for the 1st value in vector 2: ");
            scanf ("%lf%c", &(v2.array.v[1]), &nl);
            printf("Enter a double to the hundredth for the 2nd value in vector 2: ");
            scanf ("%lf%c", &(v2.array.v[2]), &nl);

            double output = cosine_sim(v1, v2);
            printf("The cosine similarity value from the result of your cosine_sim() function is: %.2f\n", output);
        }
        else if (func == 2) {
            printf("Please enter the file name you wish to open: ");
            char filename[MAX_NAME_LEN];
            scanf("%[^\n]", filename);

            int output = read_file(filename);
            printf("The value from your read_file() function is: %d\n", output);
            printf("The number of users you read is: %lu\n", g_num_users);
            for (int i = 0; i < g_num_users; i++) {
                printf("\tAt index %d of g_user_database,\n", i);
                printf("\t\tthe id is %ld,\n", g_user_database[i].id);
                printf("\t\tthe username is %s,\n", g_user_database[i].user_name);
                printf("\t\tthe gender is %d,\n", g_user_database[i].gender);
                vec_type ratings = g_user_database[i].movie_ratings;
                printf("\t\tthe movie ratings are %.2f, %.2f, %.2f.\n", ratings.array.v[0], ratings.array.v[1], ratings.array.v[2]);
            }
        }
        else if (func == 3) {
            user u1, u2;
            char tmp_gender;

            // FIRST USER

            printf("Enter a long integer for the id of the first user: ");
            scanf ("%lu%c", &u1.id, &nl);
            printf("Enter a string for the username of the first user: ");
            scanf ("%[^\n]", u1.user_name);

            gender1:
            printf("Enter a gender for the first user (m=MALE, f=FEMALE, o=OTHER): ");
            scanf ("%c%c", &tmp_gender, &nl);

            switch (tmp_gender) {
                case 'm':
                    u1.gender = MALE;
                    break;
                case 'f':
                    u1.gender = FEMALE;
                    break;
                case 'o':
                    u1.gender = OTHER;
                    break;
                default:
                    printf("Please enter a valid gender! Must be m, f, or o.\n");
                    goto gender1;
                    break;
            }

            printf("Enter a double to the hundredth for the first movie rating for the first user: ");
            scanf ("%lf%c", &u1.movie_ratings.array.v[0], &nl);
            printf("Enter a double to the hundredth for the second movie rating for the first user: ");
            scanf ("%lf%c", &u1.movie_ratings.array.v[1], &nl);
            printf("Enter a double to the hundredth for the third movie rating for the first user: ");
            scanf ("%lf%c", &u1.movie_ratings.array.v[2], &nl);

            // SECOND USER

            printf("Enter a long integer for the id of the second user: ");
            scanf ("%lu%c", &u2.id, &nl);
            printf("Enter a string for the username of the second user: ");
            scanf ("%[^\n]", u2.user_name);

            gender2:
            printf("Enter a gender for the second user (m=MALE, f=FEMALE, o=OTHER): ");
            scanf ("%c%c", &tmp_gender, &nl);

            switch (tmp_gender) {
                case 'm':
                    u2.gender = MALE;
                    break;
                case 'f':
                    u2.gender = FEMALE;
                    break;
                case 'o':
                    u2.gender = OTHER;
                    break;
                default:
                    printf("Please enter a valid gender! Must be m, f, or o.\n");
                    goto gender2;
                    break;
            }

            printf("Enter a double to the hundredth for the first movie rating for the second user: ");
            scanf ("%lf%c", &u2.movie_ratings.array.v[0], &nl);
            printf("Enter a double to the hundredth for the second movie rating for the second user: ");
            scanf ("%lf%c", &u2.movie_ratings.array.v[1], &nl);
            printf("Enter a double to the hundredth for the third movie rating for the second user: ");
            scanf ("%lf%c", &u2.movie_ratings.array.v[2], &nl);



            double output = compare_users(u1, u2);
            printf("The value from the result of your compare_users() function is: %.2f\n", output);
        }
        else if (func == 4) {
            int user_num;
            double *ratings = (double*) malloc(sizeof(double) * g_num_users);

            printf("Enter an integer for the user_num: ");
            scanf ("%d%c", &user_num, &nl);
            printf("Enter %lu number of double(s) for the ratings:\n", g_num_users);
            for (int i = 0; i < g_num_users; i++) {
                printf("Rating number %d: ", (i + 1));
                scanf ("%lf%c", &(ratings[i]), &nl);
            }

            double output = estimate_rating(user_num, ratings);
            printf("The value from the result of your estimate_rating() function is: %.2f\n", output);
            free(ratings);
        }
        else if (func == 5) {
            break;
        }
        else {
            printf("Please select one of the options.\n");
        }
    }
}


