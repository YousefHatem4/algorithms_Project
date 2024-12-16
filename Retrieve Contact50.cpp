#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> // For sqrt()

struct Contact {
    std::string phoneNumber;
    std::string firstName;
    std::string lastName;
    std::string address;
    std::string city;
    std::string email;
};

// Binary Search Function
int binarySearch(const std::vector<Contact>& phoneBook, const std::string& targetPhoneNumber) {
    int low = 0, high = phoneBook.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (phoneBook[mid].phoneNumber == targetPhoneNumber) {
            return mid; // Found
        }
        if (phoneBook[mid].phoneNumber < targetPhoneNumber) {
            low = mid + 1; // Search in the right half
        } else {
            high = mid - 1; // Search in the left half
        }
    }

    return -1; // Not found
}

// Jump Search Function
int jumpSearch(const std::vector<Contact>& phoneBook, const std::string& targetPhoneNumber) {
    int n = phoneBook.size();
    int step = sqrt(n);
    int prev = 0;

    // Find the block where the target resides
    while (prev < n && phoneBook[std::min(step, n) - 1].phoneNumber < targetPhoneNumber) {
        prev = step;
        step += sqrt(n);
        if (prev >= n) return -1; // Not found
    }

    // Perform linear search within the block
    for (int i = prev; i < std::min(step, n); i++) {
        if (phoneBook[i].phoneNumber == targetPhoneNumber) {
            return i; // Found
        }
    }

    return -1; // Not found
}

// Main Function
int main() {
    // Sample phonebook data
    std::vector<Contact> phoneBook = {
        {"01711333571", "Ahmed", "Maher", "12 Omer st", "Giza", "ahmed@must.com"},
        {"01334545786", "Khaled", "Badr", "14 Main St", "Cairo", "khaled@must.com"},
        {"01934535543", "Ali", "Salah", "15 Main St", "Alex", "ali@must.com"},
        {"01534535543", "Omar", "Eslam", "15 Main St", "Aswan", "omar@must.com"},
        {"01136634554", "MOhamed", "Ahmed", "16 Main St", "Fayoum", "mohamed@must.com"}
    };

    // Ensure the phoneBook is sorted by phone number (required for both algorithms)
    std::sort(phoneBook.begin(), phoneBook.end(), [](const Contact& a, const Contact& b) {
        return a.phoneNumber < b.phoneNumber;
    });

    // Input phone number to search
    std::string targetPhoneNumber;
    std::cout << "Enter phone number to search: ";
    std::cin >> targetPhoneNumber;

    // Binary Search
    int binaryResult = binarySearch(phoneBook, targetPhoneNumber);
    if (binaryResult != -1) {
        std::cout << "[Binary Search] Contact Found: " << phoneBook[binaryResult].firstName << " " << phoneBook[binaryResult].lastName << "\n";
    } else {
        std::cout << "[Binary Search] Contact Not Found.\n";
    }

    // Jump Search
    int jumpResult = jumpSearch(phoneBook, targetPhoneNumber);
    if (jumpResult != -1) {
        std::cout << "[Jump Search] Contact Found: " << phoneBook[jumpResult].firstName << " " << phoneBook[jumpResult].lastName << "\n";
    } else {
        std::cout << "[Jump Search] Contact Not Found.\n";
    }

    return 0;
}
