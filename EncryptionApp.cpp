#include<bits/stdc++.h>

using namespace std;

struct Affine {
    int a{}, b{}, c{};
    string message;

    void input() {
        cin.clear();
        cin.sync();
        getline(cin, message);

        cout << "Enter the number a of the equation (a x + b) , c (y - b): \n>>";
        cin >> a;
        //while input is not a number take input again.
        while (cin.fail()) {
            cin.clear();
            cin.sync();
            cout << "Invalid input,Enter the number a of the equation (a x + b) , c (y - b):\n>>";
            cin >> a;
        }

        cout << "Enter the number b of the equation (a x + b) , c (y - b): \n>>";
        cin >> b;
        while (cin.fail()) {
            cin.clear();
            cin.sync();
            cout << "Invalid input,Enter the number b of the equation (a x + b) , c (y - b):\n>>";
            cin >> b;
        }

        cout << "Enter the number c of the equation (a x + b) , c (y - b): \n>>";
        cin >> c;
        while (cin.fail()) {
            cin.clear();
            cin.sync();
            cout << "Invalid input,Enter the number c of the equation (a x + b) , c (y - b):\n>>";
            cin >> c;
        }

        //check if a & c satisfy the condition
        if ((a * c) % 26 != 1) {
            cout << "a & c doesn't satisfy the condition (a * c) mod 26 = 1\n";
            input();
        }
    }

    string cipher() {
        string enc_message;
        //Cipher each letter and add it to the new string.
        for (auto i: message) {
            if (isalpha(i)) {
                if (isupper(i)) {
                    enc_message += (char) ((a * (i - 65) + b) % 26 + 65);
                } else {
                    enc_message += (char) ((a * (i - 97) + b) % 26 + 97);
                }
            } else {
                enc_message += i;
            }
        }
        return enc_message;
    }

    string decipher() {
        string dec_message;
        //Decipher each letter and add it to the new string.
        for (auto i: message) {
            if (isalpha(i)) {
                if (isupper(i)) {
                    int mod = (c * (i - b - 65)) % 26;
                    mod = (mod % 26 + 26) % 26;
                    dec_message += (char) (mod + 65);
                } else {
                    int mod = (c * (i - b - 97)) % 26;
                    mod = (mod % 26 + 26) % 26;
                    dec_message += (char) (mod + 97);
                }
            } else {
                dec_message += i;
            }
        }
        return dec_message;
    }

    void run() {
        string choice;
        //Loop until input is exit.
        while (true) {
            cout << "Welcome to Affine Cipher\n";
            cout << "Choose the number of the operation:"
                    "\n1-Encrypt a message\n2-Decrypt a message\n3-Return\n>>";
            cin >> choice;

            if (choice == "1") {
                cout << "Enter the message you want to encrypt : ";
                input();
                cout << "Your encrypted message: " << cipher() << '\n';
            } else if (choice == "2") {
                cout << "Enter your message you want to decrypt : ";
                input();
                cout << "Your decrypted message is : " << decipher() << '\n';
            } else if (choice == "3") {
                break;
            }
                //if the choice is not 1,2 or 3 take input again.
            else {
                cout << "Wrong Option please enter a valid option\n";
            }
        }
    }
};

struct Caesar {
    string message;
    int shift{};

    void input() {
        cin.clear();
        cin.sync();
        getline(cin, message);
        cout << "Enter the number of shifts (+ve for right and -ve for left):\n>>";
        cin >> shift;
        //while input is not a number take input again.
        while (cin.fail()) {
            cin.clear();
            cin.sync();
            cout << "Invalid input,Enter the number of shifts (+ve for right and -ve for left):\n>>";
            cin >> shift;
        }
        shift = (shift % 26 + 26) % 26;
    }

    string cipher_decipher() {
        string conv_message;
        //Cipher or decipher each letter and add it to the new string.
        for (auto i: message) {
            if (isalpha(i)) {
                if (isupper(i)) {
                    if (i + shift > 'Z') {
                        conv_message += (char) (i + shift - 26);
                    } else {
                        conv_message += (char) (i + shift);
                    }
                } else {
                    if (i + shift > 'z') {
                        conv_message += (char) (i + shift - 26);
                    } else {
                        conv_message += (char) (i + shift);
                    }
                }
            } else {
                conv_message += i;
            }
        }
        return conv_message;
    }

