#include <vector>
#include <queue>
#include <set>
using namespace std;

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // Step 1: Build the graph and compute in-degree of each node
        vector<set<int>> graph(numCourses); // Adjacency list
        vector<int> inDegree(numCourses, 0); // In-degree of each node

        for (const auto& pre : prerequisites) {
            int u = pre[0]; // Prerequisite course
            int v = pre[1]; // Target course
            graph[u].insert(v); // Add edge from u to v
            inDegree[v]++; // Increment in-degree of v
        }

        // Step 2: Perform Kahn's Algorithm to get the topological order
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.push(i); // Add nodes with 0 in-degree to the queue
            }
        }

        vector<set<int>> prerequisitesMap(numCourses);
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : graph[u]) {
                // Propagate prerequisites: v inherits all prerequisites of u
                prerequisitesMap[v].insert(u);
                prerequisitesMap[v].insert(prerequisitesMap[u].begin(), prerequisitesMap[u].end());

                inDegree[v]--; // Reduce in-degree of v
                if (inDegree[v] == 0) {
                    q.push(v); // Add to queue if in-degree becomes 0
                }
            }
        }

        // Step 4: Answer the queries
        vector<bool> res;
        for (const auto& query : queries) {
            int u = query[0]; // Prerequisite course
            int v = query[1]; // Target course

            // Check if u is in the prerequisites of v
            res.push_back(prerequisitesMap[v].count(u) > 0);
        }

        return res;
    }
};