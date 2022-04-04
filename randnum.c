// rewriting random number game in c language. 050422.

#include <stdio.h>
#include <stdlib.h>

int getDifficulty();
int getRandNum();
int userWin();
int userLose();

const char invalidChars[] = "abcdefghijklmnopqrstuvwxyz~`!@#$%^&*()-_=+[{]}\"\|:;'<,>.?/";

int main()
{
    int randNum = getDifficulty();
    //printf("%d", randNum);  // un-comment this for the answer lol

    int triesLeft = 10;
    printf("\nAlright, lets start the game!\nYou have a total of %d tries, good luck!\n\n", triesLeft);

    int userGuess;

    while (triesLeft)
    {
        printf("Your guess: ");
        scanf("%d", &userGuess);
        //printf("%d\n", userGuess);

        (userGuess == randNum) ? userWin(triesLeft) :
            (userGuess > randNum) ? printf("\nYour guess is too high!\n") :
                printf("\nYour guess is too low!\n");

        triesLeft--;
        printf("You have %d tries left\n\n", triesLeft);
    }
    userLose();
}



int getDifficulty()
{
    printf("Hello! Let's play a game I'll think of a number within a certain range and you can try to guess it!\n\
I will tell you need to go higher or lower.\n\
\n\
Pick your difficulty level now:\n\
Easy   - 1-10\n\
Medium - 1-50\n\
Hard   - 1-100\n\n");

    printf("Difficulty: ");
    char difficulty[10];
    scanf("%s", difficulty);
    for (int i=0;i<strlen(difficulty);i++){difficulty[i]=tolower(difficulty[i]);}

    int rn;
    (!strcmp(difficulty, "easy")) ? rn = getRandNum(1) :
        (!strcmp(difficulty, "medium") || (!strcmp(difficulty, "med"))) ? rn = getRandNum(2) :
            (!strcmp(difficulty, "hard")) ? rn = getRandNum(3) :
                printf("I did not understand you, please try a little harder!\n");

    return rn;
}


int getRandNum(diff)
{
    srand(time(0));

    switch (diff)
    {
        case 1:
            return rand()%10+1;
        case 2:
            return rand()%50+1;
        case 3:
            return rand()%100+1;
    }
}



int userWin(tl)
{
    printf("Congratulations, you guessed my number!\nYou won with %d tries left!\n", tl);
    exit(0);
}


int userLose()
{
    printf("Sorry, you ran out of trial attempts!\nBetter luck next time!\n");
    exit(0);
}
