#include <bits/stdc++.h>

using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void sort_recursion(stack<int>& st, int x){

    if(st.empty() || st.top() <= x)
        st.push(x);
    else{

        int temp = st.top();
        st.pop();
        sort_recursion(st, x);
        st.push(temp);
    }
}

void SortedStack :: sort()
{
   if(s.empty())
        return;

    int temp = s.top();
    s.pop();
    sort();
    sort_recursion(s, temp);
}
