#include <bits/stdc++.h>

using namespace std;

int main(){

    char s[200005];
    char t[200005];

    scanf("%s", s);
    scanf("%s", t);

    int m = strlen(s);
    int n = strlen(t);

    while(m>0 && n>0 && s[m-1] == t[n-1]){
        m--;
        n--;
    }

    int ans = m+n;

    printf("%d\n", ans);


    return 0;
}
