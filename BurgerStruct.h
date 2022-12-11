#ifndef BURGER_SHOP_BURGERSTRUCT_H
#define BURGER_SHOP_BURGERSTRUCT_H


#include <cstdlib>
#include <ctime>
#include <iostream>

#define MAX_BURGERS 30
#define MAX_PRICE 55

using namespace std;

struct Burger {
    int id;
    string name;
    double price;
    double rating;
};

struct Burgers {
    Burger burgers_array[MAX_BURGERS];
    int NbOfBurgers;
};

bool InsertCSVIntoBurgers(Burgers *burgers) {

    for (int i = 0; i < burgersDoc.GetRowCount(); i++) {

        int ID = burgersDoc.GetCell<int>(0, i);
        string Name = burgersDoc.GetCell<std::string>(1, i);
        auto Price = burgersDoc.GetCell<double>(2, i);
        auto Rating = burgersDoc.GetCell<double>(3, i);

        burgers->burgers_array[i].id = ID;
        burgers->burgers_array[i].name = Name;
        burgers->burgers_array[i].price = Price;
        burgers->burgers_array[i].rating = Rating;

        burgers->NbOfBurgers++;
    }
    return true;
}

// Here goes all the functions to be implemented in the main file
void InitializeBurgers(Burgers *burgers) {
    burgers->NbOfBurgers = 0;
}

bool isEmpty(Burgers *burgers) {
    return (burgers->NbOfBurgers == 0);
}

bool isFull(Burgers *burgers) {
    return (burgers->NbOfBurgers == MAX_BURGERS);
}

void PrintBurger(Burger burger) {
    cout << "|----------- Burger Info -----------|" << endl;
    cout << "Burger's ID:   " << burger.id << endl;
    cout << "Burger's Name: " << burger.name << endl;
    cout << "Price:         " << burger.price << "$" << endl;
    cout << "Rating:        " << burger.rating << endl;
    cout << "|----------- Burger Info -----------|" << endl;
}

void PrintBurgerForArray(Burgers *burgers, int index) {
    cout << "|----------- Burger Info -----------|" << endl;
    cout << "Burger's ID: " << burgers->burgers_array[index].id << endl;
    cout << "Burger's Name: " << burgers->burgers_array[index].name << endl;
    cout << "Price: " << burgers->burgers_array[index].price << endl;
    cout << "Rating: " << burgers->burgers_array[index].rating << endl;
    cout << "|----------- Burger Info -----------|" << endl;
}

void PrintBurgers(Burgers *burgers) {

    if (isEmpty(burgers)) {

        cout << endl;
        cout << "There's No Burgers available\n";
        cout << endl;

    } else {
        cout << "|----------- All Burgers -----------|" << endl;
        cout << endl;

        for (int i = 0; i < burgers->NbOfBurgers; i++) {
            PrintBurgerForArray(burgers, i);
        }
    }
}

void PrintBurgersRatingValue(Burgers *burgers) {
    int Rating;
    char choice;

    if (isEmpty(burgers)) {

        cout << endl;
        cout << "There's No Burgers available" << endl;
        cout << endl;

    } else {
        do {
            while (cout << "Enter Rating (  / 10 ): " && !(cin >> Rating)) {
                cout << endl;
                cin.clear(); //clear bad input flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
                cout << "Invalid input; please re-enter.\n";
            }
        } while (Rating < 0 || Rating > 10);

        cout << "Display Higher (H) or Lower (L) or Equal(E)?";
        do {
            cin >> choice;

            if (choice != 'H' && choice != 'L' && choice != 'E') {
                cout << "Enter a valid Value: ";
            }

        } while (choice != 'H' && choice != 'L' && choice != 'E');

        if (choice == 'H' || choice == 'h') {
            cout << "Displaying Higher than " << Rating << endl;

            for (int i = 0; i < burgers->NbOfBurgers; i++) {
                if (burgers->burgers_array[i].rating > Rating) {
                    PrintBurgerForArray(burgers, i);
                }
            }
        }
        if (choice == 'L' || choice == 'l') {
            cout << "Displaying Lower than " << Rating << endl;

            for (int i = 0; i < burgers->NbOfBurgers; i++) {
                if (burgers->burgers_array[i].rating < Rating) {
                    PrintBurgerForArray(burgers, i);
                } else
                    cout << "No Burger Found" << endl;
            }
        }
        if (choice == 'E' || choice == 'e') {
            cout << "Displaying All that are Equal to " << Rating << endl;

            for (int i = 0; i < burgers->NbOfBurgers; i++) {
                if (burgers->burgers_array[i].rating == Rating) {
                    PrintBurgerForArray(burgers, i);
                } else
                    cout << "No Burger Found" << endl;
            }
        }
    }
}

