string isPangram(vector <string> strings)
{
    string res;
    for(int i=0;i<strings.size();i++)
    {
        map<char,int> mymap;
        for(int j=0;j<strings[i].size();j++)
        {
            if(isalpha(strings[i][j]))
            {
                mymap[strings[i][j]]++;
            }
        }
        if(mymap.size()!=26)
        {
            res+="0";
        }
        else
        {
            res+="1";
        }
    }
    return res;
}
