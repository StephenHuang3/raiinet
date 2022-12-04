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

    // set number of abilities players have
    int numabilities = 5;

    //creates mapcontroller and board

    Board* theBrd = new Blank;

    Mapcontroller theMap{theBrd};

    //adds observers
    std::vector<Observer*> observers;
    textObserver *obs1 = new textObserver{&theMap};
    observers.emplace_back(obs1);


    // creates player 1
    Player* p1 = new Player{};
    // creates player2
    Player* p2 = new Player{};

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
        if(argv[i] == "graphical") {
            graphicObserver *obs2 = new graphicObserver{theMap.board()};
            observers.emplace_back(obs2);
        } else if (argv[i] == "ability1") {
            string abilityorder = argv[i + 1];
            for(int i = 0; i < numabilities; ++i) {
                p1->setAbility(abilityorder[i], i);
            }
            ++i;
        } else if (argv[i] == "ability2") {
            string abilityorder = argv[i + 1];
            for(int i = 0; i < numabilities; ++i) {
                p2->setAbility(abilityorder[i], i);
            }
            ++i;
        } else if (argv[i] == "link1") {
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
        } else if (argv[i] == "link2") {
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
        theMap.randomize(1);
    }
    if( !linked2 ) {
        theMap.randomize(2);
    }

/*
    if (posOfString(argv[], "graphical") != -1){
        graphicObserver *obs 2 = new graphicObserver{&theMap};
        observers.emplace_back(obs2);
    }
    //creates the player 1
    Player &p1 = theBrd->getPlayer1();
    if (posOfString(argv[], "ability1", argc) == -1){
        string abilityorder = "LFDSPLFDSPLFDSP";
        for(int i = 0; i < numabilities; i++){
            p1.setAbility(abilityorder[i], i);
        }
    } else {
        string abilityorder = argv[posOfString(argv[], "ability1", argc) + 1];
        for(int i = 0; i < numabilities; i++){
            p1.setAbility(abilityorder[i], i);
        }
    }
    if (posOfString(argv[], "link1", argc) != -1){
        ifstream MyReadFile(argv[posOfString(argv, "link1", argc) + 1]);
        string linkvalues;
        getline(myReadFile, linkvalues);
        stringstream ss(linkvalues);
        string singleLink;
        for(int i = 0; i < 8; i++){
            ss >> singleLink;
            string kind;
            int position;
            if (singleLink[0] == 'V'){
                kind = "virus";
            } else {
                kind = "data";
            }
            if (i == 4 || i == 5){
                position = i + 8;
            } else {
                position = i;
            }
            theBrd.setLink(1, char(97 + i), kind, singleLink[1] - '0', position);
        }
        MyReadFile.close();
    } else { //randomize values
    }
    if ((posOfString(argv[], "link2") != 0) && (posOfString(argv[], "ability2") != -1)){
    } else if (posOfString(argv[], "link2") != -1){
    } else if (posOfString(argv[], "ability2") != -1){
    //creates player 2
    Player &p2 = theBrd->getPlayer2();
    if (posOfString(argv[], "ability2", argc) == -1){
        string abilityorder = "LFDSPLFDSPLFDSP";
        for(int i = 0; i < numabilities; i++){
            p2.setAbility(abilityorder[i], i);
        }
    } else {
        string abilityorder = argv[posOfString(argv[], "ability2", argc) + 1];
        for(int i = 0; i < numabilities; i++){
            p2.setAbility(abilityorder[i], i);
        }
    }
    
    if (posOfString(argv[], "link2", argc) != -1){
        ifstream MyReadFile(argv[posOfString(argv[], "link2", argc) + 1]);
        string linkvalues;
        getline(myReadFile, linkvalues);
        stringstream ss(linkvalues);
        string singleLink;
        for(int i = 0; i < 8; i++){
            ss >> singleLink;
            string kind;
            int position;
            if (singleLink[0] == 'V'){
                kind = "virus";
            } else {
                kind = "data";
            }
            if (i == 4 || i == 5){
                position = i + 8;
            } else {
                position = i;
            }
            theBrd.setLink(1, char(97 + i), kind, singleLink[1] - '0', position);
        }
        MyReadFile.close();
    } else { //randomize values
    }
*/
    int playerTurn = -1;
    bool errorfree = true;
    bool readfile = false;
    bool usedAbility = false;
    string command;

    // render board for player 1 before game
    theMap.render(0);

    while( cin >> command ) {
        ++playerTurn;
        theMap.render(playerTurn % 2);
        cout << "Enter a command: \n";
        // render map before move

        if( command == "move" ) {
            char id;
            std::string dir;
            cin >> id >> dir;
            try {
                theMap.moveLink(playerTurn, id, dir);
            }
            catch (1) {
                cout << "That link is already downloaded." << endl;
                continue;
            }
            catch (2) {
                cout << "The link will go out of bounds." << endl;
                continue;
            }
            catch (3) {
                cout << "You cannot move links onto your own links." << endl;
                continue;
            }
            catch (4) {
                cout << "You cannot move links onto your own server ports." << endl;
                continue;
            }
            catch (...) {
                cout << "Default Exception" << endl;
                continue;
            }
            // change playerTurn
            playerTurn = !playerTurn;
        } else if ( command == "abilities" ) {
            // display abilities
            if(playerTurn%2 == 0) {
                for(int i = 0; i < numabilities; i++){
                    cout << p1->checkAvailable(i);
                }
            } else if (playerTurn%2 == 1) {
                for(int i = 0; i < numabilities; i++){
                    cout << p2->checkAvailable(i);
                }
            }
        } else if ( command == "ability" ) {
            int id;
            cin >> id;
            char link = ' ';
            int x = 0;
            int y = 0;
            if( theBrd->getPlayer(playerTurn%2).operator*().getAbility(id)->checkInput() == 'l') {
                cin >> link;
            } else {
                cin >> x >> y;
                theBrd = new Firewall(theBrd, x + y * 8, playerTurn%2);
            }
            theBrd->getPlayer(1).operator*().useAbility(id, link, x, y);
            // check abilities
        } else if (command == "board" ) {
            // displays the board depending on whose turn it is
            playerTurn--;
            continue;
        } else if (command == "sequence" ) {
            string fileName;
            cin >> fileName;
            ifstream f(fileName);
            string fLine;
            while(getline(f, fLine)) {
                stringstream ss(fLine);
                string word;
                while(ss >> word) {
                    if( command == "move" ) {
                        char id, d;
                        cin >> id >> d;
                        // function
                    } else if ( command == "abilities" ) {
                        // display abilities
                    } else if ( command == "ability" ) {
                        int id;
                        cin >> id;
                        // check abilities
                    } else if (command == "board" ) {
                        // displays the board depending on whose turn it is
                        theMap.render(playerTurn);

                        //
                    } else if (command == "quit") break;
                }
            }
        } else if (command == "quit") break;
    }

/*        
    ifstream myReadFile;

    while(true){
        if (!readfile){
            cin >> command;
            if (cin.fail()) break;
        } else {
            getline(myReadFile, command);
            if (myReadFile.fail()){
                readfile = false;
                myReadFile.close();
                continue;
            }
        }
        if (command == "sequence"){
            string file;
            cin >> file;
            myReadFile(argv[posOfString(argv[], file, argc)]);
        } else if(command == "move"){
            cout << "move" << endl;
        } else if(command == "abilities"){
            cout << "abilities" << endl;
        } else if(command == "ability"){
            cout << "ability" << endl;
        } else if(command == "board"){
            cout << "board" << endl;
        } else if(command == "quit"){
            cout << "quit" << endl;
            break;
        }
    } // command loop
*/

}