#include <stdio.h>

int a(int *p0) {
    int p;
    printf("%20p %20p %20zd %20ld\n", p0, &p, (p0 - &p), sizeof(p));
    if (p0) return p0 > &p;
    return a(&p);
}
int main() {       
    puts(a(0) ? "y" : "n" );
}
