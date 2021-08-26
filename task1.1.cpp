#include <iostream>
#include <string>
#include <map>
#include "human.h"
#include "monster.h"


using namespace std;

struct information {
    string name;
    string kind;
    int numR;
    int numN;
    int totcost;
};

map<int, information> hotel;

int main()
{
    auto itr = hotel.end();
    human h;
    monster m;
    while (true) {
        cout << "\t\t\t\tWelcome to our hotel!\n" << "*Please answer the questions below.*\n";
        cout << "are you old guest, new guest or receptionist? (old - new - receptionist)\n";       
        string s;
        string kind;
        string name;
        string ss;
        int id;
        getline(cin, s);
        if (s == "new") {                               //asking about the user's kind and regstration's type
            cout << "what is your kind? (human - monster)\n";
            getline(cin, kind);
            if (kind == "human") {
                cout << "welcome sir! May I ask you about your name?\n";    
                getline(cin, name);
                id = hotel.size() + 1;
                cout << "your name is: " << name << "\t" << "your id is: " << id << "\n";
            }
            else if (kind == "monster") {
                cout << "welcome sir! May I ask you about your name?\n";
                getline(cin, name);
                id = hotel.size() + 1;
                cout << "your name is: " << name << "\t" << "your id is: " << id << "\n";
            }
            else {
                cout << "*please try again with suitable input*";
                continue;
            }
            hotel.insert({ id,{name,kind,0,0,0} });          //adding elements to the map to save it
            itr = hotel.find(id);
        }
        else if (s == "old") { 
            cout << "what is your id? ";
                cin >> id;
                cout << id;
            itr = hotel.find(id);
            cout << "\nwelcome back " << itr->second.name << "!\n" ;
        }
        else if (s == "receptionist") {                      //the receptionist's previlage to access the hotel info
            cout << "\t\t\t\taccess accepted!\n";
            cout << "ID\tname\tkind\tNum of rooms\tnumber of nights\ttotal cost\n";
            for (auto i = hotel.begin(); i != hotel.end(); i++) {
                cout << i->first << "\t" << i->second.name << "\t" << i->second.kind << "\t" << i->second.numR << "\t" << i->second.numN << "\t" << i->second.totcost << "\n";
            }
            cout << "\n\n\n\n";
            continue;   
        }
                                                            //introducing the several services for the user to choose from them
        cout << "what kind of service would like to have? [ 1)new reservation - 2)extend reservation - 3)additional services - 4)cancel reservation ]" << "\n";
        int servs;
        cin >> servs ;
        int  availableRooms = 0;
        switch (servs) {
        case 1 : 
            cout << "new resevation it is! " << "how many rooms would you like to reserve? ";
            int numR;
            cin >> numR;
            
            
            if (itr->second.kind == "human") {                      //checking for free rooms 
                availableRooms = h.getrooms();
                if (numR <= availableRooms) {
                    int numN;
                    cout << "and for how many nights?";
                    cin >> numN;
                    h.setrooms(numR);
                    itr->second.numR = numR;
                    itr->second.numN = numN;
                    itr->second.totcost = h.getcost(numR, numN);
                    cout << "it will cost: " << h.getcost(numR, numN)<< "\n";
                    cout << "Thank you!\n";
                }
                else {
                    cout << "sorry it can not be done, the number of rooms you desire exceeds the available ones, sir.\n";
                }
            }
            else if (itr->second.kind == "monster") {
                availableRooms = m.getrooms();

                if (numR <= availableRooms) {
                    int numN;
                    cout << "and for how many nights?";
                    cin >> numN;
                    m.setrooms(numR);
                    itr->second.numR = numR;
                    itr->second.numN = numN;
                    itr->second.totcost = m.getcost(numR, numN);
                    cout << "it will cost: " << m.getcost(numR, numN)<< "\n";
                    cout << "Thank you!\n";
                }
                else {
                    cout << "sorry it can not be done, the number of rooms you desire exceeds the available ones, sir.\n";
                }
            }
            break; 
        case 2 :
            cout << "extend resevation it is! " << "how many extra nights would you like to extend? ";
            int extnights;
            cin >> extnights;
            if (itr->second.kind == "human") {
                cout << "it will cost: " << h.extend(numR,itr->second.numR) << "\nthank you!\n";
            }
            else if (itr->second.kind == "monster") {
                cout << "it will cost: " << m.extend(numR, itr->second.numR) << "\nthank you!\n";
                }
            break;
        case 3 :
            cout << "additional services it is! " << "what service would you like to choose? (Dry cleaning - Spa)\n";
            getline(cin, ss);
            if (ss == "dry cleaning") {
                if (itr->second.kind == "human"){
                    cout << "it will cost: " << h.drycleancost() << "\n";
                }
                else if (itr->second.kind == "monster") {
                   cout <<"it will cost: " << m.drycleancost()<< "\n";
                }
            }
            else if (ss == "spa") {
                if (itr->second.kind == "human") {
                   cout << "it will cost: " << h.spacost()<< "\n";
                }
                else if (itr->second.kind == "monster") {
                   cout << "it will cost: " <<  m.spacost() << "\n";
                }
            }
            break;
        case 4 :
            cout << "cancel resevation it is!\t" << "are you sure you want to cancel the whole reservation ? (yes/no) \n";
            string ans;
            cin >> ans;
            if (ans == "yes") {
                if (itr->second.kind == "human") {
                    h.makeAvailable(itr->second.numR);
                }
                else if (itr->second.kind == "monster") {
                    m.makeAvailable(itr->second.numR);
                }
            }
            else if (ans == "no") {
                cout << "you are all set.\n";
                cout << "\n\n\n\n";
                continue;
            }
            break;
        }
        getline(cin, ss);


    }

}
