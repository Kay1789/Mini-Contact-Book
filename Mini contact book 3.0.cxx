#include <cctype>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <string>

// =====================
// ANSI color macros
// =====================
#define Remove "\033[0m"
#define Red "\033[0;31m"
#define Blue "\033[0;34m"
#define Magenta "\033[0;35m"
#define Cyan "\033[0;36m"
#define ansi_rgb(r,g,b) "\033[38;2;" #r ";" #g ";" #b "m"

// =====================
// Global dynamic arrays for contact data
// =====================
std::string* cName;
std::string* cEmail;
std::string* cNumber;

// =====================
// Contact counters
// =====================
int CurrentContactCount = 0;
int maxCount;

// =====================
// Add a new contact
// =====================
auto AddEntry(std::string* addName,std::string* addEmail,std::string* addNumber,int &addCount,int maxCount)->void{
    if(addCount >= maxCount){
        std::cout << "The Contact List is full! \n"; 
        return;
    }

    std::cout << Blue << "======= Contact List =======" << Remove << "\n";

    // Input Name
    std::cout << Cyan << "\nEnter Name: " << Remove;
    std::getline(std::cin >> std::ws, addName[addCount]);

    // Input Email
    std::cout << Cyan << "\nEnter Email: " << Remove;
    std::getline(std::cin >> std::ws, addEmail[addCount]);

    // Input Number
    std::cout << Cyan << "\nEnter Number: " << Remove;
    std::getline(std::cin >> std::ws, addNumber[addCount]);

    addCount++;
    std::cout << Blue << "======= Contact Added! =======" << Remove << "\n";
}

// =====================
// Display all contacts
// =====================
auto displayEntry(std::string* displayName,std::string* displayEmail,std::string* displayNumber,int &displayCount)->void{
    if(displayCount <= 0){
        std::cout << "There's nothing here. Add Contacts..\n"; 
        return;
    }

    std::cout << Blue << "======= Contact List =======" << Remove << "\n";

    for(int d = 0; d < displayCount; d++){
      std::cout << Red << (d+1) << Remove 
                << Magenta << ")>" << Remove 
                << Blue << displayName[d] << Remove 
                << Red << " | " << Remove 
                << Cyan << displayEmail[d] << Remove 
                << Red << " | " << Remove 
                << Red << displayNumber[d] << Remove 
                << "\n";
    }

    std::cout << Blue << "============================" << Remove << "\n";
}

// =====================
// Exit message
// =====================
auto bye()->void{
    std::cout << ansi_rgb(49,79,79) << R"(
 /\_/\   BYE!
( -.- )
 > ~ <
)" << Remove << std::endl;
}

// =====================
// Welcome message
// =====================
auto welcome()->void{
    std::cout << ansi_rgb(188,143,143) << R"(
 ,_,   WELCOME!
 (O,O)
 { " }
 -"-"-
)" << Remove << std::endl;
}

// =====================
// Delete a contact
// =====================
auto deleteEntry(std::string* deleteName,std::string* deleteEmail,std::string* deleteNumber,int &deleteCount)->void{
    int index;

    std::cout << Cyan << "Which Contact do you wanna delete? Enter from 1 to " 
              << deleteCount << Remove << ":\n";

    // Show current contacts before deleting
    displayEntry(cName, cEmail, cNumber, CurrentContactCount);

    std::cin >> std::ws >> index;
    index--;

    if(index < 0 || index >= deleteCount){
        std::cout << Red << "Invalid index input" << Remove <<"\n"; 
        return;
    }

    std::cout << Red << "======= Deleting... =======" << Remove << "\n";
    for(int d = index; d < deleteCount-1; d++){
        deleteName[d] = deleteName[d+1];
        deleteEmail[d] = deleteEmail[d+1];
        deleteNumber[d] = deleteNumber[d+1];
    }
    deleteCount--;
    std::cout << Red << "======= Deleted! =======" << Remove << "\n";
}

