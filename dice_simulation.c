/*

Program to calculate the probability of getting at least one pair of numbers from rolling three die at the same time.

Works by simulating all possible combinations and checking each one whether or not there is a pair between (1) Dice 1 and Dice 2, (2) Dice 1 and Dice 3 and (3) Dice 2 and Dice 3

*/

#include <stdio.h>

void updateDice(int* D1, int* D2, int* D3){
    if (*D1 != 6){
        if(*D2 == 6 && *D3 == 6){
            *D1 = *D1 + 1;
        }
    }
    
    if (*D2 != 6){
        if(*D3 == 6){
            *D2 = *D2 + 1;
        }
    } else{
        if(*D3 == 6){
            *D2 = 1;
        }
    }
    
    if (*D3 != 6){
        *D3 = *D3 + 1;
    } else{
        *D3 = 1;
    }
}

int pairCalculation(int* D1, int* D2, int* D3){
    if(*D1 == *D2){
        return 1;
    } else if(*D1 == *D3){
        return 1;
    } else if (*D2 == *D3) {
        return 1;
    } else{
        return 0;
    }
}

int main(){

    //Initialising variables
    int Dice1 = 1;
    int Dice2 = 1;
    int Dice3 = 1;
    int* D1 = &Dice1;
    int* D2 = &Dice2; 
    int* D3 = &Dice3;
    int isAPair = 0;

    printf("Program to calculate the probability of getting at least one pair of numbers from rolling three die at the same time. \n");

    // Total possible number of combinations are 216 (6 x 6 x 6). Will use this number as a check on the dice combinations
    for (int i = 0; i <= 215; i++){
        printf("Dice Combination [%d]: %d %d %d \n", i, Dice1, Dice2, Dice3);
        isAPair = isAPair + pairCalculation(D1, D2, D3);
        updateDice(D1, D2, D3);
    }

    printf("The probability is %d / 216", isAPair);

    return 0;

}

