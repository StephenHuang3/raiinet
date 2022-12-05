} else if (command == "quit") {
            break;
        } else {
            cout << "invalid command try again";
        }

        if( theMap.board()->getPlayer(playerTurn%2).operator*().checkScore() == 'w' || 
            theMap.board()->getPlayer(playerTurn%2).operator*().checkScore() == 'l') {
                break;
        }

        if( theMap.board()->getPlayer((1 + playerTurn) % 2).operator*().checkScore() == 'w' || 
            theMap.board()->getPlayer((1 + playerTurn) % 2).operator*().checkScore() == 'l') {
                break;
        }
        cout << endl;
        
        if(command == "move"){
            ++playerTurn;
            usedability = false;
        }
    
        theMap.render(playerTurn % 2);
        cout << "Enter a command: \n";
    }

    //print who won
    if (theMap.board()->getPlayer(0).operator*().checkScore() == 'w'){
        cout << "Player 1 has won!" << endl;
    } else if (theMap.board()->getPlayer(0).operator*().checkScore() == 'l') {
        cout << "Player 2 has won!" << endl;
    } else if (theMap.board()->getPlayer(1).operator*().checkScore() == 'w'){
        cout << "Player 2 has won!" << endl;
    } else if (theMap.board()->getPlayer(1).operator*().checkScore() == 'l'){
        cout << "Player 1 has won!" << endl;
    } else {
        cout << "Game unfinished" << endl;
    }

    } else if ( command == "ability" ) {
            if (usedability){
                cout << "You already used an ability. move a piece to end your turn.";
            } else {
                int id;
                cin >> id;
                char link = ' ';
                int x = 0;
                int y = 0;
                if( theBrd->getPlayer(playerTurn%2).operator*().getAbility(id)->checkInput() == 'l') {
                    cin >> link;
                } else {
                    cin >> x >> y;
                    theMap.board() = new FirewallTile(theMap.board(), x + y * 8, playerTurn % 2);
                }
                theMap.board()->getPlayer(playerTurn%2).operator*().useAbility(id, link, x, y);
                // check abilities
                usedability = true;
            }
        }