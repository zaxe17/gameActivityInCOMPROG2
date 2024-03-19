#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>


void diceBoard(int array[3][3]) {
    int count = 1;
    for(int row = 0; row < 3; row++) {
        for(int column = 0; column < 3; column++) {
            array[row][column] = count++;
        }
    }
}

void board(int array[3][3], int player) {
    for(int row = 0; row < 3; row++) {
        for(int column = 0; column < 3; column++) {
            if(row * 3 + column == player) {
                printf("X ");
            }
            else {
                printf("%d ", array[row][column]);
            }
        }
        printf("\n");
    }
}

int main() {
    int array[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    int player = 0;
    int dice;
    int loop = 0;

    srand(time(0));

    diceBoard(array);

    printf("Press enter to roll\n");
    
    while (loop < 3) {
        getch();

        dice = (rand() % 6) + 1;
        printf("\nThrow - %d\n", dice);

        if(player < 9) {
            player += dice;
            board(array, player - 1);
        }
        else if(player > 9) {
            player -= player;
            board(array, player - 1);
        }

        loop++;
    }

    if(player == 9) {
        printf("you win");
    }
    else {
        printf("you lose");
    }

    return 0;
}
