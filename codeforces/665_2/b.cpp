#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){

        long long int x1, y1, z1;
        long long int x2, y2, z2;

        cin>>x1>>y1>>z1;
        cin>>x2>>y2>>z2;

        long long int c = 0;

        // pair all 2's with 1's
        c += 2*min(z1, y2); // this ends either z1 or y2
        int mn = min(z1, y2);
        z1 -= mn; y2 -= mn;

        // pair all 2's with 2's
        mn =  min(z1, z2);
        z1 -= mn; z2 -= mn; // this ends either z1 or z2

        // pair all 2's with 0's
        mn = min(z1, x2);
        z1 -= mn; x2 -= mn;

        // pair all 1's with 0's
        mn = min(y1, x2);
        y1 -= mn; x2 -= mn;

        // pair all 1's with 1's
        mn = min(y1, y2);
        y1 -= mn; y2 -= mn;

        // pair  all 0's with 2's
        mn  = min(x1, z2);
        x1 -=  mn;  z2 -= mn;

        // pair all 1's with 2's
        mn = min(y1, z2);
        c -= 2*mn;
        y1 -= mn; z2 -= mn;

        //  pair all 0's with 1's
        mn = min(x1, y2);
        x1 -= mn; y2 -= mn;

        // pair all 0's with 0's
        mn =  min(x1, x2);
        mn = min(x1, x2);
        x1 -= mn; x2 -= mn;

        cout<<c<<endl;

    }

    return 0;
}
