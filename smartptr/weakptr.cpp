#include <iostream>
#include <iterator>
#include <memory>

class B; //Forward Delcaration

class A {
    std::shared_ptr<B> b_ptr;
    public:
    void set_B(std::shared_ptr<B> &b) {
        b_ptr =b;
    }
    A() {std::cout << "A Constructor" << std::endl;}
    // The Destructor method never get called when use shared pointer
    ~A() {std::cout << "A Destructor" << std::endl;}
};

class B {
    // std::shared_ptr<A> a_ptr; // This cause memory leak instead use weak pointer
    std::weak_ptr<A> a_ptr; // Use weak to prevent memory leak pointing out each other.
    public:
    void set_A(std::shared_ptr<A> &a) {
        a_ptr = a;
    }
    B() {std::cout << "B Constructor" << std::endl;}
    // The same as above A this never get called instead use weak pointer
    ~B() {std::cout << "B Destructor" << '\n';}
};


int main() {
    std::shared_ptr<A> a = std::make_shared<A>();
    std::shared_ptr<B> b = std::make_shared<B>();
    a->set_B(b);
    b->set_A(a);
}