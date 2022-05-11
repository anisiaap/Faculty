/*3) Implement a function that receives an array of integers and its capacity and fills the array with all the values read from the
 keyboard which are prime numbers, without overflowing the array. The keyboard input might consist of other
 data (words) that are to be ignored. Return the numbers of elements copied into the array. Also, provide an adequate main() function.*/
#include <stdio.h>

void func(int arr[], int cap)
{
    int x;
    if (scanf("%d", &x) != 1)
    {
        printf("error reading\n");
    }
    int index = 0;
    int ok = 1;
    while (index < cap)
    {
        for (int d = 2; d < x; d++)
        {
            if (x % d == 0)
            {
                ok = 0;
                //index++;
                break;
            }
        }
        if (ok == 1)
        {
            arr[index] = x;
            index++;
        }
        ok = 1;
        while (scanf("%d", &x) != 1)
        { //eat what is not ok
        }

        if (index == cap)
        {
            break;
        }
    }
    for (int i = 0; i < index; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int arr[2];
    int cap = 2;
    func(arr, cap);
    return 0;
}