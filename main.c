#include "hw4.h"

#include <stdio.h>

int clean_stdin() {
    while (getchar() != '\n') {
    }
    return(1);
}

int main() {
    int func = 0;
    char nl = 0;
    int output = 0;

    while (func != 9) {
        printf("Choose a function to test:\n");
        printf("  1) add()\n");
        printf("  2) multiply()\n");
        printf("  3) dot()\n");
        printf("  4) cross()\n");
        printf("  5) magnitude()\n");
        printf("  6) project()\n");
        printf("  7) unit_vec()\n");
        printf("  8) cosine_sim()\n");
        printf("  9) exit\n");

        scanf("%d%c", &func, &nl);

        if (func == 1) {
            double p1_x;
            double p1_y;
            double p1_z;
            double p2_x;
            double p2_y;
            double p2_z;

            printf("Enter a double to the hundredth for the x value in point 1: ");
            scanf ("%lf%c", &p1_x, &nl);
            printf("Enter a double to the hundredth for the y value in point 1: ");
            scanf ("%lf%c", &p1_y, &nl);
            printf("Enter a double to the hundredth for the z value in point 1: ");
            scanf ("%lf%c", &p1_z, &nl);
            printf("Enter a double to the hundredth for the x value in point 2: ");
            scanf ("%lf%c", &p2_x, &nl);
            printf("Enter a double to the hundredth for the y value in point 2: ");
            scanf ("%lf%c", &p2_y, &nl);
            printf("Enter a double to the hundredth for the z value in point 2: ");
            scanf ("%lf%c", &p2_z, &nl);

            point p1 = {p1_x, p1_y, p1_z};
            point p2 = {p2_x, p2_y, p2_z};

            point sum = add(p1, p2);
            double p_x = sum.x;
            double p_y = sum.y;
            double p_z = sum.z;
            printf("The x value from the result of your add() function is: %.2f\n", p_x);
            printf("The y value from the result of your add() function is: %.2f\n", p_y);
            printf("The z value from the result of your add() function is: %.2f\n", p_z);
        }
        else if (func == 2) {
            double p1_x;
            double p1_y;
            double p1_z;
            double d;

            printf("Enter a double to the hundredth for the x value in point 1: ");
            scanf ("%lf%c", &p1_x, &nl);
            printf("Enter a double to the hundredth for the y value in point 1: ");
            scanf ("%lf%c", &p1_y, &nl);
            printf("Enter a double to the hundredth for the z value in point 1: ");
            scanf ("%lf%c", &p1_z, &nl);
            printf("Enter a double to the hundredth to multiply by: ");
            scanf ("%lf%c", &d, &nl);

            point p1 = {p1_x, p1_y, p1_z};

            point product = multiply(p1, d);
            double p_x = product.x;
            double p_y = product.y;
            double p_z = product.z;
            printf("The x value from the result of your multiply() function is: %.2f\n", p_x);
            printf("The y value from the result of your multiply() function is: %.2f\n", p_y);
            printf("The z value from the result of your multiply() function is: %.2f\n", p_z);
        }
        else if (func == 3) {
            double p1_x;
            double p1_y;
            double p1_z;
            double p2_x;
            double p2_y;
            double p2_z;

            printf("Enter a double to the hundredth for the x value in point 1: ");
            scanf ("%lf%c", &p1_x, &nl);
            printf("Enter a double to the hundredth for the y value in point 1: ");
            scanf ("%lf%c", &p1_y, &nl);
            printf("Enter a double to the hundredth for the z value in point 1: ");
            scanf ("%lf%c", &p1_z, &nl);
            printf("Enter a double to the hundredth for the x value in point 2: ");
            scanf ("%lf%c", &p2_x, &nl);
            printf("Enter a double to the hundredth for the y value in point 2: ");
            scanf ("%lf%c", &p2_y, &nl);
            printf("Enter a double to the hundredth for the z value in point 2: ");
            scanf ("%lf%c", &p2_z, &nl);

            point p1 = {p1_x, p1_y, p1_z};
            point p2 = {p2_x, p2_y, p2_z};

            double dot_product  = dot(p1, p2);
            printf("The dot product result of your dot() function is: %.2f\n", dot_product);
        }
        else if (func == 4) {
            double v1_x;
            double v1_y;
            double v1_z;
            double v2_x;
            double v2_y;
            double v2_z;

            printf("Enter a double to the hundredth for the x value in vector 1: ");
            scanf ("%lf%c", &v1_x, &nl);
            printf("Enter a double to the hundredth for the y value in vector 1: ");
            scanf ("%lf%c", &v1_y, &nl);
            printf("Enter a double to the hundredth for the z value in vector 1: ");
            scanf ("%lf%c", &v1_z, &nl);
            printf("Enter a double to the hundredth for the x value in vector 2: ");
            scanf ("%lf%c", &v2_x, &nl);
            printf("Enter a double to the hundredth for the y value in vector 2: ");
            scanf ("%lf%c", &v2_y, &nl);
            printf("Enter a double to the hundredth for the z value in vector 2: ");
            scanf ("%lf%c", &v2_z, &nl);

            vector v1 = {v1_x, v1_y, v1_z};
            vector v2 = {v2_x, v2_y, v2_z};

            vector cross_product = cross(v1, v2);
            double v_x = cross_product.x;
            double v_y = cross_product.y;
            double v_z = cross_product.z;
            printf("The x value from the result of your cross() function is: %.2f\n", v_x);
            printf("The y value from the result of your cross() function is: %.2f\n", v_y);
            printf("The z value from the result of your cross() function is: %.2f\n", v_z);
        }
        else if (func == 5) {
            double p_x;
            double p_y;
            double p_z;

            printf("Enter a double to the hundredth for the x value in your point: ");
            scanf ("%lf%c", &p_x, &nl);
            printf("Enter a double to the hundredth for the y value in your point: ");
            scanf ("%lf%c", &p_y, &nl);
            printf("Enter a double to the hundredth for the z value in your point: ");
            scanf ("%lf%c", &p_z, &nl);

            point p = {p_x, p_y, p_z};

            double output = magnitude(p);
            printf("The value from your magnitude() function is: %.2f\n", output);
        }
        else if (func == 6) {
            double v1_x;
            double v1_y;
            double v1_z;
            double v2_x;
            double v2_y;
            double v2_z;

            printf("Enter a double to the hundredth for the x value in vector 1: ");
            scanf ("%lf%c", &v1_x, &nl);
            printf("Enter a double to the hundredth for the y value in vector 1: ");
            scanf ("%lf%c", &v1_y, &nl);
            printf("Enter a double to the hundredth for the z value in vector 1: ");
            scanf ("%lf%c", &v1_z, &nl);
            printf("Enter a double to the hundredth for the x value in vector 2: ");
            scanf ("%lf%c", &v2_x, &nl);
            printf("Enter a double to the hundredth for the y value in vector 2: ");
            scanf ("%lf%c", &v2_y, &nl);
            printf("Enter a double to the hundredth for the z value in vector 2: ");
            scanf ("%lf%c", &v2_z, &nl);

            vector v1 = {v1_x, v1_y, v1_z};
            vector v2 = {v2_x, v2_y, v2_z};

            vector projection = project(v1, v2);
            double v_x = projection.x;
            double v_y = projection.y;
            double v_z = projection.z;
            printf("The x value from the result of your project() function is: %.2f\n", v_x);
            printf("The y value from the result of your project() function is: %.2f\n", v_y);
            printf("The z value from the result of your project() function is: %.2f\n", v_z);
        }
        else if (func == 7) {
            double p1_x;
            double p1_y;
            double p1_z;
            double p2_x;
            double p2_y;
            double p2_z;

            printf("Enter a double to the hundredth for the x value in point 1: ");
            scanf ("%lf%c", &p1_x, &nl);
            printf("Enter a double to the hundredth for the y value in point 1: ");
            scanf ("%lf%c", &p1_y, &nl);
            printf("Enter a double to the hundredth for the z value in point 1: ");
            scanf ("%lf%c", &p1_z, &nl);
            printf("Enter a double to the hundredth for the x value in point 2: ");
            scanf ("%lf%c", &p2_x, &nl);
            printf("Enter a double to the hundredth for the y value in point 2: ");
            scanf ("%lf%c", &p2_y, &nl);
            printf("Enter a double to the hundredth for the z value in point 2: ");
            scanf ("%lf%c", &p2_z, &nl);

            point p1 = {p1_x, p1_y, p1_z};
            point p2 = {p2_x, p2_y, p2_z};

            vector unit_vector = unit_vec(p1, p2);
            double v_x = unit_vector.x;
            double v_y = unit_vector.y;
            double v_z = unit_vector.z;
            printf("The x value from the result of your unit_vec() function is: %.2f\n", v_x);
            printf("The y value from the result of your unit_vec() function is: %.2f\n", v_y);
            printf("The z value from the result of your unit_vec() function is: %.2f\n", v_z);
        }
        else if (func == 8) {
            double v1_x;
            double v1_y;
            double v1_z;
            double v2_x;
            double v2_y;
            double v2_z;

            printf("Enter a double to the hundredth for the x value in vector 1: ");
            scanf ("%lf%c", &v1_x, &nl);
            printf("Enter a double to the hundredth for the y value in vector 1: ");
            scanf ("%lf%c", &v1_y, &nl);
            printf("Enter a double to the hundredth for the z value in vector 1: ");
            scanf ("%lf%c", &v1_z, &nl);
            printf("Enter a double to the hundredth for the x value in vector 2: ");
            scanf ("%lf%c", &v2_x, &nl);
            printf("Enter a double to the hundredth for the y value in vector 2: ");
            scanf ("%lf%c", &v2_y, &nl);
            printf("Enter a double to the hundredth for the z value in vector 2: ");
            scanf ("%lf%c", &v2_z, &nl);

            vector v1 = {v1_x, v1_y, v1_z};
            vector v2 = {v2_x, v2_y, v2_z};

            double output = cosine_sim(v1, v2);
            printf("The cosine similarity value from the result of your cosine_sim() function is: %.2f\n", output);
        }
        else if (func == 9) {
            break;
        }
        else {
            printf("Please select one of the options.\n");
        }
    }
}



