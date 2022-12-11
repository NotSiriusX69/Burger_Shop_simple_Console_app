#ifndef BURGER_SHOP_CLIENTSTRUCT_H
#define BURGER_SHOP_CLIENTSTRUCT_H

#include <iostream>
#include <limits>
#include "BurgerStruct.h"
#include "ChefStruct.h"
#include "CSVManip.h"

using namespace std;

#define MAX_CLIENTS 100

struct Client {
    int id;
    string user_name;
    string first_name;
    string last_name;
    string password;
    string phone_number;
    int age;
};

struct Clients {
    Client clients_array[MAX_CLIENTS];
    int NbOfClients;
};

//Utility Functions
int countDigit(int n) {
    if (n == 0)
        return 1;
    int count = 0;
    while (n != 0) {
        n = n / 10;
        ++count;
    }
    return count;
}

bool InsertCSVIntoClients(Clients *clients) {

    for (int i = 0; i < clientsDoc.GetRowCount(); i++) {

        int ID = clientsDoc.GetCell<int>(0, i);
        string UserName = clientsDoc.GetCell<std::string>(1, i);
        string FirstName = clientsDoc.GetCell<std::string>(2, i);
        string LastName = clientsDoc.GetCell<std::string>(3, i);
        string Password = clientsDoc.GetCell<std::string>(4, i);
        string PhoneNumber = clientsDoc.GetCell<std::string>(5, i);
        int Age = clientsDoc.GetCell<int>(6, i);

        clients->clients_array[i].id = ID;
        clients->clients_array[i].user_name = UserName;
        clients->clients_array[i].first_name = FirstName;
        clients->clients_array[i].last_name = LastName;
        clients->clients_array[i].password = Password;
        clients->clients_array[i].phone_number = PhoneNumber;
        clients->clients_array[i].age = Age;

        clients->NbOfClients++;
    }
    return true;
}
//Functions for Manager's Interface

void InitializeClients(Clients *clients) {
    clients->NbOfClients = 0;
}

bool isEmpty(Clients *clients) {
    return (clients->NbOfClients == 0);
}

bool isFull(Clients *clients) {
    return (clients->NbOfClients == MAX_CLIENTS);
}

void PrintClient(Client client) {

    cout << endl;
    cout << "|----------- Account Info -----------|" << endl;
    cout << "ID:          " << client.id << endl;
    cout << "UserName:    " << client.user_name << endl;
    cout << "FirstName:   " << client.first_name << endl;
    cout << "LastName:    " << client.last_name << endl;
    cout << "Password:    " << client.password << endl;
    cout << "PhoneNumber: " << client.phone_number << endl;
    cout << "Age:         " << client.age << endl;
    cout << "|----------- Account Info -----------|" << endl;
    cout << endl;
}

void PrintClientForArray(Clients *clients, int index) {
    cout << endl;
    cout << "|----------- Account Info -----------|" << endl;
    cout << "ID:          " << clients->clients_array[index].id << endl;
    cout << "UserName:    " << clients->clients_array[index].user_name << endl;
    cout << "FirstName:   " << clients->clients_array[index].first_name << endl;
    cout << "LastName:    " << clients->clients_array[index].last_name << endl;
    cout << "Password:    " << clients->clients_array[index].password << endl;
    cout << "Age:         " << clients->clients_array[index].age << endl;
    cout << "PhoneNumber: " << clients->clients_array[index].phone_number << endl;
    cout << "|----------- Account Info -----------|" << endl;
}

void PrintClients(Clients *clients) {

    if (isEmpty(clients)) {
        cout << endl;
        cout << "There's no Clients" << endl;
        cout << endl;
    } else {
        cout << "|----------- All Clients -----------|" << endl;
        cout << endl;

        for (int i = 0; i < clients->NbOfClients; i++) {
            PrintClientForArray(clients, i);
        }
    }
}

