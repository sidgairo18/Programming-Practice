#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){

        int n,k;
        cin>>k>>n;

        priority_queue<int, vector<int>, greater<int> > q;
        
        int a[n];
        for(int i = 0; i<n; i++)
            cin>>a[i];

        for(int i = 0; i<k-1;i++){

            q.push(a[i]);
            cout<<"-1 ";
        }
        q.push(a[k-1]);
        cout<<q.top()<<" ";
        for(int i = k; i<n; i++){
            if(a[i] > q.top())
            {
                q.pop();
                q.push(a[i]);
            }
            cout<<q.top()<<" ";
        }
        cout<<endl;


    }

    return 0;

}
