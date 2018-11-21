#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin>>n;
    priority_queue<int> h1;
    priority_queue<int, vector<int>, greater<int> > h2;
    h1.push(INT_MIN);
    h2.push(INT_MAX);
    int x;
    while(n--){
        
        cin>>x;

        if(h1.size() == h2.size()){

            if(x <= h2.top())
                h1.push(x);
            else
                h2.push(x);
        }
        else if(h1.size() > h2.size()){

            if( x <= h1.top()){

                h2.push(h1.top());
                h1.pop();
                h1.push(x);
            }
            else
                h2.push(x);
        }
        else{

            if(x <= h2.top())
                h1.push(x);
            else{

                h1.push(h2.top());
                h2.pop();
                h2.push(x);
            }

        }

        //printing the current median.
        if(h1.size() > h2.size())
            cout<<h1.top()<<endl;
        else if(h1.size() < h2.size())
            cout<<h2.top()<<endl;
        else
            cout<<(h1.top() + h2.top())/2<<endl;

    }

    return 0;
}
