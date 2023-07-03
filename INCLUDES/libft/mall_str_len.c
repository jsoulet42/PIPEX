/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mall_str_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoulet <jsoulet@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:02:40 by jsoulet           #+#    #+#             */
/*   Updated: 2023/06/28 15:23:02 by jsoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*mall_str_len(char *str)
{
	int		i;
	char	*temp;

	i = ft_strlen(str) + 1;
	temp = ft_calloc(sizeof(char), i);
	if (!temp)
		return (NULL);
	return (temp);
}
