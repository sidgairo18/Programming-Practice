#include <bits/stdc++.h>

using namespace std;

int main(){

    char s[200005];

    scanf("%s", s);
    int l = strlen(s);

    int count = 0;
    int sm = 0;
    vector<int> prev;

    for(int i = 0; i<l; i++){
        
        int curr = (int)(s[i]-'0');
        sm += curr;
        if(curr == 0 || sm%3 == 0){
            sm = 0;
            prev.clear();
            count++;
            continue;
        }
        int sz = prev.size();
        
        int flag = 0;
        for(int i = 0; i<sz; i++){
            if((sm-prev[i])%3 == 0){
                flag = 1;
                sm = 0;
                prev.clear();
                count++;
                break;
            }
        }

        if(flag == 0)
            prev.push_back(sm);

    }

    printf("%d\n", count);

    return 0;
}
