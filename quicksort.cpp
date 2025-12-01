// 4)	Write a program to input marks of n students Sort the marks in ascending order using the Quick Sort algorithm without using built-in library functions and analyse the sorting algorithm pass by pass. Find the minimum and maximum marks using Divide and Conquer (recursively).
#include <iostream>
#include <vector>
using namespace std;
int partition(int array[], int first, int last)
{
    int pivot = array[last];
    int i = first - 1;

    for (int j = first; j < last; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            swap(array[j], array[i]);
        }
    }
    swap(array[i + 1], array[last]);
    return i + 1;
}
void quick(int array[], int first, int last)
{
    if (first >= last)
    {
        return;
    }

    int pi = partition(array, first, last);
    quick(array, first, pi - 1);
    quick(array, pi + 1, last);
}
int main()
{
    int n;
    cout << "Enter number of students :";
    cin >> n;

    string name[n];
    int marks[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter marks of student " << i + 1 << " in percentage : ";
        cin >> marks[i];
    }
    quick(marks, 0, n - 1);

    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Marks :" << marks[i] << endl;
    }
    cout << "Maximum marks : " << marks[n - 1] << ", Minimun marks : " << marks[0] << endl;
    return 0;
}
