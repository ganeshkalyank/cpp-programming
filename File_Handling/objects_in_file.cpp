#include <iostream>
#include <fstream>

using namespace std;

class Student {
    protected:
        int reg_no;
        char name[80];
    public:
        void getData() {
            cout<<"Enter student name: ";
            cin>>name;
            cout<<"Enter reg no: ";
            cin>>reg_no;
        }
        void showData() {
            cout<<"Name: "<<name<<endl
            <<"Reg no: "<<reg_no<<endl;
        }
};

int main() {
    fstream file;
    Student stud;
    char op;
    file.open("data.dat",ios::binary|ios::in|ios::out|ios::app);
    do {
        stud.getData();
        file.write(reinterpret_cast<char*>(&stud),sizeof(stud));
        cout<<"Add another student? (y/n): ";
        cin>>op;
    } while (op=='y');
    file.seekg(0);
    cout<<"Student details: "<<endl;
    while (!file.eof()) {
        file.read(reinterpret_cast<char*>(&stud),sizeof(stud));
        stud.showData();
    }
    return 0;
}