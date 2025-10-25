#include <stdio.h>

int main(void){
    int input[] = {1,2,3,4,5};
    int kernel[] = {1,4,6};
    int kernel_flipped[3];

    int output[7];

    for (int i = 0; i < sizeof(kernel) / sizeof(int); i++)
    {
        kernel_flipped[i] = kernel[2-i];
    }
    
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < sizeof(kernel) / sizeof(int); j++)
        {
            
        }
    }
    

    // for (int i = 0; i < 3; i++)
    // {
    //     printf("%d",kernel_flipped[i]);
    // }
    

    
}