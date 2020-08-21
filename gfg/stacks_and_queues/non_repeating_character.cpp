#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){

        int n;
        cin>>n;

        map<char, int> mp;
        queue<char> qu;

        char x;

        for(int i=0; i<n; i++){

            cin>>x;
            if(mp.find(x) == mp.end()){
                qu.push(x);
                mp[x] = 1;
            }
            else
                mp[x] += 1;
            while(!qu.empty())
                if(mp[qu.front()] == 1){
                    cout<<qu.front()<<" ";
                    break;
                }
                else
                    qu.pop();
            if(qu.empty())
                cout<<-1<<" ";

        }
        cout<<endl;

    }

    return 0;
}
