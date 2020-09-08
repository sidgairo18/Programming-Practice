#include <bits/stdc++.h>

using namespace std;

int main(){

    int k,r;
    cin>>k>>r;
    
    k = k%10;
    int x = 1;
    
    for(;;x++){

        if(k*x%10==0 || k*x%10==r){
            cout<<x<<endl;
            break;
        }

    }

    return 0;
}
