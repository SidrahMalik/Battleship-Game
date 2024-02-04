#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

int LShip = -1;
int LShipId = 0;

int LMyShip = -1;
int LMyShipId = 0;

const int ROWS = 10 ;
const int COLS = 10 ;
int mat[ROWS][COLS];     
int MyArea[ROWS][COLS];     


struct SHIPS
{
    int regions;          
    int regionsLeft;    
    int Axis[10][2];   
};

SHIPS Zone[10];
SHIPS ZonePC[10];

void Add_Zone(int Area, int DULL, int COORD[][2])
{
    Zone[Area].regions = DULL;
    Zone[Area].regionsLeft = DULL;
    int i;
    for(i = 0; i < DULL; i++)
	{
        Zone[Area].Axis[i][0] = COORD[i][0];
        Zone[Area].Axis[i][1] = COORD[i][1];
        MyArea[COORD[i][0]][COORD[i][1]] = Area;
    }
}

void Add_PC_Zone(int Area, int DULL, int COORD[][2])
{
    ZonePC[Area].regions = DULL;
    ZonePC[Area].regionsLeft = DULL;
    int i;
    for(i = 0; i < DULL; i++)
	{
        ZonePC[Area].Axis[i][0] = COORD[i][0];
        ZonePC[Area].Axis[i][1] = COORD[i][1];
        mat[COORD[i][0]][COORD[i][1]] = Area;
    }
}

int getRand0or1()
{
    return rand() % 2;
}

int getRand0or3()
{
    return rand() % 4;
}

int getCoordX()
{
    return rand() % ROWS;
}

int getCoordY()
{
    return rand() % COLS;
}

