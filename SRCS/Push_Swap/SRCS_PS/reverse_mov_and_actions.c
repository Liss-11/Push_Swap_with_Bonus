/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_mov_and_actions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrolova <afrolova@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 22:18:45 by afrolova          #+#    #+#             */
/*   Updated: 2022/08/30 15:00:01 by afrolova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../INC/push_swap.h"

void	rra_action(t_stack *a)
{
	if (a->length > 1)
	{
		mov_rra_rrb_rrr(a);
		write(1, "rra\n", 4);
	}
}

void	rrb_action(t_stack *b)
{
	if (b->length > 1)
	{
		mov_rra_rrb_rrr(b);
		write(1, "rrb\n", 4);
	}
}

void	rrr_action(t_stack *a, t_stack *b)
{
	if (a->length > 1 || b->length > 1)
	{
		mov_rra_rrb_rrr(a);
		mov_rra_rrb_rrr(b);
		write(1, "rrr\n", 4);
	}
}

void	mov_rra_rrb_rrr(t_stack *stack)
{
	t_element	*tmp;

	if (stack->length < 2)
		return ;
	tmp = stack->bottom_element;
	stack->bottom_element = tmp->prev;
	stack->bottom_element->next = NULL;
	tmp->next = stack->top_element;
	tmp->prev = NULL;
	stack->top_element->prev = tmp;
	stack->top_element = tmp;
}
