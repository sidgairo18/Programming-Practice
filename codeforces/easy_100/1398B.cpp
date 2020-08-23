#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){

        string s;
        cin>>s;

        int alice = 0;
        vector<int> ones;

        for(int i =0; i<s.size(); i++){
            int count = 0;
            while(s[i] == '1'){
                i++;
                count++;
            }
            if(count>0)
                ones.push_back(count);
        }
        sort(ones.rbegin(), ones.rend());
        for(int i = 0;  i<ones.size(); i+=2)
            alice += ones[i];

        cout<<alice<<endl;


    }

    return 0;
}
