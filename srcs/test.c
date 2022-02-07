#include "unistd.h"
#include "stdio.h"
#include <stdlib.h>


int	main(void)
{
	char *str = malloc(1000);
	getcwd(str, 1000);
	printf("%s\n", str);
}
