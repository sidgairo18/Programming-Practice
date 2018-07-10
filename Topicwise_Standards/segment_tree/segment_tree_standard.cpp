#include <bits/stdc++.h>

int createSegmentTree(int *st, int *arr, int ss, int se, int si){

    if(ss == se)
    {
        st[si] = arr[ss];
        return st[si];
    }

    if(ss > se)
        return 0;

    int mid = (ss+se)/2;

    st[si] = createSegmentTree(st, arr, ss, mid, 2*si+1) + createSegmentTree(st, arr, mid+1, se, 2*si+2);

    return st[si];
}

int getSum(int *st, int ss, int se, int l, int r, int si){

    if(l <= ss && r>=se)
        return st[si];

    if(l > se || r < ss)
        return 0;

    int mid = (ss+se)/2;

    return getSum(st, ss, mid, l, r, 2*si+1) + getSum(st, mid+1, se, l ,r, 2*si+2);
}

void updateValue(int *st, int ss, int se, int i, int diff, int si){

    if( i > se || i<ss)
        return;

    st[si] += diff;

    if(ss != se){
        int mid = (se+ss)/2;
        updateValue(st, ss, mid, i, diff, 2*si+1);
        updateValue(st, mid+1, se, i, diff, 2*si+2);
    }

}

int main(){

    int n;
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    //creating the segment tree
    //Height = ceil(log2(n))
    //Max number of nodes in the tree - (2*2^h - 1)
    //Number of leaves = n, number of internal nodes = n-1. Since a seg-
    //ment tree is a Full Binary Tree where each node has either 0 or 2
    //children.
    int h = (int)(ceil(log2(n)));
    int max_size = 2*(pow(2, h)) - 1;
    int *st = new int[max_size];

    createSegmentTree(st, arr, 0, n-1, 0);

    int q, x, l, r;

    while(true){

        scanf("%d", &q);
        if(q == 0)
            break;

        if(q == 1){

            scanf("%d%d", &x, &l);
            int diff = x-arr[l];
            arr[l] = x;
            updateValue(st, 0, n-1, l, diff, 0);
        }
        else if(q == 2){

            scanf("%d%d", &l, &r);
            int ans = getSum(st, 0, n-1, l, r, 0);
            printf("%d\n", ans);

        }
    }
    return 0;
}
