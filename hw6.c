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

#include "hw6.h"
#include <string.h>

/*
 * Read in a list of movies from the specified filename, store the movies in
 * the global array g_movie_array. Return the number of movies
 */

movie g_movie_array[MAX_MOVIES];
int g_movie_count;

int read_movies(char *filename) {
  FILE *file = fopen(filename, "r");
  char movie_buffer[200];
  char title[40];
  char title_reset[40];
  char seq_buffer[200];
  char buffer_reset[200];
  int minutes = 0;
  enum genre genre;
  int i = 0;
  int j = -1;
  int k = 0;
  int c = -1;
  int r = 0;
  char genre_token[100];
  char token_reset[100];
  char *delim = ":";
  char *token;
  char *seq_token;
  int null_check = fgetc(file);
  if (null_check == EOF) {
    fclose(file);
    g_movie_count = 0;
    return 0;
  }
  while (fscanf(file, "%[^|]|%d", movie_buffer, &minutes) == 2) {
    c++;
    if (c > 9) {
      g_movie_count = 0;
      return TOO_MUCH_DATA;
    }
    token = strtok(movie_buffer, delim);
    if (c == 0) {
      title[0] = null_check;
      for (r = 0; r < 40; r++) {
        title[r + 1] = token[r];
      }
    } else {
      for (r = 0; r < 40; r++) {
        title[r] = token[r];
      }
    }
    if (c > 0) {
      if (title[0] == '\n') {
        for (r = 0; r < 40; r++) {
          title[r] = title[r + 1];
        }
      }
    }
    if (strlen(title) > MAX_BUFFER_LEN) {
      g_movie_count = 0;
      return BAD_MOVIE;
    }
    if (strlen(title) > MAX_TITLE_LEN) {
      strncpy(g_movie_array[c].movie_title, title, 15);
      g_movie_array[c].movie_title[15] = '\0';
    } else {
      strncpy(g_movie_array[c].movie_title, title, 15);
    }
    seq_token = strtok(NULL, delim);
    if (seq_token[0] == '+') {
      strcpy(seq_buffer, seq_token);
      strcpy(genre_token, strtok(NULL, delim));
    } else {
      strcpy(genre_token, seq_token);
      seq_buffer[1] = '\0';
    }
    if (seq_buffer[0] == '\0') {
      g_movie_array[c].sequels[0][0] = '\0';
    }
    loop:
    while (seq_buffer[i] != '\0') {
      if (seq_buffer[i] != '+') {
        if (j >= MAX_SEQUELS) {
          g_movie_count = 0;
          return TOO_MUCH_DATA;
        }
        if (k == 15) {
          g_movie_array[c].sequels[j][k] = '\0';
          k = 0;
          while (seq_buffer[i] != '+') {
            if (seq_buffer[i++] == '\0') {
              goto loop;
            }
          }
          continue;
        } else if (k < 15) {
          g_movie_array[c].sequels[j][k] = seq_buffer[i];
          i++;
          k++;
        }
      } else if (seq_buffer[i] == '+') {
        i++;
        j++;
        k = 0;
      }
    }
    i = 0;
    j = -1;

    switch (genre_token[0]) {
      case 'A':
        genre = ACTION;
        break;
      case 'H':
        genre = HORROR;
        break;
      case 'C':
        genre = COMEDY;
        break;
      case 'D':
        genre = DRAMA;
        break;
      case 'S':
        genre = SCIFI;
        break;
      default:
        return BAD_GENRE;
    }
    g_movie_array[c].movie_genre = genre;
    g_movie_array[c].movie_len_minutes = minutes;
    for (int f = 0; f < 50; f++) {
      title[f] = '\0';
    }
    for (int f = 0; f < 50; f++) {
      movie_buffer[f] = '\0';
    }
    for (int f = 0; f < 50; f++) {
      seq_buffer[f] = '\0';
    }
    for (int f = 0; f < 50; f++) {
      token[f] = '\0';
    }
  }
  fclose(file);
  g_movie_count = c + 1;
  return g_movie_count;

} /* read_movies() */


/*
 * Search through all the sequels of a given movie
 * Return the longest movie in the given genre.
 */

int find_sequels(char *title, enum genre movie_genre) {
  int maxi = 0;
  int seq_num = 0;
  int i = 0;
  int k = 0;
  char sequel_buff[MAX_SEQUELS][MAX_TITLE_LEN];
  int sequel_count = 0;
  if (g_movie_count == 0) {
    return NO_MOVIES;
  }
  if (strlen(title) > MAX_TITLE_LEN) {
    title[15] = '\0';
  } else {
  }
  for (i = 0; i < g_movie_count; i++) {
    if (strcmp(g_movie_array[i].movie_title, title) == 0) {
      if (g_movie_array[i].movie_genre != movie_genre) {
        return NOT_FOUND;
      }
      if (g_movie_array[i].sequels[0][0] == '\0') {
        return 0;
      } else {
        for (seq_num = 0; seq_num < MAX_SEQUELS; seq_num++) {
          char temp = g_movie_array[i].sequels[seq_num][0];
          if (g_movie_array[i].sequels[seq_num][0] == '\0') {
            sequel_count = seq_num;
            break;
          } else if (seq_num == 2) {
            sequel_count = seq_num;
          }
          strcpy(sequel_buff[seq_num], g_movie_array[i].sequels[seq_num]);
        }
      }
      for (seq_num = 0; seq_num <= sequel_count; seq_num++) {
        for (i = 0; i < g_movie_count; i++) {
          if (strcmp(g_movie_array[i].movie_title, sequel_buff[seq_num]) == 0) {
            if (g_movie_array[i].movie_genre == movie_genre) {
              if (g_movie_array[i].movie_len_minutes > maxi) {
                maxi = g_movie_array[i].movie_len_minutes;
              }
            }
          }
        }
      }
    }
    if (i + 1 == g_movie_count) {
      return NOT_FOUND;
    }
  }
  if (maxi == 0) {
    return 0;
  }
  return maxi;
} /* find_sequels() */
