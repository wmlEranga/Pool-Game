#include<iostream>
#include<conio.h>
#include<dos.h>
#include <windows.h>
#include <stdio.h>

#define SCREEN_WIDTH 140
#define SCREEN_HEIGHT 25

#define MINX 3
#define MINY 2
#define MAXX 98
#define MAXY 24

using namespace std;

int balls[16][2] = {{10,27},{13,33},{11,27},{13,31},{12,27},{12,31},{13,27},{14,31},{14,27},{11,29},{15,27},{12,29},{16,27},{13,29},{14,29},{15,29}};
void play1();
void play();

int marks1,marks2;
int ballPos[2] = {}; 
int startBall = 0;
int dir = 1; 
int count =0;
int stat =0;
int player = 0;

void checkWin()
{	int i = 0;
	int a = balls[i][1];
	int b = balls[i][0];
	
	do
	{
		if(i=15)
		i=i+1;		
		{
			cout<<"**********You Have Won The Game!***********";
		}
	} while(((a>0 && a<6)&&((b>0)&&(b<4)))||((a<48 && a<56)&&(b>0 && b<4))||((a<98 && a<104)&&(b>0 && b<4))||((a>0 && a<6)&&(b>23 && b<26))||((a<48 && a<56)&&(b>23 && b<30))||((a<98 && a<104)&&(b>23 && b<26))); 
}

void Instructions()
{
	cout<<"***********POOL GAME***********"<<endl<<endl;
	cout<<"***********INSTRUCTIONS***********"<<endl;
	cout<<"First, Enter the power before start each attempt"<<endl;
	cout<<"Then Use W, S, Q, E, Z, C keys to control the ball"<<endl<<endl<<endl;
	
	
 	cout<<"Press any key to start the game"<<endl;
	char inputData;
	inputData=getch();
	system("cls");	
}

void Fullscreen()
{
	keybd_event(VK_MENU, 0x38, 0, 0);
	keybd_event(VK_RETURN, 0x1c, 0, 0);
	keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0);
	keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);
}

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

char map[35][140]={
//         10        20        30        40        50        60        70        80        90        100       
//123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345

"_____________________________________________________________________________________________________",//0
"|     *                                        *      *                                      *      |",//1
"|     *                                        *      *                                      *      |",//2                                        
"| * *                                            *  *                                          *  * |",//3                               
"|                                                                                                   |",//4
"|                                                                                                   |",//5
"|                                                                                                   |",//6
"|                                                                                                   |",//7
"|                                                                                                   |",//8
"|                                                                                                   |",//9
"|                                                                                                   |",//10
"|                                                                                                   |",//11
"|                                                                                                   |",//12
"|                                                                                                   |",//13
"|                                                                                                   |",//14
"|                                                                                                   |",//15
"|                                                                                                   |",//16
"|                                                                                                   |",//17
"|                                                                                                   |",//18
"|                                                                                                   |",//19
"|                                                                                                   |",//20
"|                                                                                                   |",//21
"|                                                                                                   |",//22
"| * *                                            *  *                                           * * |",//23
"|     *                                        *      *                                       *     |",//24                                   
"|_____*________________________________________*______*_______________________________________*_____|",//25

};


void displayBoard()
{
		for (int i = 0; i<=25;i++)
		{
			for (int j = 0; j<= 100;j++)
			{
				cout << map[i][j];	
			}
		cout<<endl;
	}	
}

void gotoxy(int x, int y)
{
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}

void setcursor(bool visible, DWORD size) 
{
	if(size == 0)
	{
		size = 20;	
	}
	CONSOLE_CURSOR_INFO lpCursor;	
	lpCursor.bVisible = visible;
	lpCursor.dwSize = size;
	SetConsoleCursorInfo(console,&lpCursor);
}

