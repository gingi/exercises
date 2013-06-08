#include <stdio.h>

class Array {
    int data[2];
public:
    explicit Array(const int n = 5) {
        data[0] = 13;
        data[1] = 21;
    }
    int * arr() const {
        return (int *)data;
    }
};

int main (int argc, char const *argv[]) {
    Array * a = new Array(5);
    int * data = a->arr();
    printf("[%d %d]\n", data[0], data[1]);
}