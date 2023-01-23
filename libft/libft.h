/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaehoei <ssaehoei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 01:39:18 by lraffin           #+#    #+#             */
/*   Updated: 2022/09/21 21:20:15 by ssaehoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft.h"

# define BUFFER_SIZE	32
# define INT_MAX		2147483647
# define INT_MIN		-214783648

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

char		**ft_split(const char *s, char c);
char		*ft_strjoin(char *s1, char *s2);
size_t		ft_strlen(const char *s);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
int	ft_strncmp(const char *str1, const char *str2, size_t n);

# endif
