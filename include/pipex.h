/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaehoei <ssaehoei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:10:03 by ssaehoei          #+#    #+#             */
/*   Updated: 2022/09/29 13:20:37 by ssaehoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/types.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
# include <stdlib.h>
# include <stddef.h>
# include "../libft/libft.h"

typedef struct s_pipex
{
	pid_t	pid;
	int		infile_fd;
	int		outfile_fd;
	int		cmd_amount; // argc - 3(./pipex infile outfile)
	char	**paths; // paths of PATH= for cheking command that has been splitted
	char	*envp_path;// an string tha we get foem envp
	char	**cmd_arg;// to store all command tha has not bee spliited yet
	char	***cmd_for_option;// for check in valid_command_path and to use as an option later
	char	**cmd_path;// to store plath that has been join with function  put - if the funtion is not valid


	// char	*ft_strjoin(char *s1, char *s2);
	// char	*ft_strdup(char *src);

}t_pipex;

// char	**ft_split(char const *s, char c);
// static int	ft_strlen(char *str);

# endif
