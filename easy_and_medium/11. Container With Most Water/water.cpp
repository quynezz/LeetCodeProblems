class Solution {
public:
    int maxArea(vector<int>& height) { 
        int water = 0, i = 0; 
        int j = height.size() - 1;
        while(i < j){ 
            int l = min(height[i],height[j]) * (j - i);
            water = max(water,l);
            if(height[i] < height[j]){ 
                i++;
            }else { 
                j--;
            }
        }
    return water;
    }
};