void EditClientValues(Clients *clients, Client client) {

    if (isEmpty(clients)) {
        cout << " The clients array is empty" << endl;
    } else {
        short ClientAttribute;

        cout << "|----------- Editable Values -----------|\n"
             << "1) UserName\n"
             << "2) PhoneNumber\n"
             << "3) FirstName\n"
             << "4) LastName\n"
             << "5) Password\n"
             << "6) Age" << endl;
        cout << "|----------- Editable Values -----------|\n";
        cout << endl;

        do {
            while (cout << "Enter Choice: " && !(cin >> ClientAttribute)) {
                cout << endl;
                cin.clear(); //clear bad input flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
                cout << "Invalid input; please re-enter.\n";
            }
        } while (ClientAttribute < 0 || ClientAttribute > 6);
        cout << endl;

        switch (ClientAttribute) {
            bool found;
            case 1:
                found = false;
                for (int i = 0; i < clients->NbOfClients; i++) {
                    string Name;
                    cout << "Enter New UserName: ";
                    cin >> Name;
                    if (clients->clients_array[i].user_name == client.user_name) {
                        clients->clients_array[i].user_name.replace(0, 20, Name);
                        OverWriteClientToCSV(clients->clients_array[i].id,
                                             clients->clients_array[i].user_name,
                                             clients->clients_array[i].first_name,
                                             clients->clients_array[i].last_name, clients->clients_array[i].password,
                                             clients->clients_array[i].phone_number, clients->clients_array[i].age);
                        found = true;
                        cout << "Changed Successfully" << endl;
                        cout << endl;
                    }
                }
                if (!found)
                    cout << "Error, Check Id!" << endl;
                break;
            case 2:
                found = false;
                int phone_number;
                while (cout << "Enter your phone number: + 961 " && !(cin >> phone_number) ||
                       countDigit(phone_number) != 8) {
                    cin.clear(); //clear bad input flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
                    cout << "Invalid input; please re-enter.\n";
                }

                for (int i = 0; i < clients->NbOfClients; i++) {
                    string phone_numberS = "+961 " + to_string(phone_number);
                    if (clients->clients_array[i].phone_number == client.phone_number) {
                        clients->clients_array[i].phone_number.replace(0, 20, phone_numberS);
                        OverWriteClientToCSV(clients->clients_array[i].id,
                                             clients->clients_array[i].user_name,
                                             clients->clients_array[i].first_name,
                                             clients->clients_array[i].last_name, clients->clients_array[i].password,
                                             clients->clients_array[i].phone_number, clients->clients_array[i].age);
                        cout << "Changed Successfully" << endl;
                        cout << endl;
                        found = true;
                    }
                    if (!found)
                        cout << "Check Id!" << endl;
                }
                break;
            case 3:
                found = false;
                for (int i = 0; i < clients->NbOfClients; i++) {
                    string FName;
                    cout << "Enter New FirstName: ";
                    cin >> FName;
                    if (clients->clients_array[i].first_name == client.first_name) {
                        clients->clients_array[i].first_name.replace(0, 20, FName);
                        OverWriteClientToCSV(clients->clients_array[i].id,
                                             clients->clients_array[i].user_name,
                                             clients->clients_array[i].first_name,
                                             clients->clients_array[i].last_name, clients->clients_array[i].password,
                                             clients->clients_array[i].phone_number, clients->clients_array[i].age);
                        cout << "Changed Successfully" << endl;
                        cout << endl;
                        found = true;
                    }
                }
                if (!found)
                    cout << "Error, Check Id!" << endl;
                break;
            case 4:
                found = false;
                for (int i = 0; i < clients->NbOfClients; i++) {
                    string LName;
                    cout << "Enter New LastName: ";
                    cin >> LName;
                    if (clients->clients_array[i].last_name == client.last_name) {
                        clients->clients_array[i].last_name.replace(0, 20, LName);
                        OverWriteClientToCSV(clients->clients_array[i].id,
                                             clients->clients_array[i].user_name,
                                             clients->clients_array[i].first_name,
                                             clients->clients_array[i].last_name, clients->clients_array[i].password,
                                             clients->clients_array[i].phone_number, clients->clients_array[i].age);
                        cout << "Changed Successfully" << endl;
                        cout << endl;
                        found = true;
                    }
                }
                if (!found)
                    cout << "Error, Check Id!" << endl;
                break;
            case 5:
                found = false;
                for (int i = 0; i < clients->NbOfClients; i++) {
                    string password;
                    cout << "Enter New Password: ";
                    cin >> password;
                    if (clients->clients_array[i].password == client.password) {
                        clients->clients_array[i].password.replace(0, 20, password);
                        OverWriteClientToCSV(clients->clients_array[i].id,
                                             clients->clients_array[i].user_name,
                                             clients->clients_array[i].first_name,
                                             clients->clients_array[i].last_name, clients->clients_array[i].password,
                                             clients->clients_array[i].phone_number, clients->clients_array[i].age);
                        cout << "Changed Successfully" << endl;
                        cout << endl;
                        found = true;
                    }
                }
                if (!found)
                    cout << "Error, Check Id!" << endl;
                break;
            case 6:
                found = false;

                int Age;
                cout << "Enter new Age: ";
                do {
                    while (cout << "Enter Age( 16 / 64 ): " && !(cin >> Age)) {
                        cout << endl;
                        cin.clear(); //clear bad input flag
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
                        cout << "Invalid input; please re-enter.\n";
                    }
                } while (Age < 16 || Age > 64);

                for (int i = 0; i < clients->NbOfClients; i++) {
                    if (clients->clients_array[i].age == client.age) {
                        clients->clients_array[i].age = Age;
                        OverWriteClientToCSV(clients->clients_array[i].id,
                                             clients->clients_array[i].user_name,
                                             clients->clients_array[i].first_name,
                                             clients->clients_array[i].last_name, clients->clients_array[i].password,
                                             clients->clients_array[i].phone_number, clients->clients_array[i].age);
                        cout << "Change will be displayed on next Login" << endl;
                        found = true;
                    }
                }
                if (!found)
                    cout << "Error, Check Id!" << endl;
                break;
            default:
                cout << "Error" << endl;
        }
    }

}

