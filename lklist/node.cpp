#include <iostream>

typedef struct node {
    int val = 0;
    struct node *next = nullptr;
} node_t;

node_t *init_list(int size) {
    node_t *head = (node_t *)malloc(sizeof(node_t));
    node_t *tail = head;
    int i = 0;
    while (i < size - 1) {
        tail->next = (node_t *)malloc(sizeof(node_t));
        tail = tail->next;
        i++;
    }
    tail->next = nullptr;
    return head;
}

void print_list(node_t *head) {
	node_t *tail = head;
	while (tail != nullptr) {
	    std::cout << tail->val << std::endl;
        tail = tail->next;
    }
}

void lk_set(node_t **head, int num, int index) {
    node_t *tail = *head;
    node_t *temp = (node_t *)malloc(sizeof(node_t));
    temp->val = num;
    int i = 0;
    if (index == 0) {
        temp->next = *head;
        *head = temp;
    }
    else {
        while (i < index - 1 && tail != nullptr) {
            tail = tail->next;
            i++;
        }
        temp->next = tail;
        tail = temp;
    }
}

int main(int argc, char** argv) {
	node_t* node = init_list(5);
	lk_set(&node, 67, 3);
	print_list(node);
	free(node);
}