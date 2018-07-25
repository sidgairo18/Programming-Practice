#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    scanf("%d", &t);

    while(t--){

        char s[405];
        scanf("%s", s);

        int l = strlen(s);

        stack<char> s1;

        for(int i = 0; i<l; i++){

            if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^'){
                s1.push(s[i]);
                continue;
            }

            if(s[i] != '(' && s[i] != ')')
                printf("%c", s[i]);
            if(s[i] == ')'){
                printf("%c", s1.top());
                s1.pop();
            }
        }
        printf("\n");

    }

    return 0;

}
