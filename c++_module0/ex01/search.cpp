#include "phonebook.hpp"

void search(PhoneBook &pb) {
    pb.display();
    std::string prompt;
    int idx = -1;
    while (true) {
        std::cout << "Choose a contact by the index (0-7): ";
        if (!std::getline(std::cin, prompt)) {
            std::cout << "\nEOF detected, exiting search.\n";
            return;
        }
        if (prompt.empty()) return;
        if (prompt.length() == 1 && isdigit(prompt[0])) {
            idx = prompt[0] - '0';
        } else {
            std::cout << "Invalid input. Enter a single digit between 0 and 7.\n";
            continue;
        }
        if (idx < 0 || idx > 7) {
            std::cout << "Index out of range. Choose between 0 and 7.\n";
            continue;
        }
        Contact& c = pb.get_contact(idx);
        if (c.getFirstName().empty() && c.getLastName().empty() &&
            c.getNickName().empty() && c.getPhoneNumber().empty() &&
            c.getDarkestSecret().empty()) {
            std::cout << "This index is empty.\n";
            return;
        }
        std::cout << "First Name: " << c.getFirstName() << "\n";
        std::cout << "Last Name: " << c.getLastName() << "\n";
        std::cout << "Nickname: " << c.getNickName() << "\n";
        std::cout << "Phone: " << c.getPhoneNumber() << "\n";
        std::cout << "Secret: " << c.getDarkestSecret() << "\n";
        break;
    }
}
