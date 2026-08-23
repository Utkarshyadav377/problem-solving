class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size(); 

        int l = 0;
        int r = n - 1;
        int maxWater = 0;

        while(l < r) {
            int water = (r - l) * min(heights[l], heights[r]);
            maxWater = max(maxWater, water);

            if(heights[l] > heights[r]) r--;
            else l++;
        }

        return maxWater;
    }
};
