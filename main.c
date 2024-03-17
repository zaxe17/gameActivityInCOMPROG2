#include <stdio.h>

void table(int array[4][2]) {
    for(int row = 0; row < 4; row++) {
        for(int colm = 0; colm < 2; colm++) {
            printf("%d ", array[row][colm]);
        }
        printf("\n");
    }
}

int game(int array[4][2]) {
    int input;
    int win;

    for(int row = 0; row < 4; row++) {
        for(int colm = 0; colm < 2; colm++) {
            array[row][colm] = 0;
        }
    }

    for(int round = 0; round < 4; round++) {
        printf("\nROUND %d\n", round + 1);

        table(array);
        
        for(int player = 0; player < 2; player++) {
            do {
                printf("Player %d enter number: ", player + 1);
                scanf("%d", &input);
                if(!(input == 2 || input == 5 || input == 6)) {
                    printf("Enter number 6, 5, or 2\n");
                }

            } while(!(input == 2 || input == 5 || input == 6));

            array[round][player] = input;
        }
        
        for(int column = 0; column < 2; column++) {
            if(array[round][column] == 6 && array[round][column + 1] == 2) {
                printf("Player 1 wins this round\n\n");
                win = 1;
                break;
            }
            else if(array[round][column] == 2 && array[round][column + 1] == 6) {
                printf("Player 2 wins this round\n\n");
                win = -1;
                break;
            }
            else if(array[round][column] < array[round][column + 1]) {
                printf("Player 1 wins this round\n\n");
                win = 1;
                break;
            }
            else if(array[round][column] > array[round][column + 1]) {
                printf("Player 2 wins this round\n\n");
                win = -1;
                break;
            }
            else {
                printf("Tie in this round\n\n");
                break;
            }
        }
    }

    if(win == 1) {
        return 1;
    }
    else if(win == -1) {
        return -1;
    }
    else {
        return 0;
    }
}

int main() {
    int array[4][2];

    printf("ROCK - 6 | PAPER - 5 | SCISSORS - 2\n");

    int winner = game(array);

    if(winner == 1) {
        printf("\n\nIn this match Player 1 wins");
    }
    else if(winner == -1) {
        printf("\n\nIn this match Player 2 wins");
    }
    else {
        printf("\n\nThe two players in this match are gay");
    }

    return 0;
}
