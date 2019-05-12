#include "hash_table_functions.h"

Node* create_hash_table(int size){
	struct Node *head;
	head = (struct Node *) malloc( sizeof(struct Node));
	head->next = 0;
    head->value = 10;

	struct Node *iterator;
	iterator = head;

	for(int i = 0; i < size; i++){
		struct Node *n = (struct Node *) malloc(sizeof (struct Node));
		n->value = 0;
		n->next = 0;
		iterator->next = n;
		iterator = n;
	}

	return head;
}

void print_hash_table(Node *current){
	while (current->next){
		printf("[%d]", current->value);
		current = current->next;
	}
}
