#include "push_swap.h"

t_list *add_new(int value)
{
    t_list  *new_node;

    new_node = (t_list *)malloc(sizeof(t_list));
    if (!new_node)
        return (NULL);
    new_node->value = value;
    new_node->next = NULL;
    return (new_node);
}

void    append_node(t_list **head, int value)
{
    t_list *new_node;
    t_list *current;
    
    new_node = add_new(value);
    if (!new_node)
        return;
    if (*head == NULL)
        *head = new_node;
    else
    {
        current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_node;
    }
}

void print_list(t_list *head)
{
    t_list *current;
    
    current = head;
    while (current != NULL)
    {
        ft_printf("%d -> ", current->value);
        current = current->next;
    }
    ft_printf("NULL\n");
}

void free_list(t_list *head)
{
    t_list *current;
    
    current = head;
    while (current != NULL)
    {
        t_list *next = current->next;
        free(current);
        current = next;
    }
}

