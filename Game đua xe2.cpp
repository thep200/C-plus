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
    int x, x1, x2, x3, x4 ;
	int y, y1, y2, y3, y4 ;
};

struct Shape
{
	char m[3][3];

	char m1[2][2] ;

	char m2[1][1] ;

	char m3[2][4] ;

	char m4[3][3] ;

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

void Make(Car &my_car, Prevent &my_prevent) ;
void Display (Car &my_car, Prevent &my_prevent ) ;
void Controll(Car &my_car) ;
int Process (Car &my_car , Prevent &my_prevent , int &time_sleep) ;
void Sound_Game(int n) ;
void out_put1() ;
void out_put2() ;
void out_put3() ;
void Run_Game() ;
void Play() ;

void Sound_Game(int n)
{
        if(n == 1){
            PlaySound(TEXT("nova.wav") , NULL , SND_ASYNC) ;
        }
        else if(n == 2) {
            PlaySound(TEXT("attack.wav") , NULL , SND_ASYNC) ;
        }
        else if(n == 3){
            PlaySound(TEXT("choigame.wav") , NULL , SND_ASYNC) ;
        }
        else if(n == 4){
            PlaySound(NULL , NULL , SND_ASYNC) ;
        }
}

void out_put1()
{
        TextColor(ColorCode_Pink) ;
        gotoXY(45 , 10) ;
        cout << "#1 Enter 1 For Play Game" << endl ;
        gotoXY(45 , 11) ;
        cout << "#2 Enter 2 For Guide" << endl ;
        gotoXY(45 , 12) ;
        cout << "#3 Enter Space for Exit game" ;

}

void out_put2()
{
        TextColor(ColorCode_DarkPink) ;
        gotoXY(45, 10) ;
        cout << "#1 Use The a And d Keys To Move Left And Right" << endl ;
        gotoXY(45, 11) ;
        cout << "#2 Use The w And s Keys To Move Up And Down" << endl ;
        gotoXY(45, 12) ;
        cout << "#3 Use The r Key To Turn off Music " << endl ;
        gotoXY(45, 13) ;
        cout << "#4 Use The e Key To Turn on Music " << endl ;
        gotoXY(45, 14) ;
        cout << "#5 Enter 1 For Play Game" << endl ;
        gotoXY(45, 15) ;
        cout << "#6 Enter 3 For Come Back Menu" << endl ;
        gotoXY(45, 16) ;
        cout << "#7 Enter Space for Exit game" << endl ;
}

void out_put3(Car my_car)
{

    gotoXY (85, 15);
	cout << "----" << my_car.Name_Car <<"----" << endl ;
	gotoXY(85 ,16) ;
	cout << "Your Scores is : " << my_car.scores ;
	gotoXY(85 ,17) ;
	cout << "R : Turn off Music " << endl ;
	gotoXY(85, 18) ;
	cout << "E : Turn on Music " << endl ;
	gotoXY(85, 19) ;
	cout << "Esc : Exit Game " << endl ;

}

void Make(Car &my_car, Prevent &my_prevent)
{
	//------ Xe

    #define Thep my_car.my_shape.m

	my_car.scores = 0;
	my_car.my_coordinates.x = 56;
	my_car.my_coordinates.y = 23;

	Thep[0][0] = Thep[2][0] ='o';	// bánh xe
	Thep[0][2] = Thep[2][2] = 'O' ;
	Thep[1][0] = '^' ;	// đầu xe
	Thep[0][1] = Thep[2][1] = ' ';	// thân xe
	Thep[1][2] = '=' ;
	Thep[1][1] = char(179);

	//---------vật cản

	my_prevent.my_coordinates.x = 45 + rand() % 19 ; // khởi tạo vị trí ban đầu ngẫu nhiên cho vật cản
	my_prevent.my_coordinates.y = -5 ;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++){
         my_prevent.my_shape.m[i][j] = char(237);
    }

    //--------------

    my_prevent.my_coordinates.x1 = 45 + rand() % 19 ;
	my_prevent.my_coordinates.y1 = -20 ;

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++){
         my_prevent.my_shape.m1[i][j] = '$';
    }

    //--------------

    my_prevent.my_coordinates.x2 = 45 + rand() % 19 ;
	my_prevent.my_coordinates.y2 =  -100 ;

    my_prevent.my_shape.m2[0][0] = '+' ;

    //-------------------

    my_prevent.my_coordinates.x3 = 45 + rand() % 19 ; // khởi tạo vị trí ban đầu ngẫu nhiên cho vật cản
	my_prevent.my_coordinates.y3 = 40 ;

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 4; j++){
         my_prevent.my_shape.m3[i][j] = char(237);
    }

    //--------------

    my_prevent.my_coordinates.x4 = 45 + rand() % 19 ; // khởi tạo vị trí ban đầu ngẫu nhiên cho vật cản
	my_prevent.my_coordinates.y4 = -10 ;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++){
         my_prevent.my_shape.m4[i][j] = char(237);
    }


}

