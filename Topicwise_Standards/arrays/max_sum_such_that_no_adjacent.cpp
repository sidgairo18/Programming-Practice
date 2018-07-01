/*
 * Maximum sum such that no two elements are adjacent
 * Given an array of positive numbers, find the maximum sum of a subsequence with the constraint that no 2 numbers in the sequence should be adjacent in the array. 
 * So 3 2 7 10 should return 13 (sum of 3 and 10) or 3 2 5 10 7 should return 15 (sum of 3, 5 and 7).Answer the question in most efficient way. 
 */
#include <bits/stdc++.h>

using namespace std;

int maxSum(int *a, int size){
    int excl_new,excl = 0, incl = a[0];

    for(int i = 1; i<size; i++){
        excl_new = max(excl, incl);
        incl = excl + a[i];
        excl = excl_new;
    }

    return max(excl, incl);

}

int main(){

    int a[] = {3,2,5,10,7};
    int ans = maxSum(a, 5);
    cout<<ans<<endl;

    return 0;
}

