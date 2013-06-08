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
    void initialize(const char * str, const int start = 0) {
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
public:
    DisjointSet(const char * str, const int start = 0) {
        initialize(str, 0);
    }
    DisjointSet(const string str, const int start = 0) {
        initialize(str.c_str(), 0);
    }
    DisjointSet(const DisjointSet& copy) {
        left(copy.left());
        right(copy.right());
    }
    int left() const {
        return nums[0];
    }
    int right() const {
        return nums[1];
    }
    void left(const int n) {
        nums[0] = n;
    }
    void right(const int n) {
        nums[1] = n;
    }
};

typedef vector<DisjointSet *> DJSetVec;

ostream& operator << (ostream& os, DisjointSet * const set) {
    os << "(" << set->nums[0] << ", " << set->nums[1] << ")";
    return os;
}

ostream& operator << (ostream& os, DJSetVec * const vec) {
    for (DJSetVec::iterator it = vec->begin(); it != vec->end(); ++it)
        os << *it << " ";
    return os;
}

DJSetVec * makeDisjointSets(const char * in) {
    string str = string(in);
    DJSetVec * v = new DJSetVec;
    if (str[0] != '[' && str[str.size() - 1] != ']')
        throw 1;
    size_t start = 1, stop = 0;
    do {
        start = str.find("(", start);
        stop  = str.find(")", start + 1);
        if (start == string::npos || stop == string::npos)
            continue;
        v->push_back(new DisjointSet(str.substr(start, start + stop - 1)));
        start = stop + 1;
    } while (stop != string::npos && start != string::npos);
    return v;
}

void mergeDisjoint(DJSetVec * sorted, const DisjointSet * in) {
    DJSetVec::iterator it = sorted->begin();
    while (it != sorted->end() && in->left() >= (*it)->left())
        ++it;

    if (it != sorted->end()) {
        if (in->left() > (*(it - 1))->right()) {
            // [...]  [...]
            //      [...
            if (in->right() < (*it)->left()) {
                // [...]    [...]
                //      [..]
                // --------------
                // [...][..][...]
                it = sorted->insert(it, new DisjointSet(*in));
            } else {
                // [...]    [...]
                //      [.....]
                // --------------
                // [...][.......]
                (*it)->left(in->left());
            }
            return;
        }
    }

    while (it != sorted->end() && in->right() > (*it)->left()) {
        sorted->erase(it);
        if (in->right() > (*(it-1))->right()) {
            (*(it-1))->right(in->right());
        }
    }
    if (in->right() > (*it)->right()) {
        (*it)->right(in->right());
    }
}

void mergeDisjointSets(const char * sStr, const char * mStr) {
    DJSetVec * sets = makeDisjointSets(sStr);
    DisjointSet * spanner = new DisjointSet(mStr);
    cout << "Before:  " << sets << endl;
    cout << "Spanner: " << spanner << endl;
    mergeDisjoint(sets, spanner);
    cout << "After:   " << sets << endl;
}

int main(int argc, char const * argv[]) {
    mergeDisjointSets("[(1, 5), (10, 15), (20, 25)]", "(3 12)");
    cout << "===========" << endl;
    mergeDisjointSets("[(1, 5), (10, 15), (20, 25)]", "(12 27)");
    cout << "===========" << endl;
    mergeDisjointSets("[(1, 5), (10, 15), (20, 25)]", "(17 19)");
    cout << "===========" << endl;
    mergeDisjointSets("[(1, 5), (10, 15), (20, 25)]", "(17 23)");
}