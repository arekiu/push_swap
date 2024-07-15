#include "libft.h"

long long ft_atoll(const char *str)
{
    int i;
    int negative;
    long long new_num;
    
    i = 0;
    negative = 1;
    new_num = 0;
    while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
        i++;
    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            negative = -1;
        if (str[i + 1] == '+' || str[i + 1] == '-')
            return 0;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        if (new_num > (LLONG_MAX - (str[i] - '0')) / 10)
        {
            if (negative == 1)
                return LLONG_MAX;
            else
                return LLONG_MIN;
        }
        new_num = (new_num * 10) + (str[i] - '0');
        i++;
    }
    return new_num * negative;
}