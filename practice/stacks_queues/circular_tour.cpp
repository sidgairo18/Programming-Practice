#include <bits/stdc++.h>

using namespace std;
typedef struct petrolarray{
    int petrol;
    int dist;
} petrolarray;

int circular_tour(petrolarray *arr, int n){
    
    int start = 0, end = 1;
    int curr_petrol = arr[start].petrol - arr[start].dist;

    while(start!=end || curr_petrol < 0){
        
        while(curr_petrol < 0 && start!=end){
            curr_petrol -= arr[start].petrol-arr[start].dist;
            start = (start+1)%n;
            if(start == 0)
                return -1;
        }

        curr_petrol += arr[end].petrol - arr[end].dist;
        end = (end+1)%n;
    }


    return start;
}
int main(){

    return 0;
}
