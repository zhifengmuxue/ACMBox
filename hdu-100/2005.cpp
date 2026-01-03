#include<iostream>
using namespace std;

int year;
int month;
int day;
char sep;
int a[] = {0, 31, 28 , 31 ,30 ,31,30,31,31,30,31,30,31};

bool is_run(int year){
    if ((year%4==0 && year%100 != 0) || (year % 400 == 0))  return 1;
    return 0;
}

int main(){
    while(cin >> year >> sep >> month >> sep >> day){
        a[2] = 28;
        if (is_run(year)) a[2] = 29;
        int num = 0;
        for (int i = 1; i < month;i++){
            num += a[i];
        }
        cout << num + day << endl;
    }
    return 0;
}
