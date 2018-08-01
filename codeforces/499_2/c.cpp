#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    scanf("%d", &n);
    double m;
    scanf("%lf", &m);
    vector<double> a(n);
    vector<double> b(n);

    int flag = 0;

    for(int i = 0; i<n; i++){

        double x;
        scanf("%lf", &x);
        a[i] = x;
        if(a[i] == 1)
        {
            flag = 1;

        }
    }

    for(int i = 0; i<n; i++){
        double x;
        scanf("%lf", &x);
        b[i] = x;

        if(b[i] == 1)
        {
            flag = 1;
        }
    }

    if(flag == 1){
        printf("-1\n");
        return 0;
    }

    double f;
    double ans = m;

    for(int i = n-1; i>=0; i--){
        int j = (i+1)%n;
        ans = (ans*b[j])/(b[j]-1);
        ans = (ans*a[i])/(a[i]-1);

    }
    
    ans = ans-m;
    printf("%.9lf\n", ans);

    return 0;
}
