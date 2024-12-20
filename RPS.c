#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include <errno.h>
#include <inttypes.h>

int playAgain();
void compMoveConversion(int rndNoParam);
void humanMove();
int moveAssignInt (char answer);
void answersComparison(char *human, char *computer);
void random_number(int min, int max);

int rndNo;
int algoAnswer;
char answer;
char humanMoveChoice[9];
char compMove[9];
int compareAnswer;
char again;

char mesg[] = "Choose Rock, Paper or Scissors. (R, P, or S): ";
char *endptr;
int row, col;

/* Prompt and accept human move */
void humanMove (void) {

char str[5];
char ans1 = 'r';
char ans2 = 'p';
char ans3 = 's';
char ans4 = 'q';

getmaxyx(stdscr, row, col); /* get the number of rows and columns */

mvprintw(row / 2, (col - (int) strlen(mesg)) / 2, "%s", mesg); /* print the message in Screen centre*/

getstr(str);
clear();

    if (*str == ans1) {
        strcpy(humanMoveChoice, "Rock");
        mvprintw(row / 2, (col - (int) strlen(humanMoveChoice)) / 2, "Your move is: %s", humanMoveChoice);
        getch();
    } else if (*str == ans2) {
        strcpy(humanMoveChoice, "Paper");
        mvprintw(row / 2, (col - (int) strlen(humanMoveChoice)) / 2, "Your move is: %s", humanMoveChoice);
        getch();
    } else if (*str == ans3) {
        strcpy(humanMoveChoice, "Scissors");
        mvprintw(row / 2, (col - (int) strlen(humanMoveChoice)) / 2, "Your move is: %s", humanMoveChoice);
        getch();
    } else if (*str == ans4) {
        endwin(); // quit ncurses if 'q' entered
    } else {
        getch(); 
        endwin();
    }
    return random_number(1, 3);
}

//generate random number between 1 and 3
void random_number(int min, int max) {
    srand(time(NULL));
   rndNo = (rand() % (max - min + 1)) + min;
   return compMoveConversion(rndNo);
}

//convert rnd no generated into compmove string
void compMoveConversion (int rndNoParam) {
    if (rndNoParam == 1) {
        strcpy(compMove, "Rock");
        clear();
        mvprintw(row / 2, (col - (int) strlen(compMove)) / 2, "%s", compMove);
        getch();
    } else if (rndNoParam == 2) {
        strcpy(compMove, "Paper");
        clear();
        mvprintw(row / 2, (col - (int) strlen(compMove)) / 2, "%s", compMove);
        getch();
    } else {
        strcpy(compMove, "Scissors");
        clear();
        mvprintw(row / 2, (col - (int) strlen(compMove)) / 2, "%s", compMove);
        getch();
    }
    return answersComparison(humanMoveChoice, compMove);
}


// compare user input with computer move
void answersComparison(char *human, char *computer) {

    char cWin[20] = "Computer wins\n";
    char yWin[20] = "You win\n";
    char draw[20] = "Draw\n";

    if (strcmp(human, "Rock") == 0 && strcmp(computer, "Paper") == 0) {
        clear();
        mvprintw(row / 2, (col - (int) strlen(cWin)) / 2, "%s", cWin);
        getch();
        playAgain();
    } else if (strcmp(human, "Rock") == 0 && strcmp(computer, "Rock") == 0) {
        clear();
        mvprintw(row / 2, (col - (int) strlen(draw)) / 2, "%s", draw);
        getch();
        playAgain();
    } else if (strcmp(human, "Rock") ==  0 && strcmp(computer, "Scissors") == 0){
        clear();
        mvprintw(row / 2, (col - (int) strlen(yWin)) / 2, "%s", yWin);
        getch();
        playAgain();
    } else if (strcmp(human, "Paper") == 0 && strcmp(computer, "Rock") == 0) {
        clear();
        mvprintw(row / 2, (col - (int) strlen(yWin)) / 2, "%s", yWin);
        getch();
        playAgain();
    } else if (strcmp(human, "Paper") == 0 && strcmp(computer, "Paper") == 0) {
        clear();
        mvprintw(row / 2, (col - (int) strlen(draw)) / 2, "%s", draw);
        getch();
        playAgain();   
    } else if (strcmp(human, "Paper") == 0 && strcmp(computer, "Scissors") == 0) {
        clear();
        mvprintw(row / 2, (col - (int) strlen(cWin)) / 2, "%s", cWin);
        getch();
        playAgain();
    } else if (strcmp(human, "Scissors") == 0 && strcmp(computer, "Paper") == 0) {
        clear();
        mvprintw(row / 2, (col - (int) strlen(cWin)) / 2, "%s", cWin);
        getch();
        playAgain();
     } else if (strcmp(human, "Scissors") == 0 && strcmp(computer, "Scissors") == 0) {
        clear();
        mvprintw(row / 2, (col - (int) strlen(draw)) / 2, "%s", draw);
        getch();
        playAgain();
    } else if (strcmp(human, "Scissors") == 0 && strcmp(computer, "Rock") == 0) {
        clear();
        mvprintw(row / 2, (col - (int) strlen(yWin)) / 2, "%s", yWin);
        getch();
        playAgain();
    }
}

// play again
int playAgain(void) {
    printf ("Do you want to play again (y)?\n");
    scanf(" %c", &again);
    if (again == 'y') {
        humanMove();
    } else {
        printf("Thanks for playing\n");
    }
    return 0;
}


int main() {
    initscr();                  /* start the curses mode */
    humanMove();
    endwin();
    return 0;
}