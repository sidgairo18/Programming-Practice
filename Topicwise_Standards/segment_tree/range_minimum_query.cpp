#include <bits/stdc++.h>

using namespace std;

int createSegmentTree(int *st, int *arr, int ss, int se, int si){

    if(ss == se){
        st[si] = arr[ss];
        return st[si];
    }

    if(ss > se)
        return INT_MAX;

    int mid = (ss+se)/2;

    st[si] = min(createSegmentTree(st, arr, ss, mid, 2*si+1),createSegmentTree(st, arr, mid+1, se, 2*si+2));

    return st[si];
}

int getMin(int *st, int ss, int se, int l, int r, int si){

    if(ss >= l && se <= r)
        return st[si];
    if( l > se || r < ss)
        return INT_MAX;

    int mid = (ss + se)/2;

    return min(getMin(st, ss, mid, l, r, 2*si+1), getMin(st, mid+1, se, l, r, 2*si+2));
}

int updateValue(int *st, int ss, int se, int i, int diff, int si){

    if(i > se || i < ss)
        return INT_MAX;

    if(ss == se){
        st[si] += diff;
        return st[si];
    }
    
    int mid = (ss+se)/2;
    st[si] = min(getMin(st, ss, mid, i, diff, 2*si+1), getMin(st, mid+1, se, i, diff, 2*si+2));
    return st[si];

}

int main(){

    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i<n; i++)
        scanf("%d", &arr[i]);

    int h = (int)(ceil(log2(n)));
    int max_size = 2*pow(2, h) - 1;
    int *st = new int[max_size];

    createSegmentTree(st, arr, 0, n-1, 0);

    int  l, r;

    scanf("%d%d",&l, &r);

    printf("%d\n", getMin(st, 0, n-1, l, r, 0));


    return 0;
}
