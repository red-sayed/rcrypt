#include <iostream>
#include <string>

#include "rcrypt.h"
#include "Hex.h"

int main() {
    // Variables.
    std::string inp;

    std::string operation;
    std::string mode;

    std::string key;
    std::string msg;

    while (true) {

        // Operations.
        while (true) {
            system("clear");
            std::cout << "\033[4mChoose operation:\033[0m 1)Encode. 2)Decode. 3)Hash.";

            std::cout << std::endl << std::endl << "[\033[91mRCRYPT\033[0m]  > ";

            inp.clear();
            key.clear();
            msg.clear();

            std::cin >> inp;

            // Operation selection.
            if (inp == "1" || inp == "2" || inp == "3") {
                if (inp == "1") {
                    operation = "Encode";

                } else if (inp == "2") {
                    operation = "Decode";

                } else if (inp == "3") {
                    operation = "Hash";
                }

                break;
            }
        }

        // Mode selection.
        while (true) {
            system("clear");
            std::cout << "\033[4mChoose mode:\033[0m 1)rcrypt512. 2)rcrypt1024. 3)rcrypt1536.";
            std::cout << std::endl << std::endl << "[\033[91mRCRYPT\033[0m]  > ";

            std::cin >> inp;

            if (inp == "1" || inp == "2" || inp == "3") {
                if (inp == "1") {
                    mode = "rcrypt512";

                } else if (inp == "2") {
                    mode = "rcrypt1024";

                } else if (inp == "3") {
                    mode = "rcrypt1536";
                }

                break;
            }
        }

        // Entering key.
        {
            system("clear");
            std::cout << "\033[4mEnter a key.\033[0m" << std::endl << "[\033[91mRCRYPT\033[0m/\033[94m" + mode + "\033[0m] > ";

            std::cin.ignore();
            inp.clear();
            getline(std::cin, key);
            std::cout << std::endl << std::endl;
        }

        // Encrypting.
        if (operation == "Encode") {
            std::cout << "\033[4mEnter a message(str).\033[0m" << std::endl << "[\033[91mRCRYPT\033[0m/\033[94m" + mode + "\033[0m] > ";

            inp.clear();
            getline(std::cin, msg);
            std::cout << std::endl << std::endl;

            std::cout << "[\033[91mRCRYPT\033[0m/\033[94m" + mode + "\033[0m] \033[4mEncrypted message(hex):\033[0m";

            if (mode == "rcrypt512") {
                // Encrypting.
                std::string *toC = new std::string(msg);
                Red::rcrypt512_enc(key, toC);

                // Hexing.
                std::string *toH = Red::GetHexArray(*toC);
                std::cout << std::endl << std::endl << *toH;

                // Finishing.
                delete toC;
                delete toH;

            } else if (mode == "rcrypt1024") {
                // Encrypting.
                std::string *toC = new std::string(msg);
                Red::rcrypt1024_enc(key, toC);

                // Hexing.
                std::string *toH = Red::GetHexArray(*toC);
                std::cout << std::endl << std::endl << *toH;

                // Finishing.
                delete toC;
                delete toH;

            } else if (mode == "rcrypt1536") {
                // Encrypting.
                std::string *toC = new std::string(msg);
                Red::rcrypt1536_enc(key, toC);

                // Hexing.
                std::string *toH = Red::GetHexArray(*toC);
                std::cout << std::endl << std::endl << *toH;

                // Finishing.
                delete toC;
                delete toH;
            }

            std::cout << std::endl << std::endl << std::endl << "Press Enter to continue.";
            std::cin.get();

        } else if (operation == "Decode") {
            std::cout << "\033[4mEnter a message(hex).\033[0m" << std::endl << "[\033[91mRCRYPT\033[0m/\033[94m" + mode + "\033[0m] > ";

            inp.clear();
            getline(std::cin, msg);
            std::cout << std::endl << std::endl;

            std::cout << "[\033[91mRCRYPT\033[0m/\033[94m" + mode + "\033[0m] \033[4mDecrypted message(str):\033[0m";
            std::cout << std::endl << std::endl;

            if (mode == "rcrypt512") {
                // De-hexing.
                std::string *toS = Red::GetStrArray(msg);

                // Encrypting.
                std::string *toC = new std::string(*toS);
                Red::rcrypt512_dec(key, toC);

                std::cout << std::endl << std::endl << *toC;

                // Finishing.
                delete toS;
                delete toC;

            } else if (mode == "rcrypt1024") {
                // De-hexing.
                std::string *toS = Red::GetStrArray(msg);

                // Encrypting.
                std::string *toC = new std::string(*toS);
                Red::rcrypt1024_dec(key, toC);

                std::cout << std::endl << std::endl << *toC;

                // Finishing.
                delete toS;
                delete toC;

            } else if (mode == "rcrypt1536") {
                // De-hexing.
                std::string *toS = Red::GetStrArray(msg);

                // Encrypting.
                std::string *toC = new std::string(*toS);
                Red::rcrypt1536_dec(key, toC);

                std::cout << std::endl << std::endl << *toC;

                // Finishing.
                delete toS;
                delete toC;
            }

            std::cout << std::endl << std::endl << std::endl << "Press Enter to continue.";
            std::cin.get();

        } else if (operation == "Hash") {
            std::cout << "\033[4mEnter a message(str).\033[0m" << std::endl << "[\033[91mRCRYPT\033[0m/\033[94m" + mode + "\033[0m] > ";

            inp.clear();
            getline(std::cin, msg);
            std::cout << std::endl << std::endl;

            std::cout << "[\033[91mRCRYPT\033[0m/\033[94m" + mode + "\033[0m] \033[4mHashed message:\033[0m";

            if (mode == "rcrypt512") {
                // Hashing.
                std::string *hashed = Red::rcrypt512_hash(key, msg);
                std::cout << std::endl << std::endl << *hashed;

                // Finishing.
                delete hashed;

            } else if (mode == "rcrypt1024") {
                // Hashing.
                std::string *hashed = Red::rcrypt1024_hash(key, msg);
                std::cout << std::endl << std::endl << *hashed;

                // Finishing.
                delete hashed;

            } else if (mode == "rcrypt1536") {
                // Hashing.
                std::string *hashed = Red::rcrypt1536_hash(key, msg);
                std::cout << std::endl << std::endl << *hashed;

                // Finishing.
                delete hashed;
            }

            std::cout << std::endl << std::endl << std::endl << "Press Enter to continue.";
            std::cin.get();
        }
    }
}
