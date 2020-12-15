#include <bits/stdc++.h>

using namespace std;

bool check(vector<long long int> v){

    int l = v.size();
    if(l==1)
        return true;

    for(int i = 1; i<l; i++)
        if(v[i]!=v[i-1])
            return false;

    return true;
}

int main(){

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        vector<long long int> a(n);
        long long int curr_max = INT_MIN;
        for(int i = 0; i<n; i++){
            cin>>a[i];
            curr_max = max(curr_max, a[i]);
        }

        int counts = 0;

        while(true){

            if(check(a))
                break;

            vector<long long int> v;
            int i = 0, j=0;
            long long int sm = 0;
            while(j<a.size()){
                while(j<a.size() && sm+a[j]<=curr_max){
                    sm+=a[j++];
                    counts++;
                }
                if(sm>0){
                    counts--;
                    v.push_back(sm);
                    sm = 0;
                }
                else if(j<a.size()){
                    v.push_back(a[j]);
                    j++;
                }
            }

            if(v.size() == a.size()){
                a.clear();
                a.push_back(v[0]+v[1]);
                counts++;
                curr_max = max(a[0],  curr_max);
                for(int i = 2; i<v.size(); i++){
                    a.push_back(v[i]);
                    curr_max = max(curr_max, v[i]);
                }
            }
            else{
                a.clear();
                for(int i = 0; i<v.size(); i++){
                    a.push_back(v[i]);
                }
            }
        }
        cout<<counts<<endl;
    }

    return 0;
}
