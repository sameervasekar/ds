// 3)	Write a program using Bubble sort algorithm, assign the roll nos. to the students of your class as per their previous years result. i.e. topper will be roll no. 1 and analyse the sorting algorithm pass by pass.
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cout << "Enter number of students :";
    cin >> n;

    string name[n];
    int marks[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter name of student " << i + 1 << " : ";
        cin >> name[i];
        cout << "Enter marks of student " << i + 1 << " in percentage : ";
        cin >> marks[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (marks[j] < marks[j + 1])
            {

                int temp = marks[j];
                marks[j] = marks[j + 1];
                marks[j + 1] = temp;

                string tempname = name[j];
                name[j] = name[j + 1];
                name[j + 1] = tempname;
            }
        }
    }

    cout << "Roll numbers (Topper = Roll No - 1)" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Roll No :" << i + 1 << ", Name :" << name[i] << ", Marks :" << marks[i] << endl;
    }
    return 0;
}
