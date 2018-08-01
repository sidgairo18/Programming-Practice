#include <bits/stdc++.h>

using namespace std;

int main(){

    int n,m;
    scanf("%d%d", &n, &m);getchar();

    char mat[105][105];

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++)
            scanf("%c", &mat[i][j]);
        getchar();
    }

    vector< pair<int, int> > v;
    map< pair<int,int>, int> mp;

    for(int i = 0; i<n; i++)
        for(int j = 0; j<m; j++){

            int l,r,u,d;
            l = r = u = d = 0;

            if(mat[i][j] == '*'){
                
                int temp = j-1;
                while(temp>=0 && mat[i][temp] == '*'){
                    l++;
                    temp--;
                }
                temp = j+1;
                while(temp<m && mat[i][temp] == '*'){
                    r++;
                    temp++;
                }
                temp = i-1;
                while(temp>=0 && mat[temp][j] == '*'){
                    u++;
                    temp--;
                }
                temp = i+1;
                while(temp<n && mat[temp][j] == '*'){
                    d++;
                    temp++;
                }

                l = min(l,r);
                u = min(u,d);

                if(min(l,u) > 0){
                    mp[make_pair(i,j)] = min(l,u);
                    v.push_back(make_pair(i,j));
                }
            }
        }

    char check[105][105];
    for(int i = 0; i<n; i++)
        for(int j = 0; j<m; j++)
            check[i][j] = '.';

    for(int i = 0; i<v.size(); i++){

        int x = v[i].first;
        int y = v[i].second;
        int sz = mp[make_pair(x,y)];
        check[x][y] = '*';

        for(int i = 1; i<=sz; i++){
            check[x+i][y] = '*';
            check[x][y+i] = '*';
            check[x-i][y] = '*';
            check[x][y-i] = '*';
        }
    }

    int flag = 0;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++)
            if(mat[i][j] != check[i][j]){
                flag = 1;
                break;
            }
        if(flag == 1)
            break;
    }


   int sz = v.size();
   /*printf("%d\n", sz);

   cout<<"Printing check"<<endl;
   for(int i = 0; i<n; i++){
       for(int j = 0; j<m; j++)
           printf("%c", check[i][j]);
       printf("\n");
   }*/

    if(flag == 1){
        printf("-1\n");
        return 0;
    }

   sz = v.size();
   printf("%d\n", sz);

   for(int i = 0; i<sz; i++)
       printf("%d %d\n", v[i].first+1, v[i].second+1);



    return 0;
}
