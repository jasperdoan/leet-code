class Solution {
private:
    pair<bool, bool> setFlag(stack<char>& s) {
        bool f_flag = false, t_flag = false;
        while (s.top() != '(') {
            // If ch is f -> set f_flag / otherwise t_flag
            s.top() == 'f' ? f_flag = true : t_flag = true;
            s.pop();
        }
        s.pop();    // Pop '('

        return make_pair(f_flag, t_flag);
    }

    void evalOperation(stack<char>& s, pair<bool, bool> flag) {
        // flag ->    first      second
        //         (TRUE_Flag, FALSE_Flag)
        char op = s.top();
        s.pop();

        if (op == '&') {
            flag.first ? s.push('f') : s.push('t');     // If there's a FALSE instance & it was '&' -> False
        } 
        else if (op == '|') {
            flag.second ? s.push('t') : s.push('f');    // If there's a TRUE instance & it was '|' -> True
        } 
        else {
            flag.second ? s.push('f') : s.push('t');    // Not Gate
        }
    }

public:
    bool parseBoolExpr(string expression) {
        stack<char> s;

        for (int i = 0; i < expression.size(); i++) {
            if (expression[i] == ')') {
                auto [f_flag, t_flag] = setFlag(s);             // Set flag instance
                evalOperation(s, make_pair(f_flag, t_flag));    // Evaluate operation 
            } 
            else if (expression[i] != ',') {
                s.push(expression[i]);
            }
        }

        return s.top() == 't';
    }
};