#include <bits/stdc++.h>

using namespace std;

int main(){

    int a[] = {1,2,3,4,5,6,7,8,9};

    int l = 0, r = 8;

    while(l<r){

        swap(a[l], a[r]);
        l++;
        r--;
    }

    for(int i = 0; i<9; i++)
        cout<<a[i]<<" ";
    cout<<endl;

    return 0;
}
