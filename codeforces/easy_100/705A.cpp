#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin>>n;
    string odd = "I hate";
    string even = "I love";
    string join = " that ";

    string ans =  "";
    ans += odd;

    for(int i = 2; i<=n; i++)
        if(i%2 == 0)
            ans += join+even;
        else
            ans += join+odd;

    cout<<ans+" it"<<endl;

    return 0;
}
