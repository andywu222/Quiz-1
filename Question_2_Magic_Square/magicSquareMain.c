#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int magicSquareTest(int grid[3][3]) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (grid[i][0] + grid[i][1] + grid[i][2] != 15)
            return 0;
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (grid[0][i] + grid[1][i] + grid[2][i] != 15)
            return 0;
    }

    // Check diagonals
    if (grid[0][0] + grid[1][1] + grid[2][2] != 15)
        return 0;
    if (grid[0][2] + grid[1][1] + grid[2][0] != 15)
        return 0;
}

int contains(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return 1;
        }
    }
    return 0;
}

void populateRandomSquare(int grid[3][3]) {
    int count = 0; 
    int numbers[9];

    while (count < 9) {
        int num = (rand() % 9) + 1; 

        if (!contains(numbers, count, num)) {
            numbers[count] = num;
            count++; 
        }
    }

    for (int i = 0, index = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            grid[i][j] = numbers[index++];
        }
    }
}

void printMagicSquare(int grid[3][3]) {
    printf("[%d %d %d]\n", grid[0][0], grid[0][1], grid[0][2]);
    printf("[%d %d %d]\n", grid[1][0], grid[1][1], grid[1][2]);
    printf("[%d %d %d]\n", grid[2][0], grid[2][1], grid[2][2]);
}

int main(void) { 
    // int magicSquare[3][3] = {
    //     {4, 9, 2},
    //     {3, 5, 7},
    //     {8, 1, 6}
    // };

    // int nonMagicSquare[3][3] = {
    //     {1, 2, 3},
    //     {4, 5, 6},
    //     {7, 8, 9}
    // };

    // printf("Testing real magic square:\n");
    // if (magicSquareTest(magicSquare))
    //     printf("This is a Lo Shu Magic Square!\n");
    // else
    //     printf("This is NOT a Lo Shu Magic Square.\n");

    // printf("\nTesting not real magic square:\n");
    // if (magicSquareTest(nonMagicSquare))
    //     printf("This is a Lo Shu Magic Square!\n");
    // else
    //     printf("This is NOT a Lo Shu Magic Square.\n");
    // return 0;

    srand(time(0));

    int grid[3][3];
    int attempts = 0;

    do {
        populateRandomSquare(grid);
        attempts++;
    } while (!magicSquareTest(grid));

    printf("Attempts before success: %d\n", attempts);

    printMagicSquare(grid);

    return 0;
}