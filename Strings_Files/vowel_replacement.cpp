#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class MyString {
    string text;
    public:
        void input() {
            cout<<"Enter text: "<<endl;
            getline(cin,text,';');
        }
        void display() {
            cout<<text;
        }
};

int main() {
    string text,word;
    cout<<"Enter text: "<<endl;
    getline(cin,text,';');
    fstream input_file,word_file;
    input_file.open("input.dat",ios::trunc|ios::in|ios::out);
    input_file << text;
    word_file.open("word.dat",ios::trunc|ios::in|ios::out);
    while (input_file >> word) {
        cout<<word;
        if (word[0]=='a'|word[0]=='e'|word[0]=='i'|word[0]=='o'|word[0]=='u'|word[0]=='A'|word[0]=='E'|word[0]=='I'|word[0]=='O'|word[0]=='U') {
            word[0] = '$';
            word_file<<word;
        }
    }
    cout<<"Successful!";
    return 0;
}