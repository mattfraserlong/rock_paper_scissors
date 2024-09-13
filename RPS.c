#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

char playAgain();
char compMoveConversion(int rndNoParam);
int humanMove();
int moveAssignInt (char answer);


int answersComparison;
int rndNo;
int algoAnswer;

char answer;
char humanMoveChoice[9];
char compMove[9];





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
int humanMove () {
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
// think not working as if statement not inside a function
//therefore syntax wrong... will have to create function
//rather than assigned fucntion

int answersComparison = strcmp(humanMoveChoice, compMove);
if (answersComparison == 0) {
    printf("That's a draw!");
    humanMove();
}


// C does not allow string comparison
//The reason for this is because != and == will only
//compare the base addresses of those strings.
//Not the contents of the strings themselves.

//use strcmp function which treats strings as arrays
//they are and compares each char in the string
//strcmp(str1, str2) => output is 0 if strings match
//Or how about just using fact string is char array
//we CAN just compare first char at address, as just R,P,S?
// do you want to play again

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