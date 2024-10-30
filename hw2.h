//#include "hw2.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct n n;

typedef struct n n;

typedef struct n n;
char g_board[3][3];
int ERR_OCCUPIED = 0;
int CPU_TURN_ERROR = 0;
int CPU_TURN_SUCCESS = 0;
const char GAME_DRAW = 'd';

//my code
int two_d_sum(int** arr, int n, int m){
int sum = 0;
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++){
            sum = sum + arr[i][j];
        }
}
return sum;
}
void initialize_board(){
    char g_board[3][3];
    for (int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++){
            g_board[i][j] = ' ';
        }
    }
}
int take_turn(int i, int j){
    if(g_board[i][j] == ' '){
        g_board[i][j] = 'x';
    } else{
        return ERR_OCCUPIED;
    }
}
int cpu_turn(){
    int i = rand() % 3;
    int j = rand() % 3;
    if(g_board[i][j] == ' '){
        g_board[i][j] = 'o';
    } else{
        return ERR_OCCUPIED;
    }
}
char check_win(){
    if(g_board[0][0] == g_board[0][1] == g_board[0][2]) {
        if (g_board[0][0] == 'x'){
            return 'x';
        } else if (g_board[0][0] == 'o'){
            return 'o';
        } else{

        }
    }
    else if(g_board[1][0] == g_board[1][1] == g_board[1][2]) {
        if (g_board[1][0] == 'x'){
            return 'x';
        } else if (g_board[1][0] == 'o'){
            return 'o';
        } else{

        }
    }
    else if(g_board[2][0] == g_board[2][1] == g_board[2][2]) {
        if (g_board[2][0] == 'x'){
            return 'x';
        } else if (g_board[2][0] == 'o'){
            return 'o';
        } else{

        }
    }
    else if(g_board[0][0] == g_board[1][0] == g_board[2][0]) {
        if (g_board[0][0] == 'x'){
            return 'x';
        } else if (g_board[0][0] == 'o'){
            return 'o';
        } else{

        }
    }
    else if(g_board[1][0] == g_board[1][1] == g_board[1][2]) {
        if (g_board[1][0] == 'x'){
            return 'x';
        } else if (g_board[1][0] == 'o'){
            return 'o';
        } else{

        }
    }
    else if(g_board[2][0] == g_board[2][1] == g_board[2][2]) {
        if (g_board[2][0] == 'x'){
            return 'x';
        } else if (g_board[2][0] == 'o'){
            return 'o';
        } else{

        }
    }
    else if(g_board[0][0] == g_board[1][1] == g_board[2][2]) {
        if (g_board[0][0] == 'x'){
            return 'x';
        } else if (g_board[0][0] == 'o'){
            return 'o';
        } else{

        }
    }
    else if(g_board[0][2] == g_board[1][1] == g_board[2][0]) {
        if (g_board[0][2] == 'x'){
            return 'x';
        } else if (g_board[0][2] == 'o'){
            return 'o';
        } else{

        }
    }
    else {
        for (int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if (g_board[i][j] == ' ') {
                    return 0;
                }
            }
        }
   }
    return GAME_DRAW;
}
//end of my code

int clean_stdin() {
    while (getchar() != '\n') {
    }
    return(1);
}

void print_board() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (g_board[i][j] != ' ') {
                printf("%c", g_board[i][j]);
            } else {
                printf("-");
            }
        }
        printf("\n");
    }
}

void play_game() {
    printf("Playing a game of Tic Tac Toe. The player goes first.\n");
    initialize_board();
    char winner = 0;
    while (1) {
        print_board();
        winner = check_win();
        if (winner) {
            switch (winner) {
                case 'x':
                    printf("You win!\n");
                    break;
                case 'o':
                    printf("CPU wins.\n");
                    break;
                case 'd':
                    printf("It's a tie!\n");
                    break;
            }
            break;
        }
        while (1) {
            int row = 0;
            int col = 0;
            printf("Player turn, enter row number\n");
            scanf("%d%*c", &row);
            printf("Enter column number\n");
            scanf("%d%*c", &col);
            if (take_turn(row, col) == 0) {
                break;
            }
            printf("Invalid move. Please try again.\n");
        }
        print_board();
        if (check_win()) {
            continue;
        }
        printf("CPU turn\n");
        if (cpu_turn() == CPU_TURN_ERROR) {
            printf("Board is full...\n");
            continue;
        }
    }
}


int main() {
    int func = 0;
    int output = 0;

    while (func != 7) {
        printf("Choose a function to test:\n");
        printf("  1) two_d_sum()\n");
        printf("  2) initialize_board()\n");
        printf("  3) take_turn()\n");
        printf("  4) cpu_turn()\n");
        printf("  5) check_win()\n");
        printf("  6) Play a full game of Tic Tac Toe\n");
        printf("  7) exit\n");

        scanf("%d%*c", &func);

        if (func == 1) {
            printf("Enter the number of arrays in the array (n): ");
            int size_n;
            scanf ("%d%*c", &size_n);

            printf("Enter the number of elements in the array in the array (m): ");
            int size_m;
            scanf ("%d%*c", &size_m);

            int **arr = (int **)malloc(size_n * sizeof(int *));
            int size = size_n * size_m;
            printf("The number of elements in the 2D array is %d.", size);
            for (int i = 0; i < size_n; i++) {
                arr[i] = (int *)malloc(size_m * sizeof(int));
                for (int j = 0; j < size_m; j++) {
                    int num;
                    printf("Enter a number: ");
                    scanf ("%d%*c", &num);
                    arr[i][j] = num;
                }
            }
            output = two_d_sum((int **)arr, size_n, size_m);
            for (int i = 0; i < size_n; i++) {
                free(arr[i]);
            }
            free(arr);
            printf("The result of your sum function is: %d.\n", output);
        }
        else if (func == 2) {
            initialize_board();
            printf("Your board is initialized.\n");
            print_board();
        }
        else if (func == 3) {
            printf("Enter an index for the row (0,1,2): ");
            int i;
            scanf ("%d%*c", &i);
            printf("Enter an index for the column (0,1,2): ");
            int j;
            scanf ("%d%*c", &j);
            int result = take_turn(i,j);
            if (result == 0) {
                printf("No error occurred.\n");
                printf("Turn taken!\n\n");
            }
            else {
                printf("Error number %d occurred!\n", result);
            }
            print_board();
        }
        else if (func == 4) {
            printf("CPU's turn.\n\n");
            if (cpu_turn() == CPU_TURN_SUCCESS) {
                printf("CPU's turn taken!\n");
            } else {
                printf("CPU turn error, board is probably full\n");
            }
            print_board();
        }
        else if (func == 5) {
            printf("Checking for winner...\n");
            char winner = check_win();
            if (winner == 0) {
                printf("No winner yet, keep playing!\n");
            }
            if (winner == 'x') {
                printf("Congratulations! You Won!\n");
            }
            if (winner == 'o') {
                printf("CPU Won! Better luck next time.\n");
            }
            if (winner == GAME_DRAW) {
                printf("The game board is full. It's a draw!");
            }
        }
        else if (func == 6) {
            play_game();
        }
        else if (func == 7) {
            break;
        }
        else {
            printf("Please select one of the options.\n");
        }
    }
}