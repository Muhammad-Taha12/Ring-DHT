#include <iostream>
using namespace std;
#include "BigInt.h"
#include <cstdlib>
#include <ctime>
#include "RoutingTable.h"
#include "sha1.hpp"

int main()
{
    cout << "_|_|_|      _|_|_|      _|_|_|    _|_|_|      _|_|          _|  _|_|_|_|    _|_|_|  _|_|_|_|_|\n";
    cout << "_|    _|  _|            _|    _|  _|    _|  _|    _|        _|  _|        _|            _|    \n";
    cout << "_|    _|    _|_|        _|_|_|    _|_|_|    _|    _|        _|  _|_|_|    _|            _|    \n";
    cout << "_|    _|        _|      _|        _|    _|  _|    _|  _|    _|  _|        _|            _|    \n";
    cout << "_|_|_|    _|_|_|        _|        _|    _|    _|_|      _|_|    _|_|_|_|    _|_|_|      _|    \n";
    cout << "______________________________________________________________________________________________\n" << endl;

    //---------------
    int identifier;
    cout << "Enter Identifier Space: ";
    cin >> identifier;
    CircularLinkedList CL(identifier);

    string ams;
    cout << "Enter the number of active machines: ";
    cin >> ams;
    // int am = stoi(ams);

   //  string ams = to_string(am);


    while (BigInt(ams) > CL.totalSize) {
        cout << "Machines should be in between 0 and " << CL.totalSize << endl;
        cin >> ams;
        //cout << CL.totalSize << ' ' << ams << endl;
    }


    int choice;
    cout << "1. Assign ids manually?\n2. Assign ids automatically(Any other key)?\n";
    cin >> choice;

    if (choice == 1) {
        for (BigInt i(0); i < BigInt(ams); i++) {
            string id;

            cout << "Enter id for " << i + 1 << " machine: ";
            cin >> id;
            BigInt s(id);
            while (s > CL.totalSize || CL.nodealreadyexists(id)) {
                if (s > CL.totalSize) {
                    cout << "Enter values between 0 and " << CL.totalSize - 1 << endl;
                }
                if (CL.nodealreadyexists(id)) {
                    cout << "This machine is already active.";
                    cin >> id;
                    continue;
                }
                cin >> id;

                //---
                s.BigSize = 0;
                while (id[s.BigSize] != '\0')
                {
                    s.BigSize++;
                }
                s.Big = new char[s.BigSize + 1];
                s.Big[s.BigSize] = '\0';
                for (int copy = 0; copy < s.BigSize; copy++)
                {
                    s.Big[copy] = id[copy];
                }

                //---
            }

            CL.insertion(id);

        }
    }
    else {
        srand(time(0));
        for (BigInt i(0); i < BigInt(ams); i++) {
            //choice = rand() % am;
            //while (CL.nodealreadyexists(choice)) {
              //  choice = rand() % am;
            //}
            //cout << choice << ' ';
            CL.insertion(i);
        }
        cout << endl;
    }
    CL.updateRoutingTable();
    //---------------

    cout << " __       __  ________  __    __  __    __  \n";
    cout << "|  \\     /  \\|        \\|  \\  |  \\|  \\  |  \ \n";
    cout << "| $$\\   /  $$| $$$$$$$$| $$\\ | $$| $$  | $$ \n";
    cout << "| $$$\\ /  $$$| $$__    | $$$\\| $$| $$  | $$ \n";
    cout << "| $$$$\\  $$$$| $$  \\   | $$$$\\ $$| $$  | $$ \n";
    cout << "| $$\\$$ $$ $$| $$$$$   | $$\\$$ $$| $$  | $$ \n";
    cout << "| $$ \\$$$| $$| $$_____ | $$ \\$$$$| $$__/ $$ \n";
    cout << "| $$  \\$ | $$| $$     \\| $$  \\$$$ \\$$    $$ \n";
    cout << " \\$$      \\$$ \\$$$$$$$$ \\$$   \\$$  \\$$$$$$  \n";
    do {
        cout << "____________________________________________\n";
        cout << "* 1. Specify the number of machines  x     *\n";
        cout << "* 2. xxxxxxxxxxx                           *\n";
        cout << "* 3. Print Btree of any machine            *\n";
        cout << "* 4. Insert file                           *\n";
        cout << "* 5. Remove data and print updated B-tree  *\n";
        cout << "* 6. Print routing table of machines       *\n";
        cout << "* 7. Add new machine on the fly            *\n";
        cout << "* 8. Remove machine on the fly             *\n";
        cout << "* 0. Exit                                  *\n";
        cout << "____________________________________________\n";

        cout << "Enter your choice: ";
        cin >> choice;
        string path, mid;
        int hval;
        switch (choice) {
        case 1:
            // specifyNumberOfMachines();
            break;
        case 2:
            //specifyIdentifierSpace();
            break;
        case 3:
            //manuallyAssignIds();
            cout << "Enter id of machine whose btree you want to print: ";
            cin >> mid;
            CL.displaymybtree(BigInt(mid));
            break;
        case 4:
            //insertFiles();
            cout << "Enter path of file: ";
            cin >> path;
            CL.addfile(path);
            break;
        case 5:
            //removeData();
            cout << "Enter hash value of file you want to remove: ";
            cin >> hval;
            break;
        case 6:
            //printRoutingTable();
            CL.display();
            cout << endl;
            CL.displayRoutingTable();
            break;
        case 7:
        {
            //addNewMachine();
          //-------------------------
            string i;
            cout << "Enter id for machine: ";
            cin >> i;
            BigInt s2(i);
            while (s2 > CL.totalSize || CL.nodealreadyexists(i)) {
                if (s2 > CL.totalSize) {
                    cout << "Enter values between 0 and " << CL.totalSize - 1 << endl;
                }
                if (CL.nodealreadyexists(i)) {
                    cout << "This machine is already active.";
                    cin >> i;
                    continue;
                }
                cin >> i;

                //---
                s2.BigSize = 0;
                while (i[s2.BigSize] != '\0')
                {
                    s2.BigSize++;
                }
                s2.Big = new char[s2.BigSize + 1];
                s2.Big[s2.BigSize] = '\0';
                for (int copy = 0; copy < s2.BigSize; copy++)
                {
                    s2.Big[copy] = i[copy];
                }

                //---
            }
            CL.insertion(i);
            CL.updateRoutingTable();
        }
        //----------------------------
        break;
        case 8:
        {
            string rm;
            cout << "Enter machine id you want to remove: ";
            cin >> rm;
            CL.deletion(BigInt(rm));
            CL.updateRoutingTable();
        }
        case 9:
        {
            int type;
            int hash;
            string hashStr;
            cout << "Type: 1- String, 2- Int: ";
            cin >> type;
            switch (type)
            {
                case 1:
                    cout << "Enter hash string: ";
                    cin >> hashStr;
                    cout << CL.search(hashStr) << endl;
                    break;
                case 2:
                    cout << "Enter hash integer: ";
                    cin >> hash;
                    cout << CL.search(hash) << endl;
                    break;
                default:
                    cout << "Invalid Input";
            }

        }
        //removeMachine();
        break;
        case 0:
            cout << "Exiting the program\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}