#include <iostream>

#define BUFF_MEM_SIZE 4096

using namespace std;

class Buffer : string {
    char *str;
    int length;
public:
    Buffer() {
        str = (char *)malloc(BUFF_MEM_SIZE);
        str[0] = '\0';
        length = 0;
    }
    void append(const char * a) {
        strcpy(str + strlen(str), a);
        length += strlen(a);
        str[length] = '\0';
    }
    void append(const char c) {
        str[length++] = c;
        str[length] = '\0';
    }
    void chop() {
        str[--length] = '\0';
    }
    friend ostream& operator<<(ostream &os, const Buffer *buffer);
};

ostream& operator<<(ostream &os, const Buffer *buffer) {
    os << buffer->str;
    return os;
}

class PermuteString {
    char *str;
    void swap(int p1, int p2) {
        char t  = str[p1];
        str[p1] = str[p2];
        str[p2] = t;
    }
    void doPermute(Buffer *out, bool *used, int level) {
        if (level == strlen(str)) {
            cout << out << endl;
            return;
        }
        for (int i = 0; i < strlen(str); i++) {
            if (used[i]) continue;
            out->append(str[i]);
            used[i] = true;
            doPermute(out, used, level + 1);
            used[i] = false;
            out->chop();
        }
    }
public:
    PermuteString(const char *input) {
        str = (char *)malloc(strlen(input));
        strcpy(str, input);
    }
    void permute() {
        bool *used = new bool[strlen(str)];
        doPermute(new Buffer(), used, 0);
    }
};

int main(int argc, char const *argv[]) {
    PermuteString *p;
    if (argc < 2) {
        (new PermuteString("AB"))->permute();
        (new PermuteString("ABC"))->permute();
        (new PermuteString("ABCD"))->permute();
    } else {
        p = new PermuteString(argv[1]);
        p->permute();
    }
    return 0;
}