#include "push_swap.h"

int *parse_str2(char *str_arr[], int len)
{
    int		*num_arr;
    int     i;

    i = 0;
    num_arr = malloc(sizeof(int) * len);
	if (!num_arr)
	{
		free_str_arr(str_arr);
		return (0);
	}
	while (i < len)
	{
		num_arr[i] = ft_atoi(str_arr[i]);
        if (num_arr[i] > INT_MAX || num_arr[i] < INT_MIN)
            return(free_invalid(num_arr));
		i++;
	}
    return (num_arr);
}

int	*parse_str(char *str)
{
	int		*num_arr;
	int		i;
	char	**str_arr;

	i = 0;
	str_arr = ft_split(str, ' ');
    if (has_duplicates(str_arr))
    {
        free_str_arr(str_arr);
        return (0);
    }
    while (str_arr[i] != NULL)
    {
        if(!is_int(str_arr[i]))
        {
            ft_printf("invalid input\n");
            free_str_arr(str_arr);
            return (0);
        }
        i++;
    }
    num_arr = parse_str2(str_arr, i);
	free_str_arr(str_arr);
	return (num_arr);
}

int *parse_multi(int argc, char *argv[])
{
    int i;
    int		*num_arr;

    i = 0;
    if (has_duplicates(argv))
        return (0);
    num_arr = malloc(sizeof(int) * (argc - 1));
    if (!num_arr)
        return (NULL);
    while (i < argc - 1)
    {   
        if(!is_int(argv[i + 1]))
            return(free_invalid(num_arr));
        num_arr[i] = ft_atoi(argv[i + 1]);
        if (num_arr[i] > INT_MAX || num_arr[i] < INT_MIN)
            return(free_invalid(num_arr));
		i++;
    }
    return (num_arr);
}

int   *parse_input(int argc, char *argv[])
{
    int *int_arr;

    if (argc == 2)
        int_arr = parse_str(argv[1]);
    else 
        int_arr = parse_multi(argc, argv);
    if (!int_arr)
            return (0);
    return (int_arr);
}