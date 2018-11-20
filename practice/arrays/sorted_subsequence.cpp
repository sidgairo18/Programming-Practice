#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin>>n;

    int a[n];
    for(int i = 0; i<n; i++)
        cin>>a[i];

    int left[n], right[n];

    for(int i = 0; i<n; i++)
        left[i] = right[i] = -1;
    
    int min_yet = INT_MAX;
    for(int i = 0; i<n; i++){
        if(min_yet < a[i])
            left[i] = 1;
        min_yet = min(min_yet, a[i]);

    }
    int max_yet = INT_MIN;
    for(int i = n-1; i>=0; i--){
        if(max_yet > a[i])
            right[i] = 1;
        max_yet = max(max_yet, a[i]);

    }

    for(int i = 0; i<n; i++)
        if(left[i] > 0 && right[i] > 0)
            cout<<"Yes"<<endl;




    return 0;
}
