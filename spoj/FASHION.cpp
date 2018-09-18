#include <bits/stdc++.h>

using namespace std;

int main(){

    int t,n;
    scanf("%d", &t);

    while(t--){

        scanf("%d", &n);
        vector<int> man(n);
        vector<int> wom(n);

        for(int i = 0; i<n; i++){
            scanf("%d", &man[i]);
        }
        for(int i = 0; i<n; i++){
            scanf("%d", &wom[i]);
        }

        sort(man.rbegin(), man.rend());
        sort(wom.rbegin(), wom.rend());

        int total = 0;
        for(int i = 0; i<n; i++)
            total += man[i]*wom[i];

        printf("%d\n", total);
    }

    return 0;
}
