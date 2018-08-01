#include <bits/stdc++.h>

using namespace std;

int main(){

    int m, n;
    scanf("%d%d", &m, &n);

    int p[n];
    for(int i = 0; i<n; i++)
        p[i] = 0;
    
    double range = pow(2, n);

    for(double i = 0; i<range; i++){
        
        int l = 1;
        int r = m;
        
        int run = 0;
        while(l<=r){

            int mid = (l+r)/2;
            printf("%d\n", mid);
            fflush(stdout);
            int out;
            scanf("%d", &out);
            
            if(out == 0)
                return 0;

            if(p[run])
                if(out == -1)
                    r = mid-1;
                else if(out == 1)
                    l = mid+1;
                else
                    return 0;
            else
                if(out == 1)
                    r = mid-1;
                else if(out == -1)
                    l = mid+1;
                else
                    return 0;
            run = (run+1)%n;
        }

        long long int temp = i;
        int j = 0;

        while(temp!=0){
            p[j] = (long long int)(temp)%2;
            temp/=2;
            j++;
        }
        for(;j<n; j++)
            p[j] = 0;

    }

    return 0;
}
