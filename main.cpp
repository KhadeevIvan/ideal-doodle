#include <iostream>
using std::cin;
using std::cout;
using std::endl;
typedef struct Node {
    int value;
    struct Node *next;
} Node;
void push_left(Node ** head, int value) {
    if (*head == NULL) {
        *head = (Node *) malloc(sizeof(Node));
        (*head) -> value = value;
        (*head) -> next = NULL;
    }
    else{
        Node * nenew = (Node *) malloc(sizeof(Node));
        (nenew) -> value = value;
        (nenew) -> next = *head;
        *head = nenew;
    }
}

