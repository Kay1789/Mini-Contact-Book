#include <iostream>
#include <string>

// Dynamic arrays to store contact names and numbers
std::string* addName;
std::string* addNumber;
int maxContactCount;
int currentContactCount;

// Function declarations
void addEntry();
void deleteEntry();
void editEntry();
void searchEntry();
void showEntry();
void mainFun();

// Welcome ASCII art
void welcomeAscci(){
    std::cout << "/\\_/\\ \n";
    std::cout << "(@ . ^) \n";
    std::cout << " > ^ <  \n";
    std::cout << " /    \\  \n";
    std::cout << "/(\")(\") \n";
    std::cout << "||=======|| \n";
    std::cout << "||Welcome|| \n";
    std::cout << "||=======|| \n";
}

// Goodbye ASCII art
void byeascci(){
    std::cout << "/\\_/\\ \n";
    std::cout << "(｡•́︿•̀｡) \n";
    std::cout << " > ^ <  \n";
    std::cout << " /    \\  \n";
    std::cout << "/(\")(\") \n";
    std::cout << "||=======|| \n";
    std::cout << "||ByeBye || \n";
    std::cout << "||=======|| \n";
}

int main(){
    std::cout << " Dynamic Mini Contact Book 3.0 \n ";
    welcomeAscci();

    char ope;

    // Ask user how many contacts they want to store
    std::cout << " How many Contact do you wanna add? \n";
    std::cin >> maxContactCount;

    // Allocate memory dynamically for contacts
    addName = new std::string[maxContactCount];
    addNumber = new std::string[maxContactCount];

    // Main loop
    while(true){
        std::cout << "/~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~/ \n";
        mainFun();

        // Ask user if they want to continue
        std::cout << " Wanna keep foing [Y/N || y/n] : \n ";
        std::cin >> ope;
        if(ope == 'N' || ope == 'n'){
            byeascci();
            break;
        }
        std::cout << "/~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~/ \n";
    }

    // Free up the allocated memory
    delete[] addName;
    delete[] addNumber;

    return 0;
}

// Function to add a contact
void addEntry(std::string* newName,std::string* newNumber,int &countt,int max){
    if(countt >= max){
        std::cout << " Contact list is full \n";
        return;
    }
    std::cout << "|>^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^<| \n " ;
    std::cout << " Add Contacts " <<std::endl;
    std::cout << " Enter Name : \n ";
    std::getline(std::cin >> std::ws,newName[countt]);
    std::cout << " Enter Number : \n ";
    std::getline(std::cin >> std::ws,newNumber[countt]);
    countt++;
    std::cout << "|>^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^<| \n " ;
}

// Function to delete a contact by index
void deleteEntry(std::string* deleteName,std::string* deleteNumber,int &countt,int index){
    if(index < 0 || index >= countt){
        std::cout << " Invalid index input \n ";
        return;
    }else{
        std::cout << ")>_*>_*>_*>_*>_*>_*>_*>_*>_*>_*>_*>_*>_*( \n ";
        for(int o = index;o < countt-1;o++){
            deleteName[o] = deleteName[o + 1];
            deleteNumber[o] = deleteNumber[o + 1];
        }
        countt--;
        std::cout << " Deleted! \n ";
        std::cout << ")>_*>_*>_*>_*>_*>_*>_*>_*>_*>_*>_*>_*>_*( \n ";
    }
}

// Function to edit a contact by index
void editEntry(std::string* editName,std::string* editNumber,int &countt,int index){
    if(index < 0 || index >= countt){
        std::cout << " Invalid index input \n ";
        return;
    }else {
        std::cout << "@_@_@_@_@_@_@_@_@_@_@_@_@_@_@_@_@_@_@_@_@_@_@ \n " ;
        std::cout << " Updating " <<std::endl;
        std::cout << " Edit Name : \n ";
        std::getline(std::cin >> std::ws,editName[index]);
        std::cout << " Edit Number : \n ";
        std::getline(std::cin >> std::ws,editNumber[index]);
        std::cout << " Updated!! \n ";
        std::cout << "@_@_@_@_@_@_@_@_@_@_@_@_@_@_@_@_@_@_@_@_@_@_@ \n " ;
    }
}

// Function to search contact by name
void searchEntry(std::string* searchName,std::string* searchNumber,int countt,std::string &query){
    bool foundIT = false;
    std::cout << "|~%~%~%~%~%~%~%~%~%~%~%~%~%~%~%~%~%~%~%~%~%~%~%~%~%~%~| \n ";
    for(int q = 0;q < countt;q++){
        if(searchName[q].find(query) != std::string::npos){
            std::cout << " Found it " <<std::endl;
            std::cout << " Name : " << searchName[q] << " || " << " Number : " << searchNumber[q] <<std::endl;
            foundIT = true;
        }
    }
    if(!foundIT){
        std::cout << " We couldn't find anything related to " << query <<std::endl;
    }
    std::cout << "|~%~%~%~%~%~%~%~%~%~%~%~%~%~%~%~%~%~%~%~%~%~%~%~%~%~%~| \n ";
}

// Function to display all contacts
void showEntry(std::string* showName,std::string* showNumber,int &countt){
    std::cout << "=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_= \n";
    std::cout << " Contact list " <<std::endl;
    for(int k = 0;k < countt;k++){
        std::cout << (k + 1) << " Name : " << showName[k] << " || " << " Number : " << showNumber[k] <<std::endl;
    }
    std::cout << "=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_= \n";
}

// Handles main menu interactions
void mainFun(){
    char op;

    std::cout << "Add Contact[A] \nDelete Contact[D] \nEdit Contact[E] \nSearchContact by name[S] \nView Contact[V] " <<std::endl;
    std::cin >> op;

    switch (op) {
        case 'A':{
            addEntry(addName,addNumber,currentContactCount,maxContactCount);
        break;
        }
        case 'D':{
            std::cout << " Deleting " <<std::endl;
            int deletee;
            std::cout << " what do you wanna delete [Enter the index] : \n ";
            std::cin >> deletee;
            deleteEntry(addName,addNumber,currentContactCount,deletee - 1);
        break;
        }
        case 'E':{
            int update;
            std::cout << " What do you wanna edit [Enter the index] : \n ";
            std::cin >> update;
            editEntry(addName,addNumber,currentContactCount,update - 1);
        break;
        }
        case 'S':{
            std::cout << " Searching \n ";
            std::string searchNewName;
            std::cout << " Enter the name you wanna search : \n ";
            std::getline(std::cin >> std::ws,searchNewName);
            searchEntry(addName,addNumber,currentContactCount,searchNewName);
        break;
        }
        case 'V':{
            showEntry(addName,addNumber,currentContactCount);
        break;
        }
        default:
            std::cout << " Invalid input please try again " <<std::endl;
    }
}