Client GetClientById(Clients *clients) {

    Client client;
    int id;

    if (isEmpty(clients)) {
        cout << endl;
        cout << "There's No Clients available" << endl;
        cout << endl;
    } else {
        while (cout << "Enter Id: " && !(cin >> id)) {
            cin.clear(); //clear bad input flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
            cout << "Invalid input; please re-enter.\n";
        }
        cout << endl;
        for (int i = 0; i < clients->NbOfClients; i++) {
            if (id == clients->clients_array[i].id)
                return clients->clients_array[i];
        }
        cout << "Client Not found" << endl;
        cout << endl;
    }
    return client;
}

Client GetClientByUserName(Clients *clients) {
    Client client;
    string name;

    if (isEmpty(clients)) {
        cout << endl;
        cout << "There's No Clients available" << endl;
        cout << endl;
    } else {

        cout << "Enter Client's User name: ";
        cin >> name;

        for (int i = 0; i < clients->NbOfClients; i++) {
            int res = clients->clients_array[i].user_name.compare(name);
            if (res == 0)
                return clients->clients_array[i];
        }
        cout << "Client Not found" << endl;
        cout << endl;
    }
    return client;
}

//Functions for Client's Interface
Client GetClientAccountThroughLogin(Clients *clients, string username, string password) {
    Client client;
    int res = 1;
    int res2 = 1;

    for (int i = 0; i < clients->NbOfClients; i++) {
        res = clients->clients_array[i].user_name.compare(username);
        res2 = clients->clients_array[i].password.compare(password);
        if (res == 0 && res2 == 0)
            return clients->clients_array[i];
    }
    return client;
}

