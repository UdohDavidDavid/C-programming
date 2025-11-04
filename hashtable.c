/*
* This is the general concept os the application
*	ht->entries.key = "David";
*	ht->entries.key = {"godswilludohdavid@gmail.com", "I use arch btw"};
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

const int TOTAL_SIZE = 10000;

typedef struct entry_t {
	char *key;
	char *value;
	struct entry_t *next;
} entry_t;

typedef struct {
	entry_t **entries;
} ht_t;




ht_t *initialise(void) {
	// Allocate size for hashtable
	ht_t *hashtable = malloc(sizeof(ht_t) * 1);

	// Allocate size for entries
	hashtable->entries = malloc(sizeof(entry_t*) * TOTAL_SIZE);


	// Set all to Null
	// Also Allocate space for individual entries
	int i = 0;
	for (; i < TOTAL_SIZE; ++i) {
		hashtable->entries[i] = NULL;
	}

	return hashtable;
}




int hash(const char *key) {
	int size = strlen(key);
	int i = 0;
	int hash = 0;
	for (; i < size; ++i) {
		hash += key[i];
	}
	int value = hash % TOTAL_SIZE;
	return value;
}




entry_t *ht_pair(const char *key, const char *value) {
	entry_t *entry = malloc(sizeof(entry_t) * 1);
	entry->key = malloc(strlen(key) + 1);
	entry->value = malloc(strlen(value) + 1);

	strcpy(entry->key, key);
	strcpy(entry->value, value);

	entry->next = NULL;

	return entry;
}





void ht_set(ht_t *hashtable, const char *key, const char *value) {
	// Get the index using the key hash
	unsigned int slot = hash(key);
	// Get the entry slots from the hashtable
	entry_t *entry = hashtable->entries[slot];

	/* Checks if slot is empty and puts the values
	 * in immediately
	 * */
	if (entry == NULL) {
		hashtable->entries[slot] = ht_pair(key, value);
		return;
	}

	entry_t *prev;
	while (entry != NULL) {
		if((strcmp(entry->key, key)) == 0) {
			free(entry->value);
			entry->value = malloc(strlen(value) + 1);
			strcpy(entry->value, value);
			return;
		}
		prev = entry;
		entry = prev->next;
	}
	prev->next = ht_pair(key, value);
}




char *ht_get(ht_t *hashtable, const char *key) {
    unsigned int slot = hash(key);

    // try to find a valid slot
    entry_t *entry = hashtable->entries[slot];

    // no slot means no entry
    if (entry == NULL) {
        return NULL;
    }

    // walk through each entry in the slot, which could just be a single thing
    while (entry != NULL) {
        // return value if found
        if (strcmp(entry->key, key) == 0) {
            return entry->value;
        }

        // proceed to next key if available
        entry = entry->next;
    }

    // reaching here means there were >= 1 entries but no key match
    return NULL;
}




int main(int argc, char **argv) {
	/* Initialise and set values
	 * Only set values using strings
	 * */
	ht_t *ht = initialise();
	ht_set(ht, "name1", "David");
	ht_set(ht, "name2", "Peace");
	ht_set(ht, "name3", "Joy");

	/*Gets the values using keys and puts them in a string*/
	char *name1 = ht_get(ht, "name1");
	char *name2 = ht_get(ht, "name2");
	char *name3 = ht_get(ht, "name3");

	//Prints the values stored
	printf("%s\n", name1);
	printf("%s\n", name2);
	printf("%s\n", name3);

	//Exit successfully
	return 0;
}
