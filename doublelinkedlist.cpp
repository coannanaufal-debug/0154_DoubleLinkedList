#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *prev;
    Node *next;
};

Node *head, *tail, *cur, *newNode, *del, *afterNode;

void createDoubleLinkedList(int data) {
    head = new Node();
    head->data = data;
    head->prev = NULL;
    head->next = NULL;
    tail = head;
}

int countDoubleLinkedList() {
    if (head == NULL) {
        return 0;
    } else {
        int jumlah = 0;
        cur = head;
        while (cur != NULL) {
            jumlah++;
            cur = cur->next;
        }
        return jumlah;
    }
}