#include <iostream>
#include <stack>
#include <map>
#include <cstring>

using namespace std;

int cnt;

int precedence(char c) {
    if (c == '+'  || c == '-') return 1;
    else if (c == '*' ||  c == '/') return 2;
    else if (c == '(') return 0;
    else return -1;
}

int main() {

    int t;
    cin >> t;

    char dummy[1000];
    gets(dummy);
    gets(dummy);

    while (t--) {
        char c;
        stack<char> st;
        char line[1000];

        while (gets(line) && strlen(line)) {
            c = line[0];

            if (c == '(') {
                st.push(c);
            } else if (isdigit(c)) {
                cout << c;
            } else if (c == ')') {
                while (!st.empty() && st.top() != '(') {
                    cout << st.top();
                    st.pop();
                }
                st.pop();
            } else {
                while (!st.empty() && (precedence(st.top()) >= precedence(c))) {
                    cout << st.top();
                    st.pop();
                }
                st.push(c);
            }
        }

        while (!st.empty()) {
            cout << st.top();
            st.pop();
        }

        cout << endl;
        if(t)cout << endl;
    }

    return 0;
}