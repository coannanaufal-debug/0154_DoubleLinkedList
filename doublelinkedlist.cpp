#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *prev;
    Node *next;
};

Node *head, *tail, *cur, *newNode, *del, *afterNode;