#include <iostream>
#include <string>

using namespace std;

class Employee {
    int empno;
    string name,desg;
    public:
        void get_data() {
            cout<<"Enter employee number: ";
            cin>>empno;
            cout<<"Enter name: ";
            cin>>name;
            cout<<"Enter designation: ";
            cin>>desg;
        }
};

class Qualification: public Employee {
    int ug,pg,exp;
};

class Salary : public Qualification {
    float salary;
};

int main() {
    // yet to finish
    return 0;
}