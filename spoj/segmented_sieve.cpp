#include <bits/stdc++.h>

using namespace std;

void get_simple_sieve(int n, vector<int> &v){

    int sieve[n];

    for(int i = 0; i<n; i++)
        sieve[i] = 0;
    sieve[0] = sieve[1] = 1;

    for(int i = 2; i*i<=n; i++)
        if(!sieve[i])
            for(int j = i+i; j<n; j+=i)
                sieve[j] = 1;

    for(int i = 0; i<n; i++)
        if(!sieve[i])
            v.push_back(i);

    return;
}

void segmented_sieve(int n){

    int limit = floor(sqrt(n))+1;

    vector<int> primes;
    get_simple_sieve(limit, primes);

    int sz = primes.size();

    for(int i = 0; i<sz; i++)
        printf("%d\n", primes[i]);


    int low = limit;
    int high = 2*limit;

    while(low<=n){

        //printf("Printing segments\n");
        //printf("Low %d High %d\n", low, high);

        if(high > n)
            high = n;

        int mark[high-low+1];

        for(int i = 0; i<(high-low+1); i++)
            mark[i] = 0;

        for(int i = 0; i<sz; i++){

            int cur_prime = primes[i];

            int start = floor(low/cur_prime)*cur_prime;

            if(start < low)
                start += cur_prime;

            for(int j = start; j<=high; j+=cur_prime)
                mark[j-low] = 1;
        }

        //printing primes in range low...high

        for(int i = 0; i<(high-low+1); i++)
            if(!mark[i])
                printf("%d\n", low+i);

        low = high+1;
        high = high + limit;
    }

    return;

}

int main(){

    segmented_sieve(100);

    return 0;
}
