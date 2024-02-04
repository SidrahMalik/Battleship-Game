#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iomanip>

using namespace std;

const int SIZE = 10;
const char SPACE = '~';
const char UNDECIDED = '?';
const char STRIKE = 'S';
const char OVERLOOK = 'O';

class Submarine {
private:
	string name;
	int length;
	int rowPosition;
	int columnPosition;
	bool amIHorizontal;
	char boardCharacter;
public:
	Submarine()
	{
		name = "Submarine";
		length = 3;
		boardCharacter = 'S';
	}
	void setPiece(int row, int column, char direction)
	{
		if (direction == 'u')
		{
			rowPosition = row - (length - 1);
			columnPosition = column;
			amIHorizontal = false;
		}
		else if (direction == 'd')
		{
			rowPosition = row;
			columnPosition = column;
			amIHorizontal = false;
		}
		else if (direction == 'l')
		{
			rowPosition = row;
			columnPosition = column - (length - 1);
			amIHorizontal = true;
		}
		else if (direction == 'r')
		{
			rowPosition = row;
			columnPosition = column;
			amIHorizontal = true;
		}
		else
		{
			rowPosition = -1;
			columnPosition = -1;
		}
	}

	bool isHorizontal() const
	{
		return amIHorizontal;
	}

	int getTopLeftRow() const
	{
		return rowPosition;
	}

	int getTopLeftColumn() const
	{
		return columnPosition;
	}

	int getLength() const
	{
		return length;
	}

	string getName() const
	{
		return name;
	}

	char getBoardCharacter() const
	{
		return boardCharacter;
	}
};
void Credit()
{
	cout << " +----------------------------------------------------+" << endl;
	cout << " |               FAST NATIONAL UNIVERSIT               |" << endl;
	cout << " |                  Final Project                      |" << endl;
	cout << " |                Syeda Daniya-9180                    |" << endl;
	cout << " |                Sidra Malik -9179                    |" << endl;
	cout << " +----------------------------------------------------+" << endl;

	cout << "     W e l c o m e   T o   B a t t l e s h i p    " << endl;

	return;
}
void Rules()
{
	cout << "----------------------------------------------------------------------" << endl;
	cout << "Instructions:" << endl;
	cout << "----------------------------------------------------------------------" << endl;
	cout << "This program will let you choose ships from your fleet" << endl;
	cout << "made up of the following vessels: Carrier, Battleship, Sub-" << endl;
	cout << "marine, and Destroyer. It will then let you assign both of" << endl;
	cout << "the vessels to the board that will be oriented by you." << endl;
	cout << " As a player you will then have to sink both of the computer's vessels!" << endl;
	cout << "----------------------------------------------------------------------" << endl;


	return;
}
void Playgame() {
	cout << endl;
	cout << " Player vs Computer" << endl;
	cout << " Difficulty level = Hard  " << endl;

	return;
}

