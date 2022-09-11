// your code here
#include <iostream>
#include "Bar.h"


potd::Bar::Bar(string s) {
    f_ = new potd::Foo(s);

}

potd::Bar::Bar(potd::Bar &b) {
    f_ = new Foo(b.get_name());
    
}

potd::Bar::~Bar() {
    delete f_;
    
}

potd::Bar& potd::Bar::operator=(const potd::Bar& b) {
    string new_name = (b.f_)->get_name();
    delete this->f_;
    this->f_ = new potd::Foo(new_name);
    return (*this);
}

string potd::Bar::get_name() {
    return f_->get_name();
}