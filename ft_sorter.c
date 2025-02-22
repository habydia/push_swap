#include "push_swap.h"

t_stack_node *find_min(t_stack_node *stack)
{
    t_stack_node *min_node = stack;
    while (stack)
    {
        if (stack->data < min_node->data)
            min_node = stack;
        stack = stack->next;
    }
    return min_node;
}

t_stack_node *find_max(t_stack_node *stack)
{
    t_stack_node *max_node = stack;
    while (stack)
    {
        if (stack->data > max_node->data)
            max_node = stack;
        stack = stack->next;
    }
    return max_node;
}

int is_next_min_or_max(t_stack_node *a, t_stack_node *b)
{
    if (!a || !b)
        return 0; // Aucun élément à comparer

    t_stack_node *min_b = find_min(b);
    t_stack_node *max_b = find_max(b);

    if (a->data < min_b->data)
        return -1; // a est le nouveau min
    if (a->data > max_b->data)
        return 1;  // a est le nouveau max

    return 0; // a n'est ni le min ni le max
}


int get_closest_to_min_or_max(t_stack_node *a, t_stack_node *b)
{
    if (!a || !b)
        return 0; // Sécurité : éviter les erreurs sur liste vide

    t_stack_node *min_b = find_min(b);
    t_stack_node *max_b = find_max(b);

    int dist_min = abs(a->data - min_b->data);
    int dist_max = abs(a->data - max_b->data);

    if (dist_min < dist_max)
        return -1; // Plus proche du min
    return 1;      // Plus proche du max
}


void parse_b(t_stack_node **a, t_stack_node **b) {
    while (stack_len(*a) > 3) { // Keep 3 elements in A
        t_stack_node *max_b = (*b) ? find_max(*b) : NULL;

        if (is_next_min_or_max(*a, *b) == 1) { // `a` is the new max in `b`
            if (*b && max_b && (*b)->data != max_b->data)
                rotate_until_top(b, max_b->data, 'b');
            pb(a, b);
        } 
        else if (is_next_min_or_max(*a, *b) == -1) { // `a` is the new min in `b`
            pb(a, b);
            if (*b && (*b)->next) // Prevent rotating when `b` has 1 element
                rotate(b, 'b');
        } 
        else { // Neither min nor max → find closest position
            if (get_closest_to_min_or_max(*a, *b) == -1) { // Closer to min
                if (*b) rotate_until_top(b, find_min(*b)->data, 'b');
            } 
            else { // Closer to max
                if (*b) rotate_until_bottom(b, find_max(*b)->data, 'b');
            }
            pb(a, b);
        }
    }
}


int find_best_insert_position(t_stack_node *a, int value) {
    if (!a) return 0;

    int index = 0, best_index = 0;
    t_stack_node *current = a;
    t_stack_node *min_node = find_min(a);
    t_stack_node *max_node = find_max(a);

    // Case 1: Smallest element, insert before min
    if (value < min_node->data)
        return get_position(a, min_node->data);

    // Case 2: Largest element, insert after max
    if (value > max_node->data)
        return (get_position(a, max_node->data) + 1) % stack_len(a);

    // Case 3: Normal insertion between two values
    while (current->next) {
        if (current->data < value && current->next->data > value)
            return index + 1;
        index++;
        current = current->next;
    }

    return best_index; // Fallback (shouldn't be reached)
}

void move_to_position(t_stack_node **a, int pos, char stack_name) {
    int len = stack_len(*a);

    if (pos <= len / 2) { // Move upwards
        while (pos-- > 0)
            rotate(a, stack_name);
    } else { // Move downwards
        pos = len - pos;
        while (pos-- > 0)
            reverse_rotate(a, stack_name);
    }
}

void reintegrate_sorted(t_stack_node **a, t_stack_node **b)
{
    while (*b)
    {
        // Find the best position in 'a' to insert b's top element
        int best_pos = find_best_insert_position(*a, (*b)->data);
        
        // Move 'a' to that position before inserting
        move_to_position(a, best_pos, 'a');
        
        pa(a, b);
    }

    // Ensure the smallest element is at the top
    rotate_until_top(a, find_min(*a)->data, 'a');
}


void sorter(t_stack_node **a, t_stack_node **b)
{

    // Étape 1 : Initialisation de b en vidant a (sauf les 3 derniers éléments pour `little_sort`)
    // Étape 2 : Trier les 3 derniers éléments restants dans a
    
    // Étape 3 : Trier b en insérant les éléments de a de manière ordonnée
        parse_b(a, b);
    little_sort(a); //trier les 3 derniers elements de la pile_a
    // Étape 4 : Réinsérer les éléments triés de b dans a
    reintegrate_sorted(a, b);
}

