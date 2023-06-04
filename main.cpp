#include <iostream>
#include <list>
#include "set.h"

using namespace std;

void add_remove(list<Set*>* sets, char c) {

    int id, elem;
    bool found = false;
    Set* s;

    cout << "Unesite id skupa: ";
    cin >> id;

    for (list<Set*>::iterator i = sets->begin(); i != sets->end(); i++) {
        if ((*i)->getID() == id) {
            s = *i;
            found = true;
            break;
        }
    }

    if (found) {
        cout << "Unesite element: ";
        cin >> elem;

        switch (c) {

            case 'A':
                if (s->addElement(elem) == true) {
                    cout << "\nElement je uspesno dodat u skup ";
                }
                else {
                    cout << "\nElement vec postoji u skupu ";
                }
                cout << s->getID() << endl;
                break;

            case 'R':
                if (s->removeElement(elem) == true) {
                    cout << "\nElement je uspesno uklonjen iz skupa ";
                }
                else {
                    cout << "\nElement ne postoji u skupu ";
                }
                cout << s->getID() << endl;
                break;
        }


    }
    else {
        cout << "\nNepostojeci skup!" << endl;
    }

}

void print_sets(list<Set*>* sets) {

    cout << "Postojeci skupovi: " << endl;
    for (list<Set*>::iterator i = sets->begin(); i != sets->end(); i++) {
        cout << "\nID = " << (*i)->getID() << endl;
        cout << "Broj elemenata: " << (*i)->getNumberOfElements() << endl;
        (*i)->printElements();
    }
    cout << endl;

}

void setOperation(list<Set*>* sets) {

    Set *set1, *set2, *res;
    bool finished = false, found1 = false, found2 = false;
    int choice, id1, id2;

    if (sets->size() < 2) {
        cout << "Nema dovoljno skupova!" << endl;
    }
    else {
        cout << "Unesite ID prvog skupa: ";
        cin >> id1;
        cout << "Unesti ID drugog skupa: ";
        cin >> id2;

        for (list<Set*>::iterator i = sets->begin(); i != sets->end(); i++) {

            if ((*i)->getID() == id1) {
                set1 = *i;
                found1 = true;
            }
            if ((*i)->getID() == id2) {
                set2 = *i;
                found2 = true;
            }
            if (found1 == true && found2 == true) {
                break;
            }
        }

        if (found1 == false || found2 == false) {
            cout << "Bar jedan od unetih skupova ne postoji!" << endl;
        }
        else {
            while (!finished) {
                system("cls");
                cout << "\tIzbor operacije sa skupovima" << endl;
                cout << "\n1 - Unija" << endl;
                cout << "2 - Presek" << endl;
                cout << "3 - Razlika" << endl;
                cout << "0 - Kraj rada" << endl;

                cout << "\nIzbor: ";
                cin >> choice;

                switch (choice) {

                    case 1:
                        system("cls");
                        cout << "Unija zadatih skupova je: ?" << endl;
                        res = Set::_union(set1, set2);
                        res->printElements();
                        system("pause");
                        break;

                    case 2:
                        system("cls");
                        cout << "Presek zadatih skupova je: " << endl;
                        res = Set::_intersection(set1, set2);
                        res->printElements();
                        system("pause");
                        break;

                    case 3:
                        system("cls");
                        cout << "Razlika zadatih skupova je: " << endl;
                        res = Set::_difference(set1, set2);
                        res->printElements();
                        system("pause");
                        break;

                    case 0:
                        finished = true;
                        break;

                    default:
                        system("cls");
                        cout << "Nepostojeca opcija!" << endl;
                        system("pause");
                        break;
                }
            }
        }
    }

}

int main() {

    bool finished = false;
    int choice;
    list<Set*> sets;
    Set* new_set;

    while (!finished) {
        system("cls");
        cout << "\tSkupovi Celih Brojeva" << endl;
        cout << "\n1 - Kreiranje novog skupa" << endl;
        cout << "2 - Dodavanje novog elementa u skup" << endl;
        cout << "3 - Brisanje elementa iz skupa" << endl;
        cout << "4 - Ispis skupova" << endl;
        cout << "5 - Operacije izmedju dva skupa" << endl;
        cout << "0 - Kraj rada" << endl;

        cout << "\nIzbor: ";
        cin >> choice;

        switch (choice) {

            case 1:
                system("cls");
                new_set = new Set();
                sets.push_back(new_set);
                cout << "Set koji ima ID = " << new_set->getID() << " je uspesno kreiran." << endl;
                system("pause");
                break;

            case 2:
                system("cls");
                add_remove(&sets, 'A');
                system("pause");
                break;

            case 3:
                system("cls");
                add_remove(&sets, 'R');
                system("pause");
                break;

            case 4:
                system("cls");
                print_sets(&sets);
                system("pause");
                break;

            case 5:
                system("cls");
                setOperation(&sets);
                system("pause");
                break;

            case 0:
                system("cls");
                finished = true;
                cout << "Hvala na koriscenju!" << endl;
                break;

            default:
                system("cls");
                cout << "Nepostojeca opcija!" << endl;
                system("pause");
                break;
        }

    }

    return 0;
}
