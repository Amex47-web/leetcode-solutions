class Solution {
public:
    int evalRPN(vector<string>& a) {
        stack<int> s;

        for (auto &x : a) {
            if (x == "+" || x == "-" || x == "*" || x == "/") {
                int b = s.top(); s.pop();
                int c = s.top(); s.pop();

                if (x == "+") s.push(c + b);
                else if (x == "-") s.push(c - b);
                else if (x == "*") s.push(c * b);
                else s.push(c / b);
            } else {
                s.push(stoi(x));
            }
        }

        return s.top();
    }
};