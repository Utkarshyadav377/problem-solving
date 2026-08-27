class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();

        int low = 0;
        int high = n - 1;

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
                r++;
            }
            else if(r >= n) {
                l--;
            }
            else if(abs(arr[l] - x) <= abs(arr[r] - x)) {
                l--;
            }
            else {
                r++;
            }
        }

        return vector<int>(arr.begin() + l + 1, arr.begin() + r);
    }
};