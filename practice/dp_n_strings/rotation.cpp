#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){

        char s1[105];
        char s2[105];
        char s3[210];
        cin>>s1;
        cin>>s2;

        int n = strlen(s1);

        for(int i = 0; i<2*n; i++)
            s3[i] = s1[i%n];

        char *p = strstr(s3, s2);

        if(p)
            cout<<1<<endl;
        else
            cout<<0<<endl;





    }

    return 0;
}
