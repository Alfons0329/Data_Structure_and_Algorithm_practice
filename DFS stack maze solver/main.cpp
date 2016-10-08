#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<vector>
#include<iostream>
#include<algorithm>
#define MAXN 1010000
#define LL long long
#define ll __int64
#define INF 0xfffffff
#define mem(x) memset(x,0,sizeof(x))
#define PI acos(-1)
#define eps 1e-8
#include "maze and main exec function.h"
using namespace std;
int main()
{
    main_maze_function maz;
    maz.solver();
	maz.show_solution();
	system("pause");
    return 0;
}
