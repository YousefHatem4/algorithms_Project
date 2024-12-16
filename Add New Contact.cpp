#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

struct Contact
{
    string phoneNumber;
    string firstName;
    string lastName;
    string address;
    string city;
    string email;
};

class PhonebookLinearSearch
{
private:
    vector<Contact> contacts;

public:
    void addContact()
    {
        Contact newContact;
        cout << "Enter Phone Number (e.g., 040-2731021): ";
        cin >> newContact.phoneNumber;

        for (const auto &contact : contacts)
        {
            if (contact.phoneNumber == newContact.phoneNumber)
            {
                cout << "Error: Phone number already exists!\n";
                return;
            }
        }

        cout << "Enter First Name: ";
        cin >> newContact.firstName;
        cout << "Enter Last Name: ";
        cin >> newContact.lastName;
        cout << "Enter Address: ";
        cin.ignore();
        getline(cin, newContact.address);
        cout << "Enter City: ";
        cin >> newContact.city;
        cout << "Enter Email: ";
        cin >> newContact.email;

        contacts.push_back(newContact);
        cout << "Contact added successfully!\n";
    }

    void displayContacts()
    {
        if (contacts.empty())
        {
            cout << "\n Phonebook is empty.\n";
            return;
        }
        for (const auto &contact : contacts)
        {
            cout << "Phone Number: " << contact.phoneNumber << "\n"
                 << "Name: " << contact.firstName << " " << contact.lastName << "\n"
                 << "Address: " << contact.address << "\n"
                 << "City: " << contact.city << "\n"
                 << "Email: " << contact.email << "\n\n";
        }
    }
};

class PhonebookHashMap
{
private:
    unordered_map<string, Contact> contacts;

public:
    void addContact()
    {
        Contact newContact;
        cout << "Enter Phone Number (e.g., 040-2731021): ";
        cin >> newContact.phoneNumber;

        if (contacts.find(newContact.phoneNumber) != contacts.end())
        {
            cout << "\n Error: Phone number already exists!\n";
            return;
        }

        cout << "Enter First Name: ";
        cin >> newContact.firstName;
        cout << "Enter Last Name: ";
        cin >> newContact.lastName;
        cout << "Enter Address: ";
        cin.ignore();
        getline(cin, newContact.address);
        cout << "Enter City: ";
        cin >> newContact.city;
        cout << "Enter Email: ";
        cin >> newContact.email;

        contacts[newContact.phoneNumber] = newContact;
        cout << "Contact added successfully!\n";
    }

    void displayContacts()
    {
        if (contacts.empty())
        {
            cout << "Phonebook is empty.\n";
            return;
        }
        for (const auto &entry : contacts)
        {
            const Contact &contact = entry.second;
            cout << "Phone Number: " << contact.phoneNumber << "\n"
                 << "Name: " << contact.firstName << " " << contact.lastName << "\n"
                 << "Address: " << contact.address << "\n"
                 << "City: " << contact.city << "\n"
                 << "Email: " << contact.email << "\n\n";
        }
    }
};

int main()
{
    int choice, methodChoice;

    PhonebookLinearSearch phonebookLinear;
    PhonebookHashMap phonebookHashMap;

    do
    {
        cout << "Phonebook Menu:\n"
             << "1. Use Linear Search Method\n"
             << "2. Use Hash Map Method\n"
             << "3. Exit\n"
             << "Enter your choice: ";
        cin >> methodChoice;

        switch (methodChoice)
        {
        case 1:
            do
            {
                cout << "\nPhonebook Menu (Linear Search):\n"
                     << "1. Add Contact\n"
                     << "2. Display Contacts\n"
                     << "3. Return to Main Menu\n"
                     << "Enter your choice: ";
                cin >> choice;

                switch (choice)
                {
                case 1:
                    phonebookLinear.addContact();
                    break;
                case 2:
                    phonebookLinear.displayContacts();
                    break;
                case 3:
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
                }
            } while (choice != 3);
            break;

        case 2:
            do
            {
                cout << "\nPhonebook Menu (Hash Map):\n"
                     << "1. Add Contact\n"
                     << "2. Display Contacts\n"
                     << "3. Return to Main Menu\n"
                     << "Enter your choice: ";
                cin >> choice;

                switch (choice)
                {
                case 1:
                    phonebookHashMap.addContact();
                    break;
                case 2:
                    phonebookHashMap.displayContacts();
                    break;
                case 3:
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
                }
            } while (choice != 3);
            break;

        case 3:
            cout << "Exiting Phonebook...\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (methodChoice != 3);

    return 0;
}