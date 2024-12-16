#include <iostream>
#include <string>
using namespace std;

struct Contact
{
    string phone_number, first_name, last_name, address, city, email;
    Contact *next; 
    string fullName() const
    {
        return first_name + " " + last_name;
    }
};

class Phonebook
{
    Contact contactsArray[100]; 
    int count;                 

public:
    Phonebook() : count(0) {}

    void addContact()
    {
        if (count < 100)
        {
            cout << "Enter Phone Number: ";
            cin >> contactsArray[count].phone_number;
            cout << "Enter First Name: ";
            cin >> contactsArray[count].first_name;
            cout << "Enter Last Name: ";
            cin >> contactsArray[count].last_name;
            cout << "Enter Address: ";
            cin.ignore();
            getline(cin, contactsArray[count].address);
            cout << "Enter City: ";
            cin >> contactsArray[count].city;
            cout << "Enter Email: ";
            cin >> contactsArray[count].email;
            count++;
        }
        else
        {
            cout << "Phonebook is full!\n";
        }
    }

    void displayContacts()
    {
        cout << "\nContacts:\n";
        for (int i = 0; i < count; i++)
        {
            cout << "Name: " << contactsArray[i].fullName()
                 << ", Phone: " << contactsArray[i].phone_number
                 << ", Address: " << contactsArray[i].address
                 << ", City: " << contactsArray[i].city
                 << ", Email: " << contactsArray[i].email << "\n";
        }
    }

    void merge(int left, int mid, int right)
    {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        Contact L[n1], R[n2];
        for (int i = 0; i < n1; i++)
            L[i] = contactsArray[left + i];
        for (int j = 0; j < n2; j++)
            R[j] = contactsArray[mid + 1 + j];

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2)
        {
            if (L[i].fullName() <= R[j].fullName())
                contactsArray[k++] = L[i++];
            else
                contactsArray[k++] = R[j++];
        }
        while (i < n1)
            contactsArray[k++] = L[i++];
        while (j < n2)
            contactsArray[k++] = R[j++];
    }

    void mergeSort(int left, int right)
    {
        if (left < right)
        {
            int mid = left + (right - left) / 2;
            mergeSort(left, mid);
            mergeSort(mid + 1, right);
            merge(left, mid, right);
        }
    }

    void sortByMergeSort()
    {
        if (count == 0)
        {
            cout << "No contacts to sort.\n";
            return;
        }
        mergeSort(0, count - 1);
        cout << "Contacts sorted by Merge Sort.\n";
    }

    int partition(int low, int high)
    {
        Contact pivot = contactsArray[high];
        int i = low - 1;

        for (int j = low; j < high; j++)
        {
            if (contactsArray[j].fullName() <= pivot.fullName())
            {
                i++;
                swap(contactsArray[i], contactsArray[j]);
            }
        }
        swap(contactsArray[i + 1], contactsArray[high]);
        return i + 1;
    }

    void quickSort(int low, int high)
    {
        if (low < high)
        {
            int pi = partition(low, high);
            quickSort(low, pi - 1);
            quickSort(pi + 1, high);
        }
    }

    void sortByQuickSort()
    {
        if (count == 0)
        {
            cout << "No contacts to sort.\n";
            return;
        }
        quickSort(0, count - 1);
        cout << "Contacts sorted by Quick Sort.\n";
    }
};

int main()
{
    Phonebook pb;
    int choice;

    do
    {
        cout << "\n--- Phonebook Menu ---\n";
        cout << "1. Add Contact\n";
        cout << "2. Display Contacts\n";
        cout << "3. Sort Contacts by Name (Merge Sort)\n";
        cout << "4. Sort Contacts by Name (Quick Sort)\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            pb.addContact();
            break;
        case 2:
            pb.displayContacts();
            break;
        case 3:
            pb.sortByMergeSort();
            pb.displayContacts();
            break;
        case 4:
            pb.sortByQuickSort();
            pb.displayContacts();
            break;
        case 5:
            cout << "Exiting program. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Try again!\n";
        }
    } while (choice != 5);

    return 0;
}
