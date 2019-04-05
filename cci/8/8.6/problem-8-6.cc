#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stack>

using namespace std;

void solve(int n, stack<int> * src, stack<int> * dest, stack<int> * buffer) {
    if(n <= 0) {
        return;
    }

    solve(n - 1, src, buffer, dest);

    dest->push(src->top());
    src->pop();

    solve(n - 1, buffer, dest, src);
}

void solve(stack<int> * a, stack<int> * b, stack<int> * c) {
    solve(a->size(), a, c, b);
}

int main()
{
    int numProblems;
    cin >> numProblems;

    for(int problemIndex = 1; problemIndex <= numProblems; problemIndex++) {
        int n;
        cin >> n;

        stack<int> a;
        stack<int> b;
        stack<int> c;

        for(int i = 0; i < n; i++) {
            a.push(n - i);
        }

        solve(&a, &b, &c);
        cout << "Case #" << problemIndex << ":\n";
        int size = c.size();
        for(int i = 0; i < size; i++) {
            cout << to_string(c.top()) << ", ";
            c.pop();
        }
        cout << "\n";
    }
}