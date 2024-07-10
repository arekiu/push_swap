#include "push_swap.h"

int is_int(char *str)
{
    int i;

    i = 0;
    if(str[i] == '-' || str[i] == '+')
        i++;
    while(str[i] != '\0')
    {
        if (!ft_isdigit(str[i]))
            return (0);
        i++;            
    }
    return (1);
}

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
		i++;
	}
    return (num_arr);
}

int	*parse_str(char *str)
{
	int		*num_arr;
	int		i;
	int		len;
	char	**str_arr;

	i = 0;
	len = 0;
	str_arr = ft_split(str, ' ');
	while(str_arr[len] != NULL)
		len++;
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
    num_arr = parse_str2(str_arr, len);
	free_str_arr(str_arr);
	return (num_arr);
}

int *parse_multi(int argc, char *argv[])
{
    int i;
    int		*num_arr;

    i = 0;
    num_arr = malloc(sizeof(int) * (argc - 1));
    if (!num_arr)
        return (NULL);
    while (i < argc - 1)
    {   
        if(!is_int(argv[i + 1]))
        {
            ft_printf("invalid input\n");
            free (num_arr);
            return (0);
        }
        num_arr[i] = ft_atoi(argv[i + 1]);
		i++;
    }
    return (num_arr);
}

int   parse_input(int argc, char *argv[])
{
    int *int_arr;
    int i;

    if (argc == 2)
    {
        if(count_nums(argv[1], ' ') == 1)
            return (0);
        int_arr = parse_str(argv[1]);
    }
    else 
        int_arr = parse_multi(argc, argv);
    if (!int_arr)
            return (0);
    i = 0;
	while (i < 4)
	{
		ft_printf("El num %d\n", int_arr[i]);
		i++;
	}
	free (int_arr);
    return (1);
}