/*
 * CS 240 - Fall 2023 - Suresh Jagannathan
 * Please type your name in place of <YOUR NAME HERE> to verify that you will
 * not cheat on this homework.
 *
 * Academic Honesty Pledge:
 * I certify that this code is of my own original work, and not that of other
 * students. online services, or other dishonesty. If I need help on homework,
 * I will ask a TA or the professor.
 *
 * Signed, <Edythe Thompson>
 */

/* Add any includes here */

#include "hw4.h"

#include <math.h>

/* Define any global variables here */

/* Define your functions here */

/*
 * Return the sum of the two points.
 */
point add(point p1, point p2) {
    struct s_point point;
    point.x = p1.x + p2.x;
    point.y = p1.y + p2.y;
    point.z = p1.z + p2.z;
    return point;
} /* add() */

/*
 * Return the product of the two points.
 */
point multiply(point p, double f) {
    struct s_point point;
    point.x = p.x * f;
    point.y = p.y * f;
    point.z = p.z * f;
    return point;
} /* multiply() */

/*
 * Return the dot product of the two vectors.
 */
double dot(vector v1, vector v2) {
    double dot;
    dot = ((v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z));
    return dot;
} /* dot() */

/*
 * Return the cross product of the two vectors.
 */
vector cross(vector v1, vector v2) {
    struct s_point vector;
    vector.x = ((v1.y * v2.z) - (v1.z * v2.y));
    vector.y = -((v1.x * v2.z) - (v1.z * v2.x));
    vector.z = ((v1.x * v2.y) - (v1.y * v2.x));
    return vector;
} /* cross() */

/*
 * Return the magnitude of the point.
 */
double magnitude(point p) {
    double mag = (p.x) * p.x + (p.y) * p.y + (p.z) * p.z;
    mag = sqrt(mag);
    return mag;
} /* magnitude() */

/*
 * Return the vector projection of vector v1 onto vector v2.
 */
vector project(vector v1, vector v2) {
    struct s_point vector;
    double mag = magnitude(v2);
    mag = mag * mag;
    vector.x = (v1.x * v2.x) / mag;
    vector.y = (v1.y * v2.y) / mag;
    vector.z = (v1.z * v2.z) / mag;
    double sum = vector.x + vector.y + vector.z;
    v2.x = v2.x * sum;
    v2.y = v2.y * sum;
    v2.z = v2.z * sum;
    return v2;
} /* project() */
/*
 * Return the unit vector in the direction of p1 -> p2.
 */
vector unit_vec(point p1, point p2) {
    struct s_point vector;
    vector.x = p2.x - p1.x;
    vector.y = p2.y - p1.y;
    vector.z = p2.z - p1.z;
    double mag = magnitude(vector);
    if (mag != 0) {
        vector.x = vector.x / mag;
        vector.y = vector.y / mag;
        vector.z = vector.z / mag;
    }
    return vector;
} /* unit_vec */

/*
 * Return the cosine similarity of the two vectors.
 */
double cosine_sim(vector v1, vector v2) {
    struct s_point vector;
    double mag1 = magnitude(v1);
    double mag2 = magnitude(v2);
    double totmag = mag1 * mag2;
    vector.x = (v1.x * v2.x);
    vector.y = (v1.y * v2.y);
    vector.z = (v1.z * v2.z);
    double add = vector.x + vector.y + vector.z;
    double cos = add / totmag;
    return cos;
} /* cosine_sim() */