    void run() {
        string choice;
        //Loop until input is exit.
        while (true) {
            cout << "Welcome to Caesar Cipher\n";
            cout << "Choose the number of the operation:"
                    "\n1-Encrypt a message\n2-Decrypt a message\n3-return\n>>";
            cin >> choice;

            if (choice == "1") {
                cout << "Enter the message you want to encrypt : \n>>";
                input();
                cout << "Your encrypted message: " << cipher_decipher() << '\n';
            } else if (choice == "2") {
                cout << "Enter your message you want to decrypt :\n>>";
                input();
                //Shift back ciphered message
                shift = 26 - shift;
                cout << "Your decrypted message is : " << cipher_decipher() << '\n';
            } else if (choice == "3") {
                break;
            }
                //if the choice is not 1,2 or 3 take input again.
            else {
                cout << "Wrong Option please enter a valid option\n";
            }
        }
    }

};

struct Atbash {
    string message;

    void input() {
        cin.clear();
        cin.sync();
        getline(cin, message);
    }

    string cipher_decipher() {
        string conv_message;
        //Cipher or Decipher each letter and add it to the new string.
        for (char i: message) {
            if (isalpha(i)) {
                if (islower(i)) {
                    conv_message += (char) ('z' - (i - 'a'));
                } else {
                    conv_message += (char) ('Z' - (i - 'A'));
                }
            } else conv_message += i;
        }
        return conv_message;
    }

    void run() {
        string choice;
        //Work until input is exit.
        while (true) {
            cout
                    << "Welcome to Atbash Cipher\n"
                       "Choose the number of the operation:\n"
                       "1-Encrypt a message\n2-Decrypt a message\n3-Return\n>>";
            cin >> choice;

            if (choice == "1") {
                cout << "Enter the message you want to encrypt\n>>: ";
                input();
                cout << "Your encrypted message is : " << cipher_decipher() << endl;
            } else if (choice == "2") {
                cout << "Enter your message you want to decrypt\n>>: ";
                input();
                cout << "Your decrypted message : " << cipher_decipher() << endl;
            } else if (choice == "3") {
                break;
            }
                //if the choice is not 1,2 or 3 take input again.
            else {
                cout << "Wrong Option please enter a valid option\n";
            }
        }
    }
};

struct Vignere {
    string message, keyword;

    void input() {
        cout << "Enter the message you want to encrypt (maximum 80 characters): ";
        cin.clear();
        cin.sync();
        getline(cin, message);

        //if the message is longer than 80 characters take input again.
        while (message.size() > 80) {
            cout << "Invalid input, Enter the message to encrypt (maximum 80 characters): ";
            cin.clear();
            cin.sync();
            getline(cin, message);
        }

        cout << "Enter cipher the keyword (maximum 8 characters): ";
        cin.clear();
        cin.sync();
        getline(cin, keyword);

        //if the keyword is longer than 8 characters take input again.
        while (keyword.size() > 8) {
            cout << "Invalid input Enter the cipher keyword (maximum 8 characters): ";
            cin.clear();
            cin.sync();
            getline(cin, keyword);
        }

        //Transform each letter to upper case in both the keyword and the message
        transform(keyword.begin(), keyword.end(), keyword.begin(), ::toupper);
        transform(message.begin(), message.end(), message.begin(), ::toupper);
        while (keyword.size() < message.size()) {
            keyword += keyword;
        }
    }

    string cipher() {
        string enc_message;
        //Cipher each letter and add it to the new string.
        for (int i = 0; i < message.size(); i++) {
            if (isalpha(message[i])) {
                enc_message += (char) ((message[i] + keyword[i]) % 26 + 65);
            } else enc_message += message[i];
        }
        return enc_message;
    }

    string decipher() {
        string dec_message;
        //decipher each letter and add it to the new string.
        for (int i = 0; i < message.size(); i++) {
            if (isalpha(message[i])) {
                int shift = 65 - keyword[i];
                shift = (shift % 26 + 26) % 26;
                if (shift + message[i] > 'Z')shift -= 26;
                else if (shift + message[i] < 'A')shift += 26;
                dec_message += (char) (message[i] + shift);
            } else dec_message += message[i];
        }
        return dec_message;
    }

