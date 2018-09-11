#include <bits/stdc++.h>

using namespace std;

int main(){

    priority_queue<long long int> pq1;
    priority_queue<long long int> pq2;

    int n;
    scanf("%d", &n);

    long long int sum1=0;
    long long int sum2=0;

    long long int x;
    for(int i = 0; i<n; i++){
        scanf("%lld", &x);
        pq1.push(x);
    }
    for(int i = 0; i<n; i++){
        scanf("%lld", &x);
        pq2.push(x);
    }

    int flag = 0;
    while(pq1.size() != 0 || pq2.size() != 0){

        if(flag == 0){
            if((pq1.size() > 0 && pq2.size() > 0)){

                if(pq1.top() >= pq2.top()){
                    sum1 += pq1.top();
                    pq1.pop();
                }
                else{
                    pq2.pop();
                }
            }
            else if (pq1.size() > 0){
                sum1 += pq1.top();
                pq1.pop();
            }
            else
                pq2.pop();
            flag = 1;
        }
        else{
            if((pq1.size() > 0 && pq2.size() > 0)){

                if(pq1.top() <= pq2.top()){
                    sum2 += pq2.top();
                    pq2.pop();
                }
                else{
                    pq1.pop();
                }
            }
            else if (pq2.size() > 0){
                sum2 += pq2.top();
                pq2.pop();
            }
            else
                pq1.pop();
            flag = 0;

        }
    }

    long long int ans = sum1-sum2;

    printf("%lld\n", ans);

    return 0;
}
