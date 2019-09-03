class Solution {
public:
    int maxArea(vector<int>& height) {
        int m = -1;
        int l = 0;
        int r = height.size()-1;
        
        while(l < r) {
            m = max(m, (r - l) * min(height[l], height[r]));
            if(height[l] >= height[r]) {
                r--;
            } else {
                l++;
            }
        }
        return m;
    }
};