void drawPeases(int i){
      gotoxy(balls[i][1], balls[i][0]);
      
      if(i>7){
        cout<<"B"; 
      }
      else{
        cout<<"W";  
      }   
	  
	for(int i=0;i<16;i++)
	{
		int a = balls[i][1];
		int b = balls[i][0];
		if(((a>0 && a<6)&&((b>0)&&(b<4)))||((a<48 && a<56)&&(b>0 && b<4))||((a<98 && a<104)&&(b>0 && b<4))||((a>0 && a<6)&&(b>23 && b<26))||((a<48 && a<56)&&(b>23 && b<30))||((a<98 && a<104)&&(b>23 && b<26)))
		
		{
			gotoxy(balls[i][1], balls[i][0]);
			cout<<" ";
		}
	}  
	     
}

void swap(char input1, char input2){
	char temp;
	
	temp = input2 ;
	input2 = input1;
	input1 = temp;
	
	cout<<input1<<endl;
	cout<<input2<<endl;
}

void pot()
{		  
	for(int i=0;i<16;i++)
	{
		int a = balls[i][1];
		int b = balls[i][0];
		if(((a>0 && a<6)&&((b>0)&&(b<4)))||((a<48 && a<56)&&(b>0 && b<4))||((a<98 && a<104)&&(b>0 && b<4))||((a>0 && a<6)&&(b>23 && b<26))||((a<48 && a<56)&&(b>23 && b<30))||((a<98 && a<104)&&(b>23 && b<26)))
				
		{
			gotoxy(balls[i][1], balls[i][0]);
			cout<<" ";
		}
	}  
}

void ballhit()
{	
		for( int i=0; i<18; i++){
				if( ballPos[0] == balls[i][0] && ballPos[1] == balls[i][1]){
				
				if( dir == 1) {//TOP RIGHT
				balls[i][0] =balls[i][0] - 1;
				balls[i][1] =balls[i][1] + 2;
				if( ballPos[1] > MAXX ){
					dir = 2;
				}  
				else if( ballPos[0] < MINY ){
					dir = 4;
				} 
				 
				 
			}
			else if( dir == 2) {//TOP LEFT
				balls[i][0] = balls[i][0] - 1;
				balls[i][1] = balls[i][1] - 2;
				if( balls[i][0] < MINY ){
					dir = 3;
				}  
				else if( balls[i][1] < MINX  ){
					dir = 1;
				}   
				 
			}
			else if( dir == 3) {//BOTTOM LEFT
				balls[i][0] = balls[i][0] + 1;
				balls[i][1] = balls[i][1] - 2;
			  
				if( balls[i][0] > MAXY ){
					dir = 2;
				
				}  
				else if( balls[i][1] < MINX  ){
					dir = 4;
				}   
				 
			}
			else if( dir == 4) {//BOTTOM RIGHT
				balls[i][0] = balls[i][0] + 1;
				balls[i][1] = balls[i][1] + 2;  
				if( balls[i][1] > MAXX ){
					dir = 1;
				} 
				else if( balls[i][0] > MAXY ){
					dir = 1;
					
				} 
			}
			
				else if( dir == 5) {//straight path UPWARD
				balls[i][0] = balls[i][0] - 1;
				//ballPos[1] = ballPos[1] + 2;  
				if(balls[i][0] < MINY ){
					dir = 6;
				} 
					 
			}
			
				else if( dir == 6) {//straight path downWARD
				balls[i][0] = balls[i][0] + 1;
				//ballPos[1] = ballPos[1] + 2;  
				if( balls[i][0] > MAXY ){
					dir = 5;
				} 	 
			}		
		}
	}			
}
		
