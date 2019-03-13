#include <iostream>
#include <time.h>
#include <conio.h>
#include "console.h"

using namespace std ;

struct Coordinates
{
    int x ;
	int y ;	// y là tung độ, x là hoành độ
};


struct Shape
{
	char m[3][3];
};


struct Car
{
	Coordinates my_coordinates ;	// tọa độ tại vị trí hd.a[1][1]
	Shape my_shape ;
	int scores ;
};


struct Prevent
{
	Coordinates my_coordinates ;
	Shape my_shape ;
};


void Make(Car &my_car, Prevent &my_prevent)
{
	//------ Xe
#define pHD my_car.my_shape.m

	my_car.scores = 0;
	my_car.my_coordinates.y = 23;
	my_car.my_coordinates.x = 12;

	pHD[0][0] = pHD[0][2] = pHD[2][0] = pHD[2][2] = 'o';	// bánh xe
	pHD[1][0] = '^';	// đầu xe
	pHD[0][1] = pHD[2][1] = '|';	// thân xe
	pHD[1][2] = '-';
	pHD[1][1] = 'A';


	//---------vật cản

	my_prevent.my_coordinates.x = 2 + rand() % 21;
	my_prevent.my_coordinates.y = -2;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++){
         my_prevent.my_shape.m[i][j] = '*';
    }
}


void Display (Car &my_car, Prevent &my_prevent)
{
	clrscr();

	// hiển thị biên nè

	TextColor (default_ColorCode);
	for (int i = 0; i < 30 ; i++){
		cout << "#" << endl ;
    }
	for (int i = 0; i < 30 ; i++){
		gotoXY (25 , i);
		cout << "#" ;
	}


	// hiển thị xe nè
	TextColor (ColorCode_Cyan);
	for (int i = -1 ; i <= 1 ; i++)
		for (int j = -1 ; j <= 1 ; j++)
		{
			int x = i + my_car.my_coordinates.x ;
			int y = j + my_car.my_coordinates.y ;

			gotoXY (x, y);
			cout << my_car.my_shape.m[i + 1][j + 1] ;
		}


	// hiển thị vật cản nè
	TextColor (ColorCode_Red);
	for (int i = -1 ; i <= 1 ; i++)
		for (int j = -1 ; j <= 1 ; j++)
		{
			int x = i + my_prevent.my_coordinates.x ;
			int y = j + my_prevent.my_coordinates.y ;

			gotoXY (x, y);
			cout << my_prevent.my_shape.m[i + 1][j + 1] ;
		}


	// hiển thị trạng thái game
	gotoXY (27, 10);
	cout << "Your Scores is : " << my_car.scores ;
}


void Controll(Car &my_car)
{
	if (_kbhit())
	{
		int key = _getch() ;

		if ((key == 'A' || key == 'a') && my_car.my_coordinates.x > 2)
			my_car.my_coordinates.x-- ;
		else if ((key == 'D' || key == 'd') && my_car.my_coordinates.x < 23)
			my_car.my_coordinates.x++ ;
        else if ((key == 'W' || key == 'w') && my_car.my_coordinates.y < 30)
            my_car.my_coordinates.y-- ;
        else if ((key == 'S' || key == 's') && my_car.my_coordinates.y < 27)
            my_car.my_coordinates.y++ ;
	}
}

// trả về 0 nếu ko có gì
// trả về -1 tức là va chạm
int Process (Car &my_car , Prevent &my_prevent , int &time_sleep)
{
	// tạo cảm giác xe di chuyển --> vật cản đi xuống dưới
	my_prevent.my_coordinates.y++;


	// nếu vật cản đi xuống dưới đáy tức là xe đã vượt qua vật cản
	// thì tăng điểm
	if (my_prevent.my_coordinates.y > 25)
	{
		my_car.scores++ ;
		my_prevent.my_coordinates.x = 2 + rand() % 22 ;
		my_prevent.my_coordinates.y = -2;

		if (time_sleep > 39)
			time_sleep -= 20;
	}

	// xử lý tình huống va chạm
	int dX = abs (my_car.my_coordinates.x - my_prevent.my_coordinates.x);
	int dY = abs (my_car.my_coordinates.y - my_prevent.my_coordinates.y) ;

	if (dX < 3 && dY < 3)
	{
		return -1 ;
	}


        return 0;
}


int main()
{
	srand (time (NULL));	// khởi tạo bộ sinh số ngẫu nhiên

	Car my_car ;
	Prevent my_prevent ;

	Make(my_car , my_prevent) ;

	int Count = 0 ;
	int time_sleep = 200 ;

	while (1)
	{
		// hiển thị
		Display(my_car , my_prevent) ;

		// điều khiển
		Controll(my_car) ;

		// xử lý
		Count = Process(my_car , my_prevent , time_sleep) ;

		// game over
		if (Count == -1)
		{
			gotoXY (27 , 9);
			cout << "Thua CMNR" ;

			while (_getch() != 13)	;

			break;
		}

		Sleep (time_sleep);
	}


	return 0;
}
