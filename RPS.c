#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int playAgain();
void compMoveConversion(int rndNoParam);
void humanMove();
int moveAssignInt (char answer);
void answersComparison(char *human, char *computer);
void random_number(int min, int max);

int rndNo;
int algoAnswer;
char answer;
char *humanMoveChoice[10];
char compMove[10];
int compareAnswer;
char again;


//Prompt and accept human move
void humanMove (void) {
printf("Choose Rock, Paper or Scissors. (R, P, or S)\n");
scanf(" %c", &answer);
    if (answer == 'r') {
        strcpy(humanMoveChoice, "Rock");
        printf("Your move is: %s\n", humanMoveChoice);
    } else if (answer == 'p') {
        strcpy(humanMoveChoice, "Paper");
        printf("Your move is: %s\n", humanMoveChoice);
    } else if (answer == 's') {
        strcpy(humanMoveChoice, "Scissors");
        printf("Your move is: %s\n", humanMoveChoice);
    } else {
        humanMove();
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
        printf("Computer plays: %s\n", compMove);
    } else if (rndNoParam == 2) {
        strcpy(compMove, "Paper");
        printf("Computer plays: %s\n", compMove);
    } else {
        strcpy(compMove, "Scissors");
        printf("Computer plays: %s\n", compMove);
    }
    return answersComparison(humanMoveChoice, compMove);
}


// compare user input with computer move
void answersComparison(char *human, char *computer) {
    if (strcmp(human, "Rock") == 0 && strcmp(computer, "Paper") == 0) {
        printf("Computer wins\n");
        playAgain();
    } else if (strcmp(human, "Rock") == 0 && strcmp(computer, "Rock") == 0) {
        printf("Draw\n");
        playAgain();
    } else if (strcmp(human, "Rock") ==  0 && strcmp(computer, "Scissors") == 0){
        printf("Human wins\n");
        playAgain();
    } else if (strcmp(human, "Paper") == 0 && strcmp(computer, "Rock") == 0) {
        printf("Human wins\n");
        playAgain();
    } else if (strcmp(human, "Paper") == 0 && strcmp(computer, "Paper") == 0) {
        printf("Draw\n");
        playAgain();   
    } else if (strcmp(human, "Paper") == 0 && strcmp(computer, "Scissors") == 0) {
        printf("Computer wins\n");
        playAgain();
    } else if (strcmp(human, "Scissors") == 0 && strcmp(computer, "Paper") == 0) {
        printf("Computer wins\n");
        playAgain();
     } else if (strcmp(human, "Scissors") == 0 && strcmp(computer, "Scissors") == 0) {
        printf("Draw\n");
        playAgain();
    } else if (strcmp(human, "Scissors") == 0 && strcmp(computer, "Rock") == 0) {
        printf("Human wins\n");
        playAgain();
    }
}

// play again routine
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
    humanMove();
    return 0;
}