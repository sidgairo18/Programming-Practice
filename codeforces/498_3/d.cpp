#include <bits/stdc++.h>

using namespace std;

//just for the heck

int main(){

    int n;
    scanf("%d", &n);

    char a[100005];
    char b[100005];

    scanf("%s", a);
    scanf("%s", b);

    int ct = 0;

    for(int i = 1; i<=(int)(n/2); i++){

        int j = i - 1;
        int k = n - i + 1 - 1;

        int arr[26];
        for(int l = 0; l<26; l++)
            arr[l] = 0;
        arr[a[j]-'a']++;
        arr[b[j]-'a']++;
        arr[a[k]-'a']++;
        arr[b[k]-'a']++;

        vector<int> check;
        for(int l = 0; l<26; l++)
            if(arr[l]!=0)
                check.push_back(arr[l]);
        sort(check.begin(), check.end());

        if(check.size() == 4)
            ct+=2;
        else if(check.size() == 3 && a[j] == a[k])
            ct+= 2;
        else if(check.size() == 3)
            ct+=1;
        else if(check.size() == 2 && check[0] == 1 && check[1] == 3)
            ct+=1;
    }

    if(n%2 != 0 && n!=1 && a[n/2] != b[n/2]){
        //cout<<"yes "<<(n/2+1)<<endl;
       ct += 1;
    }

   //condition for n = 1
   //
   //
   if(n == 1 && a[0] != b[0])
       printf("1\n");
   else
       printf("%d\n", ct); 

    return 0;
}
