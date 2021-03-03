#include <iostream>
using std::cin;
using std::cout;
using std::endl;

typedef struct Node {
    int value;
    struct Node *next;
} Node;
// удаляем элемент (пояснения скорее для самого себя делал)
int pop(Node** head, int index) {
    Node * now = *head; // Опять, now - текущий элемент
    Node * prev; // Нужен, чтоб связать список после удаления элемента
    int i = 1;
    while(i < index){
        prev = now;
        now = (now) -> next; // Переходим до тех пор, пока не дойдем до нужного
        i++;
    }
    int val = (now) -> value; // Значение указанного элемента
    (prev) -> next = (now) -> next; // Сшиваем список
    free(now); // удаляем то, что хотели удалить
    return(val);
}