#ifndef BURGERSHOP_CHEFSTRUCT_H
#define BURGERSHOP_CHEFSTRUCT_H

#include <iostream>
#include <limits>
#include "CSVManip.h"

using namespace std;

#define MAX_CHEFS 50
#define MAX_SALARY 1600 // max 1600$

struct Chef {
    int id;
    string first_name;
    string last_name;
    int age;
    double salary;
    double rating;
};

struct Chefs {
    Chef chefs_array[MAX_CHEFS];
    int NbOfChefs;
};

//Utility Functions

bool InsertCSVIntoChefs(Chefs *chefs) {

    for (int i = 0; i < chefsDoc.GetRowCount(); i++) {

        int ID = chefsDoc.GetCell<int>(0, i);
        string FirstName = chefsDoc.GetCell<std::string>(1, i);
        string LastName = chefsDoc.GetCell<std::string>(2, i);
        int Age = chefsDoc.GetCell<int>(3, i);
        auto Salary = chefsDoc.GetCell<double>(4, i);
        auto Rating = chefsDoc.GetCell<double>(5, i);


        chefs->chefs_array[i].id = ID;
        chefs->chefs_array[i].first_name = FirstName;
        chefs->chefs_array[i].last_name = LastName;
        chefs->chefs_array[i].age = Age;
        chefs->chefs_array[i].salary = Salary;
        chefs->chefs_array[i].rating = Rating;

        chefs->NbOfChefs++;
    }
    return true;
}

// Here goes all the functions to be implemented in the main file
void InitializeChefs(Chefs *chefs) {
    chefs->NbOfChefs = 0;
}

bool isEmpty(Chefs *chefs) {
    return (chefs->NbOfChefs == 0);
}

bool isFull(Chefs *chefs) {
    return (chefs->NbOfChefs == MAX_CHEFS);
}

void PrintChef(Chef chef) {

    cout << endl;
    cout << "|----------- Account Info -----------|" << endl;
    cout << "ID:          " << chef.id << endl;
    cout << "FirstName:   " << chef.first_name << endl;
    cout << "LastName:    " << chef.last_name << endl;
    cout << "Age:         " << chef.age << endl;
    cout << "Salary:      " << chef.salary << endl;
    cout << "Rating:      " << chef.rating << endl;
    cout << "|----------- Account Info -----------|" << endl;
    cout << endl;
}

void PrintChefForArray(Chefs *chefs, int index) {
    cout << endl;
    cout << "|----------- Account Info -----------|" << endl;
    cout << "ID:          " << chefs->chefs_array[index].id << endl;
    cout << "FirstName:   " << chefs->chefs_array[index].first_name << endl;
    cout << "LastName:    " << chefs->chefs_array[index].last_name << endl;
    cout << "Age:         " << chefs->chefs_array[index].age << endl;
    cout << "Salary:      " << chefs->chefs_array[index].salary << endl;
    cout << "Rating:      " << chefs->chefs_array[index].rating << endl;
    cout << "|----------- Account Info -----------|" << endl;
    cout << endl;
}

void PrintChefs(Chefs *chefs) {

    if (isEmpty(chefs)) {
        cout << " There's No Chefs " << endl;
    } else {
        cout << "|----------- All Chefs -----------|" << endl;
        cout << endl;

        for (int i = 0; i < chefs->NbOfChefs; i++) {
            PrintChefForArray(chefs, i);
        }
    }
}

