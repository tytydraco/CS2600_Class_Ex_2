#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int LO_SHU_VALID[3][3] = {
    {4, 9, 2},
    {3, 5, 7},
    {8, 1, 6}
};

int LO_SHU_INVALID[3][3] = {
    {9, 1, 2},
    {3, 4, 5},
    {6, 7, 8}
};

bool search_square(int square[3][3], int find) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (square[i][j] == find)
                return true;
    return false;
}

bool has_1_thru_9(int square[3][3]) {
    for (int i = 1; i < 10; i++)
        if (!search_square(square, i))
            return false;
    return true;
}

bool check_columns(int square[3][3]) {
    int sum;
    for (int i = 0; i < 3; i++) {
        sum = 0;
        for (int j = 0; j < 3; j++) {
            sum += square[i][j];
        }

        if (sum != 15)
            return false;
    }

    return true;
}

bool check_rows(int square[3][3]) {
    int sum;
    for (int i = 0; i < 3; i++) {
        sum = 0;
        for (int j = 0; j < 3; j++) {
            sum += square[j][i];
        }

        if (sum != 15)
            return false;
    }

    return true;
}

bool check_diagonals(int square[3][3]) {
    int sum;
    
    if (square[0][0] + square[1][1] + square[2][2] != 15)
        return false;
    
    if (square[0][2] + square[1][1] + square[2][0] != 15)
        return false;

    return true;
}

bool is_valid_square(int square[3][3]) {
    if (!has_1_thru_9(square))
        return false;

    if (!check_columns(square))
        return false;

    if (!check_rows(square))
        return false;

    if (!check_diagonals(square))
        return false;
    
    return true;
}

void roll_for_valid_square() {
    int tries = 0;

    while (true) {
        int cur_i = 0;
        int cur_j = 0;
        int square[3][3] = {};

        while (true) {
            int r = rand() % 9 + 1;
            if (search_square(square, r))
                continue;
            square[cur_i][cur_j] = r;

            if (cur_i == 2) {
                cur_i = 0;
                cur_j++;
            } else
                cur_i++;

            if (cur_j == 3)
                break;
        }

        printf("TRYING:");
        for (int i = 0; i < 3; i++) {
            printf("\n");
            for (int j = 0; j < 3; j++)
                printf("%d ", square[i][j]);
        }
        printf("\n\n");

        if (is_valid_square(square)) {
            printf("SUCCEEDED\n");
            break;
        }

        tries++;
    }

    printf("TOOK %d TRIES\n", tries);
}

int main() {
    time_t t;
    srand((unsigned) time(&t));

    if (is_valid_square(LO_SHU_VALID))
        printf("SQUARE IS VALID\n");
    else
        printf("SQUARE IS NOT VALID\n");

    roll_for_valid_square();
    
    return 0;
}