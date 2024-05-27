#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
    srand(time(0));
    int rastgelesayi=rand()%101;
    int tahmin;
    printf("Welcome to Number Guessing Game\n");
    printf("Guess a number between 1 to 100:\n");
    do{
    scanf("%d",&tahmin);
    printf("Your guess: %d\n",tahmin);
        if(tahmin<rastgelesayi){
            printf("Too low, try again\n");
        }
        if(tahmin>rastgelesayi){
            printf("Too high, try again\n");
        }
    
    }while(tahmin!=rastgelesayi);
    printf("Congratulations! You guessed the number %d correctly",tahmin);
}