#include <stdio.h>

#include "hash_table_functions.h"

#include "global.h"

int TABLE_SIZE;
int INCREMENT;
int *P_TABLE;

int main(){

    printf("Choose the table size: ");
    scanf("%d", &TABLE_SIZE);
    printf("Choose the increment: ");
    scanf("%d", &INCREMENT);

    int table[TABLE_SIZE];
	P_TABLE = table;

	for(int i =0; i < TABLE_SIZE; i++){
		*(P_TABLE + i) = 0;
	}

    int run = 1;
    int option;

    while (run){
    system("clear");
	option = 0;
	print_hash_table();
	printf("\n\n");
	printf("---------------------------------\n");
	printf("- Hash Linear Probing           -\n");
	printf("- 0 . Exit                      -\n");
	printf("- 1 . Insert key                -\n");
	printf("- 2 . Delete key                -\n");
	printf("- 3 . Search                    -\n");
	printf("---------------------------------\n");
	scanf("%d", &option);

	int key = 0;
	int test;
	switch (option){
	    case 0:
	        run = 0;
		break;
	    case 1:
        printf("Key: ");
        scanf("%d", &key);
        hash(key);
        int temp;
        scanf("%d", &temp);
		break;
      case 2:
      printf("Key: ");
      scanf("%d", &key);
      delete_key(key);
  	break;
      case 3:
      printf("Key: ");
      scanf("%d", &key);
      search(key);
      int temp1;
      scanf("%d", &temp1);
    break;
	    default:
		break;
	}

        printf("\n");
    }

    return 0;
}
