#include <iostream>
using std::cin;
using std::cout;
using std::endl;

typedef struct Node {
    int value;
    struct Node *next;
} Node;
// Очищаем списочек (пояснения скорее для самого себя делал)
void clear_list(Node ** head) {
    Node * now = *head; // now - это указатель на текущий элемент

    while(now != NULL)
    {
        Node * nenow = now; // nenow нужна, чтоб указать, какому месту нужна свобода. При этом не испортить now
        now = (now) -> next; // новый now
        free(nenow); // еее, свобода
    }
    *head = NULL // Ваш NULL, как и заказывали
}
