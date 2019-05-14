#include <stdio.h>
#include "hash_table_functions.h"

int main(){
	int table_size;

	printf("Choose the table size: ");
	scanf("%d", &table_size);

	Node *head = create_hash_table(table_size);

	int run = 1;
	int option;
	while (run)
	{
		system("clear");
		option = 0;
		print_hash_table(head);
		printf("\n");
		printf("---------------------------------\n");
		printf("- Hash Linear Probing           -\n");
		printf("- 0 . Exit                      -\n");
		printf("- 1 . Insert key                -\n");
		printf("---------------------------------\n");
		scanf("%d", &option);

		int key = 0;
		switch (option){
			case 0:
				run = 0;
				break;
			case 1:
				printf("Key: ");
				scanf("%d", &key);
				hash(key, head);
				break;
			default:
				break;
		}
		printf("\n");
	}

    return 0;
}