void ZoneRandom()
{

    int x = getCoordX();
    int y = getCoordY();
    int Ship_1[1][2] = {{x, y}};
    Add_Zone(1, 1, Ship_1);

    int aim = getRand0or1();
    do{
        do{
            x = getCoordX();
            y = getCoordY();
        }
		while((aim == 1 && y+1 > 9) || (aim == 0 && x+1 > 9));
    }
	while(MyArea[x][y] > 0 || ((aim == 1 && MyArea[x][y+1] > 0) ||(aim == 0 && MyArea[x + 1][y] > 0)));
	
    int Ship_2[2][2];
    if(aim == 1)
	{
        Ship_2[0][0] = x;
        Ship_2[0][1] = y;
        Ship_2[1][0] = x;
        Ship_2[1][1] = y + 1;
    }
	else
	{
        Ship_2[0][0] = x;
        Ship_2[0][1] = y;
        Ship_2[1][0] = x + 1;
        Ship_2[1][1] = y;
    }
    Add_Zone(2, 2, Ship_2);

    aim = getRand0or1();
    do{
        do{
            x = getCoordX();
            y = getCoordY();
        }
		while((aim == 1 && (y+1 > 9 || y+2 > 9)) || (aim == 0 && (x+1 > 9 || x+2 > 9)));
    }
	while(MyArea[x][y] > 0 ||((aim == 1 && (MyArea[x][y+1] > 0 || MyArea[x][y+2] > 0)) ||(aim == 0 && (MyArea[x + 1][y] > 0 || MyArea[x + 2][y] > 0))));
    
	int Ship_3[3][2];
    if(aim == 1)
	{
        Ship_3[0][0] = x;
        Ship_3[0][1] = y;
        Ship_3[1][0] = x;
        Ship_3[1][1] = y + 1;
        Ship_3[2][0] = x;
        Ship_3[2][1] = y + 2;
    }
	else
	{
        Ship_3[0][0] = x;
        Ship_3[0][1] = y;
        Ship_3[1][0] = x + 1;
        Ship_3[1][1] = y;
        Ship_3[2][0] = x + 2;
        Ship_3[2][1] = y;
    }
    Add_Zone(3, 3, Ship_3);

    aim = getRand0or1();
    do{
        do{
            x = getCoordX();
            y = getCoordY();
        }
		while((aim == 1 && (y+1 > 9 || y+2 > 9 || y+3 > 9)) || (aim == 0 && (x+1 > 9 || x+2 > 9 || x+3 > 9)));
    }
	while(MyArea[x][y] > 0 ||((aim == 1 && (MyArea[x][y+1] > 0 || MyArea[x][y+2] > 0 || MyArea[x][y+3] > 0)) ||(aim == 0 && (MyArea[x + 1][y] > 0 || MyArea[x + 2][y] > 0 || MyArea[x + 3][y] > 0))));
    int Ship_4[4][2];
    if(aim == 1)
	{
        Ship_4[0][0] = x;
        Ship_4[0][1] = y;
        Ship_4[1][0] = x;
        Ship_4[1][1] = y + 1;
        Ship_4[2][0] = x;
        Ship_4[2][1] = y + 2;
        Ship_4[3][0] = x;
        Ship_4[3][1] = y + 3;
    }
	else
	{
        Ship_4[0][0] = x;
        Ship_4[0][1] = y;
        Ship_4[1][0] = x + 1;
        Ship_4[1][1] = y;
        Ship_4[2][0] = x + 2;
        Ship_4[2][1] = y;
        Ship_4[3][0] = x + 3;
        Ship_4[3][1] = y;
    }
    Add_Zone(4, 4, Ship_4);

    aim = getRand0or1();
    do{
        do{
            x = getCoordX();
            y = getCoordY();
        }
		while((aim == 1 && (y+1 > 9 || y+2 > 9 || y+3 > 9 || y+4 > 9)) || (aim == 0 && (x+1 > 9 || x+2 > 9 || x+3 > 9 || x+4 > 9)));
    }
	while(MyArea[x][y] > 0 ||((aim == 1 && (MyArea[x][y+1] > 0 || MyArea[x][y+2] > 0 || MyArea[x][y+3] > 0 || MyArea[x][y+4] > 0)) ||(aim == 0 && (MyArea[x + 1][y] > 0 || MyArea[x + 2][y] > 0 || MyArea[x + 3][y] > 0 || MyArea[x + 4][y] > 0))));
    
	int Ship_5[3][2];
    if(aim == 1)
	{
        Ship_5[0][0] = x;
        Ship_5[0][1] = y;
        Ship_5[1][0] = x;
        Ship_5[1][1] = y + 1;
        Ship_5[2][0] = x;
        Ship_5[2][1] = y + 2;
        Ship_5[3][0] = x;
        Ship_5[3][1] = y + 3;
        Ship_5[4][0] = x;
        Ship_5[4][1] = y + 4;
    }
	else
	{
        Ship_5[0][0] = x;
        Ship_5[0][1] = y;
        Ship_5[1][0] = x + 1;
        Ship_5[1][1] = y;
        Ship_5[2][0] = x + 2;
        Ship_5[2][1] = y;
        Ship_5[3][0] = x + 3;
        Ship_5[3][1] = y;
        Ship_5[4][0] = x + 4;
        Ship_5[4][1] = y;
    }
    Add_Zone(5, 5, Ship_5);
}

