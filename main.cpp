#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include <set>
#include <cstdlib>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(list<Goat> trip);
void delete_goat(list<Goat> &trip);
void add_goat(list<Goat> &trip, string [], string []);
void display_trip(list<Goat> trip);
int main_menu();

// main menu to select what to do with goats
int main_menu(){
    int choice = 0;
    while (choice != 1 && choice != 2 && choice != 3 && choice != 4){
        cout << "\n--- Goat Manager 3001 ---" << endl;
        cout << "[1] Add a goat" << endl;
        cout << "[2] Delete a goat" << endl;
        cout << "[3] List goats" << endl;
        cout << "[4] Quit" << endl << endl;
        cout << "Please enter an option: ";
        cin >> choice;
        if (choice != 1 && choice != 2 && choice != 3 && choice != 4){
            cout << "Invalid choice. Please choose one of the specified options." << endl;
        }
    }
    return choice;
}

// adding a goat
void add_goat(list<Goat> &trip, string names[], string colors[]){
    string n = names[rand() % SZ_NAMES];
    int a = rand() % MAX_AGE;
    string c = colors[rand() % SZ_COLORS];
    Goat tempGoat = Goat(n, a, c);
    trip.push_back(tempGoat);
    cout << n << " added to the trip" << endl;
}

// deleting a goat
void delete_goat(list<Goat> &trip){
    int itNum = 0;
    auto it = trip.begin();
    display_trip(trip);
    cout << "Select which goat to delete: ";
    cin >> itNum;
    for (int i = 1; i < itNum; i++){
        it++;
    }
    trip.erase(it);
    cout << "Goat deleted" << endl;
}

// list all goats
void display_trip(list<Goat> trip){
    cout << "Listing all goats..." << endl;
    int i = 0;
    for (Goat g : trip){
        cout << "[" << i + 1 << "] - " << g.get_name() << " (" << g.get_age() << ", " << g.get_color() << ")" << endl;
        i++;
    }
}

int main() {
    srand(time(0));
    bool again;
    list<Goat> trip;

    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();
    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();

    int c = main_menu();
    while (c != 4){
        if (c == 1){
            add_goat(trip, names, colors);
        }
        else if (c == 2){
            delete_goat(trip);
        }
        else if (c == 3){
            display_trip(trip);
        }
        c = main_menu();
    }
    cout << "Quitting Goat Manager 3001..." << endl;

    return 0;
}

