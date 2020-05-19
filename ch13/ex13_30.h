//
// Created by hellcat on 2020.05.18.
//
#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::endl;
using std::string;

class HasPtr {
public:
    explicit HasPtr(const string &s = string())
        : ps(new string(s)), i(0), use(new size_t(1)) {}
    HasPtr(const HasPtr& rhs)
        : ps(new string(*rhs.ps)), i(rhs.i), use(rhs.use) { ++*use; }
    ~HasPtr() {
        if(--*use == 0) {
            delete ps;
            delete use;
        }
    }
    friend void swap(HasPtr &lhs, HasPtr &rhs);
    HasPtr& operator = (HasPtr& rhs_hp) {
//        ++*rhs_hp.use;
//        if(--*use == 0) {
//            delete ps;
//            delete use;
//        }
//        ps = rhs_hp.ps;
//        i = rhs_hp.i;
//        use = rhs_hp.use;
//        return *this;
        swap(*this, rhs_hp);
        return *this;
    }
    void print() {
//        cout<<(*use)<<endl;
        cout<<*ps<<endl;
    }

private:
    string *ps;
    int i;
    size_t *use; // 记录有多少个对象共享*ps的成员
};

void swap(HasPtr &lhs, HasPtr &rhs) {
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
    cout<<"swap(HasPtr &lhs, HasPtr &rhs) called."<<endl;
}

int main() {
    HasPtr p1("halo");
    HasPtr p2(p1);
    HasPtr p3(p1);
    HasPtr p4;

//    p3.print();
    p4 = p2;  // swap(HasPtr &lhs, HasPtr &rhs) called.
    p4.print();  // halo
}