    void run() {
        string choice;
        //Loop until input is exit.
        while (true) {
            cout
                    << "Welcome to Vignere Cipher\n"
                       "Choose the number of the operation:\n"
                       "1-Encrypt a message\n2-Decrypt a message\n3-Return\n>>";
            cin >> choice;

            if (choice == "1") {
                input();
                cout << "Your encrypted message is : " << cipher() << endl;
            } else if (choice == "2") {
                input();
                cout << "Your decrypted message : " << decipher() << endl;
            } else if (choice == "3") {
                break;
            }
                //if the choice is not 1,2 or 3 take input again.
            else {
                cout << "Wrong Option please enter a valid option\n";
            }
        }
    }
};

struct Baconian {

    map<char, string> cipher_letters{{'A', "aaaaa"}, {'B', "aaaab"}, {'C', "aaaba"}, {'D', "aaabb"},
                                     {'E', "aabaa"}, {'F', "aabab"}, {'G', "aabba"}, {'H', "aabbb"},
                                     {'I', "abaaa"}, {'J', "abaab"}, {'K', "ababa"}, {'L', "ababb"},
                                     {'M', "abbaa"}, {'N', "abbab"}, {'O', "abbba"}, {'P', "abbbb"},
                                     {'Q', "baaaa"}, {'R', "baaab"}, {'S', "baaba"}, {'T', "baabb"},
                                     {'U', "babaa"}, {'V', "babab"}, {'W', "babba"}, {'X', "babbb"},
                                     {'Y', "bbaaa"}, {'Z', "bbaab"}};

    map<string, char> decipher_letters{{"aaaaa", 'A'}, {"aaaab", 'B' }, {"aaaba", 'C' }, {"aaabb", 'D'},
                                       {"aabaa", 'E'}, {"aabab", 'F' }, {"aabba", 'G'}, {"aabbb", 'H'},
                                       {"abaaa", 'I'}, {"abaab", 'J' }, {"ababa", 'K'}, {"ababb", 'L'},
                                       {"abbaa", 'M'}, {"abbab", 'N' }, {"abbba", 'O'}, {"abbbb", 'P' },
                                       {"baaaa", 'Q'}, {"baaab", 'R'}, {"baaba", 'S'}, {"baabb", 'T'},
                                       {"babaa", 'U'}, {"babab", 'V'}, {"babba", 'W'}, {"babbb", 'X'},
                                       {"bbaaa", 'Y'}, {"bbaab", 'Z'}};
    string message;
    void input() {
        cin.clear();
        cin.sync();
        getline(cin, message);
    }

    string cipher() {
        transform(message.begin(), message.end(), message.begin(), ::toupper);
        string enc_message;
        //Cipher each letter and add it to the new string.
        for (char i: message) {
            if (isalpha(i)) {
                enc_message += cipher_letters[i];
            } else enc_message += i;
        }
        return enc_message;
    }

    string decipher() {
        string dec_message;
        //decipher each letter and add it to the new string.
        string pattern;
        int counter = 1;
        for (int i = 0; i < message.size(); i++) {
            if (isalpha(message[i])) {
                if (counter % 5 == 0) {
                    pattern += message[i];
                    dec_message += decipher_letters[pattern];
                    pattern = "";
                    if (message[i + 1] == ' ') {
                        i++;
                        dec_message += " ";
                    }
                } else {
                    pattern += message[i];
                }
                counter++;
            } else {
                dec_message += message[i];
            }
        }
        return dec_message;
    }

