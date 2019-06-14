#include "hash_table_functions.h"
#include <stdio.h>
#include <stdlib.h>
#include "global.h"

int TABLE_SIZE;
int INCREMENT;
int *P_TABLE;

void print_hash_table(){
    for(int i = 0; i < TABLE_SIZE; i++){
        printf("[%d]", *(P_TABLE + i));
    }
}


int hash(int key){
    int pos = key % TABLE_SIZE;

    while(*(P_TABLE + pos)){
      if(*(P_TABLE + pos) == key ){
        printf("--------------------\n");
        printf("Key already exists.\n");
        printf("--------------------\n");
        return 0;
      }
      pos = (pos + INCREMENT) % TABLE_SIZE;

      while(pos < 0){
        pos+=TABLE_SIZE;
      }
    }

    *(P_TABLE + pos) = key;

    return 1;
}

int delete_key(int key){
   int pos = key % TABLE_SIZE;

    for(int i = 0; i < TABLE_SIZE; i++){
      if(*(P_TABLE + pos) == key ){
        *(P_TABLE + pos) = 0;
		update_table((pos + INCREMENT) % TABLE_SIZE);
        return 1;
      }
      pos = (pos + INCREMENT) % TABLE_SIZE;
    }

    printf("----------------------------\n");
    printf("Key does not exists.\n");
    printf("----------------------------\n");

    return 0;
}

int update_table(int pos){
	if( (*(P_TABLE + pos) % TABLE_SIZE) == (pos) ){
		return 1;
	}

	int temp = *(P_TABLE + pos);
    *(P_TABLE + pos) = 0;
    *((P_TABLE + pos) + (INCREMENT*(-1))) = temp;

	return update_table((pos + INCREMENT) % TABLE_SIZE);
}




