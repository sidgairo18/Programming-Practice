#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin>>n;

    vector<int> a;

    int x;
    for(int i = 0; i<n; i++){
        scanf("%d", &x);
        a.push_back(x);
    }

    sort(a.begin(), a.end());

    int l = a[a.size()-1]-a[0]+1;
    int ans = l-n;

    cout<<ans<<endl;

    return 0;
}