void ZonePCRandom()
{

    int x = getCoordX();
    int y = getCoordY();
    int Ship_1[1][2] = {{x, y}};
    Add_PC_Zone(1, 1, Ship_1);

    int idea = getRand0or1();
    do{
        do{
            x = getCoordX();
            y = getCoordY();
        }
		while((idea == 1 && y+1 > 9) || (idea == 0 && x+1 > 9));
    }
	while(mat[x][y] > 0 ||((idea == 1 && mat[x][y+1] > 0) ||(idea == 0 && mat[x + 1][y] > 0)));
	
    int Ship_2[2][2];
    if(idea == 1)
	{
        Ship_2[0][0] = x;
        Ship_2[0][1] = y;
        Ship_2[1][0] = x;
        Ship_2[1][1] = y + 1;
    }
	else
	{
        Ship_2[0][0] = x;
        Ship_2[0][1] = y;
        Ship_2[1][0] = x + 1;
        Ship_2[1][1] = y;
    }
    Add_PC_Zone(2, 2, Ship_2);

    idea = getRand0or1();
    do{
        do{
            x = getCoordX();
            y = getCoordY();
        }while((idea == 1 && (y+1 > 9 || y+2 > 9)) || (idea == 0 && (x+1 > 9 || x+2 > 9)));
    }
	while(mat[x][y] > 0 ||((idea == 1 && (mat[x][y+1] > 0 || mat[x][y+2] > 0)) ||(idea == 0 && (mat[x + 1][y] > 0 || mat[x + 2][y] > 0))));
    
	int Ship_3[3][2];
    if(idea == 1)
	{
        Ship_3[0][0] = x;
        Ship_3[0][1] = y;
        Ship_3[1][0] = x;
        Ship_3[1][1] = y + 1;
        Ship_3[2][0] = x;
        Ship_3[2][1] = y + 2;
    }
	else
	{
        Ship_3[0][0] = x;
        Ship_3[0][1] = y;
        Ship_3[1][0] = x + 1;
        Ship_3[1][1] = y;
        Ship_3[2][0] = x + 2;
        Ship_3[2][1] = y;
    }
    Add_PC_Zone(3, 3, Ship_3);

    idea = getRand0or1();
    do{
        do{
            x = getCoordX();
            y = getCoordY();
        }while((idea == 1 && (y+1 > 9 || y+2 > 9 || y+3 > 9)) || (idea == 0 && (x+1 > 9 || x+2 > 9 || x+3 > 9)));
    }
	while(mat[x][y] > 0 ||((idea == 1 && (mat[x][y+1] > 0 || mat[x][y+2] > 0 || mat[x][y+3] > 0)) ||(idea == 0 && (mat[x + 1][y] > 0 || mat[x + 2][y] > 0 || mat[x + 3][y] > 0))));
    
	int Ship_4[4][2];
    if(idea == 1)
	{
        Ship_4[0][0] = x;
        Ship_4[0][1] = y;
        Ship_4[1][0] = x;
        Ship_4[1][1] = y + 1;
        Ship_4[2][0] = x;
        Ship_4[2][1] = y + 2;
        Ship_4[3][0] = x;
        Ship_4[3][1] = y + 3;
    }
	else
	{
        Ship_4[0][0] = x;
        Ship_4[0][1] = y;
        Ship_4[1][0] = x + 1;
        Ship_4[1][1] = y;
        Ship_4[2][0] = x + 2;
        Ship_4[2][1] = y;
        Ship_4[3][0] = x + 3;
        Ship_4[3][1] = y;
    }
    Add_PC_Zone(4, 4, Ship_4);

    idea = getRand0or1();
    do{
        do{
            x = getCoordX();
            y = getCoordY();
        }while((idea == 1 && (y+1 > 9 || y+2 > 9 || y+3 > 9 || y+4 > 9)) || (idea == 0 && (x+1 > 9 || x+2 > 9 || x+3 > 9 || x+4 > 9)));
    }
	while(mat[x][y] > 0 ||((idea == 1 && (mat[x][y+1] > 0 || mat[x][y+2] > 0 || mat[x][y+3] > 0 || mat[x][y+4] > 0)) ||(idea == 0 && (mat[x + 1][y] > 0 || mat[x + 2][y] > 0 || mat[x + 3][y] > 0 || mat[x + 4][y] > 0))));
    
	int Ship_5[3][2];
    if(idea == 1)
	{
        Ship_5[0][0] = x;
        Ship_5[0][1] = y;
        Ship_5[1][0] = x;
        Ship_5[1][1] = y + 1;
        Ship_5[2][0] = x;
        Ship_5[2][1] = y + 2;
        Ship_5[3][0] = x;
        Ship_5[3][1] = y + 3;
        Ship_5[4][0] = x;
        Ship_5[4][1] = y + 4;
    }
	else
	{
        Ship_5[0][0] = x;
        Ship_5[0][1] = y;
        Ship_5[1][0] = x + 1;
        Ship_5[1][1] = y;
        Ship_5[2][0] = x + 2;
        Ship_5[2][1] = y;
        Ship_5[3][0] = x + 3;
        Ship_5[3][1] = y;
        Ship_5[4][0] = x + 4;
        Ship_5[4][1] = y;
    }
    Add_PC_Zone(5, 5, Ship_5);
}

void Clear()
{
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
		{
            mat[i][j] = 0 ;
            MyArea[i][j] = 0 ;
        }
}

int NumberOfShips()
{
    int c = 0;
    for(int i = 1; i <= 5; i++)
        if(ZonePC[i].regionsLeft != 0)
            c++;
    return c;
}

