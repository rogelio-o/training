#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

bool checkValidCell(set<string> * walk, int i, int j, char prevMovement) {
    string positionKey = to_string(i) + "-" + to_string(j);

    int prevI;
    int prevJ;
    if(prevMovement == 'S') {
        prevI = i - 1;
        prevJ = j;
    } else {
        prevI = i;
        prevJ = j - 1;
    }
    string prevPositionKey = to_string(prevI) + "-" + to_string(prevJ);

    return walk->find(prevPositionKey + "->" + positionKey) == walk->end();
}

bool solve(int n, set<string> * walk, int i, int j, char prevMovement, vector<char> * result, set<string> * cache) {
    string key = to_string(i) + "-" + to_string(j);
    auto found = cache->find(key);
    if(found != cache->end()) {
        return false;
    } else if(i < 0 || j < 0 || i >= n || j >= n) {
        cache->insert(key);
        return false;
    } else if(!checkValidCell(walk, i, j, prevMovement)) {
        return false;
    } else if(i == (n - 1) && j == (n - 1)) {
        return true;
    }

    if(prevMovement == 'S') {
        bool bottom = solve(n, walk, i + 1, j, 'S', result, cache);
        if(bottom) {
            result->push_back('S');
            return true;
        }
    }

    bool right = solve(n, walk, i, j + 1, 'E', result, cache);
    if(right) {
        result->push_back('E');
        return true;
    }

    bool bottom = solve(n, walk, i + 1, j, 'S', result, cache);
    if(bottom) {
        result->push_back('S');
        return true;
    }

    cache->insert(key);
    return false;
}

vector<char> solve(int n, set<string> * matrix) {
    vector<char> result;
    set<string> cache;

    solve(n, matrix, 0, 0, 'S', &result, &cache);

    return result;
}

int main()
{
    int numProblems;
    cin >> numProblems;

    for(int problemIndex = 1; problemIndex <= numProblems; problemIndex++) {
        int n;
        cin >> n;

        set<string> walk;
        pair<int, int> position = make_pair(0, 0);
        for(int i = 0; i < (2 * n) - 2; i++) {
            char c;
            cin >> c;

            pair<int, int> newPosition;
            if(c == 'S') {
                newPosition = make_pair(position.first + 1, position.second);
            } else {
                newPosition = make_pair(position.first, position.second + 1);
            }
            string positionKey = to_string(newPosition.first) + "-" + to_string(newPosition.second);
            string prevPositionKey = to_string(position.first) + "-" + to_string(position.second);
            walk.insert(prevPositionKey + "->" + positionKey);
            position = newPosition;
        }
        cout << "\n";

        vector<char> ans = solve(n, &walk);
        cout << "Case #" << problemIndex << ": ";
        for(int i = ans.size() - 1; i >= 0; i--) {
            cout << ans[i];
        }
        cout << "\n";
    }
}