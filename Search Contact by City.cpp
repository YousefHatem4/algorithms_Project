#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct Contact
{
    string name;
    string phone;
    string city;

    Contact(string n, string p, string c) : name(n), phone(p), city(c) {}
};

void displayContact(const Contact &contact)
{
    cout << "Name: " << contact.name << ", Phone: " << contact.phone << ", City: " << contact.city << endl;
}

void searchByCityLinear(const vector<Contact> &contacts, const string &city)
{
    cout << "\nSearch Results (Linear Filtering):" << endl;
    bool found = false;
    for (const auto &contact : contacts)
    {
        if (contact.city == city)
        {
            displayContact(contact);
            found = true;
        }
    }
    if (!found)
    {
        cout << "No contacts found in " << city << "." << endl;
    }
}

class BTreePhoneBook
{
private:
    map<string, vector<Contact>> cityMap; 

public:
    void insert(const Contact &contact)
    {
        cityMap[contact.city].push_back(contact);
    }

    void searchByCity(const string &city)
    {
        cout << "\nSearch Results (B-Tree):" << endl;
        auto it = cityMap.find(city);
        if (it != cityMap.end())
        {
            for (const auto &contact : it->second)
            {
                displayContact(contact);
            }
        }
        else
        {
            cout << "No contacts found in " << city << "." << endl;
        }
    }
};

int main()
{
    vector<Contact> contacts = {
        Contact("Alice Johnson", "123-456-7890", "NewYork"),
        Contact("Bob Smith", "234-567-8901", "Los Angeles"),
        Contact("Charlie Brown", "345-678-9012", "NewYork"),
        Contact("Diana Prince", "456-789-0123", "Chicago"),
        Contact("Eve Adams", "567-890-1234", "LosAngeles")};

    BTreePhoneBook bTreePhoneBook;
    for (const auto &contact : contacts)
    {
        bTreePhoneBook.insert(contact);
    }

    string searchCity;

    cout << "Enter city to search for contacts: ";
    cin >> searchCity;

    searchByCityLinear(contacts, searchCity);

    bTreePhoneBook.searchByCity(searchCity);

    return 0;
}