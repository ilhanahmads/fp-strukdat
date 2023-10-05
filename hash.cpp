#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;


string customHash(const string& str) {
    string hash = "";
    for (char c : str) {
        if (islower(c)) {
            int num = c - 'a' + 1;
            hash += (num < 10 ? "0" : "") + to_string(num);
        } else if (isupper(c)) {
            int num = c - 'A' + 27;
            hash += (num < 10 ? "0" : "") + to_string(num);
        } else if (isdigit(c)) {
            switch (c) {
                case '1':
                    hash += "!";
                    break;
                case '2':
                    hash += "@";
                    break;
                case '3':
                    hash += "#";
                    break;
                case '4':
                    hash += "$";
                    break;
                case '5':
                    hash += "%";
                    break;
                case '6':
                    hash += "^";
                    break;
                case '7':
                    hash += "&";
                    break;
                case '8':
                    hash += "*";
                    break;
                case '9':
                    hash += "()";
                    break;
                case '0':
                    hash += ")";
                    break;
                
                default:
                    hash += c;
            }
        } else {
            hash += c;
        }
    }
    return hash;
}

struct UserData {
    string username;
    string hashedPassword;
};

unordered_map<string, UserData> users;

void registerUser() {
    string username, password;

    cout << "Masukkan Username: ";
    cin >> username;

    cout << "Masukkan Password: ";
    cin.ignore();
    getline(cin, password);

    string hashedPassword = customHash(password);

    if (users.find(username) == users.end()) {
        UserData newUser;
        newUser.username = username;
        newUser.hashedPassword = hashedPassword;
        users[username] = newUser;
        cout << "Registrasi berhasil!" << endl;
    } else {
        cout << "Username sudah digunakan!" << endl;
    }
}

bool loginUser() {
    string username, password;

    cout << "Masukkan Username: ";
    cin >> username;

    cout << "Masukkan Password: ";
    cin.ignore();
    getline(cin, password);

    if (users.find(username) != users.end()) {
        string hashedPassword = customHash(password);
        if (users[username].hashedPassword == hashedPassword) {
            cout << "Login berhasil!" << endl;
            return true;
        }
    }

    cout << "Login gagal! Periksa username dan password Anda." << endl;
    return false;
}

void displayPasswordHash() {
    string username;
    cout << "Masukkan Username: ";
    cin >> username;

    if (users.find(username) != users.end()) {
        cout << "Hashed Password: " << users[username].hashedPassword << endl;
    } else {
        cout << "Username tidak ditemukan." << endl;
    }
}

int main() {
    while (true) {
        int choice;
        cout << "MENU" << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Lihat Hash Password" << endl;
        cout << "4. Exit" << endl;
        cout << "Pilih: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                displayPasswordHash();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
