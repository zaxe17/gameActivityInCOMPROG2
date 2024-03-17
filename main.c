#include <stdio.h>

int game(int array[4][2]) {
    int input;
    int p1Wins = 0;
    int p2Wins = 0;

    for(int round = 0; round < 4; round++) {
        printf("\nROUND %d\n", round + 1);
        
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
                printf("Player 1 win this round");
                p1Wins++;
                break;
            }
            else if(array[round][column] == 2 && array[round][column + 1] == 6) {
                printf("Player 2 win this round");
                p2Wins++;
                break;
            }
            else if(array[round][column] < array[round][column + 1]) {
                printf("Player 1 win this round");
                p1Wins++;
                break;
            }
            else if(array[round][column] > array[round][column + 1]) {
                printf("Player 2 win this round");
                p2Wins++;
                break;
            }
            else {
                printf("Tie in this round");
                break;
            }
        }
    }

    if(p1Wins > p2Wins) {
        return 1;
    }
    else if(p1Wins < p2Wins) {
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
        printf("\nIn this match Player 1 wins");
    }
    else if(winner == -1) {
        printf("\nIn this match Player 2 wins");
    }
    else {
        printf("\nThe two players in this match are gay");
    }

    return 0;
}
