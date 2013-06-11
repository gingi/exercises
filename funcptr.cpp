// Simple demonstration of C/C++ function pointers.
void call(int n, int (*fp)(int)) {
    printf("fn(%d) -> %d\n", n, fp(n));
}

int add3(const int n) { return n + 3; }

int dbl(const int n)  { return n * 2; }

int main(int argc, char const *argv[]) {
    call(5, &add3);
    call(5, &dbl);
    return 0;
}