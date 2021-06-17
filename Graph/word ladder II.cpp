// https://leetcode.com/problems/word-ladder-ii/
// lc 126

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> ans;

    void DFS(string &beginWord, string &endWord, unordered_map<string, unordered_set<string>> &adj, vector<string> &path)
    {

        path.push_back(beginWord);

        if (beginWord == endWord)
        {
            ans.push_back(path);
            path.pop_back();
            return;
        }
        for (auto it : adj[beginWord])
        {
            DFS(it, endWord, adj, path);
        }
        path.pop_back();
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_map<string, unordered_set<string>> adj;
        unordered_set<string> dict(wordList.begin(), wordList.end());

        queue<string> Q;
        Q.push(beginWord);
        unordered_map<string, int> visited;
        visited[beginWord] = 0;

        while (!Q.empty())
        {
            string curr = Q.front();
            Q.pop();
            string temp = curr;

            for (int i = 0; i < curr.size(); i++)
            {
                for (char x = 'a'; x <= 'z'; ++x)
                {

                    if (temp[i] == x)
                        continue;
                    temp[i] = x;

                    if (dict.count(temp) > 0)
                    {
                        if (visited.count(temp) == 0)
                        {
                            visited[temp] = visited[curr] + 1;
                            Q.push(temp);
                            adj[curr].insert(temp);
                        }

                        else if (visited[temp] == visited[curr] + 1)
                        {
                            adj[curr].insert(temp);
                        }
                    }
                }
                temp[i] = curr[i];
            }
        }

        vector<string> path;
        DFS(beginWord, endWord, adj, path);
        return ans;
    }
};

static const int _ = []() { //Code for faster runtime
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();