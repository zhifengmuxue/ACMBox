#include<iostream>
using namespace std;

int N;

int main(){
    cin >> N;
    while(N--){
        int ah,am,as,bh,bm,bs;
        cin>>ah>>am>>as>>bh>>bm>>bs;
        int a=ah*3600+am*60+as;
        int b=bh*3600+bm*60+bs;
        int c=a+b;
        int ch=c/3600;
        int cm=c%3600/60;
        int cs=c%60;
        cout<<ch<<" "<<cm<<" "<<cs<<endl;
    }

    return 0;
}