#include <iostream>
#include <string>

using namespace std;


class Parent {
    public:
    void pFunc() {
        cout << "Parent's pFunc.\n" << endl;
        pFunc2();
    }
    virtual void pFunc2() {
        cout << "Parent's pFunc2.\n" << endl;
    }

};

class Child : public Parent {
    public:
    void pFunc2() {
        cout << "Child's pFunc2.\n" << endl;
    }

};

int main() {
    Parent p;
    Child c;

    p.pFunc();
    c.pFunc();

}

