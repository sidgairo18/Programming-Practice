#include <bits/stdc++.h>

using namespace std;

int main(){

    int a,b,c;

    while(true){

        scanf("%d%d%d", &a, &b, &c);

        if(a == 0 && b == 0 && c == 0)
            break;

        int diff1, diff2;

        diff1 = b-a;
        diff2 = c-b;
    
        double r1, r2;

        r1 = double(b)/a;
        r2 = double(c)/b;

        if(r1 == r2)
            printf("GP %d", int(c*r1));
        else if(diff1 == diff2)
            printf("AP %d", (c+diff1));

        printf("\n");

    }

    return 0;

}
