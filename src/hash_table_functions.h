typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node* create_hash_table(int size);
void print_hash_table(Node *head);
int insert_key(Node *head, int key);
int hash(int key, Node *hash_table_head);
int getPrime(int start);
