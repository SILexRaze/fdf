/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 12:12:58 by vifonne           #+#    #+#             */
/*   Updated: 2019/01/30 12:14:47 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static int	ft_is_fdf(char c)
{
	if (c == '\t' || c == ' ' || c == '\n' || c == '\0' || c == ',')
		return (1);
	return (0);
}

static int	ft_count_words(char *str)
{
	int	word;
	int	i;

	word = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] && ft_is_fdf(str[i + 1])
				&& str[i] > 32 && str[i] < 127)
			word++;
		i++;
	}
	return (word);
}

static int	ft_wordlen(char *str)
{
	int	i;

	i = 0;
	while (ft_is_fdf(str[i]) != 1)
		i++;
	return (i);
}

static void	ft_ws_strcpy(char *dest, char **str)
{
	int	i;

	i = 0;
	while (**str && !ft_is_fdf(**str))
	{
		dest[i++] = **str;
		(*str)++;
	}
	dest[i] = 0;
}

char	**split_fdf(char *str)
{
	int		words;
	char	**tab;
	int		i;

	i = 0;
	if (!str)
		return (0);
	words = ft_count_words(str);
	if (!(tab = (char**)malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	while (i < words)
	{
		while (*str && ft_is_fdf(*str) == 1)
			str++;
		if (!(tab[i] = (char*)malloc(sizeof(char) * (ft_wordlen(str) + 1))))
			return (NULL);
		ft_ws_strcpy(tab[i], &str);
		i++;
	}
	tab[i] = 0;
	return (tab);
}
