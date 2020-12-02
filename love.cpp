#include <stdio.h>
#include <Windows.h>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <gl/glut.h> //thu vien do hoa
struct rgb
{
	float r;
	float g;
	float b;
};
struct tado
{
	int x;
	int y;
};
char matr[180][120] = { 0 }; //khoi tao ma tran
rgb giam(int pt, rgb ma)
{
	//giam ma rgb xuong pt phan tram
	ma.r = ma.r*pt / 100;
	ma.g = ma.g*pt / 100;
	ma.b = ma.b*pt / 100;
	return ma;
}
void diem(int x, int y, float i, rgb m)
{
	//ve diem thuc x, y do lon i*i pixel, ma mau h
	glColor3f(m.r / 255, m.g / 255, m.b / 255);
	glPointSize(i);
	glBegin(GL_POINTS);
	glVertex2f(x, y);
	glEnd();
	glFlush();
}
void vong(int x, int y, rgb ma)
{
	//ve diem ao 5*5 pixel x, y ma mau trung tam ma
	rgb m;
	x = x * 5;
	y = y * 5;
	m = giam(30, ma);
	diem(x + 2, y + 1, 3, m);
	diem(x + 1, y + 2, 3, m);
	diem(x + 2, y + 3, 3, m);
	diem(x + 3, y + 2, 3, m);
	m = giam(70, ma);
	diem(x + 2, y + 2, 3, m);
	diem(x + 2, y + 2, 1, ma);
}
void xoa(int x, int y)
{
	//xoa diem x, y
	rgb m = { 0 };
	diem(x * 5 + 2, y * 5 + 2, 5, m);
}
tado ngnh()
{
	//lay toa do ngau nhien
	tado t;
	t.x = rand() % 180;
	t.y = rand() % 120;
	return t;
}
int kitra(int x, int y)
{
	//kiem tra x, y co thuoc trai tim ko
	float s = 0, xf, yf;
	xf = float(x - 90) / 40;
	yf = float(y - 60) / 40;
	s = pow(pow(xf, 2) + pow(yf, 2) - 1, 3) - pow(xf, 2)*pow(yf, 3);
	if (s <= 0) return 1;
	return 0;
}
rgb mau()
{
	//lay ma mau rgb ngau nghien
	rgb ma;
	int i, j, rgbx[3];
	srand(time(0));
	i = rand() % 3;
	rgbx[i] = 219;
	j = i;
	while (j == i) j = rand() % 3;
	rgbx[j] = 0;
	rgbx[3 - i - j] = rand() % 220;
	ma.r = rgbx[0];
	ma.g = rgbx[1];
	ma.b = rgbx[2];
	return ma;
}
int capq(int x, int y)
{
	//cap quyen cho diem x, y
	if (kitra(x, y))
	{
		if (matr[x][y] == 0) return 1;
		return 2;
	}
	else
	{
		if (matr[x][y] == 0) return 1;
		if (matr[x][y] == 1) return 0;
		return 2;
	}
}
void tucti(int x, int y, int dk, rgb ma)
{
	//thuc thi doi voi x, y
	switch (dk)
	{
	case 0: xoa(x, y); break;
	case 1: vong(x, y, ma); break;
	}
}
void xoavd()
{
	//xoa vai diem
	int c;
	tado t;
	for (int i = 0; i < 100; i++)
	{
		t = ngnh();
		c = capq(t.x, t.y);
		if (c == 0)
		{
			xoa(t.x, t.y);
			matr[t.x][t.y]++;
		}
	}
}
void ttvd(rgb ma)
{
	//hien 1 diem
	tado t;
	int c, d = 0;
	while (d < 1)
	{
		t = ngnh();
		c = capq(t.x, t.y);
		if (c < 2)
		{
			tucti(t.x, t.y, c, ma);
			matr[t.x][t.y]++;
			d++;
		}
	}
}
int day()
{
	//co phai chua day trai tim ko?
	int i, j;
	for (i = 40; i < 140; i++)
	for (j = 30; j < 120; j++)
	if ((kitra(i, j)) && (matr[i][j] == 0)) return 1;
	return 0;
}
void hotha()
{
	//xoa diem thua
	int i, j;
	for (i = 0; i < 180; i++)
	for (j = 0; j < 120; j++)
	{
		if ((!kitra(i, j)) && (matr[i][j] == 1)) xoa(i, j);
	}
}
int ktt(int x, int y)
{
	//kiem tra chu?
	x -= 54;
	y -= 60;
	//i
	if ((x>0) && (x<5) && (y>-1) && (y<12)) return 1;
	//l
	if ((x>8) && (x<13) && (y>-1) && (y<12)) return 1;
	if ((x>12) && (x<17) && (y>-1) && (y<3)) return 1;
	if ((x == 16) && (y == 3)) return 1;
	//0
	if ((x>20) && (x<23) && (y>2) && (y<5)) return 0;
	if ((x>17) && (x<26) && (y>-1) && (y<8)) return 1;
	//v
	if ((x>29) && (x<32) && (y>-1) && (y<5)) return 1;
	if ((x == 29) && (y>1) && (y<8)) return 1;
	if ((x == 32) && (y>1) && (y<8)) return 1;
	if ((x == 28) && (y>3) && (y<8)) return 1;
	if ((x == 33) && (y>3) && (y<8)) return 1;
	if ((x == 27) && ((y == 6) || (y == 7))) return 1;
	if ((x == 24) && ((y == 6) || (y == 7))) return 1;
	//e
	if (((x == 36) || (x == 37)) && (y == 5)) return 0;
	if ((x>36) && (x<40) && (y>1) && (y<3)) return 0;
	if ((x>34) && (x<40) && (y>-1) && (y<8)) return 1;
	//y
	if (((x == 48) || (x == 49)) && (y == 8)) return 0;
	if ((x == 44) && (y == 7)) return 0;
	if ((x == 53) && (y == 7)) return 0;
	if ((x>46) && (x<51) && (y>8) && (y<12)) return 0;
	if ((x>43) && (x<47) && (y>-1) && (y<7)) return 0;
	if ((x>50) && (x<54) && (y>-1) && (y<7)) return 0;
	if ((x>43) && (x<54) && (y>-1) && (y<12)) return 1;
	//o
	if ((x>57) && (x<60) && (y>2) && (y<5)) return 0;
	if ((x>54) && (x<63) && (y>-1) && (y<8)) return 1;
	//u
	if ((x == 64) && ((y == 0) || (y == 1))) return 0;
	if ((x == 71) && ((y == 0) || (y == 1))) return 0;
	if ((x>66) && (x<69) && (y>2) && (y<8)) return 0;
	if ((x>63) && (x<72) && (y>-1) && (y < 8)) return 1;
	return 0;
}
tado dau(tado v)
{
	//toa do tren
	if (v.x != 71) v.x++;
	else v.y--;
	return v;
}
tado cuoi(tado v)
{
	//toa do cuoi
	if (v.y != 0) v.y--;
	else v.x++;
	return v;
}
void dichu()
{
	//ghi
	int x, y;
	tado v, d, c;
	rgb ma;
	ma.r = 219;
	ma.g = 219;
	ma.b = 219;
	d.x = 0;
	d.y = 13;
	c = d;
	x = d.x + 55;
	y = d.y + 58;
	if (matr[x][y] == 2) return;
	for (int i = 0; i < 4; i++)
	{
		vong(x, y, ma);
		Sleep(300);
		xoa(x, y);
		Sleep(200);
		matr[x][y] = 2;
	}
	do
	{
		d = dau(d);
		c = cuoi(c);
		v = d;
		while ((v.x >= c.x) || (v.y >= c.y))
		{
			x = v.x + 54;
			y = v.y + 58;
			if (ktt(x, y))
			{
				vong(x, y, ma);
				Sleep(30);
				xoa(x, y);
				Sleep(20);
			}
			v.x--;
			v.y--;
		}
	} while ((d.x != c.x) || (d.y != c.y));
}
void tg(rgb hex)
{
	vong(5, 5, hex);
	vong(6, 5, hex);
	vong(6, 6, hex);
	vong(6, 8, hex);
	vong(6, 9, hex);
	vong(6, 10, hex);
	vong(7, 5, hex);
	vong(7, 6, hex);
	vong(7, 8, hex);
	vong(7, 10, hex);
	vong(8, 5, hex);
	vong(8, 6, hex);
	vong(8, 7, hex);
	vong(8, 8, hex);
	vong(8, 10, hex);
	vong(10, 5, hex);
	vong(10, 6, hex);
	vong(10, 7, hex);
	vong(10, 8, hex);
	vong(10, 9, hex);
	vong(10, 10, hex);
	vong(11, 5, hex);
	vong(11, 6, hex);
	vong(11, 7, hex);
	vong(12, 5, hex);
	vong(12, 6, hex);
	vong(12, 7, hex);
	vong(13, 6, hex);
	vong(15, 5, hex);
	vong(15, 6, hex);
	vong(15, 7, hex);
	vong(16, 5, hex);
	vong(16, 7, hex);
	vong(17, 5, hex);
	vong(17, 6, hex);
	vong(17, 7, hex);
	vong(19, 5, hex);
	vong(19, 6, hex);
	vong(19, 7, hex);
	vong(20, 3, hex);
	vong(20, 5, hex);
	vong(20, 6, hex);
	vong(21, 3, hex);
	vong(21, 4, hex);
	vong(21, 5, hex);
	vong(21, 6, hex);
	vong(21, 7, hex);
	vong(22, 9, hex);
	vong(23, 5, hex);
	vong(23, 6, hex);
	vong(23, 7, hex);
	vong(23, 8, hex);
	vong(23, 9, hex);
	vong(25, 5, hex);
	vong(25, 6, hex);
	vong(25, 7, hex);
	vong(25, 8, hex);
	vong(25, 9, hex);
	vong(26, 5, hex);
	vong(26, 7, hex);
	vong(26, 9, hex);
	vong(27, 5, hex);
	vong(27, 6, hex);
	vong(27, 7, hex);
	vong(27, 9, hex);
}
void ve(rgb hex)
{
	rgb m;
	for (int i = 1; i < 101; i++)
	{
		m = giam(i, hex);
		tg(m);
	}
}
void chay()
{
	//bat dau ve
	rgb hex;
	int i, c;
	hex = mau();
	do
	{
		for (i = 0; i < 5; i++)
		{
			ttvd(hex);
			c = day();
			if (!c) break;
		}
		xoavd();
	} while (c);
	hotha();
	Sleep(1000);
	dichu();
	hex = mau();
	Sleep(1500);
	ve(hex);
}
int main(int argc, char** argv)
{
	printf("Sboy16\nName: Ho Van Thep\nMail: loveme05ye@gmail.com");
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH); //thiet lap mang hinh
	glutInitWindowPosition(0, 0); //vi tri xuat hien cua mang hinh
	glutInitWindowSize(900, 600); //do rong mang hinh
	glutCreateWindow("I Love You");
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glOrtho(0.0, 900, 0.0, 600, -1.0, 1.0);
	glutDisplayFunc(chay); //thiet lap ham ve
	glutMainLoop();
	glFinish();
	return 0;
}
