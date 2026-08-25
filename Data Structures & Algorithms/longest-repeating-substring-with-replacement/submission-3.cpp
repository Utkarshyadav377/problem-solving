class Solution {
public:
    int characterReplacement(string s, int k) {
        int hash[26] = {0};

        int n = s.size();

        int l = 0;
        int r = 0;
        int maxLen = 0;
        int maxFreq = 0;

        while(r < n) {
            hash[s[r] - 'A']++;

            maxFreq = max(maxFreq, hash[s[r] - 'A']);
            if((r - l + 1 - maxFreq) > k) {
                hash[s[l] - 'A']--;
                l++;
            }
            else {
                maxLen = max(maxLen, r - l + 1);
            }
            r++;
        }
        return maxLen;
    }
};