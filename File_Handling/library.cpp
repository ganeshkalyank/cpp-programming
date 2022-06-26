#include <iostream>
#include <cmath>

using namespace std;

class classM {
    public:
        int alpha,beta;
        classM(int a=0,int b=0):alpha(a),beta(b) {}
        void getData() {
            cout<<"Enter alpha: ";cin>>alpha;
            cout<<"Enter beta: ";cin>>beta;
        }
};

class classA {
    float result;
    public:
        classA():result(0.0) {}
        classA(float res) {
            result = res;
        }
        classA(classM cm) {
            result = 2*cos(0.5*(cm.alpha+cm.beta))*cos(0.5*(cm.alpha-cm.beta));
        }
        float getResult() {
            return result;
        }
        classA operator + (classA ca) {
            float res;
            res = result+ca.result;
            return classA(res);
        }
        void showData() {
            cout<<"Result: "<<result<<endl;
        }
};

int main() {
    classM m1,m2,m3;
    m1.getData();
    m2.getData();
    m3.getData();
    classA a1,a2,a3,a4;
    a1=m1;a2=m2;a3=m3;
    a4=a1+a2;
    a1.showData();
    a2.showData();
    a3.showData();
    a4.showData();
    return 0;
}