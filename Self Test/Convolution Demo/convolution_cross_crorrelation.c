#include <stdio.h>

int main(void){
    int input[] = {1,2,3,4,5};
    int kernel[] = {1,0,1};

    int output[3];

    for (int i = 0; i < 3; i++)
    {
        output[i]=0;
        for (int j = 0; j < 3 ; j++)
        {
            output[i] += kernel[j] * input[i+j];
        }
    }
    
    for (int i = 0; i < 3; i++)
    {
        printf(" %d ",output[i]);
    }
    
}