#include <iostream>
#include <vector>
#include "ChefStruct.h"
#include "BurgerStruct.h"
#include "Manager.h"
#include "ClientStruct.h"
#include "QueueOrders.h"
#include "CSVManip.h"

using namespace std;

int main() {

    //prototypes
    void ClientInterface(Clients *, Client, Burgers *, Burger, Chefs *, Chef, Order, QUEUE *&);
    void ManagerBurgersInterface(Burgers *, Burger);
    void ManagerChefsInterface(Chefs *, Chef);
    void ManagerClientsInterface(Clients *, Client, Order, QUEUE);
    void ManagerInterface(Manager, Burgers *, Burger, Chefs *, Chef, Clients *, Client, Order, QUEUE *&);

    auto *chefs = new Chefs[MAX_CHEFS];
    Chef WholeChefStruct{};

    auto *burgers = new Burgers[MAX_BURGERS];
    Burger WholeBurgerStruct{};

    auto *clients = new Clients[MAX_CLIENTS];
    Client WholeClientStruct{};

    auto *queue = new QUEUE[MAX_QUEUE];
    Order WholeOrderStruct{};

    //Manager Object
    Manager manager;

    short InterfaceChoice;

    //Initialize arrays
    InitializeChefs(chefs);
    InitializeBurgers(burgers);
    InitializeClients(clients);
    InitializeQUEUE(queue);

    //Get Data from CSV files
    InsertCSVIntoClients(clients);
    InsertCSVIntoChefs(chefs);
    InsertCSVIntoBurgers(burgers);

    bool isUsingConsole = true;

    while (isUsingConsole) {

        cout << "|-------------[ Welcome to BurgerShop ]-------------|" << endl;
        cout << endl;
        cout << "1) Client \n"
             << "2) Manager \n"
             << "3) Exit Console\n";

        do {
            while (cout << "Enter Choice: " && !(cin >> InterfaceChoice)) {
                cout << endl;
                cin.clear(); //clear bad input flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
                cout << "Invalid input; please re-enter.\n";
            }
        } while (InterfaceChoice < 0 || InterfaceChoice > 3);
        cout << endl;

        if (InterfaceChoice == 1) {
            ClientInterface(clients, WholeClientStruct, burgers, WholeBurgerStruct, chefs, WholeChefStruct,
                            WholeOrderStruct, queue);
        }

        if (InterfaceChoice == 2) {
            ManagerInterface(manager, burgers, WholeBurgerStruct, chefs, WholeChefStruct, clients, WholeClientStruct,
                             WholeOrderStruct, queue);
        }

        if (InterfaceChoice == 3) {
            isUsingConsole = false;
        }
    }
    return 0;

}

void ManagerBurgersInterface(Burgers *burgers, Burger WholeBurgerStruct) {

    short BurgerManageChoice;
    bool IsUsingBurgerManage = true;

    while (IsUsingBurgerManage) {
        cout << endl;
        cout << "|---------------- Burgers Management Interface ----------------|" << endl;
        cout << "1) Display Burger list       " << "6) Add new Burger \n"
             << "2) Display Burger by name    " << "7) Add multiple Burgers \n"
             << "3) Display Burger by id      " << "8) Edit existing Burger \n"
             << "4) Display Burgers by rating " << "9) Delete existing Burger \n"
             << "5) Display Burgers by price  " << "10) Display Burger Average Rating\n"
             << "11) Exit The Management" << endl;

        do {
            while (cout << "Enter Choice: " && !(cin >> BurgerManageChoice)) {
                cout << endl;
                cin.clear(); //clear bad input flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
                cout << "Invalid input; please re-enter.\n";
            }
        } while (BurgerManageChoice < 0 || BurgerManageChoice > 11);
        cout << endl;

        switch (BurgerManageChoice) {
            case 1:
                PrintBurgers(burgers);
                break;
            case 2:
                WholeBurgerStruct = GetBurgerByName(burgers);
                PrintBurger(WholeBurgerStruct);
                break;
            case 3:
                WholeBurgerStruct = GetBurgerById(burgers);
                PrintBurger(WholeBurgerStruct);
                break;
            case 4:
                PrintBurgersRatingValue(burgers);
                break;
            case 5:
                PrintBurgersPriceValue(burgers);
                break;
            case 6:
                InsertNewBurger(burgers);
                break;
            case 7:
                int NbOfBurgersToAdd;

                cout << endl;
                do {
                    while (cout << "Enter Choice: " && !(cin >> NbOfBurgersToAdd)) {
                        cout << endl;
                        cin.clear(); //clear bad input flag
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
                        cout << "Invalid input; please re-enter.\n";
                    }
                } while (NbOfBurgersToAdd < 0 || NbOfBurgersToAdd > MAX_BURGERS);
                cout << endl;

                for (int i = 0; i < NbOfBurgersToAdd; i++) {
                    InsertNewBurger(burgers);
                }
                break;
            case 8:
                WholeBurgerStruct = GetBurgerById(burgers);
                EditBurgerValues(burgers, WholeBurgerStruct);
                break;
            case 9:
                WholeBurgerStruct = GetBurgerById(burgers);
                DeleteBurger(burgers, WholeBurgerStruct);
                break;
            case 10:
                cout << endl;
                cout << "Burgers Average is " << GetAverageRating(burgers) << endl;
                cout << endl;
                break;
            case 11:
                IsUsingBurgerManage = false;
                break;
            default:
                cout << "Error" << endl;
        }
    }
}

