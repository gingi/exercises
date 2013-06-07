#include <iostream>
#include <string>
#include <vector>

#define START     1
#define OPEN_SET  2
#define CLOSE_SET 3
#define DELIM     4
#define DIGIT     5

using namespace std;

class DisjointSet {
    int nums[2];
    friend ostream& operator << (ostream& os, DisjointSet * set);
public:
    DisjointSet(const char * str, const int start = 0) {
        int mode = START;
        int num = 0;
        int counter = 0;
        size_t i = start;
        while (mode != CLOSE_SET && i < strlen(str)) {
            switch (str[i]) {
                case '(':
                    mode = OPEN_SET;
                    break;
                case ')':
                    mode = CLOSE_SET;
                    nums[counter] = num;
                    break;
                case ' ':
                case ',':
                    if (mode == DIGIT) {
                        mode = DELIM;
                        nums[counter] = num;
                        num = 0;
                        counter++;                    
                    }
                    break;
                default:
                    mode = DIGIT;
                    num = num * 10 + (str[i] - 48);
                    break;
            }
            i++;
        }
    }
    int left() const {
        return nums[0];
    }
    int right() const {
        return nums[1];
    }
};

ostream& operator << (ostream& os, DisjointSet * const set) {
    os << "(" << set->nums[0] << ", " << set->nums[1] << ")" << endl;
    return os;
}

vector<DisjointSet> * makeDisjointSets(const char * str) {
    return new vector<DisjointSet>;
}

void mergeDisjoint(const vector<DisjointSet> * sorted, const DisjointSet * input) {
}

int main (int argc, char const *argv[]) {
    vector<DisjointSet> * sets = makeDisjointSets("[(1, 5), (10, 15), (20, 25)]");
    DisjointSet * input = new DisjointSet("(12 27)");
    cout << input << endl;
    mergeDisjoint(sets, input);
}