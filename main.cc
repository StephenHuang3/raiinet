#include "ability.h"
#include "blank.h"
#include "board.h"
#include "decorator.h"
#include "mapcontroller.h"
#include "observer.h"
#include "link.h"
#include "player.h"
#include "subject.h"

#include <vector>
#include <memory>
#include <string>
#include <iostream>
#include <map>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
    srand(time(0));

    // set number of abilities players have
    int numabilities = 5;

    // // creates player 1
    // Player* p1 = new Player{};
    // // creates player2
    // Player* p2 = new Player{};

    //creates mapcontroller and board
    Board* theBrd = new Blank;
    // creates player 1 and player 2
    shared_ptr<Player> p1 = theBrd->getPlayer(0);
    shared_ptr<Player> p2 = theBrd->getPlayer(1);

    Mapcontroller theMap{theBrd};

    //adds observers
    std::vector<Observer*> observers;
    textObserver *obs1 = new textObserver{&theMap};
    observers.emplace_back(obs1);

    //add serverport decorators
    theBrd = new Serverport{theBrd, 3, 0};
    theMap.board() = theBrd;

    theBrd = new Serverport{theBrd, 4, 0};
    theMap.board() = theBrd;

    theBrd = new Serverport{theBrd, 59, 1};
    theMap.board() = theBrd;

    theBrd = new Serverport{theBrd, 60, 1};
    theMap.board() = theBrd;

    //add display link decorator

    theBrd = new DisplayLinks{theBrd};
    theMap.board() = theBrd;

    // for checking linked files
    bool linked1 = false;
    bool linked2 = false;

    for(int i = 0; i < argc; ++i) {
        string param(argv[i]); // This should fix the compilation error of comparison of string literals
        if(param == "graphical") {
            // graphicObserver *obs2 = new graphicObserver{&theMap};
            // observers.emplace_back(obs2);
        } else if (param == "ability1") {
            string abilityorder = argv[i + 1];
            for(int i = 0; i < numabilities; ++i) {
                p1.operator*().setAbility(abilityorder[i], i);
            }
            ++i;
        } else if (param == "ability2") {
            string abilityorder = argv[i + 1];
            for(int i = 0; i < numabilities; ++i) {
                p2.operator*().setAbility(abilityorder[i], i);
            }
            ++i;
        } else if (param == "link1") {
            ifstream myReadFile(argv[i + 1]);
            string linkvalues;
            getline(myReadFile, linkvalues);
            stringstream ss(linkvalues);
            string singleLink;
            for(int i = 0; i < 8; i++){
                ss >> singleLink;
                int position;
                if (i == 4 || i == 5){
                    position = i + 8;
                } else {
                    position = i;
                }
                theBrd->setLink(1, char(97 + i), singleLink[0], singleLink[1] - '0', position);
            }
            myReadFile.close();
            ++i;
            // letting the rest of the program know that player 1 has a link file attached
            linked1 = true;
        } else if (param == "link2") {
            ifstream myReadFile(argv[i + 1]);
            string linkvalues;
            getline(myReadFile, linkvalues);
            stringstream ss(linkvalues);
            string singleLink;
            for(int i = 0; i < 8; i++){
                ss >> singleLink;
                int position;
                if (i == 4 || i == 5){
                    position = i + 57 - 8;
                } else {
                    position = i + 57;
                }
                theBrd->setLink(2, char(65 + i), singleLink[0], singleLink[1] - '0', position);
                }
            myReadFile.close();
            ++i;
            // letting the rest of the program know that player 2 has a link file attached
            linked2 = true;
        }
    };

    if( !linked1 ) {
        theMap.randomize(0);
    }
    if( !linked2 ) {
        theMap.randomize(1);
    }

    int playerTurn = -1;
    // bool errorfree = true;
    // bool readfile = false;
    // bool usedAbility = false;
    string command;
    for(int i = 0; i < 64; i++){
        try{
            int count = theBrd->getLink(i).use_count();
            cout << "link at " << i << ": " << count << endl;
        } catch (...){
            cout << "link at " << i << ": " << "failed" << endl;
        }
    }

    // render board for player 1 before game
    theMap.render(0);
    cout << "Enter a command: \n";
    while( cin >> command ) {
        ++playerTurn;
        // render map before move

        if( command == "move" ) {
            char id;
            std::string dir;
            cin >> id >> dir;
            try {
                theMap.moveLink(playerTurn%2, id, dir);
            }
            catch (int errNum) {
                if (errNum == 1) {
                    cout << "That link is already downloaded." << endl;
                } else if (errNum == 2) {
                    cout << "The link will go out of bounds." << endl;
                } else if (errNum == 3) {
                    cout << "You cannot move links onto your own links." << endl;
                } else if (errNum == 4) {
                    cout << "You cannot move links onto your own server ports." << endl;
                } else {
                    cout << "Default Exception - you're doing something weird.." << endl;
                }
                --playerTurn;
            }
        // } else if ( command == "abilities" ) {
        //     // display abilities
        //     if(playerTurn%2 == 0) {
        //         for(int i = 0; i < numabilities; i++){
        //             cout << p1.operator*().checkAvailable(i);
        //         }
        //     } else if (playerTurn%2 == 1) {
        //         for(int i = 0; i < numabilities; i++){
        //             cout << p2.operator*().checkAvailable(i);
        //         }
        //     }
        // } else if ( command == "ability" ) {
        //     int id;
        //     cin >> id;
        //     char link = ' ';
        //     int x = 0;
        //     int y = 0;
        //     if( theBrd->getPlayer(playerTurn%2).operator*().getAbility(id)->checkInput() == 'l') {
        //         cin >> link;
        //     } else {
        //         cin >> x >> y;
        //         theBrd = new FirewallTile(theBrd, x + y * 8, playerTurn % 2);
        //     }
        //     theBrd->getPlayer(playerTurn%2).operator*().useAbility(id, link, x, y);
        //     // check abilities
        // } else if (command == "board" ) {
        //     // displays the board depending on whose turn it is
        //     playerTurn--;
        //     continue;
        // } else if (command == "sequence" ) {
        //     string fileName;
        //     cin >> fileName;
        //     ifstream f(fileName);
        //     string fLine;
        //     while(getline(f, fLine)) {
        //         stringstream ss(fLine);
        //         string word;
        //         while(ss >> word) {
        //             if( command == "move" ) {
        //                 char id;
        //                 std::string dir;
        //                 cin >> id >> dir;
        //                 try {
        //                     theMap.moveLink(playerTurn, id, dir);
        //                 }
        //                 catch (int errNum) {
        //                     if (errNum == 1) {
        //                         cout << "That link is already downloaded." << endl;
        //                     } else if (errNum == 2) {
        //                         cout << "The link will go out of bounds." << endl;
        //                     } else if (errNum == 3) {
        //                         cout << "You cannot move links onto your own links." << endl;
        //                     } else if (errNum == 4) {
        //                         cout << "You cannot move links onto your own server ports." << endl;
        //                     } else {
        //                         cout << "Default Exception - you're doing something weird.." << endl;
        //                     }
        //                     continue; // without changing turns
        //                 }
            //         } else if ( command == "abilities" ) {
            //             if(playerTurn%2 == 0) {
            //                 for(int i = 0; i < numabilities; i++){
            //                     cout << p1.operator*().checkAvailable(i);
            //                 }
            //             } else if (playerTurn%2 == 1) {
            //                 for(int i = 0; i < numabilities; i++){
            //                     cout << p2.operator*().checkAvailable(i);
            //                 }
            //             }
            //         } else if ( command == "ability" ) {
            //             int id;
            //             cin >> id;
            //             char link = ' ';
            //             int x = 0;
            //             int y = 0;
            //             if( theBrd->getPlayer(playerTurn%2).operator*().getAbility(id)->checkInput() == 'l') {
            //                 cin >> link;
            //             } else {
            //                 cin >> x >> y;
            //                 theBrd = new FirewallTile(theBrd, x + y * 8, playerTurn % 2);
            //             }
            //             theBrd->getPlayer(playerTurn%2).operator*().useAbility(id, link, x, y);
            //         } else if (command == "board" ) {
            //             // displays the board depending on whose turn it is
            //             theMap.render(playerTurn%2);

            //             //
            //         } else if (command == "quit") break;
            //     }
            // }
        } else if (command == "quit") break;

        if( theBrd->getPlayer(playerTurn%2).operator*().checkScore() == 'w' || theBrd->getPlayer(playerTurn%2).operator*().checkScore() == 'l') {
            break;
        }
        cout << endl;
        theMap.render(playerTurn % 2);
        cout << "Enter a command: \n";
    }
    int size = observers.size();
    for (int i = 0; i < size; ++i) {
        delete observers[i];
    }
}
