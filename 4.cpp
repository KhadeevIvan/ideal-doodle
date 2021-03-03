#include <iostream>
using std::cin;
using std::cout;
using std::endl;

typedef struct Node {
    int value;
    struct Node *next;
} Node;
// удаляем элемент (пояснения скорее для самого себя делал)
void remove(Node** head, int value) {
    Node * now = *head;                // Опять, now - текущий элемент
    Node * prev;                       // Нужен, чтоб связать список после удаления элемента
    Node * next = (now) -> next;
    if((*head) -> value == value){     // Это нужно, если первый элемент = value
        free(*head);                   // Если мои расчеты верны, то он сначала освобождает память, на которую указывает *head
        *head = next;                  // А потом говорит, что *head теперь указывает на 2 элемент списка
    }
    else{                              // Теперь первый элемент не равен value
        while((now) -> next != NULL){
            prev = now;
            if((now) -> value == value){
                (prev) -> next = (now) -> next; // Сшиваем список
                free(now); // удаляем то, что хотели удалить
            }
        }
    }
}