/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 10:54:24 by dbegara-          #+#    #+#             */
/*   Updated: 2021/04/14 20:51:00 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libps/libps.h"
#include "libft/libft.h"

char	*ft_strtok_ps(char *str, char delim)
{
	while(*str)
	{
		if (*str == delim)
		{
			while (*str == delim)
			{
				*str = 0;
				str++;
			}
			return (str);
		}
		str++;
	}
	return (0);
}

int		ft_atoi(char *num)
{
	int		new_num;
	int		neg;

	new_num = 0;
	neg = 1;
	if (*num == '-')
	{
		neg = -1;
		num++;
	}
	while (ft_isdigit(*num))
	{
		new_num *= 10;
		new_num += *num - 48;
		num++;
	}
	new_num *= neg;
	return (new_num);
}

void	fill_stack_loop(int i, int argc, t_stack **stack, char **argv)
{
	char *tmp;

	tmp = argv[i];
	if ((tmp = ft_strtok_ps(tmp, ' ')) != 0)
	{
		if (!*stack)
			*stack = ft_stknew(ft_atoi(argv[i]));
		else
			ft_stkadd_back(stack, ft_stknew(ft_atoi(argv[i])));
		ft_stkadd_back(stack, ft_stknew(ft_atoi(tmp)));
		while ((tmp = ft_strtok_ps(tmp, ' ')) != 0)
			ft_stkadd_back(stack, ft_stknew(ft_atoi(tmp)));
	}
	else
	{
		if (!*stack)
			*stack = ft_stknew(ft_atoi(argv[i]));
		else
			ft_stkadd_back(stack, ft_stknew(ft_atoi(argv[i])));
	}
}

t_stack	*fill_stack(int argc, char **argv)
{
	int		num;
	t_stack	*stack;
	char	*tmp;
	int		i;

	stack = 0;
	i = 1;
	while (i < argc)
	{
		fill_stack_loop(i, argc, &stack, argv);
		i++;
	}
	return (stack);
}

int		main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	stack_a = fill_stack(argc, argv);
	stack_b = NULL;
	//ft_stkswap(stack_a);
	//ft_stkdel_front(&stack_a);
	//ft_stkadd_front(&stack_a, ft_stknew(4));
	//ft_stkdel_back(&stack_a);
	ft_stkpush(&stack_b, &stack_a);
	ft_stkrotate(&stack_a);
	ft_stkrotate_rev(&stack_a);
	printf("\nStack A | Stack B\n");
	printf("_________________\n\n");
	t_stack *tmp_a = stack_a;
	t_stack	*tmp_b = stack_b;
	while (1)
	{	
		if (tmp_a)
		{
			printf("%d   ", tmp_a->num);
			tmp_a = tmp_a->next;
		}
		else if (!tmp_b)
			break;
		if (tmp_b)
		{
			printf("     %d   ", tmp_b->num);
			tmp_b = tmp_b->next;
		}
		printf("\n\n");
	}
	ft_stkclear(&stack_a);
	system("leaks checker");
	return (0);
}
