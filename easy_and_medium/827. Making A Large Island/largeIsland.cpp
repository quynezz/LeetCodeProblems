#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxN = 1000001;
const int MOD = 1e9;
#define vii vector<pair<int, int>>

class Solution {
private:
    // DFS to explore the connected component and calculate its size
    int findConnectedComponent(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& islandSize, int islandID) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0 || islandSize[i][j] != -1) {
            return 0;
        }
        islandSize[i][j] = islandID;
        int size = 1;
        size += findConnectedComponent(i + 1, j, grid, islandSize, islandID);
        size += findConnectedComponent(i - 1, j, grid, islandSize, islandID);
        size += findConnectedComponent(i, j + 1, grid, islandSize, islandID);
        size += findConnectedComponent(i, j - 1, grid, islandSize, islandID);
        return size;
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int res = 0;
        vector<vector<int>> islandSize(n, vector<int>(n, -1));  // -1 means unvisited
        int islandID = 0;
        vector<int> islandAreas;  // Store the area of each island

        // Step 1: Find the connected components of 1s and label them
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && islandSize[i][j] == -1) {
                    int area = findConnectedComponent(i, j, grid, islandSize, islandID);
                    islandAreas.push_back(area);
                    res = max(res, area);  // Track the largest island found
                    islandID++;
                }
            }
        }

        // Step 2: Try flipping each 0 to 1 and calculate the resulting island size
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    int current = 1; // Start with the flipped cell
                    unordered_set<int> neighboringIslands;  // Track neighboring islands

                    if (i + 1 < n && grid[i + 1][j] == 1) {
                        neighboringIslands.insert(islandSize[i + 1][j]);
                    }
                    if (i - 1 >= 0 && grid[i - 1][j] == 1) {
                        neighboringIslands.insert(islandSize[i - 1][j]);
                    }
                    if (j + 1 < n && grid[i][j + 1] == 1) {
                        neighboringIslands.insert(islandSize[i][j + 1]);
                    }
                    if (j - 1 >= 0 && grid[i][j - 1] == 1) {
                        neighboringIslands.insert(islandSize[i][j - 1]);
                    }

                    // Add the areas of all neighboring islands
                    for (int island : neighboringIslands) {
                        current += islandAreas[island];
                    }

                    // Track the maximum size found
                    res = max(res, current);
                }
            }
        }

        return res;
    }
};

auto speedup = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();