int NumberOfMyShips()
{
    int c = 0;
    for(int i = 1; i <= 5; i++)
        if(Zone[i].regionsLeft != 0)
            c++;
    return c;
}

bool Attack(int x, int y)
{
    if(mat[x][y] > 0)
	{
        int Area = mat[x][y];
        ZonePC[Area].regionsLeft--;
        if(ZonePC[Area].regionsLeft > 0)
            LShip = 1;
        else
            LShip = 0;
        LShipId = Area;
        mat[x][y] = -1;
        return true;
    }
    return false;
}

bool AttackMe(int x, int y)
{
    if(MyArea[x][y] > 0)
	{
        int Area = MyArea[x][y];
        Zone[Area].regionsLeft--;
        if(Zone[Area].regionsLeft > 0)
            LMyShip = 1;
        else
            LMyShip = 0;
        LMyShipId = Area;
        MyArea[x][y] = -1;
        return true;
    }
    return false;
}

void ShowFull(int type)
{
    cout << " - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
    cout << " -              Welcome   to    BattleShip     Game!             -" << endl;
    cout << " -           Final            Semester             Project       -" << endl;
    cout << " -   Syeda Daniya Fatima(21F-9180)     Sidra Malik(21F-9179)     -" << endl;
    cout << " - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
    cout << " -          PC ZONE:                               MY AREA:      -" << endl;
    cout << " - - - 0 1 2 3 4 5 6 7 8 9 -           - - - 0 1 2 3 4 5 6 7 8 9 -" << endl;
    for (int i = 0; i < ROWS; i++)
	{
        cout << " | " << i << " | ";
        for (int j = 0; j < COLS; j++)
		{
            if(mat[i][j] == -1)
                cout << "X ";
            else if(mat[i][j] == 0 || type == 0)
                cout << "* ";
            else if(mat[i][j] == 1)
                cout << (char)176 << " ";
            else if(mat[i][j] == 2)
                cout << (char)177 << " ";
            else if(mat[i][j] == 3)
                cout << (char)178 << " ";
            else if(mat[i][j] == 4)
                cout << (char)240 << " ";
            else if(mat[i][j] == 5)
                cout << (char)219 << " ";
            else
                cout << mat[i][j] << " " ;
        }
        cout << "|           | " << i << " | ";
        for (int j = 0; j < COLS; j++)
            if(MyArea[i][j] == -1)
                cout << "X ";
            else if(MyArea[i][j] == 0)
                cout << "* ";
            else if(MyArea[i][j] == 1)
                cout << (char)176 << " ";
            else if(MyArea[i][j] == 2)
                cout << (char)177 << " ";
            else if(MyArea[i][j] == 3)
                cout << (char)178 << " ";
            else if(MyArea[i][j] == 4)
                cout << (char)240 << " ";
            else if(MyArea[i][j] == 5)
                cout << (char)219 << " ";
            else
                cout << MyArea[i][j] << " " ;
        cout << "|" << endl;
    }
    cout << " - - - - - - - - - - - - - -           - - - - - - - - - - - - - -" << endl;
    cout << " | SHIPS LEFT ARE: " << NumberOfShips();
    if(NumberOfShips() == 10)
        cout << " |              | ";
    else
        cout << "  |              | ";
    cout << "SHIPS LEFT ARE: " << NumberOfMyShips();
    if(NumberOfMyShips() == 10)
        cout << " | " << endl;
    else
        cout << "  | " << endl;;
}

