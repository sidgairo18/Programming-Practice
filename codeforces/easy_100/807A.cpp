#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin>>n;

    int a[n], b[n];
    int check1 = 1, check2 = 0;
    for(int i=0;i<n; i++){
        int x,y;
        cin>>x>>y;
        a[i] = x;
        b[i] = y;
        if(x != y)
            check2 = 1;

        if(i>0 && a[i]>a[i-1]){
            check1=0;
        }
    }

    if(check1==1 && check2==0)
        cout<<"maybe"<<endl;
    else if(check1==0 && check2==0)
        cout<<"unrated"<<endl;
    else if(check2==1)
        cout<<"rated"<<endl;

    return 0;

}
