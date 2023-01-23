/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaehoei <ssaehoei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 22:07:26 by ssaehoei          #+#    #+#             */
/*   Updated: 2022/09/29 16:03:56 by ssaehoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/pipex.h"

char	*ft_find_path(char **envp)
{
	while(ft_strncmp("PATH=", *envp, 5))
	{
		envp++;
	}
	return (*envp + 5);
}
/*free 2d now use for pipex.paths */
void	ft_free_2d(t_pipex *pipex)
{
	int	i;

	i = 0;
	while(pipex->paths[i])
	{
		free(pipex->paths[i]);
		i++;
	}
	free(pipex->paths);

	// free(s);

}
char	***ft_get_command(int	argc , char **argv)
{
	/*in this function we will use argv and will get all the command and split them into 3d array
	[0][0] = "ls"    or [0][0][0] = 'l', [0][0][1] = 's'
	[0][1] = "-la"   or [0][1][0] = '-', [0][1][1] = 'l' , [0][1][2] = 'a'
	*/
	char	***cmd;
	int		argv_index;
	int		cmd_amount;
	int		i;

	cmd_amount = argc - 3; //-3 for .pipex, in and out  file, + 1 for null terminate
	cmd = malloc(sizeof(char *) * (cmd_amount + 1));
	if(!cmd)
		return(NULL);
	argv_index = 2;
	i = 0;
	while (argv_index <= cmd_amount + 1)
	{
		cmd[i] = ft_split(argv[argv_index],' ');
		i++;
		argv_index++;
	}
	cmd[i] = '\0';
	return(cmd);
}
void	ft_temp_print_cmd_for_option(char ***cmd)
{
	int		i;
	int		j;
	i = 0;
	j = 0;
	while(cmd[i])
	{
		j = 0;
		while(cmd[i][j])
		{
			printf("[%d][%d]%s\n",i,j,cmd[i][j]);
			j++;
		}
		i++;
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	/*if argv look like
	./exwcve infile.txt "grep hello hello.txt" outfile.txt
		0     1                  2                  3
	 proName	infile		commandOne				outfile
	*option should look like
	{"grep","hello", "hello.txt"}
	*/
	t_pipex	pipex;
	char	*buffer;
	char	*pa;
	int		i;
	int		j;
	// printf("%c\n",*envp[1]);
	// char	*buffer;
	// printf("argv 2 = %s \n",argv[2]);
	pipex.envp_path =  ft_find_path(envp);
	pipex.paths = ft_split(pipex.envp_path,':');
	pipex.cmd_for_option = ft_get_command(argc,argv);
	ft_temp_print_cmd_for_option(pipex.cmd_for_option);

	/* join path wit command and check if the path is valid or not in other word the command is valid or not ? */

	i = 0;
	j= 0;
	while(pipex.cmd_for_option[i][0] != NULL)
	{
		j = 0;
		printf("hello  this is the i %d round\n",i);
		while(pipex.paths[j]!= NULL)
		{
			buffer = ft_strjoin(pipex.paths[j],pipex.cmd_for_option[i][0]);
			if (access(buffer, F_OK | X_OK) == 0)
			{
				printf("line [%d] %s  full path = %s\n",i,pipex.paths[j],buffer);

				free(buffer);

				break;
			}
			j++;
			free(buffer);
		}
		i++;
	}
	// free(pipex.paths); /// next free herer 2d array
	ft_free_2d(&pipex);
	// free(pipex.paths);
	// pa =  ft_find_path(envp);
	// printf("pa = %s\n",pa);
	// pa = ft_strjoin("42project/pipex/42_pipex/source","grep");
	// printf("%s\n",pa);
	// execve("/usr/bin/grep", buffer, envp);


	return(0);
	//./a.out grep s hello.txt
}
