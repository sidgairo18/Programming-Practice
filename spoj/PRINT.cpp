#include <bits/stdc++.h>

using namespace std;

void sieve(int n, vector<int> &v){

    int sieve[n];

    for(int i = 0; i<n; i++)
        sieve[i] = 0;

    sieve[0] = sieve[1] = 1;

    for(int i = 2; i*i<n; i++)
        if(!sieve[i])
            for(int j = 2*i; j<n; j+=i)
                sieve[j] = 1;

    for(int i = 0; i<n; i++)
        if(!sieve[i])
            v.push_back(i);

    return;
}

void segmented_sieve(int low, int high){

    int limit = floor(sqrt(high))+1;

    vector<int> primes;

    sieve(limit, primes);

    int sz = primes.size();

    for(int i = 0; i<sz; i++)
        if(primes[i] >=low && primes[i] <=high)
            printf("%d\n", primes[i]);

    //printf("Size %d\n", sz);

    int mark[high-low+1];
    for(int i = 0; i<(high-low+1); i++)
        mark[i] = 0;

    for(int i = 0; i<sz; i++){

        int cur_prime = primes[i];

        int start = floor(low/cur_prime)*cur_prime;

        if(start<low)
            start += cur_prime;

        for(int j = start; j<=high; j+=cur_prime)
            mark[j-low] = 1;
    }

    for(int i = 0; i<(high-low+1); i++)
        if(!mark[i] && (low+i) != 1)
            printf("%d\n", low+i);


    return; 
}



int main(){

    int t;
    scanf("%d", &t);

    int low, high;

    while(t--){

        scanf("%d%d", &low, &high);

        segmented_sieve(low, high);

    }

    return 0;
}
