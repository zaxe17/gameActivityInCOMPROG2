#include <stdio.h>

int game(int array[4][2]) {
    int input;
    int win = 0;

    for(int round = 0; round < 4; round++) {
        printf("\nROUND %d\n", round + 1);
        
        for(int player = 0; player < 2; player++) {
            do {
                printf("Player %d enter number: ", player + 1);
                scanf("%d", &input);
                if(!(input == 2 || input == 5 || input == 6)) {
                    printf("Enter number 6, 5, and 2\n");
                }

            } while(!(input == 2 || input == 5 || input == 6));

            array[round][player] = input;
        }
        
        for(int column = 0; column < 2; column++) {
            if(array[round][column] < array[round][column + 1]) {
                printf("Player 1 win this round");
                win++;
                break;
            }
            else if(array[round][column] > array[round][column + 1]) {
                printf("Player 2 win this round");
                win--;
                break;
            }
            else {
                printf("Tie in this round");
                win = 0;
                break;
            }
        }
    }

    return win;
}

int main() {
    int array[4][2];

    printf("ROCK - 6 | PAPER - 5 | SCISSORS - 2\n");

    int winner = game(array);

    if(winner > 0) {
        printf("\nIn this match Player 1 wwin");
    }
    else if(winner < 0) {
        printf("\nIn this match Player 1 wwin");
    }
    else {
        printf("\nIn this match the two player are gay");
    }

    return 0;
}
