/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttikanoj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:53:47 by ttikanoj          #+#    #+#             */
/*   Updated: 2022/11/16 13:55:59 by ttikanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	int	a;

	if ((c > 64 && c < 91) || (c > 96 && c < 123))
		a = 1;
	else if (c > 47 && c < 58)
		a = 1;
	else
		a = 0;
	return (a);
}
