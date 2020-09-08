#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){

        int n;
        cin>>n;

        if(n==1)
        {
            cout<<0<<endl;
            continue;
        }

        int threes=0;
        int twos=0;
        int temp = n;

        while(temp%3==0){
            threes++;
            temp/=3;
        }

        while(temp%2==0){
            twos++;
            temp/=2;
        }

        if(temp!=1 || twos>threes)
            cout<<-1<<endl;
        else
            cout<<(threes-twos)+threes<<endl;

    }

    return 0;
}