    void run() {
        string choice;
        //Loop until input is exit.
        while (true) {
            cout<<"Welcome Baconian Cipher\n"
                  "Choose the number of the operation:\n"
                  "1-Encrypt a message\n2-Decrypt a message\n3-Return\n>>";
            cin.clear();
            cin.sync();
            cin >> choice;

            if (choice == "1") {
                string enc_message;
                cout << "Enter the message you want to encrypt :\n>>";
                input();
                cout << "Your encrypted message is : " << cipher() << endl;
            }
            else if (choice == "2") {
                string dec_message;
                cout << "Enter your message you want to decrypt :\n>>";
                input();
                cout << "Your decrypted message : " << decipher() << endl;
            }
            else if (choice == "3") {
                break;
            }
                //if the choice is not 1,2 or 3 take input again.
            else {
                cout << "Wrong Option please enter a valid option\n";
            }
        }

    }
};

struct Polybius {
    string message, key;

    bool valid() {
        set<char> nums;
        if (key.size() != 5) {
            return false;
        }
        for (int i = 0; i < 5; ++i) {
            if (!isdigit(key[i]) || nums.count(key[i])) {
                return false;
            } else {
                nums.insert(key[i]);
            }
        }
        return true;
    }

    void input() {
        cin.clear();
        cin.sync();
        getline(cin, message);
        cout << "Enter cipher the key of 5 distinct numbers eg:24531\n>>";
        cin.clear();
        cin.sync();
        getline(cin, key);

        while (!valid()) {
            cout << "Invalid input, Enter cipher the key of 5 distinct numbers eg:24531\n>>";
            cin.clear();
            cin.sync();
            getline(cin, key);
        }
    }

    string cipher() {
        transform(message.begin(), message.end(), message.begin(), ::toupper);
        map<char, string> cipher;
        //Make a map with each letters as a key and its cipher as value
        for (char i = 65; i <= 90; ++i) {
            if (i < 74) {
                cipher[i] = key[(i - 65) / 5];
                cipher[i] += key[i % 5];
            } else {
                cipher[i] = key[(i - 66) / 5];
                cipher[i] += key[(i - 1) % 5];
            }
        }
        string enc_message;
        //Encrypt each letter and add it to a new string
        for (char &i: message) {
            if (isalpha(i)) {
                enc_message += cipher[i];
            } else {
                enc_message += i;
            }
        }
        return enc_message;
    }

    string decipher() {
        map<string, char> decipher;
        //Make a map with each number as a key and its character as value
        for (char i = 65; i <= 90; ++i) {
            if (i < 74) {
                string code;
                code = key[(i - 65) / 5];
                code += key[i % 5];
                decipher[code] = i;
            } else if (i > 74) {
                string code;
                code = key[(i - 66) / 5];
                code += key[(i - 1) % 5];
                decipher[code] = i;
            }
        }
        string dec_message;
        //decipher each letter and add it to the new string.
        string letter;
        for (int i = 0; i <= message.size(); ++i) {
            if (letter.size() == 2) {
                dec_message += decipher[letter];
                letter = "";
            }
            if (isdigit(message[i])) {
                letter += message[i];
            } else {
                dec_message += message[i];
            }
        }
        return dec_message;
    }

    void run() {
        string choice;
        //Loop until input is exit.
        while (true) {
            cout<< "Welcome to Polybius Cipher\n"
                   "Choose the number of the operation:\n"
                   "1-Encrypt a message\n2-Decrypt a message\n3-Return\n>>";
            cin >> choice;

            if (choice == "1") {
                string enc_message;
                cout << "Enter the message you want to encrypt :\n>>";
                input();
                enc_message = cipher();
                cout << "Your encrypted message is : " << enc_message << endl;
            }
            else if (choice == "2") {
                string dec_message;
                cout << "Enter your message you want to decrypt : ";
                input();
                dec_message = decipher();
                cout << "Your decrypted message : " << dec_message << endl;
            }
            else if (choice == "3") {
                break;
            }
                //if the choice is not 1,2 or 3 take input again.
            else {
                cout << "Wrong Option please enter a valid option\n";
            }
        }
    }
};

struct SimpleSub {
    string substitution_map, key;
    string original_map;

    void input(const string &opreation) {
        set<char> keys;
        bool is_alpha;
        do {
            cout << "Please enter a five letters key to " << opreation << " a message with:\n>>";
            cin >> key;
            keys.clear();
            is_alpha = true;
            for (auto i: key) {
                keys.insert(i);
                if (!isalpha(i)) {
                    is_alpha = false;
                }
            }
        } while (key.size() != 5 || keys.size() != 5 || !is_alpha);
    }