void ManagerChefsInterface(Chefs *chefs, Chef WholeChefStruct) {
    short ChefManageChoice;
    bool IsUsingChefManage = true;

    while (IsUsingChefManage) {

        cout << "|---------------- Chefs Management Interface ----------------|" << endl;
        cout << "1) Display Chefs list       " << "6) Add new Chef \n"
             << "2) Display Chef by F&L Name " << "7) Add multiple Chefs \n"
             << "3) Display Chef by id       " << "8) Edit existing Chefs \n"
             << "4) Display Chefs by rating  " << "9) Delete existing Chef \n"
             << "5) Display Chefs by salary  " << "10) Display Rating Average \n"
             << "11) Exit The Interface\n";

        do {
            while (cout << "Enter Choice: " && !(cin >> ChefManageChoice)) {
                cout << endl;
                cin.clear(); //clear bad input flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
                cout << "Invalid input; please re-enter.\n";
            }
        } while (ChefManageChoice < 0 || ChefManageChoice > 11);
        cout << endl;

        switch (ChefManageChoice) {
            case 1:
                PrintChefs(chefs);
                break;
            case 2:
                WholeChefStruct = GetChefByFirstLastName(chefs);
                PrintChef(WholeChefStruct);
                break;
            case 3:
                WholeChefStruct = GetChefById(chefs);
                PrintChef(WholeChefStruct);
                break;
            case 4:
                PrintChefsRatingValue(chefs);
                break;
            case 5:
                PrintChefsSalaryValue(chefs);
                break;
            case 6:
                InsertNewChef(chefs);
                break;
            case 7:
                int NbOfChefsToAdd;

                cout << endl;
                do {
                    while (cout << "Enter Choice: " && !(cin >> NbOfChefsToAdd)) {
                        cout << endl;
                        cin.clear(); //clear bad input flag
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
                        cout << "Invalid input; please re-enter.\n";
                    }
                } while (NbOfChefsToAdd < 0 || NbOfChefsToAdd > MAX_CHEFS);
                cout << endl;

                for (int i = 0; i < NbOfChefsToAdd; i++) {
                    InsertNewChef(chefs);
                }
                break;
            case 8:
                WholeChefStruct = GetChefById(chefs);
                EditChefValues(chefs, WholeChefStruct);
                break;
            case 9:
                WholeChefStruct = GetChefById(chefs);
                DeleteChef(chefs, WholeChefStruct);
                break;
            case 10:
                cout << endl;
                cout << "Chefs Average is " << GetAverageRating(chefs);
                cout << endl;
                break;
            case 11:
                IsUsingChefManage = false;
                break;
            default:
                cout << "Error" << endl;
        }
    }
}

