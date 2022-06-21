#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class Details {
    protected:
        char name[80];
        int marks;
    public:
        void getData() {
            cout<<"Enter name: ";
            cin>>name;
            cout<<"Enter marks: ";
            cin>>marks;
        }
        void showData() {
            cout<<"Name: "<<name<<endl
            <<"Marks: "<<marks<<endl;
        }
        void diskIn(int);
        void diskOut();
        static int diskCount();
};

void Details::diskIn(int n) {
    ifstream file;
    file.open("details.dat",ios::binary);
    file.seekg(n*sizeof(Details));
    file.read((char*)this,sizeof(*this));
}

void Details::diskOut() {
    ofstream file;
    file.open("details.dat",ios::app|ios::binary);
    file.write((char*)this,sizeof(*this));
}

int Details::diskCount() {
    ifstream file;
    file.open("details.dat",ios::binary);
    file.seekg(0,ios::end);
    return (int)file.tellg()/sizeof(Details);
}

int main() {
    Details d;
    char op;
    do {
        cout<<"Enter details: "<<endl;
        d.getData();
        d.diskOut();
        cout<<"Add another person? (y/n): ";
        cin>>op;
    } while (op=='y');
    int n = Details::diskCount();
    cout<<"There are "<<n<<" persons in the file!"<<endl;
    for (int j=0;j<n;j++) {
        cout<<"Person "<<j<<":"<<endl;
        d.diskIn(j);
        d.showData();
    }
    return 0;
}