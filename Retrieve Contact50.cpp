#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> 

struct Contact {
    std::string phoneNumber;
    std::string firstName;
    std::string lastName;
    std::string address;
    std::string city;
    std::string email;
};


int binarySearch(const std::vector<Contact>& phoneBook, const std::string& targetPhoneNumber) {
    int low = 0, high = phoneBook.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (phoneBook[mid].phoneNumber == targetPhoneNumber) {
            return mid; 
        }
        if (phoneBook[mid].phoneNumber < targetPhoneNumber) {
            low = mid + 1; 
        } else {
            high = mid - 1;
        }
    }

    return -1; 
}


int jumpSearch(const std::vector<Contact>& phoneBook, const std::string& targetPhoneNumber) {
    int n = phoneBook.size();
    int step = sqrt(n);
    int prev = 0;

    
    while (prev < n && phoneBook[std::min(step, n) - 1].phoneNumber < targetPhoneNumber) {
        prev = step;
        step += sqrt(n);
        if (prev >= n) return -1; 
    }

  
    for (int i = prev; i < std::min(step, n); i++) {
        if (phoneBook[i].phoneNumber == targetPhoneNumber) {
            return i; 
        }
    }

    return -1; 
}


int main() {
    
    std::vector<Contact> phoneBook = {
        {"01711333571", "Ahmed", "Maher", "12 Omer st", "Giza", "ahmed@must.com"},
        {"01334545786", "Khaled", "Badr", "14 Main St", "Cairo", "khaled@must.com"},
        {"01934535543", "Ali", "Salah", "15 Main St", "Alex", "ali@must.com"},
        {"01534535543", "Omar", "Eslam", "15 Main St", "Aswan", "omar@must.com"},
        {"01136634554", "MOhamed", "Ahmed", "16 Main St", "Fayoum", "mohamed@must.com"}
    };

   
    std::sort(phoneBook.begin(), phoneBook.end(), [](const Contact& a, const Contact& b) {
        return a.phoneNumber < b.phoneNumber;
    });

   
    std::string targetPhoneNumber;
    std::cout << "Enter phone number to search: ";
    std::cin >> targetPhoneNumber;

    
    int binaryResult = binarySearch(phoneBook, targetPhoneNumber);
    if (binaryResult != -1) {
        std::cout << "[Binary Search] Contact Found: " << phoneBook[binaryResult].firstName << " " << phoneBook[binaryResult].lastName << "\n";
    } else {
        std::cout << "[Binary Search] Contact Not Found.\n";
    }

  
    int jumpResult = jumpSearch(phoneBook, targetPhoneNumber);
    if (jumpResult != -1) {
        std::cout << "[Jump Search] Contact Found: " << phoneBook[jumpResult].firstName << " " << phoneBook[jumpResult].lastName << "\n";
    } else {
        std::cout << "[Jump Search] Contact Not Found.\n";
    }

    return 0;
}
