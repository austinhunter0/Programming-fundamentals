#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Class to handle password encryption and decryption
class PasswordManager {
private:
    vector<string> storedPasswords; // Vector to store passwords

public:
    // Function to encrypt the password
    string encrypt(string password) {
        int length = password.length();
        string encryptedPassword = password; // Use string to store encrypted password

        for (int i = 0; i < length; ++i) {
            encryptedPassword[i] = password[i] + 6; // Encrypt by shifting characters
        }

        return encryptedPassword;
    }

    // Function to decrypt the password
    string decrypt(string encryptedPassword) {
        int length = encryptedPassword.length();
        string decryptedPassword = encryptedPassword; // Use string to store decrypted password

        for (int i = 0; i < length; ++i) {
            decryptedPassword[i] = encryptedPassword[i] - 6; // Decrypt by reversing the shift
        }

        return decryptedPassword;
    }

    // Function to store a password
    void storePassword(string password) {
        storedPasswords.push_back(password); // Add password to the vector
    }

    // Function to display stored passwords
    void displayStoredPasswords() {
        cout << "Stored Passwords:" << endl;
        for (string password : storedPasswords) {
            cout << password << endl;
        }
    }
};

int main() {
    PasswordManager pm; // Create PasswordManager
    string password;
    int choice;

    while (true) {
        // Display menu options
        cout << "Menu:" << endl;
        cout << "===========================" << endl;
        cout << "1. Encrypt a password" << endl;
        cout << "2. Decrypt a password" << endl;
        cout << "3. View stored passwords" << endl;
        cout << "4. Exit" << endl;
        cout << "===========================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            // Encrypt a password
            cout << "Enter your password: ";
            cin >> password;
            string encryptedPassword = pm.encrypt(password);
            cout << "Encrypted password: " << encryptedPassword << endl;
            pm.storePassword(encryptedPassword); // Store the encrypted password
        } else if (choice == 2) {
            // Decrypt a password
            cout << "Enter the encrypted password: ";
            cin >> password;
            string decryptedPassword = pm.decrypt(password);
            cout << "Decrypted password: " << decryptedPassword << endl;
        } else if (choice == 3) {
            // View stored passwords
            pm.displayStoredPasswords();
        } else if (choice == 4) {
            // Exit the program
            cout << "Exiting..." << endl;
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }

    return 0;
}
