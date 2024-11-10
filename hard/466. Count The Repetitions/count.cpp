class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int len1 = s1.size(), len2 = s2.size();
        vector<int> repeatCount(len2 + 1, 0), nextIndex(len2 + 1, 0);
        int j = 0, count = 0;
        
        for (int k = 1; k <= n1; ++k) {
            for (int i = 0; i < len1; ++i) {
                if (s1[i] == s2[j]) {
                    j++;
                    if (j == len2) {
                        j = 0;
                        count++;
                    }
                }
            }
            repeatCount[k] = count;
            nextIndex[k] = j;
            
            for (int start = 0; start < k; ++start) {
                if (nextIndex[start] == j) {
                    int interval = k - start;
                    int repeatInterval = (n1 - start) / interval;
                    int remaining = (n1 - start) % interval;
                    
                    return (repeatInterval * (count - repeatCount[start]) + repeatCount[start + remaining]) / n2;
                }
            }
        }
        
        return repeatCount[n1] / n2;
    }
};