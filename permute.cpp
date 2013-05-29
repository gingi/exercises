#include <iostream>

using namespace std;

class PermuteString {
    char *str;
    void swap(int p1, int p2) {
        char t  = str[p1];
        str[p1] = str[p2];
        str[p2] = t;
    }
    void doPermute(char *out, bool *used, int level) {
        if (level == strlen(str)) {
            cout << out << endl;
            return;
        }
        for (int i = 0; i < strlen(str); i++) {
            if (used[i]) continue;
            out[strlen(out)] = str[i];
            out[strlen(out) + 1] = '\0';
            used[i] = true;
            doPermute(out, used, level + 1);
            used[i] = false;
            out[strlen(out) - 1] = '\0';
        }
    }
public:
    PermuteString(const char *input) {
        str = (char *)malloc(strlen(input));
        strcpy(str, input);
    }
    void permute() {
        bool *used = new bool[strlen(str)];
        char *buff = new char[strlen(str)];
        doPermute(buff, used, 0);
    }
};

int main(int argc, char const *argv[])
{
    PermuteString *p;
    if (argc < 2) {
        cerr << "Usage: permute <string>" << endl;
        exit(1);
    }
    // (new PermuteString("AB"))->permute();
    // (new PermuteString("ABC"))->permute();
    // (new PermuteString("ABCD"))->permute();
    p = new PermuteString(argv[1]);
    p->permute();
    return 0;
}