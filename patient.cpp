// 2) Write a program to keep track of patients as they checked into a medical clinic,
// assigning patients to doctors on a first-come, first-served basis.
#include <iostream>
#include <queue>
using namespace std;

class Patient
{
public:
    int id;
    string name;
};

int main()
{
    queue<Patient> q;
    int nextId = 1;
    int choice;

    while (true)
    {
        cout << "1. Check-in Patient" << endl;
        cout << "2. Assign Patient to Doctor" << endl;
        cout << "3. View Waiting Patients" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            Patient p;
            p.id = nextId++;
            cout << "Enter patient name: ";
            cin >> p.name;
            q.push(p);
            cout << "Patient added: " << p.name << " (ID: " << p.id << ")" << endl;
        }
        else if (choice == 2)
        {
            if (q.empty())
            {
                cout << "No patients waiting." << endl;
            }
            else
            {
                string doctor;
                cout << "Enter doctor name: ";
                cin >> doctor;
                Patient p = q.front();
                q.pop();
                cout << "Doctor " << doctor << " will see patient " << p.name << " (ID: " << p.id << ")" << endl;
            }
        }
        else if (choice == 3)
        {
            if (q.empty())
            {
                cout << "Queue is empty." << endl;
            }
            else
            {
                queue<Patient> temp = q;
                cout << "Patients waiting:" << endl;
                while (!temp.empty())
                {
                    Patient p = temp.front();
                    temp.pop();
                    cout << p.id << " - " << p.name << endl;
                }
            }
        }
        else if (choice == 4)
        {
            cout << "Goodbye!" << endl;
            break;
        }
        else
        {
            cout << "Invalid choice." << endl;
        }
    }
    return 0;
}
