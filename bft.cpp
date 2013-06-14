#include <iostream>

using namespace std;

class Node {
public:
    Node(char _c = '\0') {
        c = _c;
        lNode  = NULL;
        rNode = NULL;
    }
    virtual ~Node() {}
    Node * left(Node * n) {
        lNode = n;
        return this;
    }
    Node * right(Node * n) {
        rNode = n;
        return this;
    }
    void printBF() {
        cout << c;
        print_r(this);
        cout << endl;
    }

private:
    char c;
    Node * lNode, * rNode;
    static void print_r(Node * n) {
        if (n == NULL) return;
        if (n->lNode != NULL) cout << n->lNode->c;
        if (n->rNode != NULL) cout << n->rNode->c;
        print_r(n->lNode);
        print_r(n->rNode);
    }
};
int main(int argc, char const *argv[]) {
    Node * a = new Node('a');
    Node * b = new Node('b');
    Node * c = new Node('c');
    Node * d = new Node('d');
    Node * e = new Node('e');
    Node * f = new Node('f');
    Node * g = new Node('g');
    
    a->left(b)->right(c);
    b->left(d)->right(e);
    c->left(f)->right(g);
    a->printBF();
    return 0;
}