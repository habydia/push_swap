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

void parse_b(t_stack_node **a, t_stack_node **b, int size) {
    int chunk_size = size / 5; // Divide into 5 chunks
    int min = find_min(*a)->data;
    int pivot = min + chunk_size;
    int pushed = 0;

    while (stack_len(*a) > 3) {
        if ((*a)->data <= pivot) { 
            pb(a, b);
            pushed++;
            if (*b && stack_len(*b) > 1 && (*b)->data < pivot - (chunk_size / 2)) {
                rotate(b, 'b'); // Keep smaller elements lower
            }
        } else {
            if (pushed < chunk_size) {  
                rotate(a, 'a'); // Rotate only if we haven’t pushed enough
            } else {
                pivot += chunk_size; // Move to the next chunk
                pushed = 0; // Reset counter for next chunk
            }
        }
    }
}

int calculate_move_cost(t_stack_node *a, t_stack_node *b, int value) {
    int pos_in_a = find_best_insert_position(a, value);
    int pos_in_b = get_position(b, value);
    int len_a = stack_len(a);
    int len_b = stack_len(b);

    int move_b;
    if (pos_in_b <= len_b / 2) {
        move_b = pos_in_b;
    } else {
        move_b = len_b - pos_in_b;
    }

    int move_a;
    if (pos_in_a <= len_a / 2) {
        move_a = pos_in_a;
    } else {
        move_a = len_a - pos_in_a;
    }

    return move_a + move_b;
}

t_stack_node *find_best_element_to_move(t_stack_node *a, t_stack_node *b) {
    t_stack_node *best = b;
    t_stack_node *current = b;
    int min_cost = calculate_move_cost(a, b, current->data);

    while (current) {
        int cost = calculate_move_cost(a, b, current->data);
        if (cost < min_cost) {
            min_cost = cost;
            best = current;
        }
        current = current->next;
    }

    return best;
}

void move_to_position(t_stack_node **stack, int pos, char stack_name) { 
    int len = stack_len(*stack);
    if (pos == 0) return;

    int half = len / 2;
    if (pos <= half) {
        while (pos-- > 0)
            rotate(stack, stack_name);
    } else {
        pos = len - pos;
        while (pos-- > 0)
            reverse_rotate(stack, stack_name);
    }
}


void reintegrate_sorted(t_stack_node **a, t_stack_node **b) {
    while (*b) {
        t_stack_node *best = find_best_element_to_move(*a, *b);
        move_to_position(b, get_position(*b, best->data), 'b');
        move_to_position(a, find_best_insert_position(*a, best->data), 'a');
        pa(a, b);
    }

    // Ensure final stack is sorted
    rotate_until_top(a, find_min(*a)->data, 'a');
}

void sorter(t_stack_node **a, t_stack_node **b) {
    int size = stack_len(*a);
    
    // Push sorted chunks into `b`
    parse_b(a, b, size);
    
    // Sort remaining 3 elements in `a`
    little_sort(a);
    
    // Efficiently reintegrate sorted elements from `b` to `a`
    reintegrate_sorted(a, b);
}

