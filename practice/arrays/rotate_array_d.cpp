#include <bits/stdc++.h>

using namespace std;

int main(){

    int a[] = {1,2,3,4,5,6,7,8,9};
    int n = sizeof(a)/sizeof(a[0]);
    int r = 5;

    for(int i = 0; i<__gcd(n,r); i++){

        int temp = a[i];
        int j = i;

        while(true){

            int k = j+r;
            if(k>=n)
                k = k%n;


            int save = a[k];
            a[k] = temp;
            temp = save;
            if(k == i)
                break;
            j = k;
        }

    }

    for(int i = 0; i<n; i++)
        cout<<a[i]<<" ";
    cout<<endl;

    return 0;
}
