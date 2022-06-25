#include <iostream>

using namespace std;

class Distance {
    int feet; float inches;
    public:
        Distance():feet(0),inches(0.0) {}
        Distance(int f,float i):feet(f), inches(i) {}
        operator float() const {
            float mtr = inches/12;
            mtr += feet;
            mtr /= 3.281;
            return mtr;
        }
        void operator =(float mtrs) {
            float frac_feet = mtrs*3.281;
            feet = int(frac_feet);
            inches = (frac_feet-feet)*12;
        }
        void getData() {
            cout<<"Enter feet: ";
            cin>>feet;
            cout<<"Enter inches: ";
            cin>>inches;
        }
        void showData() {
            cout<<feet<<"'"<<inches<<"\""<<endl;
        }
};

int main() {
    Distance d1(5,4.3),d2;
    float meters = d1;
    d1.showData();
    cout <<"d1 in meters: "<<meters<<endl;
    d2 = 5.683;
    d2.showData();
    return 0;
}