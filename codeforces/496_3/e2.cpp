#include <bits/stdc++.h>

using namespace std;

long long int greatM(vector<int> arr, int m, int n){

    long long int res = 0;
    long long add = 0;
    map<int, int> mx;

    int s = 0;
    mx[s] = 1;

    for(int i = 0; i<n; i++){

        if(arr[i] < m){
            s--;
            add -= mx[s];
        }
        else{
            add += mx[s];
            s++;
        }

        res += add;
        mx[s]++;
    }

    return res;
}

int main(){

    int n, m;

    scanf("%d%d", &n, &m);
    vector<int> arr(n);


    for(int i = 0; i<n; i++)
        scanf("%d", &arr[i]);

    long long int ans = greatM(arr, m, n) - greatM(arr, m+1, n);

    printf("%lld\n", ans);

    return 0;
}