void Register(Clients *clients) { //add new Client

    if (isFull(clients))
        cout << "No more space. Please contact Staff for further info!" << endl;
    else {
        cout << "|-------------[ Welcome to BurgerShop ]-------------|" << endl;
        cout << endl;
        cout << "|------------- Please Enter Info -------------|" << endl;
        cout << endl;


        srand(time(0));
        clients->clients_array[clients->NbOfClients].id = rand();

        cout << "Your new ID: " << clients->clients_array[clients->NbOfClients].id << endl;

        cout << "Enter First Name: ";
        cin >> clients->clients_array[clients->NbOfClients].first_name;
        cout << endl;

        cout << "Enter Last Name: ";
        cin >> clients->clients_array[clients->NbOfClients].last_name;
        cout << endl;

        cout << "Enter User Name: ";
        cin >> clients->clients_array[clients->NbOfClients].user_name;
        cout << endl;

        cout << "Enter Password: ";
        cin >> clients->clients_array[clients->NbOfClients].password;
        cout << endl;

        int PhoneNumber;
        while (cout << "Enter your phone number: + 961 " && !(cin >> PhoneNumber) || countDigit(PhoneNumber) != 8) {
            cin.clear(); //clear bad input flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
            cout << "Invalid input; please re-enter.\n";
        }
        clients->clients_array[clients->NbOfClients].phone_number = "+961 " + to_string(PhoneNumber);
        cout << endl;

        do {
            while (cout << "Enter Age( 16 / 64 ): " && !(cin >> clients->clients_array[clients->NbOfClients].age)) {
                cout << endl;
                cin.clear(); //clear bad input flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
                cout << "Invalid input; please re-enter.\n";
            }
        } while (clients->clients_array[clients->NbOfClients].age < 16 ||
                 clients->clients_array[clients->NbOfClients].age > 64);
        cout << endl;
        InsertClientToCSV(clients->clients_array[clients->NbOfClients].id,
                          clients->clients_array[clients->NbOfClients].user_name,
                          clients->clients_array[clients->NbOfClients].first_name,
                          clients->clients_array[clients->NbOfClients].last_name,
                          clients->clients_array[clients->NbOfClients].password,
                          clients->clients_array[clients->NbOfClients].phone_number,
                          clients->clients_array[clients->NbOfClients].age);
        clients->NbOfClients++;
    }

}

bool Login(Clients *clients, string UserName, string Password) { //Check If client exists

    bool isLoggedIn;
    Client client;

    for (int i = 0; i < clients->NbOfClients; i++) {
        int res = clients->clients_array[i].user_name.compare(UserName);
        int res2 = clients->clients_array[i].password.compare(Password);
        if (res == 0 && res2 == 0) {
            cout << "|---------------- Logged In Successfully ----------------|" << endl;
            return true;
        }
    }
    cout << "Oops! Either Password or UserName are not correct" << endl;
    return false;

}

