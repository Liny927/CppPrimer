//
//  ex13_13.cpp
//  CP5
//
//  Created by pezy on 1/13/15.
//  Copyright (c) 2015 pezy. All rights reserved.
//
//  A good way to understand copy-control members and constructors is to define
//  a simple class with these members in which each member prints its name:
//  struct X {
//    X() {std::cout << "X()" << std::endl;}
//    X(const X&) {std::cout << "X(const X&)" << std::endl;}
//  };
//  Add the copy-assignment operator and destructor to X and write a program
//  using X objects in various ways:
//  Pass them as nonreference and reference parameters;
//  dynamically allocate them;
//  put them in containers; and so forth.
//  Study the output until you are certain you understand when and why each
//  copy-control member is used.
//  As you read the output, remember that the compiler can omit calls to the
//  copy constructor.
//
// Created by hellcat on 2020.05.18.
//
#include <iostream>
#include <vector>
using namespace std;

struct X {
    X() { cout<<"X() called."<<endl; }
    ~X() { cout<<"~X() called."<<endl; }
    X(const X&) { cout<<"X(const X&) called."<<endl; }
    X& operator = (const X&) { cout<<"X& operator = (const X&) called."<<endl; }
    int isbn() { return a; }
    int a;
};

bool fcn(const X* trans, X accum)
{
    X item1(*trans), item2(accum);
    cout<<"------------------------"<<endl;
    return item1.isbn() != item2.isbn();
    // accum(非引用参数传递, 临时变量), item1, item2离开局部作用域, 被销毁
    // trans为指针传递, 不被销毁
}

void f(const X &rx, X x) { // X(const X&) called.
    vector<X> vec;
    vec.reserve(2);
    vec.push_back(rx); // X(const X&) called.
    cout<<"*****"<<endl;
    vec.push_back(x);  // X(const X&) called. 
    cout<<"*****"<<endl;
    // ~X() called.
    // ~X() called.
    // ~X() called.
}

void f(const X &rx) {
    vector <X> vec;
    vec.push_back(rx); // X(const X&) called.
    // ~X() called.
}

void f2(X x) { // X(const X&) called.
    vector <X> vec;
    cout<<"*****"<<endl;
    vec.push_back(x); // X(const X&) called.
    cout<<"*****"<<endl;
//     ~X() called.
//     ~X() called.
}

int main() {
//    X x1, x2;
//    cout<<"-----------"<<endl;
//    fcn(&x1, x2);
//    cout<<"-----------"<<endl;
    X *px = new X;
    cout<<"-----------"<<endl;
    f(*px, *px);
//    f(*px);
//    f2(*px);
    cout<<"-----------"<<endl;
    delete px;
}
