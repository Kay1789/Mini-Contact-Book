#include <iostream>
#include <string>

std::string* addName;
std::string* addNumber;
int maxContactCount;
int currentContactCount = 0;

void addEntry();
void deleteEntry();
void editEntry();
void searchEntry();
void show();
void mainFun();

int main(){
    char op;

    std::cout << " how many Contacts do you wanna add? " <<std::endl;
    std::cin >> maxContactCount;

    addName = new std::string[maxContactCount];
    addNumber = new std::string[maxContactCount];

    while(true){
        mainFun();

        std::cout << " Wanna keep going? [Y/N || y/n] \n ";
        std::cin >> op;
        if(op == 'Y' || op == 'y'){
        }else if(op =='N' || op == 'n'){
            break;
        }
    }

    delete [] addName;
    delete [] addNumber;
    return 0;
}

void addEntry(std::string* newName,std::string* newNumber,int &countt, int max){
    if(countt >= max){
        std::cout << " Contact list full!! \n ";
        return;
    }
    std::cout << " Add Contact  " <<std::endl;
    std::cout << " Enter Name : \n ";
    std::getline(std::cin >> std::ws,newName[countt]);
    std::cout << " Enter Number : \n ";
    std::getline(std::cin >> std::ws,newNumber[countt]);
    countt++;
}

void deleteEntry(std::string* deleteName,std::string* deleteNumber,int &countt,int index){
    if(index < 0 || index >= countt){
        std::cout << " Invalid input \n ";
        return;
    }else{
        for(int u = 0;u < countt-1;u++){
             deleteName[u] = deleteName[u+1];
             deleteNumber[u] = deleteNumber[u + 1];
        }
        countt--;
        std::cout << " Deleted!! \n ";
    }
}

void editEntry(std::string* editName,std::string* editNumber,int &countt,int index){
    if(index < 0 || index >= countt){
        std::cout << " Invalid input \n" ;
        return;
    }else{
        std::cout << " Updating " <<std::endl;
        std::cout << " Enter name : \n ";
        std::getline(std::cin >> std::ws,editName[index]);
        std::cout << " Enter Number : \n ";
        std::getline(std::cin >> std::ws,editNumber[index]);
        std::cout << " Updated!! \n ";
    }
}

void searchEntry(std::string* searchName,std::string* searchNumber,int countt,std::string &query){
    bool foundIT = false;
    for(int q = 0;q < countt;q++){
        if(searchName[q].find(query) != std::string::npos){
            std::cout << " Fount it " <<std::endl;
            std::cout << " Name : " << searchName[q] << " || " << " Number : " << searchNumber[q] <<std::endl;
            foundIT = true;
        }
        if(!foundIT){
            std::cout << " Couldn't find anything related to " << query <<std::endl;
        }
    }
}

void show(std::string* showName,std::string* showNumber,int &countt){
    std::cout << " Contact list \n ";
    for(int o = 0;o < countt;o++){
        std::cout << (o + 1) << " Name : " << showName[o] << " || " << " Number : " << showNumber[o] <<std::endl;
    }
}

void mainFun(){
    char op;

    std::cout << "Add Contact[A] \nDelete Contact[D] \nEdit Contact[E] \nView Contact[V] \nSearch Contact[S] " <<std::endl;
    std::cin >> op;

    switch (op) {
        case 'A':
            addEntry(addName,addNumber,currentContactCount,maxContactCount);
        break;
        case 'D':
            std::cout << " Deleting " <<std::endl;
            int delete1;
            std::cout << " What do you wanna delete? [enter the index] \n ";
            std::cin >> delete1;
            deleteEntry(addName,addNumber,currentContactCount,delete1 - 1);
        break;
        case 'E':
            int update;
            std::cout << " What do you wanna update? [enter the index] \n ";
            std::cin >> update;
            editEntry(addName,addNumber,currentContactCount,update - 1);
        break;
        case 'V':
            show(addName,addNumber,currentContactCount);
        break;
        case 'S':{
            std::cout << " Searching " <<std::endl;
            std::string searchNewName;
            std::cout << " Enter name to search ? " <<std::endl;
            std::getline(std::cin >> std::ws,searchNewName);
            searchEntry(addName,addNumber,currentContactCount,searchNewName);
            break;
        }
            default:
                std::cout << " Invalid input try again \n ";
    }
}