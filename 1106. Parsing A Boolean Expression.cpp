class Solution {
private:
    pair<bool, bool> evalFlag(stack<char>& s) {
        bool f_flag = false, t_flag = false;
        while (s.top() != '(') {
            if (s.top() == 'f') f_flag = true;
            else t_flag = true;
            s.pop();
        }
        s.pop();
        return make_pair(f_flag, t_flag);
    }

    void evalOperation(stack<char>& s, pair<bool, bool> flag) {
        char op = s.top();
        s.pop();

        if (op == '&') {
            if (flag.first) s.push('f');
            else s.push('t');
        } else if (op == '|') {
            if (flag.second) s.push('t');
            else s.push('f');
        } else {
            if (flag.second) s.push('f');
            else s.push('t');
        }
    }

public:
    bool parseBoolExpr(string expression) {
        stack<char> s;

        for (int i = 0; i < expression.size(); i++) {
            if (expression[i] == ')') {
                auto [f_flag, t_flag] = evalFlag(s);
                evalOperation(s, make_pair(f_flag, t_flag));
            } 
            else if (expression[i] != ',') {
                s.push(expression[i]);
            }
        }

        return s.top() == 't';
    }
};