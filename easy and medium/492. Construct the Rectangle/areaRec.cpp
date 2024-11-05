class Solution {
public:
    vector<int> constructRectangle(int area) { 
        int n = sqrt(area);
        int width = 0; 
        vector<int> v;
        for(int i = 1; i <= n; i++){ 
            if(area % i == 0){      
                width = i;
            }
        }
        int length = area / width;  
        v.push_back(length); 
        v.push_back(width); 
        return v;
    }
};