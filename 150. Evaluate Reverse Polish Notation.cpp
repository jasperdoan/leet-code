class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int x, y;

        auto topPop = [&] () -> void {
            x = s.top();
            s.pop();
            y = s.top();
            s.pop();
        };

        for (auto str : tokens){
            if (str == "+" or str == "-" or str == "*" or str == "/"){
                const char *ch = str.c_str();
                topPop();
                switch (*ch){
                    case '+':
                        s.push(x + y);
                        break;
                    case '-': 
                        s.push(y - x);
                        break;
                    case '*':
                        s.push(x * y);
                        break;
                    case '/':
                        s.push(y / x);
                        break;
                }  
            }
            else{
                s.push(stoi(str));
            }
        }

        return s.top();
    }
};


// BAD CODE:
// auto topPop = [&] () -> void {
//     x = s.top();
//     s.pop();
//     y = s.top();
//     s.pop();
// };

// for (auto ch : tokens){
//     if (ch == "+"){
//         topPop();
//         s.push(x + y);
//     }
//     else if (ch == "-"){
//         topPop();
//         s.push(y - x);
//     }
//     else if (ch == "*"){
//         topPop();
//         s.push(x * y);
//     }
//     else if (ch == "/"){
//         topPop();
//         s.push(y / x);
//     }
//     else{
//         s.push(stoi(ch));
//     }
// }