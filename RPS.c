#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include <errno.h>
#include <inttypes.h>

//function declarations
void playAgain();
void compMoveConversion(int rndNoParam);
void humanMove();
void answersComparison(char *human, char *computer);
void random_number(int min, int max);

//global variables
char answer;
char humanMoveChoice[9];
char compMove[9];
int compareAnswer;
char again;
char *endptr;
int row, col;

/* Prompt and accept human move */
/* needs validation input is r, p or s*/
void humanMove (void) {  

//local variables
char str[5];
char ans1 = 'r';
char ans2 = 'p';
char ans3 = 's';
char ans4 = 'q';
char mesg[] = "Choose Rock, Paper or Scissors. (R, P, or S): ";
char moveMsg[36] = "Your move is: ";
char yrMove[36];

getmaxyx(stdscr, row, col); /* get the number of rows and columns */
mvprintw(row / 2, (col - (int) strlen(mesg)) / 2, "%s", mesg); /* print the message in Screen centre*/

getstr(str);
    if (*str == ans1) {
        strcpy(humanMoveChoice, "Rock");
        strcat(moveMsg, humanMoveChoice);
        mvprintw(row / 1.8, (col - (int) strlen(moveMsg)) / 2, "%s", moveMsg);
    } else if (*str == ans2) {
        strcpy(humanMoveChoice, "Paper");
        strcat(moveMsg, humanMoveChoice);
        mvprintw(row / 1.8, (col - (int) strlen(moveMsg)) / 2, "%s", moveMsg);
    } else if (*str == ans3) {
        strcpy(humanMoveChoice, "Scissors");
        strcat(moveMsg, humanMoveChoice);
        mvprintw(row / 1.8, (col - (int) strlen(moveMsg)) / 2, "%s", moveMsg);
    }
    return random_number(1, 3);
}

/*generate random number between 1 and 3*/
void random_number(int min, int max) {

    //local variable
    int rndNo;

    srand(time(NULL));
    rndNo = (rand() % (max - min + 1)) + min;
    return compMoveConversion(rndNo);
}

/*convert rnd no generated into compmove string*/
void compMoveConversion (int rndNoParam) {

    //local variables
    char moveMsg[36] = "Computer move: ";

    if (rndNoParam == 1) {
        strcpy(compMove, "Rock");
        strcat(moveMsg, compMove);
        mvprintw(row / 1.7, (col - (int) strlen(moveMsg)) / 2, "%s", moveMsg);
    } else if (rndNoParam == 2) {
        strcpy(compMove, "Paper");
        strcat(moveMsg, compMove);
        mvprintw(row / 1.7, (col - (int) strlen(moveMsg)) / 2, "%s", moveMsg);
    } else {
        strcpy(compMove, "Scissors");
        strcat(moveMsg, compMove);
        mvprintw(row / 1.7, (col - (int) strlen(moveMsg)) / 2, "%s", moveMsg);
    }
    return answersComparison(humanMoveChoice, compMove);
}

/*compare user input with computer move*/
void answersComparison(char *human, char *computer) {

    //local variables
    char cWin[20] = "Computer wins\n";
    char yWin[20] = "You win\n";
    char draw[20] = "Match drawn\n";

    if (strcmp(human, "Rock") == 0 && strcmp(computer, "Paper") == 0) {
        mvprintw(row / 1.6, (col - (int) strlen(cWin)) / 2, "%s", cWin);
    } else if (strcmp(human, "Rock") == 0 && strcmp(computer, "Rock") == 0) {
        mvprintw(row / 1.6, (col - (int) strlen(draw)) / 2, "%s", draw);
    } else if (strcmp(human, "Rock") ==  0 && strcmp(computer, "Scissors") == 0){
        mvprintw(row / 1.6, (col - (int) strlen(yWin)) / 2, "%s", yWin);
    } else if (strcmp(human, "Paper") == 0 && strcmp(computer, "Rock") == 0) {
        mvprintw(row / 1.6, (col - (int) strlen(yWin)) / 2, "%s", yWin);
    } else if (strcmp(human, "Paper") == 0 && strcmp(computer, "Paper") == 0) {
        mvprintw(row / 1.6, (col - (int) strlen(draw)) / 2, "%s", draw);  
    } else if (strcmp(human, "Paper") == 0 && strcmp(computer, "Scissors") == 0) {
        mvprintw(row / 1.6, (col - (int) strlen(cWin)) / 2, "%s", cWin);
    } else if (strcmp(human, "Scissors") == 0 && strcmp(computer, "Paper") == 0) {
        mvprintw(row / 1.6, (col - (int) strlen(yWin)) / 2, "%s", yWin);
     } else if (strcmp(human, "Scissors") == 0 && strcmp(computer, "Scissors") == 0) {
        mvprintw(row / 1.6, (col - (int) strlen(draw)) / 2, "%s", draw);
    } else if (strcmp(human, "Scissors") == 0 && strcmp(computer, "Rock") == 0) {
        mvprintw(row / 1.6, (col - (int) strlen(cWin)) / 2, "%s", cWin);
    }
    playAgain();
}

/*play again*/
void playAgain() {

    /*local variables*/
    char againMSG[] = "Do you want to play again (y/any key)?\n";
    char endMSG[] = "Thanks for playing\n";
    char trigMSG[] = "Hit any key to play again!\n";
    char str[5];

    initscr();

    getmaxyx(stdscr, row, col); /* get the number of rows and columns */
    mvprintw(row / 1.2, (col - (int) strlen(againMSG)) / 2, "%s", againMSG);

    getstr(str);
    clear();

    if (*str == 'y') {
        clear();
        humanMove();
    } else {
        mvprintw(row / 1.2, (col - (int) strlen(endMSG)) / 2, "%s", endMSG);
        getch();
    }
    endwin();   // end ncurses session
}

int main(void) {
    initscr();                  // start the curses mode
    humanMove();
    endwin();
}