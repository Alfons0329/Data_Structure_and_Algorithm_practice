
void counterGame(vector <string> tests)
{
    int reduce_value = 0;
    for(int i=0;i<tests.size();i++)
    {
        // cout<<"Testcase "<<i<<" is "<<tests[i]<<endl;
        long long int cnt = stoll(tests[i]);
        long long int near = 0;
        if(cnt == 1)
        {
            cout<<"Richard"<<endl;
        }
        else
        {
            int winner = 0;// 0 for Louise begin but since toggle, 1 = louise win, else richard
            while(cnt != 1)
            {
                if(( cnt & (cnt - 1) )== 0) //is a power of 2 divide by half
                {
                    cnt /= 2;
                }
                else //reduced by the max value that closes to cnt
                {
                    near = (long long int)pow(2, (int) log2(cnt));
                    // cout<<"Near is "<<near<<endl;
                    cnt -= near;
                }
                // cout<<"Cnt is now "<<cnt<<endl;
                winner ^= 1; //toggle
            }
            if(winner)
            {
                cout<<"Louise"<<endl;
            }
            else
            {
                cout<<"Richard"<<endl;
            }
        }
    }
}