void PrintBurgersPriceValue(Burgers *burgers) {
    double Price;
    char choice;

    if (isEmpty(burgers)) {

        cout << endl;
        cout << "There's No Burgers available" << endl;
        cout << endl;

    } else {
        cout << endl;
        do {
            while (cout << "Enter Salary( 100$ / " << MAX_PRICE << "$ ): " && !(cin >> Price)) {
                cout << endl;
                cin.clear(); //clear bad input flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
                cout << "Invalid input; please re-enter.\n";
            }
        } while (Price < 0 || Price > MAX_PRICE);
        cout << endl;

        cout << "Display Higher (H) or Lower (L) or Equal(E)?";
        cout << endl;

        do {
            cin >> choice;

            if (choice != 'H' && choice != 'L' && choice != 'E') {
                cout << "Enter a valid Value: ";
            }

        } while (choice != 'H' && choice != 'L' && choice != 'E');

        if (choice == 'H' || choice == 'h') {
            cout << "Displaying Higher than " << Price << endl;

            for (int i = 0; i < burgers->NbOfBurgers; i++) {
                if (burgers->burgers_array[i].price > Price)
                    PrintBurgerForArray(burgers, i);
            }
        }
        if (choice == 'L' || choice == 'l') {
            cout << "Displaying Lower than " << Price << endl;

            for (int i = 0; i < burgers->NbOfBurgers; i++) {
                if (burgers->burgers_array[i].price < Price)
                    PrintBurgerForArray(burgers, i);
            }
        }
        if (choice == 'E' || choice == 'e') {
            cout << "Displaying All that are Equal to " << Price << endl;

            for (int i = 0; i < burgers->NbOfBurgers; i++) {
                if (burgers->burgers_array[i].price == Price)
                    PrintBurgerForArray(burgers, i);
            }
        }
    }

}

void EditBurgerValues(Burgers *burgers, Burger burger) {
    short BurgerAttribute;

    if (isEmpty(burgers)) {
        cout << "There's No Burgers available" << endl;
    } else {
        cout << "|----------- Editable Values -----------|\n"
             << "1) Name\n"
             << "2) Price\n";
        cout << "|----------- Editable Values -----------|\n";
        cout << endl;

        do {
            while (cout << "Enter Choice: " && !(cin >> BurgerAttribute)) {
                cout << endl;
                cin.clear(); //clear bad input flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
                cout << "Invalid input; please re-enter.\n";
            }
        } while (BurgerAttribute < 0 || BurgerAttribute > 6);
        cout << endl;

        switch (BurgerAttribute) {
            case 1: {

                string Name;
                cout << "Enter New Name: ";
                cin >> Name;
                cout << endl;

                for (int i = 0; i < burgers->NbOfBurgers; i++) {
                    if (burgers->burgers_array[i].name == burger.name) {
                        burgers->burgers_array[i].name.replace(0, 20, Name);
                        OverWriteBurgersToCSV(burgers->burgers_array[i].id, burgers->burgers_array[i].name,
                                              burgers->burgers_array[i].price, burgers->burgers_array[i].rating);
                        break;
                    }
                }
                break;
            }
            case 2: {
                double Price;
                while (cout << "Enter Price: " && !(cin >> burgers->burgers_array[burgers->NbOfBurgers].price) ||
                       burgers->burgers_array[burgers->NbOfBurgers].price > MAX_PRICE) {
                    cin.clear(); //clear bad input flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
                    cout << "Invalid input; please re-enter.\n";
                }
                cout << endl;

                for (int i = 0; i < burgers->NbOfBurgers; i++) {
                    if (burgers->burgers_array[i].price == burger.price) {
                        burgers->burgers_array[i].price = Price;
                        OverWriteBurgersToCSV(burgers->burgers_array[i].id, burgers->burgers_array[i].name,
                                              burgers->burgers_array[i].price, burgers->burgers_array[i].rating);
                        break;
                    }
                }
                break;
            }
            default:
                cout << "Error" << endl;
        }
    }
}

