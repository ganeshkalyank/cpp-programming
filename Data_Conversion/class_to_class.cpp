#include <iostream>

using namespace std;

class time24 {
    int hrs,mins,secs;
    public:
        time24():hrs(0),mins(0),secs(0) {}
        time24(int h,int m,int s):hrs(h),mins(m),secs(s) {}
        int getHrs() {
            return hrs;
        }
        int getMins() {
            return mins;
        }
        int getSecs() {
            return secs;
        }
};

class time12 {
    bool pm;
    int hrs,mins,secs;
    public:
        time12():pm(false),hrs(0),mins(0),secs(0) {}
        time12(time24 t24) {
            if (t24.getHrs()>=12) {
                pm=true;
                if (t24.getHrs()>12) hrs=t24.getHrs()-12;
                else hrs=t24.getHrs();
                mins=t24.getMins();
                secs=t24.getSecs();
            } else {
                pm = false;
                hrs=t24.getHrs();
                mins=t24.getMins();
                secs=t24.getSecs();
            }
        }
        time12(int h,int m,int s):hrs(h),mins(m),secs(s) {}
        void getTime() {
            cout<<hrs<<":"<<mins<<":"<<secs<<(pm?"pm":"am")<<endl;
        }
};

int main() {
    time24 t2(5,56,45);
    time12 t1=t2;
    t1.getTime();
    return 0;
}