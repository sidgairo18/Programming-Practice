#include <bits/stdc++.h>

using namespace std;

int isDistinct(int y){

    int d[10];
    memset(d,0,sizeof(d));
    
    int check = 0;
    while(y!=0){
        int dig = y%10;
        d[dig]++;
        y/=10;
        if(d[dig] > 1)
            check=1;
    }

    if(check==1)
        return 0;
    else
        return 1;
}

int main(){

    int y;
    cin>>y;

    for(int i=y+1;;i++){

        if(isDistinct(i)==1){

            cout<<i<<endl;
            break;

        }

    }

    return 0;
}
