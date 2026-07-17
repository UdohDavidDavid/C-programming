#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100
#define MAX_COMMANDS 50
#define MAX_STRING_LENGTH 100


int split(const char *buffer, char **argv, char split)
{
	int word_index = 0;
	int char_index = 0;

	for (int i = 0; buffer[i] != '\0'; ++i) {
		if (buffer[i] == split) {
			if (char_index > 0) {
				argv[word_index][char_index] = '\0';
				word_index++;
				char_index = 0;
			}
		} else {
			argv[word_index][char_index++] = buffer[i];
		}
	}

    // only add the last word if it’s not empty
    if (char_index > 0) {
        argv[word_index][char_index] = '\0';
        word_index++;
    }

	return word_index;
}


int main()
{
	bool running = 1;
	char *buffer = malloc(sizeof(char) * BUFFER_SIZE);
	buffer = "hello dude main  ";
	char **argv = malloc(sizeof(char*) * MAX_COMMANDS);
	for (int i = 0; i < MAX_COMMANDS; ++i)
		argv[i] = malloc(MAX_STRING_LENGTH);
	int count = split(buffer, argv, ' ');
	for (int i = 0; i < count; ++i) {
		printf("[");
		printf("%s", argv[i]);
		printf("]\n");
	}
	/*
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
	*/
	return 0;
}
