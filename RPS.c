#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

char playAgain();
char compMoveConversion(int rndNoParam);
int humanMove();
int moveAssignInt (char answer);
int answersComparison(char human[9], char computer[9]);



int rndNo;
int algoAnswer;
char answer;
char humanMoveChoice[9];
char compMove[9];
int compareAnswer;





//generate random number between 1 and 3
int random_number(int min, int max) {
    srand(time(NULL));
   rndNo = (rand() % (max - min + 1)) + min;
   printf("%d\n", rndNo);
   return compMoveConversion(rndNo);
}

//convert rnd no generated into compmove string
char compMoveConversion (int rndNoParam) {
    if (rndNoParam == 1) {
        strcpy(compMove, "Rock");
    } else if (rndNoParam == 2) {
        strcpy(compMove, "Paper");
    } else {
        strcpy(compMove, "Scissors");
    }
}

//Prompt and accept human move
int humanMove (void) {
printf("Choose Rock, Paper or Scissors. (R, P, or S)\n");
scanf("%c", &answer);
    if (answer == 'r') {
        strcpy(humanMoveChoice,"Rock");
    } else if (answer == 'p') {
        strcpy(humanMoveChoice,"Paper");
    } else if (answer == 's') {
        strcpy(humanMoveChoice,"Scissors");
    } else {
        humanMove();
    }
}

//input assigned integer value
int moveAssignInt (char answer) {
    if (answer == 'R' || answer == 'r') {
        algoAnswer = 1;
        printf("%d\n", rndNo);
        return algoAnswer;
    } else if (answer == 'P' || answer == 'p') {
        algoAnswer = 2;
        printf("%d\n", rndNo);
        return algoAnswer;
    } else {
        algoAnswer = 3;
        printf("%d\n", rndNo);
        return algoAnswer;
    }
}

// compare user input with computer move
int answersComparison(char human[9], char computer[9]) {
    int compareAnswer = strcmp(human, computer);
        if (compareAnswer == 0) {
        printf("That's a draw!");
        }
}

/*
char playAgain(void) {
    printf ("Do you want to play again (y/n)?\n");
    scanf("%c", &again);
     if (again == 'y') {
        humanMove();
    } else {
        return printf("Thanks for playing\n");
    }
}
*/
int main() {

char answer;
int answerNo;
int humanMoveChoice;

humanMove();
random_number(1, 3);
moveAssignInt(algoAnswer);
//  compare(algoAnswer, rndNo);
//playAgain();
};