void PrintChefsRatingValue(Chefs *chefs) {
    int Rating;
    char choice;

    if (isEmpty(chefs)) {

        cout << endl;
        cout << "There's No Chefs available" << endl;
        cout << endl;

    } else {

        do {
            while (cout << "Enter Rating: " && !(cin >> Rating)) {
                cout << endl;
                cin.clear(); //clear bad input flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
                cout << "Invalid input; please re-enter.\n";
            }
        } while (Rating < 0 || Rating > 10);
        cout << endl;


        cout << "Display Higher (H) or Lower (L) or Equal(E)?";
        do {
            cin >> choice;
            cout << endl;

            if (choice != 'H' && choice != 'L' && choice != 'E') {
                cout << "Enter a valid Value: ";
                cout << endl;
            }

        } while (choice != 'H' && choice != 'L' && choice != 'E');

        if (choice == 'H' || choice == 'h') {
            cout << "Displaying Higher than " << Rating << endl;

            for (int i = 0; i < chefs->NbOfChefs; i++) {
                if (chefs->chefs_array[i].rating > Rating)
                    PrintChefForArray(chefs, i);
            }
        } else
            cout << "No Chef Found" << endl;
        if (choice == 'L' || choice == 'l') {
            cout << "Displaying Lower than " << Rating << endl;

            for (int i = 0; i < chefs->NbOfChefs; i++) {
                if (chefs->chefs_array[i].rating < Rating)
                    PrintChefForArray(chefs, i);
            }
        } else
            cout << "No Chef Found" << endl;
        if (choice == 'E' || choice == 'e') {
            cout << "Displaying All that are Equal to " << Rating << endl;

            for (int i = 0; i < chefs->NbOfChefs; i++) {
                if (chefs->chefs_array[i].rating == Rating)
                    PrintChefForArray(chefs, i);
            }
        } else
            cout << "No Chef Found" << endl;
    }
}

void PrintChefsSalaryValue(Chefs *chefs) {
    int Salary;
    char choice;

    if (isEmpty(chefs)) {
        cout << " The chefs array is empty" << endl;
    } else {
        do {
            while (cout << "Enter Salary( 100$ / " << MAX_SALARY << "$ ): " &&
                   !(cin >> chefs->chefs_array[chefs->NbOfChefs].salary)) {
                cout << endl;
                cin.clear(); //clear bad input flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
                cout << "Invalid input; please re-enter.\n";
            }
        } while (chefs->chefs_array[chefs->NbOfChefs].salary < 100 ||
                 chefs->chefs_array[chefs->NbOfChefs].salary > MAX_SALARY);
        cout << endl;

        cout << "Display Higher (H) or Lower (L) or Equal(E)?";
        do {
            cin >> choice;

            if (choice != 'H' && choice != 'L' && choice != 'E') {
                cout << "Enter a valid Value: ";
            }

        } while (choice != 'H' && choice != 'L' && choice != 'E');

        if (choice == 'H' || choice == 'h') {
            cout << "Displaying Higher than " << Salary << endl;

            for (int i = 0; i < chefs->NbOfChefs; i++) {
                if (chefs->chefs_array[i].salary > Salary)
                    PrintChefForArray(chefs, i);
            }
        }
        if (choice == 'L' || choice == 'l') {
            cout << "Displaying Lower than " << Salary << endl;

            for (int i = 0; i < chefs->NbOfChefs; i++) {
                if (chefs->chefs_array[i].salary < Salary)
                    PrintChefForArray(chefs, i);
            }
        }
        if (choice == 'E' || choice == 'e') {
            cout << "Displaying All that are Equal to " << Salary << endl;

            for (int i = 0; i < chefs->NbOfChefs; i++) {
                if (chefs->chefs_array[i].salary == Salary)
                    PrintChefForArray(chefs, i);
            }
        }
    }
}

