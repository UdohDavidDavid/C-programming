#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

int INFO_SIZE = 2;
int TOTAL_ARR_SIZE = 20;

char *david_info[] = {"David","godswilludohdavid@gmail.com", "Uses arch btw"};
char *peace_info[] = {"Peace","21dpeace@cottagegrove-tkat.org", "Does not use arch"};
char *tt_info[] = {"TT","ttnamecollide@gmail.com", "Uses Ubuntu"};


int hash(char *user, int *total) {
	int size = strlen(user);
	int list[size];
	int hash = 0;
	for (int i = 0; i < size; i++) {
		list[i] = user[i];
		hash += list[i];
	}
	int real_hash = hash % *total;
	return real_hash;
}

void add_info(char *user, char ***database, char **info) {
	int index = hash(user, &TOTAL_ARR_SIZE);

	if (info[0] != user) {
		printf("Sorry but the first index of the info must be equal to the username for weird reasons\n");
	}

	if (database[index] == NULL) {
		database[index] = info;
	}
	else {
		while (database[index] != NULL) {
			if (index == TOTAL_ARR_SIZE - 1) {
				index = 0;
			}
			index++;
		}
		database[index] = info;
	}
}

void get_info(char *user, char ***database) {
	int index = hash(user, &TOTAL_ARR_SIZE);
	int info_size = 2;
	if (user == database[index][0]) {
		for (int i = 0; i < info_size; ++i) {
			printf("%s\n", database[index][i]);
		}
		printf("At index %d\n", index);
		printf("\n");
	}
	else {
		while (user != database[index][0]) {
			index++;
		}
		for (int i = 0; i < info_size; ++i) {
			printf("%s\n", database[index][i]);
		}
		printf("At index %d\n", index);
		printf("\n");
	}
}

int main(int argc, char **argv) {

	char ***database_arr = malloc(sizeof(char***) * TOTAL_ARR_SIZE);
	for (int i = 0; i < TOTAL_ARR_SIZE; ++i) {
		database_arr[i] = NULL;
	}

	add_info("David", database_arr, david_info);
	get_info("David", database_arr);

	add_info("TT", database_arr, tt_info);
	get_info("TT", database_arr);

	add_info("Peace", database_arr, peace_info);
	get_info("Peace", database_arr);


	return 0;
}
