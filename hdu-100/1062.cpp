#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include<stack>
#define IOS ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
#define ll long long
#define endl '\n'
#define pii pair<int,int>
using namespace std;



signed main(){
 IOS;

 char ch;
    int n;
    cin>>n;
    cin.ignore();//吸收cin>>n输入之后的换行符 ,这个使用于scanf的getchar(); //吸收cin>>n输入之后的换行符 
    while(n--) {
        stack<char> st;

        while(true) {
            ch=getchar();//逐字符读取输入
            if(ch==' ' || ch=='\n') {
                while(!st.empty()) {
                    cout<<st.top();
                    st.pop();
                }
                if(ch==' ') cout<<' ';
                else break;//换行弹出
            } else st.push(ch);
        }
        cout<<endl;
    }
    return 0;
}

