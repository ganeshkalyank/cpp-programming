#include <iostream>
#include <iomanip>

using namespace std;

class Reading {
    int consumer_number,month_number,previous_reading,current_reading;
    public:
        Reading():consumer_number(0), month_number(0), previous_reading(0), current_reading(0) {}
        Reading(int cn,int mn, int pr, int cr):consumer_number(cn), month_number(mn), previous_reading(pr), current_reading(cr) {}
        void getData() {
            cout<<"Enter consumber number: ";
            cin>>consumer_number;
            cout<<"Enter month number: ";
            cin>>month_number;
            if (month_number==1) {
                cout<<"Enter previous reading: ";
                cin>>previous_reading;
                cout<<"Enter current reading: ";
                cin>>current_reading;
            } else {
                cout<<"Enter current reading: ";
                cin>>current_reading;
            }
        }
        int getConNum() {
            return consumer_number;
        }
        int getMonthNum() {
            return month_number;
        }
        int getPrevRead() {
            return previous_reading;
        }
        int getCurrRead() {
            return current_reading;
        }
        void update_reading(Reading r) {
            previous_reading = r.getCurrRead();
        }
};

class Consumer {
    int consumer_number,month_number,units_consumed,charges;
    public:
        Consumer():consumer_number(0),month_number(0),units_consumed(0),charges(0) {}
        void disp_charge() {
            cout<<setw(20)<<consumer_number<<setw(20)<<month_number<<setw(20)<<units_consumed<<setw(20)<<charges<<endl;
        }
        void operator = (Reading r) {
            consumer_number = r.getConNum();
            month_number = r.getMonthNum();
            units_consumed = r.getCurrRead()-r.getPrevRead();
            charges = 2*units_consumed;
        }
};

int main() {
    Reading r[4];
    int i;
    Consumer c;
    for (i=0;i<4;i++) {
        r[i].getData();
    }
    for (i=0;i<4;i++) {
        c = r[i];
        r[i+1].update_reading(r[i]);
        c.disp_charge();
    }
    return 0;
}