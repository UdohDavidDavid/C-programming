#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char**argv)
{
	bool running = 1;
	char buffer[100];
	while (running)
	{
		printf("#lsh>> ");
		fgets(buffer, sizeof(buffer), stdin);
		if (strstr(buffer, "exit"))
		{
			running = 0;
		}
		else
		{
			system(buffer);
		}
	}
	return 0;
}
