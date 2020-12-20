#include <bits/stdc++.h>

using namespace std;

vector<string> generate(long long N)
{
    queue<string> q;
    q.push("1");
    vector<string> ans;
    while(N--){
        string curr = q.front();
        q.pop();
        q.push(curr+"0");
        q.push(curr+"1");
        ans.push_back(curr);
    }

    return ans;
}

int main(){

    return 0;
}
