class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> v(n, 0); // Initialize the array with 0s
        vector<int> ans;     // To store the results
        int count = 0;       // Tracks the number of valid adjacent pairs

        for (auto it : queries) {
            int idx = it[0]; 
            int color = it[1]; 
            if (idx > 0 && v[idx] != 0 && v[idx] == v[idx - 1]) {
                count--;
            }
            if (idx < n - 1 && v[idx] != 0 && v[idx] == v[idx + 1]) {
                count--;
            }

            // Update the color at the given index
            v[idx] = color;

            // Check and increment count for new pairs at idx-1 and idx
            if (idx > 0 && v[idx] != 0 && v[idx] == v[idx - 1]) {
                count++;
            }
            if (idx < n - 1 && v[idx] != 0 && v[idx] == v[idx + 1]) {
                count++;
            }

            // Store the current count in the result
            ans.push_back(count);
        }

        return ans;
    }
};
