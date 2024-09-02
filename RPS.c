#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

char playAgain();

// you need to use vscode debug console... to do this use
//https://code.visualstudio.com/docs/cpp/launch-json-reference
// need to create a file structure with a launch json file

//generate random number between 1 and 3
int rndNo;
int random_number(int min, int max) {
    srand(time(NULL));
   rndNo = (rand() % (max - min + 1)) + min;
   printf("%d\n", rndNo);
   compMoveConversion(rndNo);
   return void;
}
char compMoveConversion;
char compMoveConversion (rndNo) {
    if (rndNo = 1) {
        return compMove = "Rock";
    } else if (rndNo = 2) {
        return compMove = "Paper";
    } else {
        return compMove = "Scissors";
    }
}


// accept user input of R P S and turn into number
char answer;
int answerNo;
char humanMove () {
printf("Choose Rock, Paper or Scissors. (R, P, or S)");
scanf("%c", &answer);
    if (answer == 'r') {
        return compare("Rock", compMove);
    } else if (answer == 'p') {
        return compare("Paper", compMove);
    } else if (answer == 's') {
        return compare("Scissors", compMove);
    } else {
        printf ("You must enter r, p or s\n");
        humanMove();
    }
}

//input assigned integer value
int algoAnswer;
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
// C does not allow string comparison
//The reason for this is because != and == will only
//compare the base addresses of those strings.
//Not the contents of the strings themselves.

//use strcmp function which treats strings as arrays
//they are and compares each char in the string
//strcmp(str1, str2) => output is 0 if strings match
//Or how about just using fact string is char array
//we CAN just compare first char at address, as just R,P,S?



char compare(humanMove, compMove) {
    if (compMove == "Rock" && humanMove == "Rock") {
        printf("You've drawn.\n");
        playAgain();
        return void;
    } else if (compMove == "Rock" && humanMove == "Paper") {
        printf("You've won.\n");
        playAgain();
        return void;
    } else if (compMove == "Rock" && humanMove == "Scissors") {
        printf("You've lost.\n");
        playAgain();
        return void;
    } else if (compMove == "Paper" && humanMove == "Rock") {
        printf("You've lost.\n");
        playAgain();
        return void;
    }else if (compMove == "Paper" && humanMove == "Paper") {
        printf("You've drawn.\n");
        playAgain();
        return void;
    }else if (compMove == "Paper" && humanMove == "Scissors") {
        printf("You've lost.\n");
        playAgain();
        return void;
    }else if (compMove == "Scissors" && humanMove == "Rock") {
        printf("You've won.\n");
        playAgain()
        return void;
    }else if (compMove == "Scissors" && humanMove == "Paper") {
        printf("You've lost.\n");
        playAgain();
        return void;
    }else if (compMove == "Scissors" && humanMove == "Scissors") {
        printf("You've drawn.\n");
        playAgain();
        return void;
    }
}

// do you want to play again

char playAgain(void) {
    printf ("Do you want to play again (y/n)?\n");
    scanf("%c", &again);
     if (again == 'y') {
        humanMove();
    } else {
        return printf("Thanks for playing\n");
    }
}


int main() {
humanMove();
random_number(1, 3);
moveAssignInt(algoAnswer);
compare(algoAnswer, rndNo);
playAgain();
};
