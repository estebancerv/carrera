#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <ctime> // Needed for the true randomization
#include <cstdlib>
#include <conio.h>

using namespace std;
int x,y;
DWORD WINAPI hilo(LPVOID LPARAM);


int main()
{
	HANDLE MiHilo;
	DWORD  IdDelHilo;
	
	MiHilo=CreateThread(NULL,0,hilo,NULL,0,& IdDelHilo);
	int xRan;
	char pista[4];
	bool corriendo;
	char pist[10][6]={{'|',' ',' ',' ',' ','|'},{'|',' ',' ',' ',' ','|'},{'|',' ',' ',' ',' ','|'},{'|',' ',' ',' ',' ','|'},{'|',' ',' ',' ',' ','|'},
	{'|',' ',' ',' ',' ','|'},{'|',' ',' ',' ',' ','|'},{'|',' ',' ',' ',' ','|'},{'|',' ',' ',' ',' ','|'},{'|',' ',' ',' ',' ','|'}};
	srand( time(0));
	y=1;
	x=0;
	corriendo = true;
	while (corriendo){
		for (int i=0;i<4;i++){
			// This will ensure a really randomized number by help of time.
			xRan=rand()%100+1;	// Randomizing the number between 1-15.
			if (xRan<15){
				pista[i]=1;
			}
			else {
				pista[i]=' ';
			}
		}
		system("CLS");
		for (int j = 0; j<4; j++){
			cout << pista[j];
		}
		cout << endl << endl;
		for (int t = 0; t<10; t++){
			for (int j = 0; j<6; j++){
				cout << pist[t][j];
			}
			cout << endl;
		}
		Sleep(1000);
		for (int t = 0; t<9; t++){
			for (int j = 1; j<5; j++){
				pist[t][j]=pist[t+1][j];
			}
		}
		for (int j = 0; j<4; j++){
			pist[9][j+1]=pista[j];
		}
		if (pist[x+1][y]==1){
			cout << "PERDISTE!!";
			return 0;
		}
		pist[x][y]='V';
	}
	
	//-------------------------------------------------------------------------------------------------------------------------------------------//
	cout << endl << "Shows a random number between 1-15: " << xRan;	
	
	return 0;
}

DWORD WINAPI hilo(LPVOID LPARAM)
{
	while (true){
		int d;
		d=getch();
		switch(d) {
		case 119: // key up
			x--;
			cout << "arriba";
			break;
		case 115:
			x++;
			cout << "abajo";// key down
			break;
		case 97:
			y--;
			cout << "derecha";// key right
			break;
		case 100:
			y++;
			cout << "izquierda";// key left
			break;
		}
	}
	
	return 0;
}