    void generate_key() {
        transform(key.begin(), key.end(), key.begin(), ::tolower);
        // delete key letters from alphabet list
        for (char c: key) {
            substitution_map.erase(remove(substitution_map.begin(), substitution_map.end(), c), substitution_map.end());
        }
        // concatenate key to the beginning of the key list
        substitution_map = key + substitution_map;
    }

    void cipher(string message) {
        transform(message.begin(), message.end(), message.begin(), ::tolower);
        for (char i: message) {
            //  check if string blank print it as it is
            if (i == ' ') {
                cout << " ";
            } else {
                // iterate over all alphabet letters
                for (int j = 0; j < original_map.length(); j++) {
                    // print the letters corresponding in the key list
                    if (i == original_map[j]) {
                        cout << substitution_map[j];
                    }
                }
            }
        }
        cout << endl;
    }

    void decipher(string message) {
        transform(message.begin(), message.end(), message.begin(), ::tolower);
        for (char i: message) {
            //  check if string blank print it as it is
            if (i == ' ') {
                cout << " ";
            } else {
                for (int j = 0; j < original_map.length(); j++) {
                    // print the letters of message corresponding in the original list
                    if (i == substitution_map[j]) {
                        cout << original_map[j];
                    }
                }
            }
        }
        cout << endl;
    }

    void run() {
        string choice;
        //Loop until input is exit.
        while (true) {
            substitution_map = "abcdefghijklmnopqrstuvwxyz";
            original_map = "abcdefghijklmnopqrstuvwxyz";
            key = "";
            string message, code;
            cout<< "Welcome to Simple Substitution Cipher\n"
                   "Choose the number of the operation:\n"
                   "1-Encrypt a message\n2-Decrypt a message\n3-Return\n>>";
            cin >> choice;

            if (choice == "1") {
                input("encrypt");
                generate_key();
                cout << "Please enter a message to encrypt: " << endl;
                cin.clear();
                cin.sync();
                getline(cin, message);
                cout << "Your encrypted message is : ";
                cipher(message);
            }
            else if (choice == "2") {
                input("decrypt");
                generate_key();
                cout << "Please enter a message to decrypt: " << endl;
                cin.clear();
                cin.sync();
                getline(cin, message);
                cout << "Your decrypted message is : ";
                decipher(message);
            }
            else if (choice == "3") {
                break;
            }
                //if the choice is not 1,2 or 3 take input again.
            else {
                cout << "Wrong Option please enter a valid option\n";
            }
        }

    }

};

struct Morse {
    map <char, string> morse_code{
            {'A',".-"  },{'B',"-..."},{'C',"-.-."},{'D',"-.." },{'E',"."   },
            {'F',"..-."},{'G',"--." },{'H',"...."},{'I',".."  },{'J',".---"},
            {'K',"-.-" },{'L',".-.."},{'M',"--"  },{'N',"-."  },{'O',"---" },
            {'P',".--."},{'Q',"--.-"},{'R',".-." },{'S',"..." },{'T',"-"   },
            {'U',"..-" },{'V',"...-"},{'W',".--" },{'X',"-..-"},{'Y',"-.--"},
            {'Z',"--.."}
    };

    void cipher(string word) {
        //iterate over each letter in message
        for (char letter: word) {
            //print the equivelant symbol to the letter in morse code
            cout << morse_code[toupper(letter)] << " ";
        }
        cout << endl;
    }

    void decipher(string code) {
        string token;
        stringstream scin("");
        scin.str(code);
        while (scin >> token) {
            //iterate over each letter in alphabet
            for (char letter = 'A'; letter < 'Z'; letter++) {
                // print the equivalent letter to the symbol in map
                if (morse_code[letter] == token) {
                    cout << letter;
                }
            }
        }
        cout << endl;
    }