void EditAccount(Clients *clients, Client client) { //Edit Client's Account

    short ClientAttribute;

    cout << "|----------- Editable Values -----------|\n"
         << "1) UserName\n"
         << "2) PhoneNumber\n"
         << "3) FirstName\n"
         << "4) LastName\n"
         << "5) Password\n"
         << "6) Age" << endl;
    cout << "|----------- Editable Values -----------|\n";
    cout << endl;

    do {
        while (cout << "Enter Choice: " && !(cin >> ClientAttribute)) {
            cout << endl;
            cin.clear(); //clear bad input flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
            cout << "Invalid input; please re-enter.\n";
        }
    } while (ClientAttribute < 0 || ClientAttribute > 6);
    cout << endl;

    switch (ClientAttribute) {
        bool found;
        case 1:
            found = false;
            for (int i = 0; i < clients->NbOfClients; i++) {
                string Name;
                cout << "Enter New UserName: ";
                cin >> Name;

                if (clients->clients_array[i].user_name == client.user_name) {
                    clients->clients_array[i].user_name.replace(0, 20, Name);

                    OverWriteClientToCSV(clients->clients_array[i].id,
                                         clients->clients_array[i].user_name,
                                         clients->clients_array[i].first_name,
                                         clients->clients_array[i].last_name, clients->clients_array[i].password,
                                         clients->clients_array[i].phone_number, clients->clients_array[i].age);

                    found = true;
                    cout << "Change will be displayed on next Login" << endl;
                }
            }
            if (!found) {
                cout << "You have Edited your account recently!" << endl;
                cout << endl;
            }
            break;
        case 2:
            found = false;
            int phone_number;
            while (cout << "Enter your phone number: + 961 " && !(cin >> phone_number) ||
                   countDigit(phone_number) != 8) {
                cin.clear(); //clear bad input flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
                cout << "Invalid input; please re-enter.\n";
            }

            for (int i = 0; i < clients->NbOfClients; i++) {
                string phone_numberS = "+961 " + to_string(phone_number);
                if (clients->clients_array[i].phone_number == client.phone_number) {
                    clients->clients_array[i].phone_number.replace(0, 20, phone_numberS);

                    OverWriteClientToCSV(clients->clients_array[i].id,
                                         clients->clients_array[i].user_name,
                                         clients->clients_array[i].first_name,
                                         clients->clients_array[i].last_name, clients->clients_array[i].password,
                                         clients->clients_array[i].phone_number, clients->clients_array[i].age);

                    cout << "Change will be displayed on next Login" << endl;
                    found = true;
                }
                if (!found) {
                    cout << "You have Edited your account recently!" << endl;
                    cout << endl;
                }
            }
            break;
        case 3:
            found = false;
            for (int i = 0; i < clients->NbOfClients; i++) {
                string FName;
                cout << "Enter New FirstName: ";
                cin >> FName;
                if (clients->clients_array[i].first_name == client.first_name) {
                    clients->clients_array[i].first_name.replace(0, 20, FName);

                    OverWriteClientToCSV(clients->clients_array[i].id,
                                         clients->clients_array[i].user_name,
                                         clients->clients_array[i].first_name,
                                         clients->clients_array[i].last_name, clients->clients_array[i].password,
                                         clients->clients_array[i].phone_number, clients->clients_array[i].age);

                    cout << "Change will be displayed on next Login" << endl;
                    found = true;
                }
            }
            if (!found) {
                cout << "You have Edited your account recently!" << endl;
                cout << endl;
            }
            break;
        case 4:
            found = false;
            for (int i = 0; i < clients->NbOfClients; i++) {
                string LName;
                cout << "Enter New LastName: ";
                cin >> LName;
                if (clients->clients_array[i].last_name == client.last_name) {
                    clients->clients_array[i].last_name.replace(0, 20, LName);

                    OverWriteClientToCSV(clients->clients_array[i].id,
                                         clients->clients_array[i].user_name,
                                         clients->clients_array[i].first_name,
                                         clients->clients_array[i].last_name, clients->clients_array[i].password,
                                         clients->clients_array[i].phone_number, clients->clients_array[i].age);

                    cout << "Change will be displayed on next Login" << endl;
                    found = true;
                }
            }
            if (!found) {
                cout << "You have Edited your account recently!" << endl;
                cout << endl;
            }
            break;
        case 5:
            found = false;
            for (int i = 0; i < clients->NbOfClients; i++) {
                string password;
                cout << "Enter New Password: ";
                cin >> password;
                if (clients->clients_array[i].password == client.password) {
                    clients->clients_array[i].password.replace(0, 20, password);

                    OverWriteClientToCSV(clients->clients_array[i].id,
                                         clients->clients_array[i].user_name,
                                         clients->clients_array[i].first_name,
                                         clients->clients_array[i].last_name, clients->clients_array[i].password,
                                         clients->clients_array[i].phone_number, clients->clients_array[i].age);

                    cout << "Change will be displayed on next Login" << endl;
                    found = true;
                }
            }
            if (!found) {
                cout << "You have Edited your account recently!" << endl;
                cout << endl;
            }
            break;
        case 6:
            found = false;
            int Age;
            do {
                while (cout << "Enter Age( 16 / 64 ): " && !(cin >> Age)) {
                    cout << endl;
                    cin.clear(); //clear bad input flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
                    cout << "Invalid input; please re-enter.\n";
                }
            } while (Age < 16 || Age > 64);

            for (int i = 0; i < clients->NbOfClients; i++) {
                if (clients->clients_array[i].age == client.age) {
                    clients->clients_array[i].age = Age;

                    OverWriteClientToCSV(clients->clients_array[i].id,
                                         clients->clients_array[i].user_name,
                                         clients->clients_array[i].first_name,
                                         clients->clients_array[i].last_name, clients->clients_array[i].password,
                                         clients->clients_array[i].phone_number, clients->clients_array[i].age);

                    cout << "Change will be displayed on next Login" << endl;
                    found = true;
                }
            }
            if (!found) {
                cout << "You have Edited your account recently!" << endl;
                cout << endl;
            }
            break;
        default:
            cout << "Error" << endl;
    }
}

