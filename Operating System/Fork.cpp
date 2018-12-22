#include <sys/types.h>
#include <studio.h>
#include <unistd.h>
int main()
{
int  pid;
	/* fork another process */
	pid = fork();
	if (pid < 0) { /* error occurred */
		fprintf(stderr, "Fork Failed");
		return 1;
	}
	else if (pid == 0) { /* child process */
		for (int i = 0; i < 10; i++)
			cout << i;
	}
	else { /* parent process */
		/* parent will wait for the child */
		wait (NULL);
		printf ("Child Complete");
	}
	return 0;
}
