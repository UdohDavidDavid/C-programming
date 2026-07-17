#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int size;
	int val;
	struct node *next;
} node_t;

node_t *create(int size) {
	node_t *head = malloc(sizeof(node_t));
	node_t *current = head;
	int i = 0;
	while (i < size - 1) {
		current->next = malloc(sizeof(node_t));
		current = current->next;
		i++;
	}
	current->next = NULL;
	return head;
}

void lk_set(node_t *head, int num) {
	node_t *current = head;
	int i = 0;
	while (i < num && current != NULL) {
		current->val = i;
		current = current->next;
		i++;
	}
}

void print_list(node_t *head) {
	node_t *current = head;
	while (current != NULL) {
		printf("%d\n", current->val);
		current = current->next;
	}
}

int main(int argc, char **argv) {
	node_t *head = create(5);

	lk_set(head, 40);
	print_list(head);

	return 0;
}
