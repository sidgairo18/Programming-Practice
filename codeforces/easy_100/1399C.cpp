#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){

        int n;
        cin>>n;

        vector<int> wt(n);
        int counts[50+5];
        memset(counts, 0, sizeof(counts));
        for(int i=0; i<n; i++){
            cin>>wt[i];
            counts[wt[i]]++;
        }
        
        int ans = -1;
        for(int i = 0; i<n; i++){

            int curr_counts[50+5];
            for(int j = 0; j<50+5; j++)
                curr_counts[j] = counts[j];
            
            for(int j=i+1; j<n; j++){
                int s = wt[i]+wt[j];
                int curr_ans = 1;
                curr_counts[wt[i]]--, curr_counts[wt[j]]--;

                for(int k = 0; k<n; k++){
                    if(k == i || k == j)
                        continue;

                    if(curr_counts[wt[k]] > 0 && curr_counts[s-wt[k]]>0){
                        curr_ans++;
                        curr_counts[wt[k]]--, curr_counts[s-wt[k]]--;
                    }

                }
                ans = max(curr_ans, ans);

            }

        }

        cout<<ans<<endl;


    }

    return 0;
}
