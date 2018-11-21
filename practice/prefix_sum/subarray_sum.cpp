#include <bits/stdc++.h>

using namespace std;

int main(){

    int n,t;
    long long int check;
    cin>>t;

    while(t--){
        
        cin>>n>>check;
        long long int s = 0;
        long long int a[n];
        
        for(int i = 0; i<n; i++)
            cin>>a[i];

        long long int cur_sum = a[0];
        int start = 0;
        int flag = 0;
        for(int i = 1; i<n;){

            if(cur_sum == check){
                cout<<start+1<<" "<<i<<endl;
                flag = 1;
                break;
            }
            else if(cur_sum < check){

                cur_sum += a[i++];

            }
            else{

                while(start < i && cur_sum > check){

                    cur_sum -= a[start++];

                }

            }

        }
        if(!flag)
            cout<<-1<<endl;


    }

    return 0;
}
