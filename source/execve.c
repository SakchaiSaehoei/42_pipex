#include <unistd.h>
#include <stdio.h>

int	main(int argc, char *argv[], char **envp)
{
	/*if argv look like
	./exwcve grep hello hello.txt
		0     1    2       3
	*option should look like
	{"grep","hello", "hello.txt"}
	{"grep hello hello.txt"}
	*/
	char *option[] = {"grep","hello", "hello.txt",NULL};// argv
	// printf("%d\n",argc);
	// int tem = argc;
	char *option[4] = {argv[1],argv[2],argv[3],NULL};
	execve("/usr/bin/cat", option, envp);
	return(0);
	//./a.out grep s hello.txt
}

