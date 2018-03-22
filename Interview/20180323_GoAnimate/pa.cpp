void printBracketMatch(string str)
{
    stack<char> stk;
    int right = 1;
    for(int i=0;i<str.size();i++)
    {
        if(str[i] == '(' || str[i] == '[' || str[i] == '<' || str[i] == '{')
        {
            stk.push(str[i]);
        }
        else if( str[i] == ')' )
        {
            if(stk.empty() || stk.top() != '(')
            {
                right = 0;
                break;
            }
            stk.pop();

        }
        else if( str[i] == ']' )
        {
            if(stk.empty() || stk.top() != '[')
            {
                right = 0;
                break;
            }
            stk.pop();

        }
        else if( str[i] == '>' )
        {
            if(stk.empty() || stk.top() != '<')
            {
                right = 0;
                break;
            }
            stk.pop();

        }
        else if( str[i] == '}' )
        {
            if(stk.empty() || stk.top() != '{')
            {
                right = 0;
                break;
            }
            stk.pop();
        }
    }

    if(!stk.empty())
    {
        right = 0;
    }

    if(right)
    {
        cout<<"MATCH";
    }
    else
    {
        cout<<"NO MATCH";
    }
}
