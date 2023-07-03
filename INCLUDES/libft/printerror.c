/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printerror.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoulet <jsoulet@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:55:08 by jsoulet           #+#    #+#             */
/*   Updated: 2023/06/28 14:05:41 by jsoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	printerror(char *msg, int option)
{
	if (!msg)
		return (-1);
	ft_printf("%s\n", msg);
	if (option == 0)
		return (0);
	exit (0);
}