class BattleshipGame {
public:
	BattleshipGame()
	{
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				playerBoard[i][j] = SPACE;
			}
		}

		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				computerBoard[i][j] = UNDECIDED;
			}
		}

		playerSub = Submarine();
		computerSub = Submarine();
	}
	void placePlayerPieces()
	{
		bool correctPlacement;
		do {
			displayBoards();
			correctPlacement = placePiece(playerSub);
			if (!correctPlacement)
			{
				cout <<endl<<"Please enter a valid position and direction"<<endl;
			}
		} while (!correctPlacement);

		addPieceToBoard(playerBoard, playerSub);
	}
	void placeComputerPieces(string s)
	{
		ifstream in;
		if (s != "")
		{
			in.open(s.c_str());
			if (in.fail())
			{
				cout << "Incorrect file, aborting protocol!"<<endl;
				exit(404);
			}
		}

		char tempBoard[SIZE][SIZE];
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				tempBoard[i][j] = SPACE;
			}
		}

		bool correctPlacement;
		do {
			int randColumn, randRow;
			string randDirection;
			if (s == "") 
			{
				randColumn = rand() % SIZE;
				randRow = rand() % SIZE;

				int randDirectionInt = rand() % 4;
				randDirection = "";
				switch (randDirectionInt)
				{
				case 0:
					randDirection = "up";
					break;
				case 1:
					randDirection = "down";
					break;
				case 2:
					randDirection = "left";
					break;
				case 3:
					randDirection = "right";
					break;
				default:
					randDirection = "";
					break;
				}
			}
			else
			{
				if (in.eof())
				{
					cout << "Error, not enough valid ships in file!"<<endl;
					exit(1);
				}

				string type;
				in >> type >> randRow >> randColumn >> randDirection;
			}

			computerSub.setPiece(randRow, randColumn, getFirstChar(randDirection));
			correctPlacement = isValidPlacement(tempBoard, computerSub);
		} while (!correctPlacement);

		addPieceToBoard(tempBoard, computerSub);
		in.close();
	}
	string playerMove()
	{
		int attackRow;
		int attackColumn;
		string coordinate;

		do
		{
			cout << "Which coordinate would you like to bombard?"<<endl;
			coordinate = toLower(requeststring());
			attackRow = rowCharToInt(getFirstChar(coordinate));
			attackColumn = getFirstInt(coordinate) - 1;
		} while ((attackRow < 0 || attackRow > SIZE - 1) || (attackColumn < 0 || attackColumn > SIZE - 1));

		int row = computerSub.getTopLeftRow();
		int column = computerSub.getTopLeftColumn();
		for (int i = 0; i < computerSub.getLength(); i++)
		{
			if (row == attackRow && column == attackColumn)
			{
				computerBoard[attackRow][attackColumn] = STRIKE;
				if (isVanish(computerBoard, computerSub))
				{
					string result = computerSub.getName();
					result += " VANISH at ";
					result += toupper(getFirstChar(coordinate));
					result += ('0' + getFirstInt(coordinate));
					return result;
				}
				string result = "STRIKE at ";
				result += toupper(getFirstChar(coordinate));
				result += ('0' + getFirstInt(coordinate));
				return result;
			}

			if (computerSub.isHorizontal())
			{
				column++;
			}
			else
			{
				row++;
			}
		}

		computerBoard[attackRow][attackColumn] = OVERLOOK;
		string result = "OVERLOOK at ";
		result += toupper(getFirstChar(coordinate));
		result += ('0' + getFirstInt(coordinate));
		return result;
	}
	string computerMove()
	{
		int attackRow = rand() % SIZE;
		int attackColumn = rand() % SIZE;

		string coordinate = "";
		coordinate += (attackRow + 'A');
		coordinate += (attackColumn + '1');

		int row = playerSub.getTopLeftRow();
		int column = playerSub.getTopLeftColumn();
		for (int i = 0; i < playerSub.getLength(); i++)
		{
			if (row == attackRow && column == attackColumn)
			{
				playerBoard[attackRow][attackColumn] = STRIKE;
				if (isVanish(playerBoard, playerSub))
				{
					string result = playerSub.getName();
					result += " VANISH at ";
					result += coordinate;
					return result;
				}
				string result = "STRIKE at ";
				result += coordinate;
				return result;
			}

			if (playerSub.isHorizontal())
			{
				column++;
			}
			else
			{
				row++;
			}
		}

		playerBoard[attackRow][attackColumn] = OVERLOOK;

		string result = "OVERLOOK at ";
		result += coordinate;
		return result;
}
	int gameOver()
	{
		int result = 0;

		int computerShipCoordinateTotal = 0;
		computerShipCoordinateTotal += computerSub.getLength();

		int playerShipCoordinateTotal = 0;
		playerShipCoordinateTotal += playerSub.getLength();


		int playerBoardHitTotal = 0;
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				if (playerBoard[i][j] == STRIKE)
				{
					playerBoardHitTotal++;
				}
			}
		}
		if (playerBoardHitTotal == playerShipCoordinateTotal)
		{
			result += 1;
		}

		int computerBoardHitTotal = 0;
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				if (computerBoard[i][j] == STRIKE)
				{
					computerBoardHitTotal++;
				}
			}
		}
		if (computerBoardHitTotal == computerShipCoordinateTotal)
		{
			result += 2;
		}

		return result;
	}
	void displayBoards()
	{
		displayBoards("", "", playerBoard, computerBoard);
	}
	void displayBoards(string move1, string move2)
	{
		displayBoards(move1, move2, playerBoard, computerBoard);
	}
	void displayBoards(string move1, string move2, char leftBoard[SIZE][SIZE], char rightBoard[SIZE][SIZE])
	{
		cout << "  ";
		for (int i = 0; i < SIZE; i++)
		{
			cout << setw(2) << i + 1 << " ";
		}
		cout << "                    ";
		cout << "   ";
		for (int i = 0; i < SIZE; i++)
		{
			cout << setw(2) << i + 1 << " ";
		}
		cout <<endl;
		for (int i = 0; i < SIZE; i++)
		{
			char row = 'A' + i;
			cout << row << "  ";
			for (int j = 0; j < SIZE; j++)
			{
				cout << leftBoard[i][j] << "  ";
			}
			cout << "                    ";
			cout << row << "  ";
			for (int j = 0; j < SIZE; j++)
			{
				cout << rightBoard[i][j] << "  ";
			}
			cout <<endl;
		}

		if (move1 != "")
		{
			cout << "Your move:"<<endl;
			cout << move1 << endl;
		}
		if (move2 != "")
		{
			cout << "Computer's move:"<<endl;
			cout << move2 << endl;
		}
	}
	int rowCharToInt(char c)
	{
		return c - 'a';
	}


