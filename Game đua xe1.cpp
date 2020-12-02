#include <iostream>
#include <time.h>
#include <conio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <windows.h>
#include <mmsystem.h>
#include "console.h"

using namespace std ;


struct Coordinates
{
    int x ;
	int y ;
};


struct Shape
{
	char m[3][3];
};


struct Car
{
	Coordinates my_coordinates ;
	Shape my_shape ;
	int scores ;
	string Name_Car ;
};


struct Prevent
{
	Coordinates my_coordinates ;
	Shape my_shape ;
};

void Sound_Game(int n)
{

        if(n == 1){
            PlaySound(TEXT("tevo.wav") , NULL , SND_ASYNC) ;
        }
        else if(n == 2) {
            PlaySound(TEXT("attack.wav") , NULL , SND_ASYNC) ;
        }
        else if(n == 3){
            PlaySound(TEXT("1.wav") , NULL , SND_ASYNC) ;
        }
        else if(n == 4){
            PlaySound(TEXT("123.wav") , NULL , SND_ASYNC) ;
        }


}



void Make(Car &my_car, Prevent &my_prevent)
{
	//------ Xe
#define Thep my_car.my_shape.m

	my_car.scores = 0;
	my_car.my_coordinates.x = 56;
	my_car.my_coordinates.y = 23;

	Thep[0][0] = Thep[0][2] = Thep[2][0] = Thep[2][2] = 'o';	// bánh xe
	Thep[1][0] = '^' ;	// đầu xe
	Thep[0][1] = Thep[2][1] = ' ';	// thân xe
	Thep[1][2] = '=';
	Thep[1][1] = '|';


	//---------vật cản

	my_prevent.my_coordinates.x = 46 + rand() % 19 ;
	my_prevent.my_coordinates.y = -2 ;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++){
         my_prevent.my_shape.m[i][j] = char(237);
    }
}


void Display (Car &my_car, Prevent &my_prevent )
{
	clrscr();

	// hai biên

	TextColor (ColorCode_Green);
	for (int i = 0; i < 30 ; i++){
	    gotoXY(44 , i) ;
		cout << char(199)  ;
    }
	for (int i = 0; i < 30 ; i++){
		gotoXY (68 , i);
		cout << char(182) ;
	}


	// Xe
	TextColor (ColorCode_Cyan);
	for (int i = -1 ; i <= 1 ; i++)
		for (int j = -1 ; j <= 1 ; j++)
		{
			int x = i + my_car.my_coordinates.x ;
			int y = j + my_car.my_coordinates.y ;

			gotoXY (x, y);
			cout << my_car.my_shape.m[i + 1][j + 1] ;
		}


    //--------------

	// Vật Cản
	TextColor (ColorCode_Red);
	for (int i = -1 ; i <= 1 ; i++)
		for (int j = -1 ; j <= 1 ; j++)
		{
			int x = i + my_prevent.my_coordinates.x ;
			int y = j + my_prevent.my_coordinates.y ;

			gotoXY (x, y);
			cout << my_prevent.my_shape.m[i + 1][j + 1] ;
		}

	// Điểm số
	gotoXY (85, 15);
	cout << "----" << my_car.Name_Car <<"----" << endl ;
	gotoXY(85 ,16) ;
	cout << "Your Scores is : " << my_car.scores ;
}


void Controll(Car &my_car)
{
	if (_kbhit())
	{
		int key = _getch() ;

		if ((key == 'A' || key == 'a') && my_car.my_coordinates.x > 46)
			my_car.my_coordinates.x -= 2 ;
		else if ((key == 'D' || key == 'd') && my_car.my_coordinates.x < 66)
			my_car.my_coordinates.x += 2 ;
        else if ((key == 'W' || key == 'w') && my_car.my_coordinates.y < 30)
            my_car.my_coordinates.y-- ;
        else if ((key == 'S' || key == 's') && my_car.my_coordinates.y < 26)
            my_car.my_coordinates.y++  ;
	}
}

int Process (Car &my_car , Prevent &my_prevent , int &time_sleep)
{

	my_prevent.my_coordinates.y++;


	if (my_prevent.my_coordinates.y > my_car.my_coordinates.y)
	{
	    //--------------------


		my_car.scores += 109 ;
		my_prevent.my_coordinates.x = 46 + rand() % 19 ;
		my_prevent.my_coordinates.y = -2 ;

		if (time_sleep > 10)
			time_sleep -= 7;
	}

	// Va chạm
	int dX = abs (my_car.my_coordinates.x - my_prevent.my_coordinates.x);
	int dY = abs (my_car.my_coordinates.y - my_prevent.my_coordinates.y) ;

	if (dX < 3 && dY <= 2)
	{
		return -1 ;
	}

        return 0;
}

void Play()
{
    srand (time (0));

	Car my_car ;
	Prevent my_prevent ;

	Make(my_car , my_prevent) ;

	int Count = 0 ;
	int time_sleep = 150 ;

	gotoXY(50 , 9) ;
    cout << "Enter Your name :" ;
    fflush(stdin) ;
    getline(cin, my_car.Name_Car) ;

	while (1)
            {

                Display(my_car , my_prevent) ;

                Controll(my_car) ;

                Count = Process(my_car , my_prevent , time_sleep) ;

                if (Count == -1)
                {
                    Sound_Game(2) ;

                    //-------------------------------

                    gotoXY (85 , 14);
                    cout << "Thua CMNR" ;

                    while (_getch() != 13)	;

                    break;
                }

                Sleep (time_sleep);
            }
}


int main()
{

    Sound_Game(1) ;



    int choise ;
    TextColor(ColorCode_Pink) ;
    gotoXY(50 , 5) ;
    cout << char(175) << " Choise 1 for Play game " << endl ;
    gotoXY(50 , 6) ;
    cout << char(175) << " Choise 2 for guide " << endl ;
    gotoXY(50 , 7) ;
    cout << char(175) << " Choise random for exit game " ;
    gotoXY(50 , 8) ;
    cout << char(175) << " Your Choise is : " ;
    cin >> choise ;

    //---------------------------------

	switch(choise)
	{
    case 1 :
        {
            //PlaySound(TEXT("123.wav") , NULL , SND_ASYNC) ;
            Play() ;
            break ;
        }
    case 2 :
        {
            char C ;
            //PlaySound(TEXT("123.wav") , NULL , SND_ASYNC) ;
            TextColor(ColorCode_DarkPink) ;
            gotoXY(50 , 10) ;
            cout << "Su dung phim a d de di chuyen sang trai phai " << endl ;
            gotoXY(50 , 11) ;
            cout << "Su dung phim w s de di chuyen xe len xuong " << endl ;
            gotoXY(50 , 12) ;
            cout << "chuc cac ban choi game vui ve" << endl ;
            gotoXY(50 , 13) ;
            cout << "Chon phim bat ky va nhan enter de nhap ten nguoi choi va choi game" ;
            cin >> C ;
            if(C != '~')
            {
                    Play() ;
                    break ;
            }

        }

	}
	return 0;
}