// =====================
// Edit a contact
// =====================
auto editEntry(std::string* editName,std::string* editEmail,std::string* editNumber,int &editCount)->void{
    int index;

    std::cout << Cyan << "Which Contact do you wanna edit? Enter from 1 to " 
              << editCount << Remove << ":\n";

    displayEntry(cName, cEmail, cNumber, CurrentContactCount);

    std::cin >> std::ws >> index;
    index--;

    if(index < 0 || index >= editCount){
        std::cout << Red << "Invalid index input" << Remove << "\n"; 
        return;
    }

    std::cout << Magenta << "======= Editing... =======" << Remove << "\n";

    std::cout << Cyan << "Edit Name: " << Remove;
    std::getline(std::cin >> std::ws, editName[index]);

    std::cout << Cyan << "Edit Email: " << Remove;
    std::getline(std::cin >> std::ws, editEmail[index]);

    std::cout << Cyan << "Edit Number: " << Remove;
    std::getline(std::cin >> std::ws, editNumber[index]);

    std::cout << Magenta << "======= Edited! =======" << Remove << "\n";
}

// =====================
// Search a contact
// =====================
auto searchEntry(std::string* searchName,std::string* searchEmail,std::string* searchNumber,int &searchCount)->void{
    std::string Query;
    bool fountIT = false;

    std::cout << Cyan << "What do you wanna search? " << Remove;
    std::cin >> std::ws >> Query;

    for(int q = 0; q < searchCount; q++){
        if(searchName[q].find(Query) != std::string::npos || 
           searchEmail[q].find(Query) != std::string::npos || 
           searchNumber[q].find(Query) != std::string::npos){

            std::cout << Red << (q+1) << Remove 
                      << Magenta << ")>" << Remove 
                      << Blue << searchName[q] << Remove 
                      << Red << " | " << Remove 
                      << Cyan << searchEmail[q] << Remove 
                      << Red << " | " << Remove 
                      << Red << searchNumber[q] << Remove 
                      << "\n";

            fountIT = true;
        }
    }

    if(!fountIT){
        std::cout << Red << "Couldn't find anything related to " << Query << ". Try again" << Remove << "\n"; 
        return;
    }
}

// =====================
// Main menu
// =====================
auto mainMenu()->void{
    char op;

    std::cout << Cyan 
              << "======= Main Menu =======\n"
              << "Add Contact [A] \n"
              << "Remove Contact [R] \n"
              << "Edit Contact [E] \n"
              << "Search Contact [S] \n"
              << "Display Contact [D] \n"
              << "Quit [Q] " 
              << Remove << "\n";

    std::cin >> std::ws >> op;
    op = std::toupper(op);

    switch(op){
        case 'A': AddEntry(cName,cEmail,cNumber,CurrentContactCount,maxCount); break;
        case 'R': deleteEntry(cName,cEmail,cNumber,CurrentContactCount); break;
        case 'E': editEntry(cName,cEmail,cNumber,CurrentContactCount); break;
        case 'S': searchEntry(cName,cEmail,cNumber,CurrentContactCount); break;
        case 'D': displayEntry(cName,cEmail,cNumber,CurrentContactCount); break;
        case 'Q': 
            std::cout << "Exiting....\n"; 
            bye(); 
            delete [] cName; 
            delete [] cEmail; 
            delete [] cNumber; 
            exit(EXIT_SUCCESS); 
            break;
        default: 
            std::cout << Red << "Invalid input" << Remove << "\n";
    }
}

// =====================
// Program entry
// =====================
auto main()->int{

    std::cout << Cyan << "======= Contact Book 4.0.1 =======" << Remove << "\n";

    welcome();

    std::cout << Cyan << "How many Contacts do you wanna add? " << Remove;
    std::cin >> std::ws >> maxCount;

    // Allocate memory dynamically
    cName = new std::string[maxCount];
    cEmail = new std::string[maxCount];
    cNumber = new std::string[maxCount];

    // Main loop
    while(true){
        mainMenu();
    }

    // Clean up memory
    delete [] cName;
    delete [] cEmail;
    delete [] cNumber;

    return 0;
}