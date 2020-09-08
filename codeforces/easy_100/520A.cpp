#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin>>n;
    string s;
    cin>>s;

    transform(s.begin(), s.end(), s.begin(), ::tolower);
    int count[26];
    memset(count,0,sizeof(count));
    for(int i =0; i<n; i++)
        count[s[i]-'a']++;

    int flag = 0;
    for(int i = 0; i<26; i++)
        if(count[i] == 0)
        {
            flag = 1;
            break;
        }

    if(flag == 0)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

    return 0;
}
