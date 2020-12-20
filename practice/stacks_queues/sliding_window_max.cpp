#include <bits/stdc++.h>

using namespace std;

void printKMax(int *arr, int n, int k){
    deque<int> dq;
    for(int i = 0; i<k; i++){
        while(!dq.empty() && arr[dq.back()] <= arr[i])
            dq.pop_back();
        dq.push_back(i);
    }
    for(int i = k; i<n; i++){
        
        cout<<arr[dq.front()]<<" ";
        while(!dq.empty() && dq.front() <= (i-k))
            dq.pop_front();

        while(!dq.empty() && arr[dq.back()] <= arr[i])
            dq.pop_back();

        dq.push_back(i);
    }
    cout<<arr[dq.front()]<<endl;

    return;
}

// Driver code
int main()
{
    int arr[] = { 12, 1, 78, 90, 57, 89, 56 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    cout<<n<<" "<<k<<endl;
    printKMax(arr, n, k);
    return 0;
}
