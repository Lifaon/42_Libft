/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_white_spaces.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 16:43:56 by mlantonn          #+#    #+#             */
/*   Updated: 2018/05/01 19:33:47 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	is_white_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

static int	get_word_nb(char *str)
{
	int i;
	int nb;

	i = 0;
	while (is_white_space(str[i]))
		++i;
	nb = 0;
	while (str[i])
	{
		++nb;
		while (str[i] && !(is_white_space(str[i])))
			++i;
		while (is_white_space(str[i]))
			++i;
	}
	return (nb);
}

static char	*copy_word(char *str)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	while (str[i] && !(is_white_space(str[i])))
		i++;
	if (!(ret = (char *)malloc(sizeof(char) * (i + 1))))
	{
		perror("Error ");
		return (NULL);
	}
	j = -1;
	while (++j < i)
		ret[j] = str[j];
	ret[j] = '\0';
	return (ret);
}

static void	*free_arr_and_return_null(char **arr, int index)
{
	int i;

	i = -1;
	perror("Error ");
	while (++i < index)
		free(arr[i]);
	free(arr);
	return (NULL);
}

char		**ft_split_white_spaces(char *str)
{
	char	**arr;
	int		word_nb;
	int		i;
	int		j;

	if (!(word_nb = get_word_nb(str)))
		return (NULL);
	if (!(arr = (char **)malloc(sizeof(char *) * (word_nb + 1))))
	{
		perror("Error ");
		return (NULL);
	}
	i = -1;
	j = 0;
	while (++i < word_nb)
	{
		while (is_white_space(str[j]))
			j++;
		if (!(arr[i] = copy_word(str + j)))
			return (free_arr_and_return_null(arr, i));
		while (str[j] && !(is_white_space(str[j])))
			j++;
	}
	arr[i] = NULL;
	return (arr);
}
