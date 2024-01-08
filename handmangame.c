#include <stdio.h>
#include <string.h>

int hangman_game(char *word) {
    char gameField[7][7] = {{'=', '=', '=', '=', '=', 'Y', '='},
                            {' ', '|', ' ', ' ', ' ', ' ', ' '},
                            {' ', '|', ' ', ' ', ' ', ' ', ' '},
                            {' ', '|', ' ', ' ', ' ', ' ', ' '},
                            {' ', '|', ' ', ' ', ' ', ' ', ' '},
                            {' ', '|', ' ', ' ', ' ', ' ', ' '},
                            {'=', '=', '=', '=', '=', '=', '='}};

    int attempts = 7;
    int found = 0;
    int incorrect_attempts = 0;
    char letter;

    while (attempts != 0) {
        attempts--;

        // print GameField
        for (int x = 0; x < 7; x++) {
            for (int y = 0; y < 7; y++) {
                printf("%c", gameField[x][y]);
            }
            printf("\n");
        }

        int is_found = 0;
        printf("Choose your letter : ");
        scanf(" %c", &letter);

        for (int i = 0; i < strlen(word); i++) {
            if (letter == word[i]) {
                is_found = 1;
                found++;
                attempts++;
                printf("Found !\n");

                if (found == strlen(word)) {
                    printf("Victory !\n");
                    return 0;
                }
            }
        }

        if (is_found == 0) {
            printf("Not Found !\n");
            incorrect_attempts++;

            if (incorrect_attempts >= 1) {
                gameField[1][5]='|';
            }
            if (incorrect_attempts >= 2) {
                gameField[2][5]='O';
            }
            if (incorrect_attempts == 3) {
                gameField[3][5]='|';
            }
            if (incorrect_attempts == 4) {
                gameField[3][4]='/';
            }
            if (incorrect_attempts >= 5) {
                gameField[3][6]='\\';
            }
            if (incorrect_attempts == 6) {
                gameField[4][4]='/';
            }
            if (incorrect_attempts == 7) {
                gameField[4][6]='\\';

                // print GameField
                for (int x = 0; x < 7; x++) {
                    for (int y = 0; y < 7; y++) {
                        printf("%c", gameField[x][y]);
                    }
                    printf("\n");
                }

                printf("It's Loose !\n");
                return 2 ;
            }
        }
    }
    return 3;
}
