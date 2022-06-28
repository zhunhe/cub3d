/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 18:25:12 by juhur             #+#    #+#             */
/*   Updated: 2022/06/28 17:33:24 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

size_t	_strlen(const char *s)
{
	const char	*e;

	e = s;
	while (*e != '\0')
		++e;
	return (e - s);
}
