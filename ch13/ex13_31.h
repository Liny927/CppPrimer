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
    bool operator < (const HasPtr &rhs) {
        return *ps < *rhs.ps;
    }

    HasPtr& operator = (HasPtr tmp) {
//        ++*rhs_hp.use;
//        if(--*use == 0) {
//            delete ps;
//            delete use;
//        }
//        ps = rhs_hp.ps;
//        i = rhs_hp.i;
//        use = rhs_hp.use;
//        return *this;
        this->swap(tmp);
        return *this;
    }
    void swap(HasPtr& rhs) {
        using std::swap;
        swap(ps, rhs.ps);
        swap(i, rhs.i);
        cout<<"swap(HasPtr& rhs) called."<<endl;
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
#include <vector>
#include <algorithm>
using std::vector;
using std::sort;

int main() {
    HasPtr p1("abc"), p2("abcd"), p3("bca");
//    HasPtr p2(p1);
//    HasPtr p3(p1);
//    HasPtr p4;
//
//    p3.print();
//    p4 = p2;  // swap(HasPtr &lhs, HasPtr &rhs) called.
//    p4.print();
    vector<HasPtr> v = { p3 };
    v.push_back(p1);
    v.push_back(p2);
    sort(v.begin(), v.end()); // 交换4次
}
