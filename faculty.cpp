/*2)WAP to simulate a faculty database as a hash table. Search a particular faculty by 
using MOD as a hash function for linear probing with chaining with replacement 
method of collision handling technique. Assume suitable data for faculty record*/
#include <iostream>
#include <string>
using namespace std;

struct Faculty {
    int id;
    string name;
    string dept;
    bool occupied;
    int next;   // index of next node in chain, -1 if none

    Faculty() {
        id = -1;
        name = "";
        dept = "";
        occupied = false;
        next = -1;
    }
};

class HashTable {
    int size;
    Faculty* table;

    // find next free slot using linear probing
    int findFreeSlot(int start) {
        int i = (start + 1) % size;
        while (i != start) {
            if (!table[i].occupied)
                return i;
            i = (i + 1) % size;
        }
        return -1; // table full
    }

public:
    HashTable(int s) {
        size = s;
        table = new Faculty[size];
    }

    int hashFunction(int key) {
        return key % size;
    }

    // Insert using Linear Probing + Chaining with Replacement
    void insertFaculty(int id, string name, string dept) {
        int index = hashFunction(id);

        // If slot empty → directly insert (no chain yet)
        if (!table[index].occupied) {
            table[index].id = id;
            table[index].name = name;
            table[index].dept = dept;
            table[index].occupied = true;
            table[index].next = -1;
            return;
        }

        // Slot occupied → check if existing element belongs here
        int existingHome = hashFunction(table[index].id);

        // ---------- CASE 1: WITH REPLACEMENT ----------
        // Existing element DOES NOT belong at this index
        if (existingHome != index) {
            // find a free slot for the displaced element
            int freeIndex = findFreeSlot(index);
            if (freeIndex == -1) {
                cout << "Hash Table Full! Cannot insert.\n";
                return;
            }

            // Find predecessor of 'index' in the chain (someone pointing to index)
            int pred = -1;
            for (int i = 0; i < size; i++) {
                if (table[i].occupied && table[i].next == index) {
                    pred = i;
                    break;
                }
            }

            // Move existing record from 'index' to 'freeIndex'
            table[freeIndex] = table[index];  // copy full Faculty (including next)

            // Update predecessor to point to new location
            if (pred != -1) {
                table[pred].next = freeIndex;
            }

            // Place new faculty at its correct home position (index)
            table[index].id = id;
            table[index].name = name;
            table[index].dept = dept;
            table[index].occupied = true;
            table[index].next = -1;

            return;
        }

        // ---------- CASE 2: NORMAL CHAINING ----------
        // Existing element belongs here → add new one at free slot & link by chain
        int freeIndex = findFreeSlot(index);
        if (freeIndex == -1) {
            cout << "Hash Table Full! Cannot insert.\n";
            return;
        }

        // Insert new faculty at freeIndex
        table[freeIndex].id = id;
        table[freeIndex].name = name;
        table[freeIndex].dept = dept;
        table[freeIndex].occupied = true;
        table[freeIndex].next = -1;

        // Attach freeIndex at end of chain starting from 'index'
        int curr = index;
        while (table[curr].next != -1) {
            curr = table[curr].next;
        }
        table[curr].next = freeIndex;
    }

    // Search by faculty ID using chaining
    void searchFaculty(int id) {
        int index = hashFunction(id);

        if (!table[index].occupied) {
            cout << "\nFaculty with ID " << id << " not found!\n";
            return;
        }

        int curr = index;
        while (curr != -1) {
            if (table[curr].id == id) {
                cout << "\nFaculty Found:\n";
                cout << "ID: " << table[curr].id << endl;
                cout << "Name: " << table[curr].name << endl;
                cout << "Department: " << table[curr].dept << endl;
                return;
            }
            curr = table[curr].next;
        }

        cout << "\nFaculty with ID " << id << " not found!\n";
    }

    void displayTable() {
        cout << "\n--- Hash Table ---\n";
        for (int i = 0; i < size; i++) {
            if (table[i].occupied) {
                cout << i << " -> " << table[i].id << " | "
                     << table[i].name << " | " << table[i].dept
                     << " | next: " << table[i].next << endl;
            }
            else {
                cout << i << " -> empty\n";
            }
        }
    }
};

int main() {
    HashTable ht(10);

    // --- Sample Faculty Records ---
    ht.insertFaculty(101, "Dr. Amit", "Computer");
    ht.insertFaculty(101, "Dr. Sumit", "Computer");
    ht.insertFaculty(205, "Dr. Neha", "ENTC");
    ht.insertFaculty(305, "Dr. Sneha", "ENTC");
    ht.insertFaculty(315, "Dr. Kiran", "Mechanical");
    ht.insertFaculty(109, "Dr. Riya", "Civil");
    ht.insertFaculty(209, "Dr. Siya", "Mechanical");
    ht.insertFaculty(309, "Dr. Diya", "Mechanical");
    ht.insertFaculty(409, "Dr. Vijaya", "Mechanical");
    ht.insertFaculty(503, "Dr. Meera", "IT");
    ht.insertFaculty(603, "Dr. Heera", "IT");

    ht.displayTable();

    int sid;
    cout << "\nEnter Faculty ID to search: ";
    cin >> sid;

    ht.searchFaculty(sid);

    return 0;
}