void EditChefValues(Chefs *chefs, Chef chef) {

    if (isEmpty(chefs)) {
        cout << " The chefs array is empty" << endl;
    }

    short ChefAttribute;

    cout << "|----------- Editable Values -----------|\n"
         << "1) FirstName\n"
         << "2) LastName\n"
         << "3) Age\n"
         << "4) Salary\n";
    cout << "|----------- Editable Values -----------|\n";
    cout << endl;

    do {
        while (cout << "Enter Choice: " && !(cin >> ChefAttribute)) {
            cout << endl;
            cin.clear(); //clear bad input flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
            cout << "Invalid input; please re-enter.\n";
        }
    } while (ChefAttribute < 0 || ChefAttribute > 4);
    cout << endl;

    switch (ChefAttribute) {
        case 1:
            for (int i = 0; i < chefs->NbOfChefs; i++) {
                string FirstName;
                cout << "Enter New First name: ";
                cin >> FirstName;
                if (chefs->chefs_array[i].first_name == chef.first_name)
                    chefs->chefs_array[i].first_name.replace(0, 20, FirstName);
                OverWriteChefsToCSV(chefs->chefs_array[i].id,
                                    chefs->chefs_array[i].first_name, chefs->chefs_array[i].last_name,
                                    chefs->chefs_array[i].age, chefs->chefs_array[i].salary,
                                    chefs->chefs_array[i].rating);
            }
            break;
        case 2: {
            string LastName;
            cout << "Enter New Last name: ";
            cin >> LastName;
            for (int i = 0; i < chefs->NbOfChefs; i++) {
                if (chefs->chefs_array[i].last_name == chef.last_name)
                    chefs->chefs_array[i].last_name.replace(0, 20, LastName);
                OverWriteChefsToCSV(chefs->chefs_array[i].id,
                                    chefs->chefs_array[i].first_name, chefs->chefs_array[i].last_name,
                                    chefs->chefs_array[i].age, chefs->chefs_array[i].salary,
                                    chefs->chefs_array[i].rating);
            }
        }
            break;
        case 3:
            for (int i = 0; i < chefs->NbOfChefs; i++) {
                int Age;
                do {
                    while (cout << "Enter Age( 16 / 64 ): " && !(cin >> Age)) {
                        cout << endl;
                        cin.clear(); //clear bad input flag
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
                        cout << "Invalid input; please re-enter.\n";
                    }
                } while (Age < 16 || Age > 64);
                cout << endl;

                if (chefs->chefs_array[i].age == chef.age) {
                    chefs->chefs_array[i].age = Age;
                    OverWriteChefsToCSV(chefs->chefs_array[i].id,
                                        chefs->chefs_array[i].first_name, chefs->chefs_array[i].last_name,
                                        chefs->chefs_array[i].age, chefs->chefs_array[i].salary,
                                        chefs->chefs_array[i].rating);
                    break;
                }
            }
            break;
        case 4:
            for (int i = 0; i < chefs->NbOfChefs; i++) {
                double Salary;
                do {
                    while (cout << "Enter Salary( 100$ / " << MAX_SALARY << "$ ): " && !(cin >> Salary)) {
                        cout << endl;
                        cin.clear(); //clear bad input flag
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
                        cout << "Invalid input; please re-enter.\n";
                    }
                } while (Salary < 100 || Salary > MAX_SALARY);
                cout << endl;
                if (chefs->chefs_array[i].salary == chef.salary) {
                    chefs->chefs_array[i].salary = Salary;
                    OverWriteChefsToCSV(chefs->chefs_array[i].id,
                                        chefs->chefs_array[i].first_name, chefs->chefs_array[i].last_name,
                                        chefs->chefs_array[i].age, chefs->chefs_array[i].salary,
                                        chefs->chefs_array[i].rating);
                }
            }
        default:
            cout << "Error" << endl;
    }
}

void DeleteChef(Chefs *chefs, Chef chef) {

    short NbOfChef = 0;

    if (isEmpty(chefs))
        cout << "Chefs Array is empty" << endl;

    // Count for position of chef in array to be deleted
    for (int i = 0; i < chefs->NbOfChefs; i++) {
        NbOfChef++;
        if (chefs->chefs_array[i].id == chef.id)
            break;
    }

    // Delete chef and replace the next chef with its position
    for (int i = NbOfChef; i < chefs->NbOfChefs; i++){
        chefs[i] = chefs[i + 1];
        OverWriteChefsToCSV(chefs->chefs_array[i].id,
                            chefs->chefs_array[i].first_name, chefs->chefs_array[i].last_name,
                            chefs->chefs_array[i].age, chefs->chefs_array[i].salary,
                            chefs->chefs_array[i].rating);
        }
    chefs->NbOfChefs--;
}