void Display (Car &my_car, Prevent &my_prevent )
{
	clrscr();

	//  3 hai biên

	TextColor (ColorCode_Green);
	for (int i = 0; i < 30 ; i++){
	    gotoXY(44, i) ;
        cout << char(199) ;
    }
	for (int i = 0; i < 30 ; i++){
		gotoXY(68, i) ;
		cout << char(182) ;
	}
	TextColor(ColorCode_DarkYellow) ;
	for (int i = 0; i < 30 ; i++){
        gotoXY(56 , i) ;
        cout << "|" ;
	}

	//------------------Xe

	TextColor (ColorCode_Cyan);
	for (int i = -1 ; i <= 1 ; i++)
		for (int j = -1 ; j <= 1 ; j++)
		{
			int x = i + my_car.my_coordinates.x ;
			int y = j + my_car.my_coordinates.y ;

			gotoXY (x, y);
			cout << my_car.my_shape.m[i + 1][j + 1] ;
		}

    //------------

    TextColor(ColorCode_Grey) ;

	for (int i = -1 ; i <= 1 ; i++)
		for (int j = -1 ; j <= 1 ; j++)
		{
			int x = i + my_prevent.my_coordinates.x ;
			int y = j + my_prevent.my_coordinates.y ;
            if(y >= 0 && y < 30){
                gotoXY (x, y);
                cout << my_prevent.my_shape.m[i + 1][j + 1] ;
            }

		}

    //----------------

	for (int i = -1 ; i <= 0 ; i++)
		for (int j = -1 ; j <= 0 ; j++)
		{
			int x1 = i + my_prevent.my_coordinates.x1 ;
			int y1 = j + my_prevent.my_coordinates.y1 ;

		if(y1 >= 0 && y1 < 30){
                gotoXY (x1, y1);
                cout << my_prevent.my_shape.m1[i + 1][j + 1] ;
            }
		}

    //-----------------

			int x2 = my_prevent.my_coordinates.x2 ;
			int y2 = my_prevent.my_coordinates.y2 ;
			if(y2 >= 0 && y2 < 30){
                gotoXY (x2, y2);
                cout << my_prevent.my_shape.m2[0][0] ;
            }

    //-------------

	for (int i = -1 ; i <= 0 ; i++)
		for (int j = -1 ; j <= 2 ; j++)
		{
			int x3 = i + my_prevent.my_coordinates.x3 ;
			int y3 = j + my_prevent.my_coordinates.y3 ;
            if(y3 >= 0 && y3 < 30){
                gotoXY (x3, y3);
                cout << my_prevent.my_shape.m3[i + 1][j + 1] ;
            }
		}

    //----------------

		for (int i = -1 ; i <= 1 ; i++)
            for (int j = -1 ; j <= 1 ; j++)
            {
			int x4 = i + my_prevent.my_coordinates.x4 ;
			int y4 = j + my_prevent.my_coordinates.y4 ;
            if(y4 >= 0 && y4 < 30){
                gotoXY (x4, y4);
                cout << my_prevent.my_shape.m4[i + 1][j + 1] ;
            }

		}

	//----------------Điểm số

	TextColor(ColorCode_DarkPink) ;
	out_put3(my_car) ;

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
            my_car.my_coordinates.y -= 2 ;
        else if ((key == 'S' || key == 's') && my_car.my_coordinates.y < 26)
            my_car.my_coordinates.y += 2  ;
        else if(key == 'r')
            Sound_Game(4) ;
        else if(key == 'e')
            Sound_Game(1) ;
        else if(key == char(27))
            Sound_Game(4) ;
	}
}

