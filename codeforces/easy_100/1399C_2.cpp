#include  <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){

        int n;
        cin>>n;

        int counts[100+5];
        memset(counts, 0, sizeof(counts));
        vector<int> wts(n);

        for(int i = 0; i<n; i++){
            cin>>wts[i];
            counts[wts[i]]++;
        }
        
        int ans = -1;
        for(int s = 2;  s<=100; s++){
            
            int curr_counts[100+5];
            for(int i = 0; i<100+5; i++)
                curr_counts[i] = counts[i];
            
            int curr_ans = 0;
            for(int i = 0; i<n; i++){
                if(curr_counts[wts[i]] > 0){

                    curr_counts[wts[i]]--;
                    if(s-wts[i]>0 &&  curr_counts[s-wts[i]] > 0){
                        curr_ans++;
                        curr_counts[s-wts[i]]--;
                    }
                    else
                        curr_counts[wts[i]]++;
                }
            }
            ans = max(ans, curr_ans);
        }

        cout<<ans<<endl;

    }

    return 0;
}
