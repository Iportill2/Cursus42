/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:34:18 by iportill          #+#    #+#             */
/*   Updated: 2023/10/03 17:38:03 by iportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	correct_argc(int argc)
{
	if (argc != 5)
	{
		write(1, "argc incorrecto\n", 15);
		exit(1);
	}
}

t_pipex	*create_struc(t_pipex *p, int argc, char **argv, char **env)
{
	int	i;

	i = 0;
	p = ft_calloc(sizeof(t_pipex), (1));
	p->infile = argv[1];
	p->cmd1 = argv[2];
	p->cmd2 = argv[3];
	p->cmd1_split = ft_split(p->cmd1, ' ');
	p->cmd2_split = ft_split(p->cmd2, ' ');
	p->argc = argc;
	p->outfile = argv[4];
	p->path_raw = find_env_file(env, p);
	p->path_raw_split = ft_split(p->path_raw, ':');
	p->path_raw_split_repair = NULL;
	return (p);
}

char	*find_env_file(char **env, t_pipex *p)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			p->path_raw = env[i] + 5;
			break ;
		}
		i++;
	}
	return (p->path_raw);
}

void	repair_and_check_path_raw_split(t_pipex *p)
{
	int		i;
	char	*temp;

	i = 0;
	while (p->path_raw_split[i])
	{
		temp = p->path_raw_split[i];
		p->path_raw_split[i] = ft_strjoin(p->path_raw_split[i], "/");
		free(temp);
		i++;
	}
}

char	*try_path_access(char **s1, char *s2)
{
	int		i;
	char	*executable_path;

	i = 0;
	while (s1[i])
	{
		executable_path = ft_strjoin(s1[i], s2);
		if (access(executable_path, F_OK) == 0)
			break ;
		free(executable_path);
		i++;
	}
	return (executable_path);
}
