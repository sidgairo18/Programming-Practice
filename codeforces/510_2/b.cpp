#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin>>n;

    vector<int> c;
    vector<string> v;
    int x;
    string s;
    
    int check[3];
    check[0]=check[1] = check[2] = 0;

    for(int i = 0; i<n; i++){

        scanf("%d", &x);
        c.push_back(x);
        cin>>s;
        v.push_back(s);

        for(int i = 0; i<s.size(); i++)
            check[s[i]-'A'] += 1;
    }


    if(check[0] == 0 || check[1] == 0 || check[2] == 0)
    {
        cout<<"-1"<<endl;
        return 0;
    }

    vector< pair<int, string> > c2;

    for(int i = 0; i<c.size(); i++){

        int a[3];
        a[0] = a[1] = a[2] = 0;
        for(int j = 0; j<v[i].size(); j++)
            a[v[i][j]-'A'] = 1;

        if(a[0] == 1 && a[1] == 1 && a[2] == 1)
        {
            c2.push_back(make_pair(c[i], v[i]));
            continue;
        }

        for(int j = i+1; j<c.size(); j++){

            int b[3];
            b[0] = b[1] = b[2] = 0;
            for(int k = 0; k<v[j].size(); k++)
                b[v[j][k]-'A'] = 1;

            if(b[0]+b[1]+b[2] == 3)
            {
                c2.push_back(make_pair(c[j], v[j]));
                continue;
            }

            b[0]+=a[0];
            b[0] = b[0]>=1?1:0;
            b[1]+=a[1];
            b[1] = b[1]>=1?1:0;
            b[2]+=a[2];
            b[2] = b[2]>=1?1:0;

            string temp = "";
            if(b[0])
                temp+='A';
            if(b[1])
                temp+='B';
            if(b[2])
                temp+='C';
            if(b[0]+b[1]+b[2] >= 2)
                c2.push_back(make_pair(c[j]+c[i], temp));
        }

    }

    int ans = INT_MAX;

    for(int i = 0; i<c2.size(); i++){

        int a[3];
        a[0] = a[1] = a[2] = 0;
        for(int j = 0; j<c2[i].second.size(); j++)
            a[c2[i].second[j]-'A'] = 1;

        if(a[0]+a[1]+a[2] == 3){
            ans = min(ans, c2[i].first);
            continue;
        }

        for(int j = 0; j<c.size(); j++){


            int b[3];
            b[0] = b[1] = b[2] = 0;
            for(int k = 0; k<v[j].size(); k++)
                b[v[j][k]-'A'] = 1;

            if(b[0]+b[1]+b[2] == 3){
                ans = min(ans, c[j]);
                continue;
            }

            b[0] +=a[0];
            b[1] += a[1];
            b[2] += a[2];
            b[0] = b[0]>=1?1:0;
            b[1] = b[1]>=1?1:0;
            b[2] = b[2]>=1?1:0;

            if(b[0] + b[1] + b[2] == 3)
                ans = min(ans, c2[i].first + c[j]);


        }

    }

    cout<<ans<<endl;

    return 0;
}
