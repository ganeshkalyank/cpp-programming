#include <iostream>

using namespace std;

class InputData {
    int data_a,data_b;
    public:
        void get_data() {
            cout<<"Enter a: ";
            cin>>data_a;
            cout<<"Enter b: ";
            cin>>data_b;
        }
        int get_a() {
            return data_a;
        }
        int get_b() {
            return data_b;
        }
};

class Arith_Unit: public InputData {
    public:
        int add() {
            return InputData::get_a()+InputData::get_b();
        }
        int sub() {
            return InputData::get_a()-InputData::get_b();
        }
        int mul() {
            return InputData::get_a()*InputData::get_b();
        }
        int div() {
            return InputData::get_a()/InputData::get_b();
        }
};

class Logic_Unit: public InputData {
    public:
        int logic_and() {
            return InputData::get_a()&InputData::get_b();
        }
        int logic_or() {
            return InputData::get_a()|InputData::get_b();
        }
        int logic_xor() {
            return InputData::get_a()^InputData::get_b();
        }
};

int main() {
    Arith_Unit au;
    au.get_data();
    cout<<"Sum: "<<au.add()<<endl;
    cout<<"Difference: "<<au.sub()<<endl;
    cout<<"Product: "<<au.mul()<<endl;
    cout<<"Quotient: "<<au.div()<<endl;
    Logic_Unit lu;
    lu.get_data();
    cout<<"AND: "<<lu.logic_and()<<endl;
    cout<<"OR: "<<lu.logic_or()<<endl;
    cout<<"XOR: "<<lu.logic_xor()<<endl;
    return 0;
}