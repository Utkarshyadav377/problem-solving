class Solution {
public:
    int calPoints(vector<string>& operations) {
        int n = operations.size();

        stack<int> st;

        for(int i = 0; i < n; i++) {
            if(operations[i] == "+") {
                int prev = st.top();
                st.pop();
                int prev2 = st.top();
                st.push(prev);
                st.push(prev2 + st.top());
            }
            else if(operations[i] == "C") {
                st.pop();
            }
            else if(operations[i] == "D") {
                st.push(2 * st.top());
            }
            else {
                st.push(stoi(operations[i]));
            }
        }
        int ans = 0;
        while(st.size()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};