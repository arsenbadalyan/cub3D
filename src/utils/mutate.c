/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsbadal <arsbadal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 19:16:11 by arsbadal          #+#    #+#             */
/*   Updated: 2023/07/08 19:16:12 by arsbadal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

size_t	get_2d_array_length(void **array)
{
	size_t	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

char	**init_2d_array(void)
{
	char	**arr;

	arr = (char **)malloc(sizeof(char *));
	if (!arr)
		return (NULL);
	arr[0] = NULL;
	return (arr);
}

char	**push_to_double_array(char **arr, char *new_line)
{
	char	**new_arr;
	size_t	size;

	if (!arr)
		arr = init_2d_array();
	if (!arr)
		return (NULL);
	size = get_2d_array_length((void **)arr) + 2;
	new_arr = (char **)malloc(sizeof(char *) * size);
	if (!new_arr)
		return (NULL);
	new_arr[size - 2] = new_line;
	new_arr[size - 1] = NULL;
	size = 0;
	while (arr[size])
	{
		new_arr[size] = arr[size];
		size++;
	}
	free(arr);
	return (new_arr);
}
