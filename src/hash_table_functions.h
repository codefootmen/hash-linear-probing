typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node* create_hash_table(int size);
void print_hash_table(Node *head);

