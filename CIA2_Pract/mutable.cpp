#include <iostream>
#include <string>

using namespace std;

class List {
    string name;
    mutable string order_details;
    public:
        List():name("null"),order_details("null") {}
        List(string n, string od):name(n),order_details(od) {}
        void changeOrder(string co) const {
            order_details = co;
        }
};

int main() {

    return 0;
}