private:
	char playerBoard[SIZE][SIZE];
	char computerBoard[SIZE][SIZE];
	Submarine playerSub;
	Submarine computerSub;
	bool placePiece(Submarine& piece)
	{
		cout << "What coordinate do you want to place the " << toLower(piece.getName()) << " (length " << piece.getLength() << ") at?"<<endl;
		string coordinate = toLower(requeststring());
		cout << "What direction do you want the piece to go? (up, down, left or right)"<<endl;
		string direction = toLower(requeststring());

		piece.setPiece(rowCharToInt(getFirstChar(coordinate)), getFirstInt(coordinate) - 1, getFirstChar(direction));

		return isValidPlacement(playerBoard, piece);
	}
	void addPieceToBoard(char board[SIZE][SIZE], const Submarine& piece)
	{
		int row = piece.getTopLeftRow();
		int column = piece.getTopLeftColumn();

		for (int i = 0; i < piece.getLength(); i++)
		{
			board[row][column] = piece.getBoardCharacter();

			if (piece.isHorizontal())
			{
				column++;
			}
			else
			{
				row++;
			}
		}
	}
	bool isVanish(char board[SIZE][SIZE], const Submarine& piece)
	{
		int row = piece.getTopLeftRow();
		int column = piece.getTopLeftColumn();
		for (int i = 0; i < piece.getLength(); i++)
		{
			if (board[row][column] != STRIKE)
			{
				return false;
			}

			if (piece.isHorizontal())
			{
				column++;
			}
			else
			{
				row++;
			}
		}

		return true;
	}
	bool isValidPlacement(char board[SIZE][SIZE], const Submarine& piece)
	{
		int row = piece.getTopLeftRow();
		int column = piece.getTopLeftColumn();
		if (column < 0 || (column + piece.getLength() - 1 > SIZE - 1 && piece.isHorizontal()))
		{
			return false;
		}
		if (row < 0 || (row + piece.getLength() - 1 > SIZE - 1 && !piece.isHorizontal()))
		{
			return false;
		}
		for (int i = 0; i < piece.getLength(); i++)
		{
			if (board[row][column] != SPACE)
			{
				return false;
			}

			if (piece.isHorizontal())
			{
				column++;
			}
			else
			{
				row++;
			}
		}

		return true;
	}
	string requeststring()
	{
		string temp;
		getline(cin, temp);

		return temp;
	}
	string toLower(string s)
	{
		for (int i = 0; i < static_cast<int>(s.length()); i++)
		{
			s[i] = tolower(s[i]);
		}

		return s;
	}
	char getFirstChar(string temp)
	{
		int i = 0;
		char c;
		if (temp.length() == 0)
		{
			c = 0;
		}
		else
		{
			while (i < static_cast<int>(temp.length()) && !isalpha(temp[i]))
			{
				i++;
			}
			if (i < static_cast<int>(temp.length()))
			{
				c = temp[i];
			}
			else
			{
				c = 0;
			}
		}

		return c;
	}
	int getFirstInt(string temp)
	{
		int i = 0;
		if (temp.length() == 0)
		{
			return 0;
		}

		while (i < static_cast<int>(temp.length()) && !isdigit(temp[i]))
		{
			i++;
		}

		string number = temp.substr(i);

		if (number == "")
		{
			return 0;
		}

		return atoi(number.c_str());
	}
};


int main()
{
	srand(time(0));
	BattleshipGame game;
	Credit();
	Rules();
	Playgame();
	game.placeComputerPieces("");

	game.placePlayerPieces();

	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
	game.displayBoards();
	do {
		string playerMove = game.playerMove();
		string computerMove = game.computerMove();
		cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
		game.displayBoards(playerMove, computerMove);
	} while (game.gameOver() == 0);

	int gameOver = game.gameOver();
	if (gameOver == 1)
	{
		cout << "Your Bad! You Lost The Game." << endl;
	}
	else if (gameOver == 2)
	{
		cout << "Congratulation You Have Won The Game!" << endl;
	}
	else if (gameOver == 3)
	{
		cout << "Oh My God,its a Draw!" << endl;
	
	}
}
