class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int ans = 0;
        int num = 0;
        char op = '+';
        for (int i = 0; i < s.size(); i++){
            if (isdigit(s[i])){
                num = num * 10 + (s[i] - '0');
            }
            if ((!isdigit(s[i]) and !isspace(s[i])) or i == s.size() - 1){
                switch (op){
                    case '+':
                        st.push(num);
                        break;
                    case '-':
                        st.push(-num);
                        break;
                    case '*':
                        num *= st.top();
                        st.pop();
                        st.push(num);
                        break;
                    case '/':
                        num = st.top() / num;
                        st.pop();
                        st.push(num);
                        break;
                }
                op = s[i];
                num = 0;
            }
        }
        while (!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};