void DeleteBurger(Burgers *burgers, Burger burger) {

    short NbOfBurger = 0;

    if (isEmpty(burgers)) {
        cout << endl;
        cout << "There's No Burgers available" << endl;
        cout << endl;
    } else {
        // Count for position of burger in array to be deleted
        for (int i = 0; i < burgers->NbOfBurgers; i++) {
            NbOfBurger++;
            if (burgers->burgers_array[i].id == burger.id)
                break;
        }

        // Delete burger and replace the next burger with its position
        for (int i = NbOfBurger; i < burgers->NbOfBurgers; i++) {
            burgers[i] = burgers[i + 1];
            OverWriteBurgersToCSV(burgers->burgers_array[i].id, burgers->burgers_array[i].name,
                                  burgers->burgers_array[i].price, burgers->burgers_array[i].rating);
        }
        burgers->NbOfBurgers--;
    }
}

void InsertNewBurger(Burgers *burgers) {

    if (isFull(burgers)) {
        cout << endl;
        cout << " The Burgers Array is Full" << endl;
        cout << endl;
    } else {

        srand(time(0));
        burgers->burgers_array[burgers->NbOfBurgers].id = rand();

        cout << endl;
        cout << "|------------- Please Enter Burger Info -------------|" << endl;
        cout << endl;

        cout << "New Burger id is: " << burgers->burgers_array[burgers->NbOfBurgers].id << endl;
        cout << endl;

        cout << "Enter Name: ";
        cin >> burgers->burgers_array[burgers->NbOfBurgers].name;
        cout << endl;

        while (cout << "Enter Price: " && !(cin >> burgers->burgers_array[burgers->NbOfBurgers].price ||
                                            burgers->burgers_array[burgers->NbOfBurgers].price > MAX_PRICE)) {
            cin.clear(); //clear bad input flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
            cout << "Invalid input; please re-enter.\n";
        }
        cout << endl;

        cout << "Rating will be 5 by default" << endl;
        burgers->burgers_array[burgers->NbOfBurgers].rating = 5;
        cout << endl;

        InsertBurgersToCSV(burgers->burgers_array[burgers->NbOfBurgers].id,
                           burgers->burgers_array[burgers->NbOfBurgers].name,
                           burgers->burgers_array[burgers->NbOfBurgers].price,
                           burgers->burgers_array[burgers->NbOfBurgers].rating);

        burgers->NbOfBurgers++;
    }
}

Burger GetBurgerById(Burgers *burgers) {

    Burger burger;
    int id;

    if (isEmpty(burgers)) {
        cout << endl;
        cout << "There's No Burgers available" << endl;
        cout << endl;
    } else {
        while (cout << "Enter Id: " && !(cin >> id)) {
            cin.clear(); //clear bad input flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
            cout << "Invalid input; please re-enter.\n";
        }
        cout << endl;
        cout << endl;

        for (int i = 0; i < burgers->NbOfBurgers; i++) {
            if (id == burgers->burgers_array[i].id)
                return burgers->burgers_array[i];
        }
        cout << "Burger Not found" << endl;
        cout << endl;
    }
    return burger;
}

Burger GetBurgerByName(Burgers *burgers) {
    Burger burger;
    string name;

    if (isEmpty(burgers)) {
        cout << endl;
        cout << "There's No Burgers available" << endl;
        cout << endl;
    } else {

        cout << endl;
        cout << "Enter Burger's name: ";
        cin >> name;

        for (int i = 0; i < burgers->NbOfBurgers; i++) {
            int res = burgers->burgers_array[i].name.compare(name);
            if (res == 0)
                return burgers->burgers_array[i];
        }
        cout << "Burger Not found" << endl;
        cout << endl;
    }
    return burger;
}

float GetAverageRating(Burgers *burgers) {

    double total = 0;

    for (int i = 0; i < burgers->NbOfBurgers; i++)
        total += burgers->burgers_array[i].rating;

    return total / burgers->NbOfBurgers;
}

#endif