void InsertNewChef(Chefs *chefs) {

    if (isFull(chefs)) {
        cout << " The chefs Array is Full" << endl;
    } else {

        srand(time(0));
        chefs->chefs_array[chefs->NbOfChefs].id = rand();

        cout << endl;
        cout << "|------------- Please Enter Chef Info -------------|" << endl;
        cout << endl;

        cout << "New Chef id is: " << chefs->chefs_array[chefs->NbOfChefs].id << endl;
        cout << endl;

        cout << "Enter First Name: ";
        cin >> chefs->chefs_array[chefs->NbOfChefs].first_name;
        cout << endl;

        cout << "Enter Last Name: ";
        cin >> chefs->chefs_array[chefs->NbOfChefs].last_name;
        cout << endl;

        do {
            while (cout << "Enter Age( 16 / 64 ): " && !(cin >> chefs->chefs_array[chefs->NbOfChefs].age)) {
                cout << endl;
                cin.clear(); //clear bad input flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
                cout << "Invalid input; please re-enter.\n";
            }
        } while (chefs->chefs_array[chefs->NbOfChefs].age < 16 || chefs->chefs_array[chefs->NbOfChefs].age > 64);
        cout << endl;

        do {
            while (cout << "Enter Salary( 100$ / " << MAX_SALARY << "$ ): " &&
                   !(cin >> chefs->chefs_array[chefs->NbOfChefs].salary)) {
                cout << endl;
                cin.clear(); //clear bad input flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
                cout << "Invalid input; please re-enter.\n";
            }
        } while (chefs->chefs_array[chefs->NbOfChefs].salary < 100 ||
                 chefs->chefs_array[chefs->NbOfChefs].salary > MAX_SALARY);
        cout << endl;

        cout << "Rating will be 5 by default" << endl;
        chefs->chefs_array[chefs->NbOfChefs].rating = 5;
        cout << endl;

        InsertChefsToCSV(chefs->chefs_array[chefs->NbOfChefs].id,
                         chefs->chefs_array[chefs->NbOfChefs].first_name,
                         chefs->chefs_array[chefs->NbOfChefs].last_name,
                         chefs->chefs_array[chefs->NbOfChefs].age,
                         chefs->chefs_array[chefs->NbOfChefs].salary,
                         chefs->chefs_array[chefs->NbOfChefs].rating);

        chefs->NbOfChefs++;
    }
}

Chef GetChefById(Chefs *chefs) {

    Chef chef;
    int id;

    if (isEmpty(chefs)) {
        cout << endl;
        cout << "There's No Chefs available" << endl;
        cout << endl;
    } else {
        cout << endl;
        while (cout << "Enter Id: " && !(cin >> id)) {
            cin.clear(); //clear bad input flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
            cout << "Invalid input; please re-enter.\n";
        }
        cout << endl;

        for (int i = 0; i < chefs->NbOfChefs; i++) {
            if (id == chefs->chefs_array[i].id)
                return chefs->chefs_array[i];
        }
        cout << " Chef Not found" << endl;
    }
    return chef;
}

Chef GetChefByFirstLastName(Chefs *chefs) {

    Chef chef;
    string fname, lname;

    if (isEmpty(chefs)) {
        cout << endl;
        cout << "There's No Chefs available" << endl;
        cout << endl;
    } else {
        cout << "Enter Chef's First & Last Name: ";
        cin >> fname >> lname;
        cout << endl;

        for (int i = 0; i < chefs->NbOfChefs; i++) {
            int res = chefs->chefs_array[i].first_name.compare(fname);
            int res2 = chefs->chefs_array[i].last_name.compare(lname);
            if (res == 0 && res2 == 0)
                return chefs->chefs_array[i];
            else
                cout << "Chef Not found ";
        };
    }
    return chef;
}

float GetAverageRating(Chefs *chefs) {

    float total = 0;

    for (int i = 0; i < chefs->NbOfChefs; i++)
        total += chefs->chefs_array[i].rating;

    return total / chefs->NbOfChefs;
}


#endif //BURGERSHOP_CHEFSTRUCT_H
