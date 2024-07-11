#include "libft.h"

int ft_strcmp(const char *s1, const char *s2)
{
    size_t i;
    unsigned char st1;
    unsigned char st2;

    i = 0;
    while (s1[i] != '\0' || s2[i] != '\0') {
        st1 = (unsigned char)s1[i];
        st2 = (unsigned char)s2[i];
        if (st1 == st2) {
            i++;
        } else {
            return (st1 - st2);
        }
    }
    return (0);
}