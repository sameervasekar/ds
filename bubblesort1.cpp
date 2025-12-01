#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;
struct students{
    string name;
    int marks;
};
int main()
{
    int n;
    cout<<"Enter the number of students:";
    cin>>n;
    vector<students>v(n);
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the name of the student "<<i+1<<endl;
        cin>>v[i].name;
        cout<<"Enter the marks of the student "<<i+1<<endl;
        cin>>v[i].marks;

    }
    cout<<"The students and their marks are:"<<endl;
    cout<<left<<setw(8)<<"Name"<<setw(8)<<"Marks"<<endl;
    for(int j=0;j<n;j++)
    {
        cout<<left<<setw(8)<<v[j].name<<setw(8)<<v[j].marks<<endl;
    }
    for(int i=n-2;i>=0;i--)
    {
        bool swapped=0;
        for(int j=0;j<=i;j++)
        {
            if(v[j].marks<v[j+1].marks)
            {
                swap(v[j],v[j+1]);
                swapped=1;
            }
            
        }
        if(!swapped)
            {
                break;
            }
            cout<<"Pass "<<n-1-i<<endl;
            cout<<left<<setw(8)<<"Roll"<<setw(8)<<"Name"<<setw(8)<<"Marks"<<endl;
            for(int l=0;l<n;l++)
    {
        cout<<left<<setw(8)<<l+1<<setw(8)<<v[l].name<<setw(8)<<v[l].marks<<endl;
    }

    }
    cout<<left<<setw(8)<<"Roll"<<setw(8)<<"Name"<<setw(8)<<"Marks"<<endl;
    for(int k=0;k<n;k++)
    {
        cout<<left<<setw(8)<<k+1<<setw(8)<<v[k].name<<setw(8)<<v[k].marks<<endl;
    }
}
