/***********************************************************************************************/
                                    /*NOTES DURING CLASS*/

// avem un rucsac, cu valoare si greutate
// capacitate=W
// v maxim?
// ordonam raportul V/W descrescator, luam pe primul si scadem capacitatea cu w celui de dinainte,
//  daca intra ok daca nu, (capacitatea ramasa si o impartim cu W ul lui)*valoarea lui
// adunam valorile maxime sau raport din ultimul
/************************************************************************************************/
#include <stdio.h>
#include <string.h>

struct backpack
{
    int weight, value;
    double ratio;
};
typedef struct backpack backpack_T;

void bubble_sort(backpack_T arr[], int n)
{
    int i, ok;
    backpack_T aux;

    do
    {
        ok = 1;
        for (i = 1; i < n; i++)
        {
            if (arr[i].ratio < arr[i + 1].ratio)
            {
                aux = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = aux;
                ok = 0;
            }
        }
    } while (ok == 0);
}

double putinbackpack(backpack_T arr[], int n, int cap)
{
    int bp_weight = 0;
    double bp_value = 0;
    int new_weight = 0;

    for (int i = 1; (i <= n) && (bp_weight < cap); i++)
    {
        new_weight = bp_weight + arr[i].weight;
        if (new_weight <= cap)
        {
            bp_weight = new_weight;
            bp_value += arr[i].value;
        }

        else
        {
            bp_value += arr[i].value * ((double)(cap - bp_weight) / arr[i].weight);
            bp_weight = cap; // whenever we exceed, we belive it is full
        }
    }

    return bp_value;
}

int main()
{

    int cap = 0, count_obj = 0, x;
    backpack_T backpack_arr[101];
    double backpack_max_value;

    printf("Type the capacity: ");
    scanf("%d", &cap);
    printf("\n");

    int i = 1;

    do
    {
        
        printf("type weight of object number %d or press  if you don't want to add more objects into the backpack: ", i);
        scanf("%d", &x);

        count_obj++;
        backpack_arr[i].weight = x;
        printf("\n");

        printf("type value of object number %d: ", i);
        scanf("%d", &backpack_arr[i].value);
        printf("\n");

        backpack_arr[i].ratio = (double)backpack_arr[i].value / backpack_arr[i].weight;
        i++;
    } while (x != '@');

    bubble_sort(backpack_arr, count_obj);

    backpack_max_value = putinbackpack(backpack_arr, count_obj, cap);
    printf("The maximum value of the backpack is %f\n", backpack_max_value);

    return 0;
}