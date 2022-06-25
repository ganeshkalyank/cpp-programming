#include <iostream>

using namespace std;

class sample {
    static int x;
    public:
        static void getdata(int a) {
            this->x=a;
            cout<<"x="<<x;
        }
};