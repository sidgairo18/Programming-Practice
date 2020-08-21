#include <bits/stdc++.h>

using namespace std;

struct petrolPump{
    int petrol;
    int distance;
};

int tour(petrolPump p[], int n){

    int start = 0, end = 1;
    int curr = p[start].petrol - p[start].distance;
    while(end!=start || curr < 0){

        while(start!=end && curr<0){
            curr -= p[start].petrol - p[start].distance;
            start = (start+1)%n;
            if (start == 0)
                return -1;
        }

        curr +=  p[end].petrol - p[end].distance;
        end = (end+1)%n;

    }

    return start;

}

int main(){

    int n;
    cin>>n;

    petrolPump p[n];
    // petrol
    for(int i = 0; i<n; i++)
        cin>>p[i].petrol;
    for(int i = 0; i<n; i++)
        cin>>p[i].distance;

    int ans = tour(p, n);
    cout<<ans<<endl;

    return 0;
}
