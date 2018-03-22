#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VPII;
typedef pair<LL,LL> PLL;
typedef vector<PLL> VPLL;
bool is_prime(int num)
{
    for(int i=2;i<=(int)sqrt(num);i++)
    {
        if(num % i == 0)
        {
            return false;
        }
    }
    return true;
}
void solve(vector<int> nums)
{
    int exist = 0;
    for(int i=0;i<nums.size();i++)
    {
        if(!is_prime(nums[i]))
        {
            exist = 1;
            break;
        }
    }
    printf("%s\n", exist ? "NO" : "YES" );
}
int main()
{
/* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int tc, len, tmp;
    cin>>tc;
    while(tc--)
    {
        cin>>len;
        vector<int> nums;
        for(int i=0;i<len;i++)
        {
            cin>>tmp;
            nums.push_back(tmp);
        }
        solve(nums);
    }
    return 0;
}
