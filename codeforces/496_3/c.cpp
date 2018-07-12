#include <bits/stdc++.h>

using namespace std;

int main(){

    vector<int> two;
    int i;
    for(i = 2; i<=1000000000; i*=2){

        two.push_back(i);
    }

    two.push_back(i);
    
    int two_size = two.size();
    map<int, int> m;
    int n;
    int arr[120005];
    scanf("%d", &n);

    for(int i = 0; i<n; i++){
        scanf("%d", &arr[i]);
        if(m.find(arr[i]) == m.end())
            m[arr[i]] = 1;
        else
            m[arr[i]] += 1;
    }

    int count = 0, flag;
    map<int, int> :: iterator it;
    for(int i = 0; i<n; i++){

        flag = 0;

        for(int j = 0; j<two_size; j++){

            long int diff = two[j]-arr[i];

            it = m.find(diff);
            if (it != m.end() && (it->first != arr[i] || (it->first == arr[i] && it->second > 1))){
                flag = 1;
                //cout<<arr[i]<<" "<<it->first<<endl;
                break;
            }
        }
        
        if(flag == 0)
            count++;
    }

    printf("%d\n", count);

    return 0;
}
