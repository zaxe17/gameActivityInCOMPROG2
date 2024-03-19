#include <stdio.h>

void winner(int player1, int player2) {
    if(player1 == 6 && player2 == 2) {
        printf("Player 1 wins this round\n");
    }
    else if(player1 == 2 && player2 == 6) {
        printf("Player 2 wins this round\n");
    }
    else if(player1 < player2) {
        printf("Player 1 wins this round\n");
    }
    else if(player1 > player2) {
        printf("Player 2 wins this round\n");
    }
    else {
        printf("Tie in this round\n");
    }
}

void table(int array[4][2], int round) {
    printf("\nRound %d:\n", round + 1);

    for(int row = 0; row <= round; row++) {
        for(int column = 0; column < 2; column++) {
            printf("%d ", array[row][column]);
        }
        
        int result = 0;

        if (array[row][0] == 6 && array[row][1] == 2) {
            result = 1;
        }
        else if (array[row][0] == 2 && array[row][1] == 6) {
            result = -1;
        }
        else if (array[row][0] < array[row][1]) {
            result = 1;
        }
        else if (array[row][0] > array[row][1]) {
            result = -1;
        }
        
        printf("| %d", result);
        printf("\n");
    }
}

int main() {
    int array[4][2] = {
        {0, 0,},
        {0, 0,},
        {0, 0,},
        {0, 0,},
    };
    int choice;
    char ans;

    do {
        printf("\nROCK - 6 | PAPER - 5 | SCISSORS - 2\n");

        for(int round = 0; round < 4; round++) {
            printf("\nRound %d:\n", round + 1);

            for(int player_input = 0; player_input < 2; player_input++) {
                do {
                    printf("Player %d: ", player_input + 1);
                    scanf("%d", &choice);

                    if(!(choice == 6 || choice == 5 || choice == 2)) {
                        printf("\nEnter ROCK - 6, PAPER - 5, or SCISSORS - 2\n");
                    }

                } while(!(choice == 6 || choice == 5 || choice == 2));

                array[round][player_input] = choice;
            }

            winner(array[round][0], array[round][1]);

            table(array, round);
        }
        
        printf("Do you want to play again? (Y/N):");
        scanf(" %c", &ans);

    } while(ans == 'Y' || ans == 'y');

    return 0;
}
