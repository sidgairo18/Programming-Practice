#include <bits/stdc++.h>

using namespace std;

int main(){

    int n,m;
    vector<int> v;
    int x;

    cin>>n>>m;

    for(int i = 0; i<n; i++){
        cin>>x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());

    int max_k = v[n-1]+m;

    int min_k = 0;

    while(m){

            v[0]++;
            m--;
            sort(v.begin(), v.end());

            //for(int i = 0; i<n; i++)
              //  cout<<v[i]<<" ";
            //cout<<endl;
    }

    min_k = v[n-1];




    cout<<min_k<<" "<<max_k<<endl;

    return 0;
}
