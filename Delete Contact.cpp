#include <iostream>
#include <string>
using namespace std;

struct Contact
{
    string phone_number, first_name, last_name, address, city, email;
    Contact *next; // Used for Linked List
    Contact(string phone = "", string fname = "", string lname = "", string addr = "", string c = "", string mail = "")
        : phone_number(phone), first_name(fname), last_name(lname), address(addr), city(c), email(mail), next(nullptr) {}
};

class Phonebook
{
    Contact contactsArray[100]; 
    int count;                  
    Contact *head;              

public:
    Phonebook() : count(0), head(nullptr) {}

    void addToArray()
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
            cout << "Phonebook (Array) is full!\n";
        }
    }

    void addToLinkedList()
    {
        string phone, fname, lname, addr, city, mail;
        cout << "Enter Phone Number: ";
        cin >> phone;
        cout << "Enter First Name: ";
        cin >> fname;
        cout << "Enter Last Name: ";
        cin >> lname;
        cout << "Enter Address: ";
        cin.ignore();
        getline(cin, addr);
        cout << "Enter City: ";
        cin >> city;
        cout << "Enter Email: ";
        cin >> mail;

        Contact *newContact = new Contact(phone, fname, lname, addr, city, mail);
        newContact->next = head;
        head = newContact;
    }

    void deleteFromArray()
    {
        string phone;
        cout << "Enter Phone Number to delete: ";
        cin >> phone;
        for (int i = 0; i < count; i++)
        {
            if (contactsArray[i].phone_number == phone)
            {
                for (int j = i; j < count - 1; j++)
                    contactsArray[j] = contactsArray[j + 1];
                count--;
                cout << "Deleted from Array!\n";
                return;
            }
        }
        cout << "Not found in Array!\n";
    }

    void deleteFromLinkedList()
    {
        string phone;
        cout << "Enter Phone Number to delete: ";
        cin >> phone;

        Contact *temp = head, *prev = nullptr;
        while (temp && temp->phone_number != phone)
        {
            prev = temp;
            temp = temp->next;
        }
        if (!temp)
        {
            cout << "Not found in Linked List!\n";
            return;
        }
        if (prev)
            prev->next = temp->next;
        else
            head = temp->next;
        delete temp;
        cout << "Deleted from Linked List!\n";
    }

    void displayArray()
    {
        cout << "\nArray Contacts:\n";
        for (int i = 0; i < count; i++)
        {
            cout << "Phone: " << contactsArray[i].phone_number
                 << ", Name: " << contactsArray[i].first_name << " " << contactsArray[i].last_name
                 << ", Address: " << contactsArray[i].address
                 << ", City: " << contactsArray[i].city
                 << ", Email: " << contactsArray[i].email << "\n";
        }
    }

    void displayLinkedList()
    {
        cout << "\nLinked List Contacts:\n";
        for (Contact *temp = head; temp; temp = temp->next)
        {
            cout << "Phone: " << temp->phone_number
                 << ", Name: " << temp->first_name << " " << temp->last_name
                 << ", Address: " << temp->address
                 << ", City: " << temp->city
                 << ", Email: " << temp->email << "\n";
        }
    }
};

int main()
{
    Phonebook pb;
    int choice;

    do
    {
        cout << "\n--- Phonebook Menu ---\n";
        cout << "1. Add Contact to Array\n";
        cout << "2. Add Contact to Linked List\n";
        cout << "3. Display Array Contacts\n";
        cout << "4. Display Linked List Contacts\n";
        cout << "5. Delete Contact from Array\n";
        cout << "6. Delete Contact from Linked List\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            pb.addToArray();
            break;
        case 2:
            pb.addToLinkedList();
            break;
        case 3:
            pb.displayArray();
            break;
        case 4:
            pb.displayLinkedList();
            break;
        case 5:
            pb.deleteFromArray();
            break;
        case 6:
            pb.deleteFromLinkedList();
            break;
        case 7:
            cout << "Exiting program. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Try again!\n";
        }
    } while (choice != 7);

    return 0;
}
