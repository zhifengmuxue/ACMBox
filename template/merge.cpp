#include<iostream>
using namespace std;

const int N = 100005;
int a[N], temp[N];
int n;

void merge(int l, int mid, int r){
    int i = l;
    int j = mid + 1;
    int k = l;

    while(i <= mid && j <= r){
        if(a[i] <= a[j]){
            temp[k++] = a[i++];
        }else{
            temp[k++] = a[j++];
        }
    }

    while(i <= mid) temp[k++] = a[i++];
    while(j <= r) temp[k++] = a[j++];

    for(int t = l; t <= r; t++){
        a[t] = temp[t];
    }
}

void mergeSort(int l, int r){
    if(l >= r) return;

    int mid = (l + r) / 2;

    mergeSort(l, mid);
    mergeSort(mid + 1, r);

    merge(l, mid, r);
}

int main(){

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    mergeSort(0, n - 1);

    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }

    return 0;
}