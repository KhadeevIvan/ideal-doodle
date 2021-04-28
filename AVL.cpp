#include <iostream>
#include <cstdlib>

struct Node                                   // вводится структура узлов
{
    int key;                                  // ключ узла
    unsigned char height;                     // высота поддерева
    Node* left;                               // указатели на правый и левый узел
    Node* right;
};

Node* init_node(int key)             // инициализация узла (корня)
{
    Node* nd = (Node*)malloc(sizeof(Node));
    nd -> key = key;
    nd -> left = nd -> right = nullptr;
    nd -> height = 1;
    return nd;
}

unsigned char height(Node* nd)
{
    if (nd != nullptr) {
        return nd ->height;
    } else {
        return 0;
    }
}

int balance_factor(Node* nd)
{
    return (height(nd -> right) - height(nd -> left));
}

void fixheight(Node* nd)
{
    unsigned char height_left = height(nd -> left);
    unsigned char height_right = height(nd -> right);
    if (height_left > height_right) {
        nd->height = height_left + 1;
    } else {
        nd->height = height_right + 1;
    }
}

Node* rotateright(Node* nd) // правый поворот вокруг nd, левый сын становится корнем
{
    Node* nd_left = nd -> left;
    nd -> left = nd_left -> right;
    nd_left -> right = nd;
    fixheight(nd);
    fixheight(nd_left);
    return nd_left;
}

Node* rotateleft(Node* nd) // левый поворот вокруг nd, правый сын становится корнем
{
    Node* nd_right = nd -> right;
    nd -> right = nd_right -> left;
    nd_right -> left = nd;
    fixheight(nd);
    fixheight(nd_right);
    return nd_right;
}

Node* balance(Node* nd) // балансировка узла nd. Предполагается, что эта функция используется
{                       // для балансировки после добавления или удаления элемента, поэтому balace factor не больше 2 по модулю
    fixheight(nd);
    if( balance_factor(nd) == 2 )
    {
        if( balance_factor(nd -> right) < 0 )
            nd -> right = rotateright(nd -> right);
        return rotateleft(nd);
    }
    if( balance_factor(nd) == -2 )
    {
        if( balance_factor(nd -> left) > 0  )
            nd -> left = rotateleft(nd -> left);
        return rotateright(nd);
    }
    return nd;
}

Node* insert_a(Node* nd, int k) // вставка ключа k в дерево с корнем nd. Это первая версия,
{                               // тут балансировка происходит от корня к вставленному элементу. Если так работает, то хорошо
    if (nd == nullptr) {
        nd = init_node(k);
    } else {
        Node* now_nd = nd;
        Node* prev_nd = nullptr;
        while (now_nd != nullptr) {
            if (k >= now_nd -> key) {
                prev_nd = now_nd;
                now_nd = now_nd -> right;
            } else {
                prev_nd = now_nd;
                now_nd = now_nd -> left;
            }
        }
        if (k >= prev_nd -> key) {
            prev_nd -> right = init_node(k);
        } else {
            prev_nd -> left = init_node(k);
        }
        now_nd = nd;
        while (now_nd != nullptr) {
            if (k >= now_nd -> key) {
                prev_nd = now_nd;
                now_nd = balance(now_nd);
                if (prev_nd == now_nd) {
                    now_nd = now_nd -> right;
                }
            } else {
                prev_nd = now_nd;
                now_nd = balance(now_nd);
                if (prev_nd == now_nd) {
                    now_nd = now_nd -> left;
                }
            }
        }
    }

    return nd;
}

Node* insert_b(Node* nd, int k) // вставка ключа k в дерево с корнем nd. Это вторая версия с рекурсией. Так точно должно работать
{
    if (nd == nullptr) {
        nd = init_node(k);
    }
    if (k < nd -> key) {
        nd -> left = insert_b(nd->left,k);
    } else {
        nd -> right = insert_b(nd->right,k);
    }
    return balance(nd);
}

Node* findmin(Node* nd) // поиск узла с минимальным ключом в дереве nd
{
    Node* now_nd = nd;
    Node* min_nd;
    while (now_nd != nullptr) {
        min_nd = now_nd;
        now_nd = now_nd -> left;
    }
    return min_nd;
}

Node* removemin(Node* nd) // удаление узла с минимальным ключом из дерева nd
{
    if (nd -> left == nullptr) {
        return nd -> right;
    } else {
        nd -> left = removemin(nd->left);
        return balance(nd);
    }
}

Node* remove(Node* nd, int k) // удаление ключа k из дерева nd
{
    if(nd == nullptr){
        return 0;
    }
    if (k < nd -> key){
        nd -> left = remove(nd -> left, k);
    } else if (k > nd -> key) {
        nd->right = remove(nd -> right, k);
    } else {
        Node* l = nd -> left;
        Node* r = nd -> right;
        delete nd;
        if(r == nullptr) {
            return l;
        }
        Node* min_nd = findmin(r);
        min_nd -> right = removemin(r);
        min_nd -> left = l;
        return balance(min_nd);
    }
    return balance(nd);
}