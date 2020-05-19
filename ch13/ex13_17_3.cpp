#include <iostream>
using namespace std;

struct numbered {
    numbered() {
//        static int unique = 10;
        mysn = unique++;
    }
    numbered(const numbered& n) { mysn = n.mysn + 1; }
    int mysn;
    static int unique;
};

int numbered::unique = 10;

void f(const numbered& s) {
    cout<<s.mysn<<" ";
}

int main() {
    numbered a, b = a, c = b;
    f(a); f(b); f(c);
}
/*
 * 13.14 Output: 10 10 10
 * 13.15 Output: 11 12 13
 * 13.16 Output: 11 12 13
 */
