#include "LoShuMagicSquare.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int testArray[3][3] = {{0,0,0},{0,0,0},{0,0,0}};  
    int numOfTesting =0; 
    time_t t; 
    srand((unsigned)time(&t));
    
    do
    {
        int numUsed[10] = {0,0,0,0,0,0,0,0,0,0}; 
        for(int row =0; row <3; ++row)
        {
            for(int col =0; col <3; ++col)
            {
                int randomNumber = rand()% 9 +1; //random number between 1-9
                while(numUsed[randomNumber] ==1)
                {
                    randomNumber = rand()%9+1; 
                }
                testArray[row][col] = randomNumber; 
                numUsed[randomNumber] = 1; 
            }  
        }
        ++numOfTesting; //The total number of squares generated and tested before success, the count 
   } while (!LoShouMagicSquareTest(testArray));

    printf("\nThe total number of squares generated and tested before success is: %d\n", numOfTesting);

    for(int i=0; i <3; ++i)
    {
        printf("["); 
        for(int j=0; j<3;++j)
        {
            printf("%d ", testArray[i][j]);
        }
        printf("]\n"); 
    }
    printf("\n");

    return EXIT_SUCCESS; 
}