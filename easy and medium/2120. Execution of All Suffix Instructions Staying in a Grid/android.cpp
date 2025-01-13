class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int> ans;
        int x = startPos[0];
        int y = startPos[1];
        for (int i = 0; i < s.size(); i++) {
            int count = 0;
            int k1 = x; 
            int k2 = y;
            for (int j = i; j < s.size(); j++) {
                if (s[j] == 'L') {
                    if (k2 - 1 >= 0) {
                        k2 -= 1;
                        count++;
                    } else {
                        break; 
                    }
                } else if (s[j] == 'R') {
                    if (k2 + 1 < n) {
                        k2 += 1;
                        count++;
                    } else {
                        break;
                    }
                } else if (s[j] == 'U') {
                    if (k1 - 1 >= 0) {
                        k1 -= 1;
                        count++;
                    } else {
                        break;
                    }
                } else if (s[j] == 'D') {
                    if (k1 + 1 < n) {
                        k1 += 1;
                        count++;
                    } else {
                        break;
                    }
                }
            }

            ans.push_back(count);
        }

        return ans;
    }
};
