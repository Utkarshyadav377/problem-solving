class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();

        int low = 0;
        int high = n - 1;
        vector<int> ans;

        while(low <= high) {
            int mid = low + (high - low) /2;

            if(arr[mid] >= x) {
                high = mid - 1;
            }
            else if(arr[mid] < x) low = mid + 1;
        }

        int l = low - 1;
        int r = low;

        while(k--) {

            if(l < 0) {
                ans.push_back(arr[r]);
                r++;
            }
            else if(r >= n) {
                ans.push_back(arr[l]);
                l--;
            }
            else if(abs(arr[l] - x) <= abs(arr[r] - x)) {
                ans.push_back(arr[l]);
                l--;
            }
            else {
                ans.push_back(arr[r]);
                r++;
            }
        }
        sort(ans.begin(), ans.end());

        return ans;
    }
};