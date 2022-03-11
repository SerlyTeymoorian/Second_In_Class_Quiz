#include "LoShuMagicSquare.h"

bool LoShouMagicSquareTest(int arr[3][3])
{
    //keeps track of sum of each row 
    int rowSum[3] ={0,0,0}; 
    int colSum[3] = {0,0,0}; 

    int diag1 = arr[0][0] + arr[1][1] + arr[2][2]; //add up diag1 from L to R
    int diag2 = arr[0][2] + arr[1][1] + arr[2][0]; //add up diag2 from R to L
    
    if(diag1 == diag2)
    {
        for(int row =0; row <3; ++row) //traverses each row 
        {
            for(int col=0; col <3; ++col) //traverses each col 
            {
                rowSum[row] += arr[row][col]; //saving sum of rows 
                colSum[col] += arr[row][col]; //saving sum of columns 
            }
        }
        if(rowSum[0] == rowSum[1] && rowSum[1] == rowSum[2] && rowSum[2] == colSum[0] && colSum[0] == colSum[1] && colSum[1] == colSum[2] && colSum[2] == diag1)
            return true; 
        else
            return false; 
    }
    else
        return false; 
}