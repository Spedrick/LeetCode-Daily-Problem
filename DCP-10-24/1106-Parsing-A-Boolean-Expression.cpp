class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;

        for(char c: expression) {
            if(c == '(' || c == ',') continue;
            else if (c == 't' || c == 'f' || c == '&' || c == '|' || c == '!') st.push(c);
            else {
                bool hasTrue = false, hasFalse = false;
                char top = st.top();
                while(top == 'f' || top == 't') {
                    if(top == 'f') hasFalse = true;
                    if(top == 't') hasTrue = true;

                    st.pop();
                    top = st.top();
                }
                st.pop();
                cout << top << " " << hasTrue << " " << hasFalse << endl;
                if(top == '!') {
                    st.push(hasTrue ? 'f' : 't');
                } else if (top == '&') {
                    st.push(hasFalse ? 'f' : 't');
                } else {
                    st.push(hasTrue ? 't' : 'f');
                }
            }
        }

        return st.top() == 't';
    }
};