void DeleteAccount(Clients *clients, Client client) { //Delete Client's Account

    short NbOfChef = 0;

    if (isEmpty(clients))
        cout << "Clients Array is empty" << endl;

    // Count for position of chef in array to be deleted
    for (int i = 0; i < clients->NbOfClients; i++) {
        NbOfChef++;
        if (clients->clients_array[i].id == client.id)
            break;
    }

    // Delete chef and replace the next chef with its position
    for (int i = NbOfChef; i < clients->NbOfClients; i++) {
        clients[i] = clients[i + 1];

        OverWriteClientToCSV(clients->clients_array[i].id,
                             clients->clients_array[i].user_name,
                             clients->clients_array[i].first_name,
                             clients->clients_array[i].last_name, clients->clients_array[i].password,
                             clients->clients_array[i].phone_number, clients->clients_array[i].age);
    }
    clients->NbOfClients--;


}

void AddRating(Chefs *chefs, Chef chef, Burgers *burgers, Burger burger) {

    short RateChoice;
    double rate;

    cout << "Please choose your rating cautiously" << endl;

    cout << "1)Rate specific Chef \n"
         << "2)Rate specific Burger " << endl;

    cout << "choose: ";
    do {

        cin >> RateChoice;
        if (RateChoice != 1 && RateChoice != 2) {
            cout << "Enter a valid Value: ";
        }

    } while (RateChoice != 1 && RateChoice != 2);


    switch (RateChoice) {
        case 1: {
            if (chefs->NbOfChefs == 0) {
                cout << endl;
                cout << "No chefs Available for rating\n";
                cout << endl;
                break;
            }

            chef = GetChefById(chefs); // get Chef struct through id
            bool foundChef;
            cout << "Choose Your rating / 10: ";
            cout << endl;
            do {
                cin >> rate;
                cout << endl;
                if (rate < 0 || rate > 10) {
                    cout << "Please enter a valid value" << endl;
                }
            } while (rate < 0 || rate > 10);

            for (int i = 0; i < chefs->NbOfChefs; i++) {
                if (chefs->chefs_array[i].id == chef.id) {
                    (chefs->chefs_array[i].rating += rate / 2);
                    foundChef = true;
                }
            }
            if (!foundChef) {
                cout << "Value is not saved, please make sure Id is correct" << endl;
            }
            break;
        }
        case 2: {
            if (burgers->NbOfBurgers == 0) {
                cout << endl;
                cout << "No Burgers Available for rating\n";
                cout << endl;
                break;
            }

            burger = GetBurgerByName(burgers); // get Burger struct through name
            bool foundBurger;
            cout << "Choose Your rating / 10: ";
            cout << endl;
            do {
                cin >> rate;
                cout << endl;
                if (rate < 0 || rate > 10) {
                    cout << "Please enter a valid value" << endl;
                }
            } while (rate < 0 || rate > 10);

            for (int i = 0; i < burgers->NbOfBurgers; i++) {
                if (burgers->burgers_array[i].id == burger.id) {
                    (burgers->burgers_array[i].rating += rate / 2);
                    foundBurger = true;
                }
            }
            if (!foundBurger) {
                cout << "Value is not saved, please make sure name is correct" << endl;
            }
            break;
        }
        default:
            cout << "Error" << endl;
    }
}

#endif //BURGER_SHOP_CLIENTSTRUCT_H
