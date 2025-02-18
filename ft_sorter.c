#include "push_swap.h"
void big_sort(t_stack_node **a, t_stack_node **b)
{
    int size = stack_len(*a);
    int max_bits = 0;
    int i;
    int j;
    int num;

    // Trouver le nombre maximum de bits nécessaires
    t_stack_node *tmp = *a;
    while (tmp)
    {
        num = tmp->data;
        i = 0;
        while ((num >> i) != 0)
            i++;
        max_bits = (i > max_bits) ? i : max_bits;
        tmp = tmp->next;
    }

    // Trier pour chaque bit
    for (i = 0; i < max_bits; i++)
    {
        for (j = 0; j < size; j++)
        {
            num = (*a)->data;
            // Si le bit actuel est 0, push vers B
            if ((num >> i) & 1)
                ra(a);
            else
                pb(a, b);
        }
        // Ramener tous les nombres de B vers A
        while (*b)
            pa(a, b);
    }
}