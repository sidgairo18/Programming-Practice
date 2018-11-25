#include <bits/stdc++.h>
using namespace std;

int main() {
    //code
    int t;
    cin>>t;
    
    while(t--){
        
        double k;
        cin>>k;
        double ans[1001][1001];
        for(int i = 0; i<=1000; i++)
            for(int j = 0; j<=1000; j++)
                ans[i][j] = 0;
        ans[1][1] = (k);
        int flag = 0;
        for(int i = 1;;i++){
                flag = 0;
            for(int j =1; j<=i; j++ ){
                k = ans[i][j];

                if(k > 1){
                    ans[i][j] = 1;
                    k = k-1;
                    ans[i+1][j] += k/2;
                    ans[i+1][j+1] += k/2;
                    flag = 1;
                }
                    
            }
            if(!flag)
                break;
                
        }
        int i,j;
        cin>>i>>j;
        printf("%.6lf\n", ans[i][j]);
    }
    return 0;
}
