#include <stdio.h>
#include "header.h"
#include "handmangame.c"

int main() {
    printf("Welcome to the Hangman Game !\n");
    char searching_word[10];
    printf("What is your word ? ");
    scanf("%s", searching_word);
    hangman_game(searching_word);
    return 0;
}
