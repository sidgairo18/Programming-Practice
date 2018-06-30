#include <bits/stdc++.h>

using namespace std;

int findPivot(int a[], int l, int h){

    if (l > h)
        return -1;
    if (l == h)
        return l;

    int mid = (l+h)/2;

    if (mid < h && a[mid] > a[mid+1])
        return mid;
    if (mid > l && a[mid] < a[mid-1])
        return mid-1;

    if (a[l] >= a[mid])
        return findPivot(a,l,mid-1);

    return findPivot(a,mid+1, h);

}

int binSearch(int a[], int l, int h, int key){

    if (l>h)
        return -1;
    if (l == h)
        return l;

    int mid = (l+h)/2;

    if (a[mid] == key)
        return mid;
    if (a[mid] > key)
        return binSearch(a, l, mid-1, key);
    return binSearch(a,mid+1, h, key);

}

int main(){

    int a[] = {5,6,7,8,9,10, 1,2,3};
    int size = 9;

    int pivot = findPivot(a, 0,size-1);
    int ans = -99999;
    int key = 100;
    if (pivot == -1)
        ans = binSearch(a, 0, size-1, key);
    else if(key >= a[0])
        ans = binSearch(a,0,pivot, key);
    else
        ans = binSearch(a,pivot+1, size-1, key);

    cout<<"ANS "<<ans<<endl;
    

    return 0;
}
