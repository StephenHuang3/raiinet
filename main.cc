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

    //creates mapcontroller and board
    Board* theBrd = new Blank;
    Mapcontroller theMap{theBrd};
    // bring player 1 and player 2 into main
    shared_ptr<Player> p1 = theMap.board()->getPlayer(0);
    shared_ptr<Player> p2 = theMap.board()->getPlayer(1);
    //adds observers
    std::vector<Observer*> observers;
    textObserver *obs1 = new textObserver{&theMap};
    observers.emplace_back(obs1);
    //add serverport decorators
    theMap.board() = new Serverport{theMap.board(), 3, 0};
    // cout << "after 1 serverport, board ptr: " << theMap.board() << endl;
    theMap.board() = new Serverport{theMap.board(), 4, 0};
    // cout << "after 2 serverport, board ptr: " << theMap.board() << endl;
    theMap.board() = new Serverport{theMap.board(), 59, 1};
    // cout << "after 3 serverport, board ptr: " << theMap.board() << endl;
    theMap.board() = new Serverport{theMap.board(), 60, 1};
    // cout << "after 4 serverport, board ptr: " << theMap.board() << endl;

    //add display link decorator
    theMap.board() = new DisplayLinks{theMap.board()};

    // for checking linked files
    bool linked1 = false;
    bool linked2 = false;
    bool ability1 = false;
    bool ability2 = false;

    for(int i = 0; i < argc; ++i) {
        string param (argv[i]); // This should fix the compilation error of comparison of string literals
        if(param == "-graphics") {
            graphicObserver *obs2 = new graphicObserver{&theMap};
            observers.emplace_back(obs2);
        } else if (param == "-ability1") {
            string abilityorder = argv[i + 1];
            for(int i = 0; i < numabilities; ++i) {
                theMap.board()->getPlayer(0)->setAbility(abilityorder[i], i);
            }
            ability1 = true;
            ++i;
        } else if (param == "-ability2") {
            string abilityorder = argv[i + 1];
            for(int i = 0; i < numabilities; ++i) {
                theMap.board()->getPlayer(1)->setAbility(abilityorder[i], i);
            }
            ability2 = true;
            ++i;
        } else if (param == "-link1") {
            ifstream myReadFile(argv[i + 1]);
            string linkvalues;
            getline(myReadFile, linkvalues);
            stringstream ss(linkvalues);
            string singleLink;
            for(int i = 0; i < 8; i++){
                ss >> singleLink;
                int position;
                if (i == 3 || i == 4){
                    position = i + 8;
                } else {
                    position = i;
                }
                theMap.board()->setLink(0, (char)(97 + i), singleLink[0], singleLink[1] - '0', position);
            }
            myReadFile.close();
            ++i;
            // letting the rest of the program know that player 1 has a link file attached
            linked1 = true;
        } else if (param == "-link2") {
            
            ifstream myReadFile(argv[i + 1]);
            string linkvalues;
            getline(myReadFile, linkvalues);
            stringstream ss(linkvalues);
            string singleLink;
            for(int i = 0; i < 8; i++){
                ss >> singleLink;
                int position;
                if (i == 3 || i == 4){
                    position = i + 56 - 8;
                } else {
                    position = i + 56;
                }
                
                theMap.board()->setLink(1, char(65 + i), singleLink[0], singleLink[1] - '0', position);
                }
            myReadFile.close();
            ++i;
            // letting the rest of the program know that player 2 has a link file attached
            linked2 = true;
        }
    };
    // cout << theMap.board() << endl;
    if( !linked1 ) {
        theMap.randomize(0);
    }
    if( !linked2 ) {
        theMap.randomize(1);
    }
    if (!ability1){
        theMap.board()->getPlayer(0)->setAbility('L', 0);
        theMap.board()->getPlayer(0)->setAbility('F', 1);
        theMap.board()->getPlayer(0)->setAbility('D', 2);
        theMap.board()->getPlayer(0)->setAbility('S', 3);
        theMap.board()->getPlayer(0)->setAbility('P', 4);
    }
    if(!ability2){
        theMap.board()->getPlayer(1)->setAbility('L', 0);
        theMap.board()->getPlayer(1)->setAbility('F', 1);
        theMap.board()->getPlayer(1)->setAbility('D', 2);
        theMap.board()->getPlayer(1)->setAbility('S', 3);
        theMap.board()->getPlayer(1)->setAbility('P', 4);
    }

    int playerTurn = 0;
    bool usedability = false;
    // bool errorfree = true;
    // bool readfile = false;
    string command;
    // for(int i = 0; i < 64; i++){
    //     try{
    //         int count = theMap.board()->getLink(i).use_count();
    //         cout << "link at " << i << ": " << count << endl;
    //     } catch (...){
    //         cout << "link at " << i << ": " << "failed" << endl;
    //     }
    // }

    // render board for player 1 before game
    theMap.render(0, 0);
    cout << "Enter a command: \n";
    while( cin >> command ) {
        if( command == "move" ) {
            char id;
            std::string dir;
            cin >> id >> dir;
            try {
                theMap.moveLink(playerTurn, id, dir);
            }
            catch (char const* err) {
                cerr << err << endl;
                --playerTurn;
            }
        } else if ( command == "abilities" ) {
            // display abilities

            if(playerTurn%2 == 0) {
                for(int i = 0; i < numabilities; i++){
                    cout << "Position "<< i + 1<< ": " <<theMap.board()->getPlayer(0)->checkAvailable(i) << endl;
                }
            } else { // player 2
                for(int i = 0; i < numabilities; i++){
                    cout << "Position "<< i + 1 << ": " <<theMap.board()->getPlayer(1)->checkAvailable(i) << endl;
                }
            }
        } else if ( command == "ability" ) {
            if (usedability){
                char filler[256];
                std::cin.getline(filler, 256);
                cout << "You already used an ability. move a piece to end your turn.";
            } else {
                int idx;
                char link = ' ';
                int x = 0;
                int y = 0;
                cin >> idx;
                --idx;
                shared_ptr<Player> currentP = theMap.board()->getPlayer(playerTurn%2);
                if(currentP->abilityStatusAtPos(idx)) {
                    cout << "Ability has already been used." << endl;
                } else {
                    char c = currentP->getAbility(idx)->checkInput();
                    if ( c == 'l') {
                        cin >> link;
                        try {
                            p1->getAbility(idx)->activate(currentP, theMap.board()->findLink(link), playerTurn);
                            usedability = true;
                        } catch(char const* err) {
                            cerr << err;
                        }
                    } else if (c == 'f' ) {
                        cin >> x >> y;
                          if( x < 0 || y < 0 || x > 7 || y > 7) {
                            cerr << "Uh oh, you don't want to add fuel to fire." << endl;
                            cout << "That's out of bounds!" << endl;
                            continue;
                          } else {
                            theMap.board() = new FirewallTile(theMap.board(), x + 8 * y, (playerTurn % 2) + 1);
                            theMap.board() = new DisplayLinks{theMap.board()};
                          }
                        usedability = true;
                    } else if (c == 't'){
                        cin >> link >> x >> y;
                        if(x < 0 || x > 7 || y < 0 || y > 7){
                            cout << "must be on a square in range" << endl;
                            continue;
                        }
                        else if (theMap.getTile(x + y * 8) != '.'){
                            cout << "Must move onto empty square" << endl;
                            continue;
                        } else {
                            theMap.board()->moveLink(theMap.board()->findLink(link)->getPos(),x + y * 8);
                            theMap.board()->findLink(link)->changePos(x + y * 8);
                            usedability = true;
                            
                        }
                    }
                    currentP->setUsed(idx);
                }
            }
        } else if (command == "board" ) {
            theMap.render(playerTurn, 0);
        } else if (command == "sequence" ) {
            string fileName;
            cin >> fileName;
            ifstream f(fileName);
            string fLine;
            while(getline(f, fLine)) {
                stringstream ss(fLine);
                string word;
                while(ss >> word) {
                    if( word == "move" ) {
                        char id;
                        std::string dir;
                        ss >> id >> dir;
                        try {
                            theMap.moveLink(playerTurn, id, dir);
                        }
                        catch (char const* err) {
                            cerr << err << endl;
                            --playerTurn;
                        }
                    } else if ( word == "abilities" ) {
                        // display abilities
                        if(playerTurn%2 == 0) {
                            for(int i = 0; i < numabilities; i++){
                                cout << "Position "<< i + 1<< ": " <<theMap.board()->getPlayer(0)->checkAvailable(i) << endl;
                            }
                        } else { // player 2
                            for(int i = 0; i < numabilities; i++){
                                cout << "Position "<< i + 1 << ": " <<theMap.board()->getPlayer(1)->checkAvailable(i) << endl;
                            }
                        }
                    } else if ( word == "ability" ) {
                        if (usedability) {
                            char filler[256];
                            ss.getline(filler, 256);
                            cout << "You already used an ability. move a piece to end your turn.";
                        } else {
                            int idx;
                            char link = ' ';
                            int x = 0;
                            int y = 0;
                            ss >> idx;
                            --idx;
                            shared_ptr<Player> currentP = theMap.board()->getPlayer(playerTurn%2);
                            if(currentP->abilityStatusAtPos(idx)) {
                                cout << "Ability has already been used." << endl;
                            } else {
                                char c = currentP->getAbility(idx)->checkInput();
                                if ( c == 'l') {
                                    ss >> link;
                                    try {
                                        p1->getAbility(idx)->activate(currentP, theMap.board()->findLink(link), playerTurn);
                                        usedability = true;
                                    } catch(char const* err) {
                                        cerr << err;
                                    }
                                } else if (c == 'f' ) {
                                    ss >> x >> y;
                                    theMap.board() = new FirewallTile(theMap.board(), x + 8 * y, (playerTurn % 2) + 1);
                                    theMap.board() = new DisplayLinks{theMap.board()};
                                    usedability = true;
                                } else if (c == 't'){
                                    ss >> link >> x >> y;
                                    if((x + y * 8) > 63 || (x + y * 8) < 0 || x < 0 || x > 8 || y < 0){
                                        cout << "must be on a square in range" << endl;
                                        continue;
                                    }
                                    else if (theMap.getTile(x + y * 8) != '.'){
                                        cout << "Must move onto empty square" << endl;
                                        continue;
                                    } else {
                                        theMap.board()->moveLink(theMap.board()->findLink(link)->getPos(),x + y * 8);
                                        theMap.board()->findLink(link)->changePos(x + y * 8);
                                        usedability = true;
                                        
                                    }
                                }
                                p1->setUsed(idx);
                            }
                        }
                    } else if (word == "link") {
                        char c;
                        cin >> c;
                        shared_ptr<Link> l = theMap.board()->getPlayer(0)->getLinks().at(c);
                        cout << c << l->getType() << ": " << l->getPos() << endl;
                        cout << "is downloaded: " << l->getDownloaded() << endl;
                    } else if (word == "position") {
                        int position;
                        cin >> position;
                        cout << "at position " << position << " the tile is " << theMap.board()->getTile(position) << endl;
                        cout << endl;
                    } else if (word == "board" ) {
                        theMap.render(playerTurn, 0);
                    } else if (word == "quit") {
                        break;
                    }
                }
            }

        } else if (command == "quit") {
            break;
        } else {
            char filler[256];
            cin.getline(filler, 256);
            cerr << "invalid command try again";
        }

        if( p1->checkScore() == 'w' || p2->checkScore() == 'l') {
            break;
        }

        if( p2->checkScore() == 'w' || p1->checkScore() == 'l') {
            break;
        }
        cout << endl;
        if(command == "move") {
            ++playerTurn;
            theMap.render(playerTurn, 0);
            usedability = false;
        }
        cout << "Enter a command: \n";
    }

    //print who won
    if (theMap.board()->getPlayer(0)->checkScore() == 'w'){
        theMap.render(0, 1);
        cout << "Player 1 has won!" << endl;
    } else if (theMap.board()->getPlayer(0)->checkScore() == 'l') {
        theMap.render(0, 2);
        cout << "Player 2 has won!" << endl;
    } else if (theMap.board()->getPlayer(1)->checkScore() == 'w'){
        theMap.render(0, 2);
        cout << "Player 2 has won!" << endl;
    } else if (theMap.board()->getPlayer(1)->checkScore() == 'l'){
        theMap.render(0, 1);
        cout << "Player 1 has won!" << endl;
    } else {
        cout << "Game unfinished" << endl;
    }
    int size = observers.size();
    for (int i = 0; i < size; ++i) {
        delete observers[i];
    }
}
