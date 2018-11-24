#include <bits/stdc++.h>

using namespace std;

int main(){

    char s1[] = "GeeksforGeeks";
    char s2[] = "forGeeks";
    char *p;

    p = strstr(s1, s2);

    int ans = strlen(s1)-strlen(p);
    cout<<ans<<endl;

    return 0;
}
