#include <stdio.h>
#include <stdint.h>

static int x = 0b00000000;

void turn_on_a_bit(uint8_t n)
{
    x |= (1<<n);
}

void turn_off_a_bit(uint8_t n)
{
    x &=~(1<<n);
}

void turn_toggle_a_bit(uint8_t n)
{
    x ^=(1<<n);
}

uint8_t check_bit (uint8_t n)
{
    uint8_t check = x & (1<<n);
    return check;
}

void swap_non_temp(int a, int b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    printf("%d\n",a);
    printf("%d\n",b);
}

void check_power_of_two (int a)
{
    int check = a & (a-1);

    switch (check)
    {
    case 0:
        printf("%d is power of two",a);
        break;
    
    default:
        printf("%d is not power of two",a);
        break;
    }
}

void odd_or_even(int a)
{
    int check = a & 1;
    switch (check)
    {
    case 0:
        printf("%d is even",a);
        break;
    case 1:
        printf("%d is odd",a);
        break;
    
    default:
        printf("%d is unknown number",a);
        break;
    }
}

void check_equal(int a, int b)
{
    int check = a ^ b;

    switch (check)
    {
    case 0:
        printf("%d is equal %d",a,b);
        break;
    case 1:
        printf("%d is not equal %d",a,b);
        break;
    
    default:
        printf("%d,%d is unknown number",a,b);
        break;
    }
}

void two_implement(int a)
{
    int check = ~a + 1;
    printf("%d",check);
}

void multipler_of_eight(int a)
{
    int check = a & 7;

    switch (check)
    {
    case 0:
        printf("%d is multipler_of_eight\n",a);
        break;
    case 1:
        printf("%d is multipler_of_eight\n",a);
        break;
    
    default:
        printf("%d is unknown number",a);
        break;
    }
}

void find_position_msb(int a) 
{
    static int index = -1;
    
    while (0 != a)
    {
        a >>= 1;
        index++;
    }
    
    printf("%d",index);
}

void find_position_lsb(int a) 
{
    /* -a as 2's compilment ( bu` 2 ) */
    printf("%d", a & (-a));
}

void turn_off_right_most(int a)
{
    printf("%d",a & (a-1));
}

void isolation_bit (int a) {
    printf("%d", a & -a);
}

int main(void) 
{
    
}