void ManagerClientsInterface(Clients *clients, Client WholeClientStruct, QUEUE *&queue) {
    short ClientManageChoice;
    bool IsUsingClientManage = true;

    while (IsUsingClientManage) {

        cout << "|---------------- Clients ManagementInterface ----------------|" << endl;
        cout << "1) Display Clients list       " << "4) Check Clients Orders Queue \n"
             << "2) Display Client by UserName " << "5) Edit existing Client \n"
             << "3) Display Client by id       " << "6) Exit Clients Management Interface \n";

        do {
            while (cout << "Enter Choice: " && !(cin >> ClientManageChoice)) {
                cout << endl;
                cin.clear(); //clear bad input flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
                cout << "Invalid input; please re-enter.\n";
            }
        } while (ClientManageChoice < 0 || ClientManageChoice > 6);
        cout << endl;

        switch (ClientManageChoice) {
            case 1:
                PrintClients(clients);
                break;
            case 2:
                WholeClientStruct = GetClientByUserName(clients);
                PrintClient(WholeClientStruct);
                break;
            case 3:
                WholeClientStruct = GetClientById(clients);
                PrintClient(WholeClientStruct);
                break;
            case 4:
                PrintQUEUE(queue);
                break;
            case 5:
                WholeClientStruct = GetClientById(clients);
                EditClientValues(clients, WholeClientStruct);
                break;
            case 6:
                cout << "Exiting Clients Management Interface" << endl;
                IsUsingClientManage = false;
                break;
            default:
                cout << "Error" << endl;
        }
    }
}

void ManagerInterface(Manager manager, Burgers *burgers, Burger WholeBurgerStruct,
                      Chefs *chefs, Chef WholeChefStruct,
                      Clients *clients, Client WholeClientStruct, Order WholeOrderStruct, QUEUE *&queue) {

    string username;
    string password;
    bool isUsingManagerInterface = false;

    cout << endl;
    cout << "|---------------- Welcome To Manager Interface ----------------|" << endl;
    cout << endl;
    cout << "Please enter UserName and Password: ";

    do {
        cin >> username >> password;
        if (username != manager.getUserName() || password != manager.getPassWord()) {
            cout << "Please make sure your username or password are right!" << endl;
            cout << "Please enter UserName and Password again: ";
            cout << endl;
        }
    } while (username != manager.getUserName() || password != manager.getPassWord());

    if (username == manager.getUserName() && password == manager.getPassWord()) // true
    {
        isUsingManagerInterface = true;

        while (isUsingManagerInterface) {

            short ManageChoice;

            cout << endl;
            cout << "|---------------- Welcome " << username << " To Manager Interface ----------------|" << endl;
            cout << endl;

            cout << "1) Manage Burgers\n"
                 << "2) Manage Chefs\n"
                 << "3) Manage Clients\n"
                 << "4) Exit Manager Interface\n";
            cout << endl;

            do {
                while (cout << "Enter Choice: " && !(cin >> ManageChoice)) {
                    cout << endl;
                    cin.clear(); //clear bad input flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
                    cout << "Invalid input; please re-enter.\n";
                }
            } while (ManageChoice < 0 || ManageChoice > 4);
            cout << endl;

            cout << endl;
            if (ManageChoice == 1) // Burger Management
            {
                ManagerBurgersInterface(burgers, WholeBurgerStruct);
            } else if (ManageChoice == 2) // Chefs Management
            {
                ManagerChefsInterface(chefs, WholeChefStruct);
            } else if (ManageChoice == 3) //Clients Management
            {
                ManagerClientsInterface(clients, WholeClientStruct, queue);
            }
            if (ManageChoice == 4) {
                isUsingManagerInterface = false;
                cout << endl;
                cout << "Exiting Manager Interface..." << endl;
            }
        }

    }
}

