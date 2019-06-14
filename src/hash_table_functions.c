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
		 pos = (pos + INCREMENT) % TABLE_SIZE;
	 }

	 *(P_TABLE + pos) = key;

     return 1;
}