int main()
{
    srand(time(NULL));
    Clear();

    ZoneRandom();
    ZonePCRandom();


    int place1,place2;
    int placex , placey;
    char choice = 'n';
    char work = 'n';


    int exit;
    int hit = 0;
    int Ship_Hit = 0;


    do{
        cout << "DO YOU WANT TO FINISH GAME EARLIER? (y/n): ";
        cin >> work;
    }
	while(work != 'y' && work != 'n');

    while(1)
	{
        system("cls");
        ShowFull(1);

        if((work == 'y' || work == 'n') && (choice == 'y' || choice == 'n'))
		{
            if (hit == 1 && LShip == 1)
                cout << " Player 1: THE SHIP WAS PARTIALLY DESTROYED! (" << LShipId << ")! ... (" << place1 << "," << place2 << ")" << endl;
            else if (hit == 1 && LShip == 0)
                cout << " Player 1: THE SHIP WAS COMPLETELY DESTROYED! (" << LShipId<< ")! ... (" << place1 << "," << place2 << ")" << endl;
            else if(hit == 2)
                cout << " Player 1: THERE IS NO SHIP AT THAT POSITION!   ... (" << place1 << "," << place2 << ")" << endl;

            if(Ship_Hit == 1 && LMyShip == 1)
                cout << " Player 2: THE SHIP WAS PARTIALLY DESTROYED! (" << LMyShipId << ")! ... (" << placex << "," << placey << ")" << endl;
            else if(Ship_Hit == 1 && LMyShip == 0)
                cout << " Player 2: THE SHIP WAS COMPLETELY DESTROYED! (" << LMyShipId << ")! ... (" << placex << "," << placey << ")" << endl;
            else if(Ship_Hit == 2)
                cout << " Player 2: THERE IS NO SHIP AT THAT POSITION!   ... (" << placex << "," << placey << ")" << endl;
            cout << " - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;

            if(choice == 'n' && NumberOfShips() != 0)
			{
                do{
                    cout << " Player 1: PLEASE ENTER THE LOCATION YOU WANT TO PLACE: ";
                    cin >> place1 >> place2;
                }
				while(place1 < 0 || place1 > 10 || place2 < 0 || place2 > 10);
                if(Attack(place1,place2))
                    hit = 1;
                else
                    hit = 2;
            }
            if(choice == 'n' && NumberOfMyShips() != 0)
			{
                do{
                    cout << " Player 2: PLEASE ENTER THE LOCATION YOU WANT TO PLACE: ";
                    cin >> placex >> placey;
                }
				while(placex < 0 || placex > 10 || placey < 0 || placey > 10);
                if(AttackMe(placex,placey))
                    Ship_Hit = 1;
                else
                    Ship_Hit = 2;
            }
            

             if(NumberOfShips() == 0)
			 {
                exit = 1;
                break;
            }
            if(NumberOfMyShips() == 0)
			{
                exit = 2;
                break;
            }
        }

        if(work == 'y')
		{
            cout << " - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
            if (hit == 1 && LShip == 1)
                cout << " Player 1: THE SHIP WAS PARTIALLY DESTROYED! (" << LShipId << ")! ... (" << place1 << "," << place2 << ")" << endl;
            else if (hit == 1 && LShip == 0)
                cout << " Player 1: THE SHIP WAS COMPLETELY DESTROYED!(" << LShipId << ")! ... (" << place1 << "," << place2 << ")" << endl;
            else if(hit == 2)
			{
                cout << " Player 1: THERE IS NO SHIP AT THAT POSITION!  ... (" << place1 << "," << place2 << ")" << endl;
            }
            if(Ship_Hit == 1 && LMyShip == 1)
                cout << " Player 2: THE SHIP WAS PARTIALLY DESTROYED! (" << LMyShipId << ")! ... (" << placex << "," << placey << ")" << endl;
            else if(Ship_Hit == 1 && LMyShip == 0)
                cout << " Player 2: THE SHIP WAS COMPLETELY DESTROYED! (" << LMyShipId << ")! ... (" << placex << "," << placey << ")" << endl;
            else if(Ship_Hit == 2)
                cout << " Player 2: THERE IS NO SHIP AT THAT POSITION!   ... (" << placex << "," << placey << ")" << endl;
            cout << " - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
            cout << " Me: DO YOU WANT TO SURRENDER (y/n) ? " ;
            cin >> choice;
        }
        if (choice == 'y')
		{
            exit = 0;
            break;
        }
    }
    system("cls");
    ShowFull(1);
    if(exit == 0)
    {
        cout << " YOU SURRENDERED !" << endl;	
	}
    else if(exit == 1)
    {
        cout << "PLAYER 1 HAS WON! CONGRATS." << endl;	
	}
    else if(exit == 2)
    {
        cout << "PLAYER 2 HAS WON! CONGRATS." << endl;	
	}

    return 0;
}

