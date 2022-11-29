#ifndef AUTH
#define AUTH

#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>

using namespace std;

class LoginManager {
public:

    LoginManager() {
        accessGranted = 0;
    }
    void login() {
        cout << "LOGIN:" << endl;
        cout << "Enter username and password:" << endl;
        cout << "Username: ";
        cin >> UserN;

        int uID = checkFile(UserN, "username.txt");
        if (uID != 0) {
            cout << "Password: ";
            cin >> PassW;

            int pID = checkFile(PassW, "password.txt");

            if (uID == pID) {
                cout << "------------You have been authenticated----------" << endl << endl << endl;
            }

            else {
                cout << "The username or password is invalid" << endl;
                login();
            }
        }

        else {
            cout << "The username or password is invalid" << endl;
            login();
        }
    }

    void addUser(const string username, const string password) {
        if (checkFile(username, "username.txt") != 0) {
            cout << "That username is not available." << endl;
            return;
        }

        int id = 1 + getLastID();

        saveFile(username, "username.txt", id);
        saveFile(password, "password.txt", id);
    }

    int getLastID() {
        fstream file;
        file.open("username.txt", ios::in);
        file.seekg(0, ios::end);

        if (file.tellg() == -1) {
            return 0;
        }

        string s;

        for (int i = -1; s.find("#") == string::npos; i--) {
            file.seekg(i, ios::end);
            file >> s;
        }

        file.close();
        s.erase(0, 4);

        int id;
        istringstream(s) >> id;

        return id;
    }

    int checkFile(string attempt, const char* p_fileName) {
        string line;
        fstream file;

        string currentChar;
        long long eChar;

        file.open(p_fileName, ios::in);

        while (1) {
            file >> currentChar;
            if (currentChar.find("#ID:") != string::npos) {
                if (attempt == line) {
                    file.close();
                    currentChar.erase(0, 4);
                    int id;
                    istringstream(currentChar) >> id;
                    return id;
                }
                else {
                    line.erase(line.begin(), line.end());
                }
            }
            else {
                istringstream(currentChar) >> eChar;
                line = line + (char)decrypt(eChar);
                currentChar = "";
            }

            if (file.peek() == EOF) {
                file.close();
                return 0;
            }
        }
    }

    void saveFile(string p_line, const char* p_fileName, const int& id) {
        fstream file;
        file.open(p_fileName, ios::app);
        file.seekg(0, ios::end);

        if (file.tellg() != 0) {
            file << "\n";
        }

        file.seekg(0, ios::beg);

        for (int i = 0; i < p_line.length(); i++) {
            file << encrypt(p_line[i]);
            file << "\n";
        }

        file << "#ID:" << id;
        file.close();
    }

    long long encrypt(int p_letter) {
        return (powf(p_letter, 6) + 200) * 4;
    }

    int decrypt(long long p_letter) {
        return powf(((p_letter / 4) - 200), 1 / 6.f);
    }

private:
    string UserN;
    string PassW;
    bool accessGranted;
};


#endif