    void run() {
        string choice;
        //Loop until input is exit.
        while (true) {
            string message, code;
            cout<< "Welcome to Morse code Cipher\n"
                   "Choose the number of the operation:\n"
                   "1-Encrypt a message\n2-Decrypt a message\n3-Return\n>>";
            cin >> choice;

            if (choice == "1") {
                cout << "Please Enter word to cipher using morse code:\n>>";
                cin.clear();
                cin.sync();
                getline(cin, message);
                cout << "Your encrypted message is : ";
                cipher(message);
            }
            else if (choice == "2") {
                cout << "Please Enter code to decipher: \n";
                cin.clear();
                cin.sync();
                getline(cin, code);
                cout << "Your decrypted message is : ";
                decipher(code);;
            }
            else if (choice == "3") {
                break;
            }
                //if the choice is not 1,2 or 3 take input again.
            else {
                cout << "Wrong Option please enter a valid option\n";
            }
        }
    }
};

struct XOR {
    string message, key;

    void input() {
        cin.clear();
        cin.sync();
        getline(cin, message);
        //Remove spaces and transform each letter to lowercase
        message.erase(remove(message.begin(), message.end(), ' '), message.end());
        transform(message.begin(), message.end(), message.begin(), ::tolower);

        cout << "Please enter the secret key :\n>>";
        cin >> key;
        while (key.size() != 1 || !isalpha(key[0])) {
            cout << "Invalid input, Please enter the secret key :\n>>";
            cin >> key;
        }
        key[0] = toupper(key[0]);
    }

    void encrypt() {
        string encrypted_message;
        for (auto i: message) {
            encrypted_message += i ^ key[0];
        }
        cout << "Your encrypted message: " << encrypted_message << endl;
        cout << "(Hexa:";
        for (char i: encrypted_message) {
            cout << hex << (int) static_cast <unsigned char>(i);
        }
        cout << ")" << endl;
    }

    void decrypt() {
        string decrypted_message, ascii;
        //Remove spaces and transform each letter to lowercase
        message.erase(remove(message.begin(), message.end(), ' '), message.end());
        transform(message.begin(), message.end(), message.begin(), ::tolower);
        set<char> hex{'a', 'b', 'c', 'd', 'e', 'f'};
        for (size_t i = 0; i < message.length(); i += 2) {
            string part = message.substr(i, 2);
            if ((isdigit(part[0]) || hex.count(part[0])) && (isdigit(part[1]) || hex.count(part[1]))) {
                char ch = stoul(part, nullptr, 16);
                ascii += ch;
            }
        }

        for (char i: ascii) {
            decrypted_message += (char) (i ^ key[0]);
        }
        cout << "Your decrypted message: " << decrypted_message << endl;
    }

    void run() {
        string choice;
        //Loop until input is exit.
        while (true) {
            cout<< "Welcome to XOR Cipher\n"
                   "Choose the number of the operation:\n"
                   "1-Encrypt a message\n2-Decrypt a message\n3-Return\n>>";
            cin >> choice;
            message = "";
            key = "";
            if (choice == "1") {
                cout << "Please enter a message to cipher:\n>>";
                input();
                encrypt();
            }
            else if (choice == "2") {
                string ascii;
                cout << "Please enter a Hexa to decipher:\n>>";
                input();
                decrypt();
            }
            else if (choice == "3") {
                break;
            }
                //if the choice is not 1,2 or 3 take input again.
            else {
                cout << "Wrong Option please enter a valid option\n";
            }
        }
    }
};

struct RailFence {
    int key = 3;

    void encrypt() {
        int j = 0;
        string message, encrypted_message;
        cout << "Please enter a message to cipher:\n>>";
        cin.clear();
        cin.sync();
        getline(cin, message);
        //Remove spaces and transform each letter to lower case
        message.erase(remove(message.begin(), message.end(), ' '), message.end());
        transform(message.begin(), message.end(), message.begin(), ::tolower);

        while (j < key + 1) {
            for (int i = j; i < message.size(); i += key + 1) {
                encrypted_message += message[i];
            }
            j++;
            if (j == 1) {
                for (int i = j; i < message.size(); i += 2) {
                    encrypted_message += message[i];
                }
            }
            j++;
        }
        cout << "Your encrypted message: " << encrypted_message << endl;
    }