void play()
{
	
	ballPos[0] =13;
	ballPos[1] =75;
	
	while(1)
	{
		system("cls");			
		displayBoard();
		
		for(int i =0;i<16;i++)
		{
			drawPeases(i);	
		}
	    
		gotoxy(ballPos[1],ballPos[0]);
		cout<<"O";
 
		if(kbhit()){
			char ch = getch();			
			if(ch=='q'||ch=='Q')
				{
				dir = 2;
				startBall = 1;
				}
				
			else if(ch=='w'||ch=='W')
				{
				dir = 5;
				startBall = 1;
				}
				
			else if(ch=='s'||ch=='S')
				{
				dir = 6;
				startBall = 1;
				}
				
			else if(ch=='e'||ch=='E')
				{
				dir = 1;
				startBall = 1;
				}
				
			else if(ch=='z'||ch=='Z')
				{
				dir = 3;
				startBall = 1;
				}
			
			else if(ch=='c'||ch=='C')
				{
				dir = 4;
				startBall = 1;
				}				
		}
		
		if(startBall == 1){
		
         //disk();
         count = count +1;
         
         if( dir == 1) {//TOP RIGHT
				ballPos[0] = ballPos[0] - 1;
				ballPos[1] = ballPos[1] + 2;
				if( ballPos[1] > MAXX ){
					dir = 2;
				}  
				else if( ballPos[0] < MINY ){
					dir = 4;
				} 
				 	 
			}
			else if( dir == 2) {//TOP LEFT
				ballPos[0] = ballPos[0] - 1;
				ballPos[1] = ballPos[1] - 2;
				if( ballPos[0] < MINY ){
					dir = 3;
				}  
				else if( ballPos[1] < MINX ){
					dir = 1;
				}   
				 
			}
			else if( dir == 3) {//BOTTOM LEFT
				ballPos[0] = ballPos[0] + 1;
				ballPos[1] = ballPos[1] - 2;
			  
				if( ballPos[0] > MAXY ){
					dir = 2;
				
				}  
				else if( ballPos[1] < MINX  ){
					dir = 4;
				}   
				 
			}
			
			else if( dir == 4) {//BOTTOM RIGHT
				ballPos[0] = ballPos[0] + 1;
				ballPos[1] = ballPos[1] + 2;  
				if( ballPos[1] > MAXX ){
					dir = 1;
				} 
				else if( ballPos[0] > MAXY ){
					dir = 1;
					
				}	 
			}
			
				else if( dir == 5) { //straight path UPWARD
				ballPos[0] = ballPos[0] - 1;
				//ballPos[1] = ballPos[1] + 2;  
				if( ballPos[0] < MINY ){
					dir = 6;
				} 	 
			}
			
			else if(dir == 6) { //straight path downWARD
				ballPos[0] = ballPos[0] + 1;
				//ballPos[1] = ballPos[1] + 2;  
				if( ballPos[0] > MAXY ){
					dir = 5;
				} 
			}
			
			else if(dir == 7) { //straight path Right
				ballPos[1] = ballPos[1] + 2;
				//ballPos[1] = ballPos[1] + 2;  
				if( ballPos[1] > MAXX ){
					dir = 8;
				} 
			}
			
			else if(dir == 8) { //straight path Left
				ballPos[1] = ballPos[1] - 2;
				//ballPos[1] = ballPos[1] + 2;  
				if( ballPos[1] > MAXX ){
					dir = 7;
				} 
			}
		}
		
		if(count > stat)
		{
			player=1;
			count=0;
			stat =0;
			cout << "\n\n\n\t\t Next Attempt...";
			system("pause"); 			
			break;
		}
	
		ballhit();

		Sleep(100);
	}	
	pot();
	player=1;
}

