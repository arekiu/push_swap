#include "push_swap.h"

void free_str_arr(char **str_arr)
{
    int i;

    i = 0;
    while (str_arr[i] != NULL)
    {
        free(str_arr[i]);
        i++;
    }
    free(str_arr);
}

int *free_invalid(int *int_arr)
{
    ft_printf("Invalid input\n");
    free (int_arr);
    return (0);
}