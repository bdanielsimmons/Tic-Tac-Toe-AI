#ifndef BOARD_H
#define BOARD_H
#include <iostream>

using namespace std;

class GBoard{
	private:
	public:
	    GBoard();
        char board[3][3];
	    char player1;
	    char cpu;
		static void initalize_board (char board[3][3]) {
		    for (int i = 0; i < 3; i++) {
		        for (int j = 0; j < 3; j++) {
		            board[i][j] = '.';
		        }
		    }
		}

		static void print_board(char board[3][3]) {

		    for (int i = 0; i < 3; i++) {
		        cout << endl;
		        for (int j = 0; j < 3; j++) {
		            if(j == 0 && i == 0){
                        cout << "-  1  2  3" << endl;
                        cout << 'A';
		            }
                    if (j == 0 && i == 1)
                        cout << 'B';
                    if (j == 0 && i == 2)
                        cout << 'C';
		            cout << "  ";
		            cout << board[i][j];
		        }
		    }
		    cout << endl << endl;
		}
		static char check_win(char board[3][3]) {

			 	int i;
			    for (i=0;i<3;i++)
			    {
			        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != '.')
			        {
			            return(board[i][0]);
			        }

			        if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != '.')
			        {
			            return(board[0][i]);
			        }
			    }

			    if(board[0][0] == board[1][1] && board [0][0] == board [2][2] && board[0][0] != '.')
			    {
			        return(board[0][0]);
			    }
			    if(board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[2][0] != '.')
			    {
			        return(board[2][0]);
			    }
			    else{
                    return '.';
			    }

			}
};

class AI {
	private:
	public:
		static int pick_best_move(GBoard game, char board[3][3], char player1, char player2) {
		    int best_move_score = -5000;
		    int best_move_row = -5000;
		    int best_move_col = -5000;
		    int move_score = 0;

		    for (int r = 0; r < 3; r++) {
		        for (int c = 0; c < 3; c++) {
		            if (board[r][c] == '.') {
		                board[r][c] = player1;
		                move_score = -(negamax(game, board, player2, player1));
		                board[r][c] = '.';
		                if (move_score >= best_move_score) {
		                    best_move_score = move_score;
		                    best_move_row = r;
		                    best_move_col = c;
		                }
		            }
		        }
		    }
		    return (10*best_move_row + best_move_col);
		}

		static int negamax(GBoard game, char board[3][3], char player1, char player2) {

		    int best_move_score = -5000;
		    int best_score = 0;

		    if (game.check_win(board) == player1)
		        return 1000;

		    else if (game.check_win(board) == player2)
		        return -1000;

		    for (int r = 0; r < 3; r++) {
		        for (int c = 0; c < 3; c++) {
		            if (board[r][c] == '.') {
		                board[r][c] = player1;
		                best_score = -(negamax(game, board, player2, player1));
		                board[r][c] = '.';
		                if (best_score >= best_move_score) {
		                    best_move_score = best_score;
		                }
		            }
		        }
		    }

		    if (best_move_score == -5000 || best_move_score == 0)
		        return 0;

		    else if (best_move_score < 0)
		        return best_move_score + 1;

		    else if (best_move_score > 0)
		        return best_move_score - 1;

		}
};

class Players {
    public:
    AI comp;
    GBoard game;
	static void player_placement(char board[3][3], char player) {
    while (true) {
        string gRow;
        int row = 0, col = 0;
        while (1) {
            cout << "Where would you like to play?\nEnter your desired location: ";
            cin >> gRow;
            if(gRow == "A1" || gRow == "a1"){
                row = 1;
                col = 1;
                break;
            }
            else if(gRow == "A2" || gRow == "a2"){
                row = 1;
                col = 2;
                break;
            }
            else if(gRow == "A3" || gRow == "a3"){
                row = 1;
                col = 3;
                break;
            }
            else if(gRow == "B1" || gRow == "b1"){
                row = 2;
                col = 1;
                break;
            }
            else if(gRow == "B2" || gRow == "b2"){
                row = 2;
                col = 2;
                break;
            }
            else if(gRow == "B3" || gRow == "b3"){
                row = 2;
                col = 3;
                break;
            }
            else if(gRow == "C1" || gRow == "c1"){
                row = 3;
                col = 1;
                break;
            }
            else if(gRow == "C2" || gRow == "c2"){
                row = 3;
                col = 2;
                break;
            }
            else if(gRow == "C3" || gRow == "c3"){
                row = 3;
                col = 3;
                break;
            }
            else{
                cin.clear();
                cout << "Invalid location. Try again.\n";
            }
        }
        if (board[row-1][col-1] == '.') {
            board[row-1][col-1] = player;
            break;
        }
        else
            cout << "This space is occupied." << endl << endl;
   		}
	}

	static char cpu_choice (char player1) {
	    char cpu_char;
	    cout << "Welcome to Tic-Tac-Toe! Make your choices very carefully." << endl;
	    cout << "If you're X, I'm O. If you're O, I'm X." << endl;
	    cout << "By default, I'll be X." << endl << endl;

	    if (player1 == 'x' || player1 == 'X')
	        cpu_char = 'o';

	    else
	        cpu_char = 'x';

	    return cpu_char;
	}

	static char player_choice () {
	    while (true) {
	    	char choice;
	        cout << "Human, what would you like your character to be?\n";
	        cin >> choice;
	        if (choice == 'x' || choice == 'X')
	            return choice;
	        else if(choice == 'o' || choice == 'O')
                return choice;
            else
                cout << "I'm gonna need you to enter an X or an O, buddy.\n\n";
	    }
	}

    void play_game_1_player (GBoard game, char board[3][3], char player1, char cpu, bool oneP) {
	    int moves = 0;
	    if(oneP){
		    while (moves < 9) {
		        player_placement(board, player1);
		        moves++;
		        game.print_board(board);
		        if (game.check_win(board)== player1) {
		            cout << player1 << " won!" <<endl;
		            return;
		        }
		        if (moves == 9)
		            break;
		        int bestmove = comp.pick_best_move(game, board, cpu, player1);
		        int row = bestmove / 10;
		        int col = bestmove % 10;
		        board[row][col] = cpu;
		        moves++;
		        game.print_board(board);
		        if (game.check_win(board) == cpu) {
		            cout << cpu << " won!" <<endl;
		            return;
		        }
		    }
		    cout << "It's a draw. You wouldn't have won, anyway." << endl;
    }
        else{
            while (moves < 9) {
                int bestmove = comp.pick_best_move(game, board, cpu, player1);
		        int row = bestmove / 10;
		        int col = bestmove % 10;
		        board[row][col] = cpu;
		        moves++;
		        game.print_board(board);
		        if (game.check_win(board) == cpu) {
		            cout << cpu << " won!" <<endl;
		            return;
		        }
		        if (moves == 9)
		            break;
                player_placement(board, player1);
		        moves++;
		        game.print_board(board);
		        if (game.check_win(board)== player1) {
		            cout << player1 << " won!" <<endl;
		            return;
		        }
            }
            cout << "It's a draw. You wouldn't have won, anyway." << endl;
        }
    }

};
#endif
