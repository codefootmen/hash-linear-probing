#include "hash_table_functions.h"
#include <stdio.h>
#include <stdlib.h>
#include "global.h"

int TABLE_SIZE;

Node* create_hash_table(int size){
    struct Node *head;
    head = (struct Node *) malloc( sizeof(struct Node));
    head->next = 0;
    head->value = 0;

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

int insert_key(Node *current, int key){
    if(!current){
       return 0;
    }

    while (current->next){
        if(!current->value){
            current->value = key;
            return 1;
        }
        current = current->next;
    }

    return 0;
}

int hash(int key, Node *hash_table_head){
    
    int pos = key % getPrime(TABLE_SIZE);

    for(int i = 0; i < pos; i++){
        hash_table_head = hash_table_head->next;
    }

    return insert_key(hash_table_head, key);
}

int getPrime(int start){

    int isPrime = 1;

    for(int i = 2; i <= start/2; ++i){
        if(start % i == 0){
            isPrime = 0;
        }
    }
	
    if(isPrime){
        return start;
    }

    return getPrime(start - 1);
}

