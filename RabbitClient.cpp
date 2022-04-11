#include "RabbitDataBase.h"
#include <iostream>
#include "ReadUtils.h"
using namespace std;

const int MAX_MENU_LEN = 70;
void printMenu(char options[][MAX_MENU_LEN], int numEntries){
  for(int index = 0; index < numEntries; index++){
    cout << (index + 1) << ") " << options[index] << endl;
  }
}

int main() {
    RabbitDataBase rabbits; 
    int option = 0;
    char menuOptions[][MAX_MENU_LEN]={  "Print rabbit list",
                                        "Save list to file",
                                        "Remove rabbit",
                                        "Add rabbit",
                                        "Quit"};
    rabbits.read();
    do {
        printMenu(menuOptions,5);
        option = readInt("Please select an option: ");
        switch(option) {
            case 1:
                rabbits.print(cout, true);
                break;
            case 2:
                rabbits.save();
                break;
            case 3:
                rabbits.remove();
                break;
            case 4:
                rabbits.add();
                break;
            case 5:
                break;
            default:
                cout << "Invalid option, try again" << endl;
                break;
        }
    }while(option != 5);
    
    return 0;
}
