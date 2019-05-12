#include <stdio.h>
#include "hash_table_functions.h"

int main(){
	Node *head = create_hash_table(3);
	print_hash_table(head);
    return 0;
}
