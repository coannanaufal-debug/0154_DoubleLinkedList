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

void addFirst(int data) {
    if (head == NULL) {
        cout << "Double Linked List belum dibuat" << endl;
    } else {
        newNode = new Node();
        newNode->data = data;
        newNode->prev = NULL;
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void addLast(int data) {
    if (head == NULL) {
        cout << "Double Linked List belum dibuat" << endl;
    } else {
        newNode = new Node();
        newNode->data = data;
        newNode->prev = tail;
        newNode->next = NULL;
        tail->next = newNode;
        tail = newNode;
    }
}

void addMiddle(int data, int posisi) {
    if (head == NULL) {
        cout << "Double Linked List belum dibuat" << endl;
    } else {
        if (posisi == 1) {
            cout << "Posisi 1 bukan posisi tengah" << endl;
        } else if (posisi < 1 || posisi > countDoubleLinkedList()) {
            cout << "Posisi di luar jangkauan" << endl;
            } else {
            newNode = new Node();
            newNode->data = data;
            cur = head;
            int nomor = 1;
            while (nomor < posisi - 1) {
                cur = cur->next;
                nomor++;
            }
            afterNode = cur->next;
            newNode->prev = cur;
            newNode->next = afterNode;
            cur->next = newNode;
            afterNode->prev = newNode;
        }
    }
}

void removeFirst() {
    if (head == NULL) {
        cout << "Double Linked List belum dibuat" << endl;
    } else {
        del = head;
        head = head->next;
        head->prev = NULL;
        delete del;
    }
}

void removeLast() {
    if (head == NULL) {
        cout << "Double Linked List belum dibuat" << endl;
    } else {
        del = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete del;
    }
}

void removeMiddle(int posisi) {
    if (head == NULL) {
        cout << "Double Linked List belum dibuat" << endl;
    } else {
        if (posisi == 1 || posisi == countDoubleLinkedList()) {
            cout << "Posisi bukan di tengah" << endl;
        } else if (posisi < 1 || posisi > countDoubleLinkedList()) {
            cout << "Posisi di luar jangkauan" << endl;
            } else {
            int nomor = 1;
            cur = head;
            while (nomor < posisi - 1) {
                cur = cur->next;
                nomor++;
            }
            del = cur->next;
            afterNode = del->next;
            cur->next = afterNode;
            afterNode->prev = cur;
            delete del;
        }
    }
}