    void decrypt() {

        cout << "Please enter a message to decipher:\n>>";
        string message;
        cin.clear();
        cin.sync();
        getline(cin, message);
        //Remove spaces and transform each letter to lower case
        message.erase(remove(message.begin(), message.end(), ' '), message.end());
        transform(message.begin(), message.end(), message.begin(), ::tolower);
        char decrypt[key][message.size()];

        for (int i = 0; i < key; i++) {
            for (int j = 0; j < message.size(); j++) {
                decrypt[i][j] = '\n';
            }
        }
        bool dir_down;
        int row = 0, col = 0;
        for (int i = 0; i < message.size(); i++) {
            if (row == 0) {
                dir_down = true;
            }
            if (row == key - 1) {
                dir_down = false;
            }
            decrypt[row][col++] = '*';
            dir_down ? row++ : row--;
        }
        int index = 0;
        for (int i = 0; i < key; i++) {
            for (int j = 0; j < message.size(); j++) {
                if (decrypt[i][j] == '*' && index < message.size()) {
                    decrypt[i][j] = message[index++];
                }
            }
        }
        string result;
        row = 0, col = 0;
        for (int i = 0; i < message.size(); i++) {
            if (row == 0) {
                dir_down = true;
            }
            if (row == key - 1) {
                dir_down = false;
            }
            if (decrypt[row][col] != '*') {
                result.push_back(decrypt[row][col++]);
            }
            dir_down ? row++ : row--;
        }
        cout << "Your decrypted message: " << result << endl;
    }

    void run() {
        string choice;
        while (true) {
            cout<< "Welcome to The Rail-fence Cipher\n"
                   "Choose the number of the operation:\n"
                   "1-Encrypt a message\n2-Decrypt a message\n3-Return\n>>";
            cin >> choice;
            if (choice == "1") {
                encrypt();
            }
            else if (choice == "2") {
                decrypt();
            }
            else if (choice == "3") {
                break;
            }
                //if the choice is not 1,2 or 3 take input again.
            else {
                cout << "Wrong Option please enter a valid option\n";
            }
        }
    }
};


int main() {
    string cont = "C";
    cout << "Welcome to FCAI Cipher Application.\n\n";
    //Work until input is exit.
    while (cont == "C") {
        string choice;
        Affine affine;
        Caesar caesar;
        Atbash atbash;
        Vignere vignere;
        Baconian baconian;
        SimpleSub simpleSub;
        Polybius polybius;
        Morse morse;
        XOR xOR;
        RailFence railFence;
        cout << "Choose the number of the caesar you want use:\n"
                "0-Affine Cipher\n"
                "1-Caesar Cipher\n"
                "2-Atbash Cipher\n"
                "3-Vignere Cipher\n"
                "4-Baconian Cipher\n"
                "5-Simple Substitution Cipher\n"
                "6-Polybius Square Cipher\n"
                "7-Morse Code\n"
                "8-XOR Cipher\n"
                "9-Rail-fence Cipher\n>>";
        cin >> choice;
        while (choice.size() != 1 || !isdigit(choice[0])) {
            cin.clear();
            cin.sync();
            cout << "Invalid input ,Choose the number of the caesar you want use:\n"
                    "0-Affine Cipher\n"
                    "1-Caesar Cipher\n"
                    "2-Atbash Cipher\n"
                    "3-Vignere Cipher\n"
                    "4-Baconian Cipher\n"
                    "5-Simple Substitution Cipher\n"
                    "6-Polybius Square Cipher\n"
                    "7-Morse Code\n"
                    "8-XOR Cipher\n"
                    "9-Rail-fence Cipher\n>>";
            cin >> choice;
        }
        switch (choice[0]) {
            case '0':
                affine.run();
                break;
            case '1':
                caesar.run();
                break;
            case '2':
                atbash.run();
                break;
            case '3':
                vignere.run();
                break;
            case '4':
                baconian.run();
                break;
            case '5':
                simpleSub.run();
                break;
            case '6':
                polybius.run();
                break;
            case '7':
                morse.run();
                break;
            case '8':
                xOR.run();
                break;
            case '9':
                railFence.run();
                break;
        }
        cout << "Enter C to continue or anything else to exit\n";
        cin >> cont;
        cont[0] = toupper(cont[0]);
    }
    cout << "Thanks for using FCAI Cipher Application.";
}





