#include "push_swap.h"
#include "libft/libft.h"

static int find_biggest(t_stack *stack)
{
    int biggest = stack->stack[0];
    int i = 0;
    while (i < stack->size)
    {
        if (stack->stack[i] > biggest)
            biggest = stack->stack[i];
        i++;
    }
    return biggest;
}
static int find_smallest(t_stack *stack)
{
    int smallest = stack->stack[0];
    int i = 0;
    while (i < stack->size)
    {
        if (stack->stack[i] < smallest)
            smallest = stack->stack[i];
        i++;
    }
    return smallest;
}
void sort_five_numbers(t_stack *stack_a, t_stack *stack_b)
{
    int i = 0;
    int biggest = stack_a->stack[0];
    int smallest;
    if (stack_a->size < 5)
        return;

    smallest = find_smallest(stack_a);
    push_to_stack(stack_a, stack_b);
    push_to_stack(stack_a, stack_b);
    sort_three_numbers(stack_a);
    biggest = find_biggest(stack_a);
    while (stack_b->size != 0)
    {
        if (stack_b->stack[0] > biggest)
        {
            while (stack_a->stack[0] != biggest)
                rotate_stack(stack_a);
            biggest = stack_b->stack[0];
            rotate_stack(stack_a);
            push_to_stack(stack_b, stack_a);
        }
        else
        {

            if (stack_b->stack[0] <= stack_a->stack[0])
                push_to_stack(stack_b, stack_a);
            else
                rotate_stack(stack_a);
        }
    }
    while (stack_a->stack[0] != smallest)
        rotate_stack(stack_a);
    print_stack(stack_a);
}
