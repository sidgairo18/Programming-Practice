#include <bits/stdc++.h>

using namespace std;

int my_gcd(int a, int b){

    if(b == 0)
        return a;
    return (b, a%b);
}

int main(){

    int n;
    scanf("%d", &n);

    vector<int> s1;
    vector<int> s2;

    for(int i = 1; i<=n; i++){
        if(i%2 == 0)
            s1.push_back(i);
        else
            s2.push_back(i);
    }

    if(n == 1 || n==2){
        printf("No\n");
        return 0;
    }

    int g1 = s1[0];
    int g2 = s2[0];

    for(int i = 1; i<s1.size(); i++)
        g1 = my_gcd(g1, s1[i]);

    for(int i = 1; i<s2.size(); i++)
        g2 = my_gcd(g2, s2[i]);

    if(g1>g2){
        int l1 = s1.size();
        int l2 = s2.size();
        printf("Yes\n");
        printf("%d ", l1);
        for(int i = 0; i<l1; i++)
            printf("%d ", s1[i]);
        printf("\n");
        printf("%d ", l2);
        for(int i = 0; i<l2; i++)
            printf("%d ", s2[i]);
        printf("\n");
    }
    else if(g1<g2){

        int l1 = s1.size();
        int l2 = s2.size();
        printf("Yes\n");
        printf("%d ", l2);
        for(int i = 0; i<l2; i++)
            printf("%d ", s2[i]);
        printf("\n");
        printf("%d ", l1);
        for(int i = 0; i<l1; i++)
            printf("%d ", s1[i]);
        printf("\n");

    }
    else
        printf("No\n");


    return 0;
}
