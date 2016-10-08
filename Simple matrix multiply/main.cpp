#include <iostream>
#include <vector>
using namespace std;
vector<vector <long long int> >matrix_a,matrix_b;
long long int aro,bro,acl,bcl;
void matrix_mul(vector<vector <long long int> > ma,vector<vector <long long int> > mb) //O(N^3) normal multiplication
{
    vector <vector <long long int>> ans;
    if(acl!=bro)
    {
        cout<<"Unable to multiply both matrices. \n";
    }
    else
    {
            ans.resize(aro,vector<long long int>(bcl,0)); //initial all the element in ans 2d vector to be 0
        for(int i=0;i<aro;i++)
        {
            for(int j=0;j<bcl;j++)
            {
                for(int k=0;k<acl /*k<bro also works*/;k++)
                {
                    ans[i][j]+=matrix_a[i][k]*matrix_b[k][j];
                }
            }
        }
        cout<<"Multiplication of 2 matrices :\n";
        for(int i=0;i<aro;i++)
        {
            cout<<endl;
            for(int j=0;j<bcl;j++)
                cout<<ans[i][j]<<" ";
        }

    }
}
int main()
{
    cout<<"Enter matrix_a row col and matrix_b row col: ";
    cin>>aro>>acl>>bro>>bcl;
    matrix_a.resize(aro);
    matrix_b.resize(bro);
    cout<<"Enter a's data \n";
    for(int i=0;i<aro;i++)
    {
        cout<<"Row "<<i<<"->";
        for(int j=0;j<acl;j++)
        {
            int tmp;
            cin>>tmp;
            matrix_a[i].push_back(tmp);
        }
    }
    cout<<"Enter b's data \n";
    for(int i=0;i<bro;i++)
    {
        cout<<"Row "<<i<<"->";
        for(int j=0;j<bcl;j++)
        {
            int tmp;
            cin>>tmp;
            matrix_b[i].push_back(tmp);
        }
    }
    matrix_mul(matrix_a,matrix_b);
    return 0;
}