int Process (Car &my_car , Prevent &my_prevent , int &time_sleep)
{

	my_prevent.my_coordinates.y++ ;                         // vật đi xuống tạo cảm giác xe đang di chuyển
	my_prevent.my_coordinates.y1 += 2 ;
    my_prevent.my_coordinates.y2++ ;
    my_prevent.my_coordinates.y3-- ;
    my_prevent.my_coordinates.y4++ ;

    //------------------------

    int dX = abs (my_car.my_coordinates.x - my_prevent.my_coordinates.x);
	int dY = abs (my_car.my_coordinates.y - my_prevent.my_coordinates.y) ;    // khoảng cách (điều kiện) để xảy ra câu lệnh trong khối if


	int dX1 = abs (my_car.my_coordinates.x - my_prevent.my_coordinates.x1);
	int dY1 = abs (my_car.my_coordinates.y - my_prevent.my_coordinates.y1) ;


	int dX2 = abs (my_car.my_coordinates.x - my_prevent.my_coordinates.x2);
	int dY2 = abs (my_car.my_coordinates.y - my_prevent.my_coordinates.y2) ;


	int dX3 = abs (my_car.my_coordinates.x - my_prevent.my_coordinates.x3);
	int dY3 = abs (my_car.my_coordinates.y - my_prevent.my_coordinates.y3) ;

	int dX4 = abs (my_car.my_coordinates.x - my_prevent.my_coordinates.x4);
	int dY4 = abs (my_car.my_coordinates.y - my_prevent.my_coordinates.y4) ;

	//---------------------vật cản 1

	if (my_prevent.my_coordinates.y > my_car.my_coordinates.y)
	{
	    my_car.scores += 100 ;

		my_prevent.my_coordinates.x = 46 + rand() % 19 ;
		my_prevent.my_coordinates.y = -5 ;                  //vị trí tiếp theo mà vật sẽ di chuyển đến

		if (time_sleep > 15)
			time_sleep -= 7;
	}

	//------------------vật cản 2

	if(dY1 <= 2 && dX1 < 3)
    {
        my_prevent.my_coordinates.x1 = 46 + rand() % 19 ;
		my_prevent.my_coordinates.y1 = -20 ;

        my_car.scores += 205 ;
        time_sleep += 14 ;
    }
    else if(my_prevent.my_coordinates.y1 > 30)
    {
        my_prevent.my_coordinates.x1 = 46 + rand() % 19 ;
		my_prevent.my_coordinates.y1 = -20 ;
        my_car.scores += 100 ;
    }

    //-------------------vật cản 3

    if(dY2 <= 2 && dX2 < 3)
    {
        my_prevent.my_coordinates.x2 = 46 + rand() % 19 ; // Vật phẩm đặc biệt nên cho chạy từ -150
        my_prevent.my_coordinates.y2 = -150 ;

        my_car.scores += 300 ;
        time_sleep += 40 ;

    }
    else if (my_prevent.my_coordinates.y2 > 30)
    {
        my_prevent.my_coordinates.x2 = 46 + rand() % 19 ;
        my_prevent.my_coordinates.y2 = -150 ;
        my_car.scores -= 200 ;
    }

  //--------------------

  if (my_prevent.my_coordinates.y3 < 0)
	{
	    my_car.scores += 200 ;

		my_prevent.my_coordinates.x3 = 46 + rand() % 19 ;
		my_prevent.my_coordinates.y3 = 50 ;

	}

    //----------------

    if (my_prevent.my_coordinates.y4 > 30)
	{
	    my_car.scores += 100 ;

		my_prevent.my_coordinates.x4 = 46 + rand() % 19 ;
		my_prevent.my_coordinates.y4 = -30 ;                  //khởi tạo vị trí tiếp theo mà vật sẽ di chuyển đến

	}

	// ----------- Va chạm

    if ((dY <= 2 && dX < 3)||(dY3 <= 2 && dX3 < 3)||(dY4 <= 2 && dX4 < 3))
	{
       // Sound_Game(2) ;
		return -1 ;
	}
    else
        return 0 ;

}

void Play()
{
    Sound_Game(1) ;

    srand (time (0));

	Car my_car ;
	Prevent my_prevent ;

	Make(my_car , my_prevent) ;

	int Count = 0 ;
	int time_sleep = 150 ;

    clrscr() ;
	gotoXY(45 , 11) ;
    cout << "Enter Your name :" ;
    fflush(stdin) ;
    getline(cin, my_car.Name_Car) ;

	while (1)
            {
                //----------------

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

                //---------------

                Sleep (time_sleep);
            }
}

void Run_Game()
{
    //Sound_Game(3) ;

    out_put1() ;
    while(true)
    {
        if(kbhit())
        {
            char number = getch() ;
            if(number == '1'){
                Play() ;
            }
            else if(number == '2'){
                clrscr() ;
                out_put2() ;
            }
            else if(number == '3'){
                clrscr() ;
                out_put1() ;
            }
            else if(number != '1' && number != '2' && number != 3){
                break ;
            }

        }
    }
}

int main()
{

    Run_Game() ;

	return 0;
}
