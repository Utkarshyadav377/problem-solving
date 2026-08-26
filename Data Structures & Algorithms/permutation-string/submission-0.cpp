class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();

        if(n1 > n2) return false;
        unordered_map<char, int> mpp;
        
        int l = 0;
        int r = n1 - 1;

        vector<int> count1(26, 0);

        for(int i = 0; i < n1; i++) {
            count1[s1[i] - 'a']++;
        }

        while(r < n2) {
            int matches = 0;
            vector<int> count2(26, 0);
            for(int k = l; k <= r; k++) {
                count2[s2[k] - 'a']++;
            }
            for(int j = 0; j < 26; j++) {
                if(count1[j] == count2[j]) matches++;
            }
            if(matches == 26) return true;
            l++;
            r++;
        }
        return false;
    }
};
