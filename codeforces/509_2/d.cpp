#include <bits/stdc++.h>

using namespace std;

long long int dist[200005];
long long int pre_dist[200005];


int bin_search(int l, int r, long long int h){

    //cout<<"Iside b search"<<endl;
    //
    long long int key;
    key = h+pre_dist[l]-1;
    int mid = -1;
    int ans = -1;
    while(l<=r){

        mid = (l+r)/2;
        if(key<pre_dist[mid])
            r = mid-1;
        else if(key > pre_dist[mid]){
            l = mid+1;
            ans = mid;
        }
        else if(key == pre_dist[mid])
        {   ans = mid;
            //ans--;
            break;
        }
    }
    
    return ans;
}

int main(){

    long long int n, h;
    scanf("%lld%lld", &n, &h);

    vector< pair<long long int, long long int> > v;
    long long int x,y;

    for(int i = 0; i<n; i++){
        scanf("%lld%lld", &x, &y);
        v.push_back(make_pair(x,y));
    }

    dist[0] = 0;
    for(int i = 1; i<n; i++){
        dist[i] = v[i].first-v[i-1].second;
    }
    pre_dist[0] = dist[0];
    for(int i = 1; i<n; i++){
        pre_dist[i] = dist[i]+pre_dist[i-1];
        //cout<<"Pre_dist "<<i<<" "<<pre_dist[i]<<endl;
    }

    long long int ans = INT_MIN;

    for(int i = 0; i<n; i++){
        
        int j = bin_search(i,n-1, h);
        long long int temp1 = v[j].second-v[i].first;
        long long int temp2 = h - (pre_dist[j]-pre_dist[i]);
        ans = max(ans, temp1+temp2);
        //cout<<"i:"<<i<<" j:"<<j<<" ans:"<<ans<<endl;
        //cout<<temp1<<" "<<temp2<<endl;
    }

    printf("%lld\n", ans);

    return 0;
}
