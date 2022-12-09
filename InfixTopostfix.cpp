#include <iostream>
#include <stack>
using namespace std;

int precidence(char ch)
{
    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return -1;
}
string InfixTopostfix(string s)
{

    stack<char> st;
    string ans;
    for (int i = 0; i < s.length()+1; i++)
    {

        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'z'))
        {
            ans += s[i];
        }
        else if (s[i] == '(')
            st.push(s[i]);
        else if (s[i] == ')')
        {
            while(!st.empty() && st.top()!= '(')
            {
                ans += st.top();
                st.pop();
            }
            if(!st.empty())
            {
                st.pop();
            }
        }
        else if (s[i] == '*' || s[i] == '/' || s[i] == '+' || s[i] == '-')
        {
        
                while(!st.empty() && precidence(st.top()) >= precidence(s[i]))
                {
                    ans += st.top();
                    st.pop();
                }
                st.push(s[i]);
        }
    }
    while(!st.empty())        
    {
        ans += st.top();
        st.pop();
    }
    return ans;
}
int main()
{
    cout<<"infix to postfix converted string is : "<< InfixTopostfix("a-b/c*d+e*f/g");

    return 0;
}