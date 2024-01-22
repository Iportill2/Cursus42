#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

size_t ft_strlen(const char *s)
{
	size_t i =0;
	if(s == NULL)
		return(0);
	while(s[i])
		i++;
	return(i);
	}

void ft_puterr(char *s, char *arg)
{
	write(2, s, ft_strlen(s));
	write(2, arg, ft_strlen(arg));
	write(2, "\n", 1);
}

char **getargs(char **argv, int i, int e)
{
	int n = e - i;
	int c = 0;
	char **args = malloc(sizeof(char *) * (n + 1));

	while (c < n)
	{
		args[c] = argv[i + c];
		c++;
	}
	args[n] = NULL;
	return (args);
}
size_t ft_len(char **s)
{
	size_t i = 0;
	if(s == NULL)
		return(0);
	while(s[i])
		i++;
	return(i);
}

int main(int argc,char **argv)
{
	int i =1;
	int e = 0;
	int ogin = dup(0);
	int ogout = dup(1);
	int fd[2];
	fd[0] = ogin;
	fd[1] = ogout;
	while(i < argc)
	{
		if(argv[i] && strcmp(argv[i], ";") == 0)//si encuentra un ; resetea los fd
		{
			dup2(ogin, 0);
			dup2(ogout,1);
			fd[0]=ogin;
			fd[1]=ogout;
			i++;
		}
		else if(argv[i] && strcmp(argv[i],"|") == 0) //si encuentra un | sigue recoriendo argv
			i++;
		if(argv[i] && strcmp(argv[i],"cd") == 0)//si encuentra un cd..
		{
			e = i;
			while (argv[e] && strcmp(argv[e],";")!= 0 && strcmp(argv[e],"|") != 0)//recorre hasta encontrar un ; o un |
				e++;
			if(e - i - 1 != 1)//si hay mas de un argumento
				ft_puterr("error: cd: bad arguments", NULL);//devuelve error
			else if (chdir(argv[i + 1]))//si no puede cambiar de directorio
				ft_puterr("error: cd: cannot change directory to ", argv[i + 1]);//si falla devuelve error
			i = e;
		}
		else
		{
			e = i;
			while(argv[e] && strcmp(argv[e],";") != 0 && strcmp(argv[e],"|") != 0)//recorre hasta encontrar un ; o un |
				e++;
			if ((argv[i] && e == argc && strcmp(argv[i], ";") != 0) || (argv[e] && strcmp(argv[e], ";") == 0 && strcmp(argv[i], ";")!= 0))
			{//hay argumentos y e == argc y el argumento actual es iferente de ;|| hay argumentos y el argumnto es un ; y el argumento [i] es diferente de ;
				dup2(ogout,1);//redirecciona la salida estandar a la salida original
				if(fork() == 0)//ejecuta el comando haciendo un hijo
				{
					char **args = getargs(argv, i, e);
					execve(args[0], args, NULL);
					ft_puterr("error: cannot execute ", args[0]);
					free(args);
					exit(-1);
				}	
				else//el padre espera a hasta que acabe de ejecutarse el hijo
					waitpid(-1,NULL,0);
			}
			else if((argv[e] && strcmp(argv[e],"|") == 0 && strcmp(argv[i], "|") != 0))//si hay un | y el argumento actual es diferente de |
			{
				dup2(fd[0], 0);//redirecciona la entrada estandar al fd[0]
				close(fd[0]);//cierra el fd[0]
				pipe(fd);//crea un pipe
				dup2(fd[1], 1);//redirecciona la salida estandar al fd[1]
				close(fd[1]);//cierra el fd[1]

				if (fork() == 0)//ejecuta el comando haciendo un hijo
				{
					char **args = getargs(argv, i, e);
					execve(args[0], args, NULL);
					ft_puterr("error: cannot execute ", args[0]);
					free(args);
					exit(-1);
				}
				else//el padre espera a hasta que acabe de ejecutarse el hijo
					waitpid(-1,NULL,0);
				dup2(fd[0],0);//redirecciona la entrada estandar al fd[0]
				close(fd[0]);//cierra el fd[0]
			}
			i=e;
		}
		i++;//avanza al siguiente argumento
	}	
}