void ClientInterface(Clients *clients, Client WholeClientStruct,
                     Burgers *burgers, Burger WholeBurgerStruct,
                     Chefs *chefs, Chef WholeChefStruct,
                     Order WholeOrderStruct, QUEUE *&queue) {

    short ClientChoice;
    bool LoggedIn = false;

    cout << endl;
    cout << "1) Register\n"
         << "2) Login" << endl;

    do {
        while (cout << "Enter Choice: " && !(cin >> ClientChoice)) {
            cout << endl;
            cin.clear(); //clear bad input flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
            cout << "Invalid input; please re-enter.\n";
        }
    } while (ClientChoice != 1 && ClientChoice != 2);
    cout << endl;

    string UserName, Password;
    int Nb = 0;

    if (ClientChoice == 1) {

        Register(clients);

        cout << endl;
        cout << "|---------------- Registered Account Successfully ----------------|" << endl;
        cout << endl;

        //get Login Info
        cout << "|---------------- Please ReEnter Account Info ----------------|" << endl;
        cout << endl;

        cout << "Enter UserName: ";
        cin >> UserName;
        cout << endl;

        cout << "Enter Password: ";
        cin >> Password;

        cout << endl;

        LoggedIn = Login(clients, UserName, Password);
        WholeClientStruct = GetClientAccountThroughLogin(clients, UserName, Password);
    } else {
        //get Login Info
        cout << "|---------------- Please Enter Account Info ----------------|" << endl;
        cout << endl;

        cout << "Enter UserName: ";
        cin >> UserName;
        cout << endl;

        cout << "Enter Password: ";
        cin >> Password;

        LoggedIn = Login(clients, UserName, Password);
        WholeClientStruct = GetClientAccountThroughLogin(clients, UserName, Password);
    }

    while (LoggedIn) {

        short ClientManageChoice;
        cout << "|---------------- Clients Interface ----------------|" << endl;

        cout << "1) Display Account Info " << "4) Reserve Order \n"
             << "2) Edit Account Info    " << "5) Rate Chefs or Burgers \n"
             << "3) Delete Account       " << "6) Display Order\n"
             << "7) Display Burgers Menu " << "8) Check Order \n"
             << "9) Exit Client Interface\n";

        do {
            while (cout << "Enter Choice: " && !(cin >> ClientManageChoice)) {
                cout << endl;
                cin.clear(); //clear bad input flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
                cout << "Invalid input; please re-enter.\n";
            }
        } while (ClientManageChoice < 0 || ClientManageChoice > 9);
        cout << endl;

        switch (ClientManageChoice) {
            case 1:
                cout << "Your Account Info" << endl;
                cout << "-----------------" << endl;
                PrintClient(WholeClientStruct);
                break;
            case 2:
                WholeClientStruct = GetClientAccountThroughLogin(clients, UserName, Password);
                EditAccount(clients, WholeClientStruct);
                break;
            case 3:
                char DeleteChoice;

                cout << "Are you sure?\n"
                     << "Yes (Y) \n"
                     << "No (N) " << endl;

                do {
                    cin >> DeleteChoice;
                    if (DeleteChoice != 'Y' && DeleteChoice != 'N') {
                        cout << "Oops! Enter Again: ";
                    }

                } while (DeleteChoice != 'Y' && DeleteChoice != 'N' );

                if (DeleteChoice == 'Y' || DeleteChoice == 'y') {
                    DeleteAccount(clients, WholeClientStruct);

                    cout << endl;
                    cout << "Account Deleted!" << endl;
                    cout << endl;
                    LoggedIn = false;
                } else
                    break;
            case 4:
                WholeClientStruct = GetClientAccountThroughLogin(clients, UserName, Password);
                WholeOrderStruct = AddToQueue(queue, WholeOrderStruct, WholeClientStruct, burgers);
                break;
            case 5:
                AddRating(chefs, WholeChefStruct, burgers, WholeBurgerStruct);
                break;
            case 6:
                WholeClientStruct = GetClientAccountThroughLogin(clients, UserName, Password);
                WholeOrderStruct = getOrderThroughLogin(queue, WholeClientStruct);
                DisplayOrder(WholeOrderStruct, queue);
                break;
            case 7:
                PrintBurgers(burgers);
                break;
            case 8: {
                WholeClientStruct = GetClientAccountThroughLogin(clients, UserName, Password);
                WholeOrderStruct = getOrderThroughLogin(queue, WholeClientStruct);
                Dequeue(queue, WholeOrderStruct);
                break;
            }
            case 9:
                cout << endl;
                cout << "Exiting Interface..." << endl;
                cout << "Thanks for your visit !" << endl;
                cout << endl;
                LoggedIn = false;
                break;
            default:
                cout << "Error" << endl;
        }
    }
}