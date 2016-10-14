#include <iostream>
#include <string>
#include <stdlib.h>
#include <Board.h>

using namespace std;

int main() {

    GBoard game;
    Players human;
    char choice;
    bool QUIT = false;
    bool oneP;

    do{
    game.initalize_board(game.board);
    cout << "Would you like to go first?(Y or N)\n";
    cin >> choice;
	    if( choice == 'y' || choice == 'Y')
	        oneP = true;
	    else if( choice == 'n' || choice == 'N')
	        oneP = false;
	    else{
	        cout << "I'm just going to assume that's a yes.\n";
	        oneP = true;
	    }
    game.player1 = human.player_choice();
    game.cpu = human.cpu_choice(game.player1);
    game.print_board(game.board);

    human.play_game_1_player(game, game.board, game.player1, game.cpu, oneP);
    cout << "Wanna play again?(Y or N)\n";
    cin >> choice;
	    if( choice == 'y' || choice == 'Y')
	        continue;
	    else if( choice == 'n' || choice == 'N')
	        QUIT = true;
	    else{
	        cout << "Invalid response. Terminating program.\n";
	        return 0;
	    }
    }while(!QUIT);
    cout << "Thanks for playing. Go ahead and close the program.\n";
    return 0;
}