void play1(){

		while(1){
					
		system("cls");			
		displayBoard();
		
		
		for(int i=0;i<16;i++){
			drawPeases(i);	
		}
	    
		gotoxy(ballPos[1],ballPos[0]);
		cout<<"O";
 
		if(kbhit()){
			char ch = getch();			
			if(ch=='q'||ch=='Q')
				{
				dir = 2;
				startBall = 1;
				}
				
			else if(ch=='w'||ch=='W')
				{
				dir = 5;
				startBall = 1;
				}
				
			else if(ch=='s'||ch=='S')
				{
				dir = 6;
				startBall = 1;
				}
				
			else if(ch=='e'||ch=='E')
				{
				dir = 1;
				startBall = 1;
				}
				
			else if(ch=='z'||ch=='Z')
				{
				dir = 3;
				startBall = 1;
				}
			
			else if(ch=='c'||ch=='C')
				{
				dir = 4;
				startBall = 1;
				}			
		}
		
		if(startBall == 1)
		{
         count = count +1;
         if( dir == 1) { // TOP RIGHT
				ballPos[0] = ballPos[0] - 1;
				ballPos[1] = ballPos[1] + 2;
				if( ballPos[1] > MAXX ){
					dir = 2;
				}  
				else if( ballPos[0] < MINY ){
					dir = 4;
				} 	 
			}
			
			else if( dir == 2) { // TOP LEFT
				ballPos[0] = ballPos[0] - 1;
				ballPos[1] = ballPos[1] - 2;
				if( ballPos[0] < MINY ){
					dir = 3;
				}  
				else if( ballPos[1] < MINX  ){
					dir = 1;
				}   
				 
			}
			else if( dir == 3) { // BOTTOM LEFT
				ballPos[0] = ballPos[0] + 1;
				ballPos[1] = ballPos[1] - 2;
			  
				if( ballPos[0] > MAXY ){
					dir = 2;
				
				}  
				else if( ballPos[1] < MINX  ){
					dir = 4;
				}   
				 
			}
			else if( dir == 4) { // BOTTOM RIGHT
				ballPos[0] = ballPos[0] + 1;
				ballPos[1] = ballPos[1] + 2;  
				if( ballPos[1] > MAXX ){
					dir = 1;
				} 
				else if( ballPos[0] > MAXY ){
					dir = 1;
					
				}
				 
			}
				else if( dir == 5) { // straight path UPWARD
				ballPos[0] = ballPos[0] - 1;
				//ballPos[1] = ballPos[1] + 2;  
				if( ballPos[0] < MINY ){
					dir = 6;
				} 
					 
			}
			
			else if( dir == 6) { // straight path downWARD
				ballPos[0] = ballPos[0] + 1;
				//ballPos[1] = ballPos[1] + 2;  
				if( ballPos[0] > MAXY ){
					dir = 5;
				} 	 
			}
			
			else if(dir == 7) { // straight path Right
				ballPos[1] = ballPos[1] + 2;
				//ballPos[1] = ballPos[1] + 2;  
				if( ballPos[1] > MAXX ){
					dir = 8;
				} 
			}
			
			else if(dir == 8) { // straight path Left
				ballPos[1] = ballPos[1] - 2;
				//ballPos[1] = ballPos[1] + 2;  
				if( ballPos[1] > MAXX ){
					dir = 7;
				} 
			}

		}
		if(count > stat){
			//startBall = 0;
			player = 1;
			count = 0;
			stat = 0;
			startBall = 0;
			cout << "\n\n\n\t\t Next Attempt...";
			system("pause");
			break;
		}
		
			ballhit();
	
		Sleep(100);
	}

	pot();
	player=1;
}

void start()
{
	while(1)
	{
		switch (player)
		{
			case 0:
				gotoxy(70,10);
				cout<<"Enter the Power:";
				cin>>stat;
				while(stat<=0 || stat>300)
				{
					cout<<"Enter value between 0-50"<<endl;
					cout<<"Enter the Power:";
					cin>>stat;
				}
				 	
				play();
			
			case 1:
				gotoxy(70,10);
				cout<<"Enter the Power:";
				cin>>stat;
				while(stat<=0 || stat>300)
				{
					cout<<"Enter value between 0-50"<<endl;
					cout<<"Enter the Power:";
					cin>>stat;
				}
				play1();
		}
	}
}

int main()   
{
	Fullscreen();
	Instructions();
	setcursor(0,0);
	displayBoard();	
	start();		
}

