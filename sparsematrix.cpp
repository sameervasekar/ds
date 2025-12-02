// 2)	Develop a program to identify and efficiently store a sparse matrix using compact representation and perform basic operations like display and simple transpose.
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cout << "Enter no of rows :";
    cin >> n;
    int m;
    cout << "Enter no of columns :";
    cin >> m;

    vector<vector<int>> array(n, vector<int>(m));

    cout << "Enter elements of the array : " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int val;
            cin >> val;
            array[i][j] = val;
        }
    }
    cout<<"Original matrix:"<<endl;
    for(int k=0;k<n;k++)
    {
        for(int l=0;l<m;l++)
        {
            cout<<array[k][l]<<" ";
        }
        cout<<endl;
    }
    cout << endl;
    
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (array[i][j] != 0)
            {
                count++;
            }
        }
    }
    vector<vector<int>> sparse(count, vector<int>(3));
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (array[i][j] != 0)
            {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = array[i][j];
                k++;
            }
        }
    }
    cout << "Row " << "Column " << "Element " << endl;
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << sparse[i][j] << "      ";
        }
        cout << endl;
    }
    vector<vector<int>>temp(n,vector<int>(m));
    for(int a=0;a<n;a++)
    {
        for(int b=0;b<m;b++)
        {
            temp[b][a]=array[a][b];
        }
    }
    for(int c=0;c<m;c++)
    {
        for(int d=0;d<n;d++)
        {
            cout<<temp[c][d]<<" ";
        }
        cout<<endl;
    }
    }

