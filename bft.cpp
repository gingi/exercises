#include <iostream>
#include <queue>

using namespace std;

class Node {
public:
    Node(char _c = '\0') {
        c = _c;
        leftChild  = NULL;
        rightChild = NULL;
    }
    virtual ~Node() {}
    Node * left(Node * n) {
        leftChild = n;
        return this;
    }
    Node * right(Node * n) {
        rightChild = n;
        return this;
    }
    void bft() {
        queue<Node *> * q = new queue<Node *>;
        q->push(this);
        while (!q->empty()) {
            Node * n = q->front();
            q->pop();
            if (n->leftChild)  q->push(n->leftChild);
            if (n->rightChild) q->push(n->rightChild);
            cout << n->c;
        }
        cout << endl;
    }

private:
    char c;
    Node * leftChild, * rightChild;
};

int main(int argc, char const *argv[]) {
    Node * a = new Node('a');
    Node * b = new Node('b');
    Node * c = new Node('c');
    Node * d = new Node('d');
    Node * e = new Node('e');
    Node * f = new Node('f');
    Node * g = new Node('g');
    Node * h = new Node('h');
    Node * i = new Node('i');
    Node * j = new Node('j');
    
    /*
     *                 a
     *              /     \
     *            b         c
     *          /   \     /   \
     *         d     e   f     g
     *          \   /
     *           h i
     *          /
     *         j
     */        
    a->left(b)->right(c);
    b->left(d)->right(e);
    c->left(f)->right(g);
    d->right(h);
    e->left(i);
    h->left(j);
    a->bft();
    return 0;
}