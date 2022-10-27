// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream> 
#include <thread>
#include <vector> 
#include <chrono> 
#include "graphics.h"
#pragma comment(lib,"graphics.lib")
#define _USE_MATH_DEFINES
#include <cmath>
#include <windows.h>

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

using namespace std;
float M_PI = 3.14;
class Figure { 

protected:

	double x0;
	double y0;
	double r_angle;
	double s_factor;

public:

	
	void setCoordX0(double x0) {
		this->x0 = x0;
	}

	void setCoordY0(double y0) {
		this->y0 = y0;
	}

	void setRotateAngle(double r_angle) {
		this->r_angle = r_angle;
	}

	void setScaleFactor(double s_factor) {
		this->s_factor = s_factor;
	}

	

	double getCoordX0() {
		return x0;
	}

	double getCoordY0() {
		return y0;
	}

	double getRotateAngle() {
		return r_angle;
	}

	double getScaleFactor() {
		return s_factor;
	}



	virtual void create_figure() = 0;
	virtual void rotate_figure() = 0;
	virtual void destroy_figure() = 0;
	virtual void move_figure() = 0;
	virtual void scale_figure() = 0;
};


class Tetragon : public Figure { //Класс-потомок (четырехугольник)

private:

	double x1;
	double y1;
	double x2;
	double y2;
	double x3;
	double y3;
	double x4;
	double y4;

public:

	

	void setCoordX1(double x1) {
		this->x1 = x1;
	}

	void setCoordY1(double y1) {
		this->y1 = y1;
	}

	void setCoordX2(double x2) {
		this->x2 = x2;
	}

	void setCoordY2(double y2) {
		this->y2 = y2;
	}

	void setCoordX3(double x3) {
		this->x3 = x3;
	}

	void setCoordY3(double y3) {
		this->y3 = y3;
	}

	void setCoordX4(double x4) {
		this->x4 = x4;
	}

	void setCoordY4(double y4) {
		this->y4 = y4;
	}

	

	double getCoordX1() {
		return x1;
	}

	double getCoordY1() {
		return y1;
	}

	double getCoordX2() {
		return x2;
	}

	double getCoordY2() {
		return y2;
	}

	double getCoordX3() {
		return x3;
	}

	double getCoordY3() {
		return y3;
	}

	double getCoordX4() {
		return x4;
	}

	double getCoordY4() {
		return y4;
	}

	

	void create_figure() { //Функция рисования фигуры

		cout << "Enter a tetragon coords:\n";
		cout << "x1 = ";
		cin >> x1;
		cout << "y1 = ";
		cin >> y1;
		cout << "x2 = ";
		cin >> x2;
		cout << "y2 = ";
		cin >> y2;
		cout << "x3 = ";
		cin >> x3;
		cout << "y3 = ";
		cin >> y3;
		cout << "x4 = ";
		cin >> x4;
		cout << "y4 = ";
		cin >> y4;
		cout << "Enter tetragon center coords:\n";
		cout << "x0 = ";
		cin >> x0;
		cout << "y0 = ";
		cin >> y0;

		setcolor(9); 
		circle(x0, y0, 3); //Изображаем центр фигуры (вокруг него происходит вращение)
		setcolor(4);

		line(x1, y1, x2, y2);
		line(x2, y2, x3, y3);
		line(x3, y3, x4, y4);
		line(x4, y4, x1, y1);

		setCoordX1(x1);
		setCoordY1(y1);
		setCoordX2(x2);
		setCoordY2(y2);
		setCoordX3(x3);
		setCoordY3(y3);
		setCoordX4(x4);
		setCoordY4(y4);
		setCoordX0(x0);
		setCoordY0(y0);

		getch();
	}

	void rotate_figure() { //Функция поворота фигуры на заданный угол

		double nx1;
		double ny1;
		double nx2;
		double ny2;
		double nx3;
		double ny3;
		double nx4;
		double ny4;

		x0 = getCoordX0();
		y0 = getCoordY0();
		x1 = getCoordX1();
		y1 = getCoordY1();
		x2 = getCoordX2();
		y2 = getCoordY2();
		x3 = getCoordX3();
		y3 = getCoordY3();
		x4 = getCoordX4();
		y4 = getCoordY4();

		for (int i = 0; i <= r_angle; i++) {

			nx1 = cos(i * 3.14 / 180) * (x1 - x0) - sin(i * M_PI / 180) * (y1 - y0) + x0;
			ny1 = sin(i * M_PI / 180) * (x1 - x0) + cos(i * M_PI / 180) * (y1 - y0) + y0;
			nx2 = cos(i * M_PI / 180) * (x2 - x0) - sin(i * M_PI / 180) * (y2 - y0) + x0;
			ny2 = sin(i * M_PI / 180) * (x2 - x0) + cos(i * M_PI / 180) * (y2 - y0) + y0;
			nx3 = cos(i * M_PI / 180) * (x3 - x0) - sin(i * M_PI / 180) * (y3 - y0) + x0;
			ny3 = sin(i * M_PI / 180) * (x3 - x0) + cos(i * M_PI / 180) * (y3 - y0) + y0;
			nx4 = cos(i * M_PI / 180) * (x4 - x0) - sin(i * M_PI / 180) * (y4 - y0) + x0;
			ny4 = sin(i * M_PI / 180) * (x4 - x0) + cos(i * M_PI / 180) * (y4 - y0) + y0;

			this_thread::sleep_for(chrono::microseconds(500));
			cleardevice();

			line(nx1, ny1, nx2, ny2);
			line(nx2, ny2, nx3, ny3);
			line(nx3, ny3, nx4, ny4);
			line(nx4, ny4, nx1, ny1);

		}

		setCoordX1(nx1);
		setCoordY1(ny1);
		setCoordX2(nx2);
		setCoordY2(ny2);
		setCoordX3(nx3);
		setCoordY3(ny3);
		setCoordX4(nx4);
		setCoordY4(ny4);

		getch();
	}

	void move_figure() { //Функция перемещения фигуры на заданный вектор

		int x, y;
		double x_end, y_end;

		cout << "Enter a new vector coords:\n";
		cout << "x_end = ";
		cin >> x_end;
		cout << "y_end = ";
		cin >> y_end;

		x1 += x_end;
		y1 += y_end;
		x2 += x_end;
		y2 += y_end;
		x3 += x_end;
		y3 += y_end;
		x4 += x_end;
		y4 += y_end;
		x0 += x_end;
		y0 += y_end;

		for (x = 0, y = 0; x <= fabs(x_end), y <= fabs(y_end); x++, y++) {

			this_thread::sleep_for(chrono::microseconds(500));
			cleardevice();

			line(x1, y1, x2, y2);
			line(x2, y2, x3, y3);
			line(x3, y3, x4, y4);
			line(x4, y4, x1, y1);
		}

		setCoordX1(x1);
		setCoordY1(y1);
		setCoordX2(x2);
		setCoordY2(y2);
		setCoordX3(x3);
		setCoordY3(y3);
		setCoordX4(x4);
		setCoordY4(y4);
		setCoordX0(x0);
		setCoordY0(y0);

		getch();
	}

	void scale_figure() { //Функция масштабирования фигуры (четырехугольника) относительно заданного центра

		double x1_n = x0 * (1 - s_factor) + x1 * s_factor;
		double y1_n = y0 * (1 - s_factor) + y1 * s_factor;
		double x2_n = x0 * (1 - s_factor) + x2 * s_factor;
		double y2_n = y0 * (1 - s_factor) + y2 * s_factor;
		double x3_n = x0 * (1 - s_factor) + x3 * s_factor;
		double y3_n = y0 * (1 - s_factor) + y3 * s_factor;
		double x4_n = x0 * (1 - s_factor) + x4 * s_factor;
		double y4_n = y0 * (1 - s_factor) + y4 * s_factor;

		cleardevice();

		line(x1_n, y1_n, x2_n, y2_n);
		line(x2_n, y2_n, x3_n, y3_n);
		line(x3_n, y3_n, x4_n, y4_n);
		line(x4_n, y4_n, x1_n, y1_n);

		setCoordX1(x1_n);
		setCoordY1(y1_n);
		setCoordX2(x2_n);
		setCoordY2(y2_n);
		setCoordX3(x3_n);
		setCoordY3(y3_n);
		setCoordX4(x4_n);
		setCoordY4(y4_n);
		setCoordX0(x0);
		setCoordY0(y0);

		getch();
	}

	void destroy_figure() { //Функция уничтожения изображения
		cleardevice();
		getch();
	}

	//Конструктор по умолчанию

	Tetragon() {
		initwindow(800, 600);
		setScaleFactor(2);
		setRotateAngle(270);
	}
};


int main() {
	Figure** figure = new Figure*[3]; //Определяем массив указателей на абстрактный класс, которым присваиваются адреса объектов производных классов
	figure[0] = new Tetragon(); //Объявляем указатель на производный класс (четырехугольник)
	figure[0]->create_figure(); //Создаем фигуру типа четырехугольник
	figure[0]->move_figure(); //Перемещаем фигуру на заданный вектор
	figure[0]->setScaleFactor(7); //Задаем масштабный фактор (увеличение)
	figure[0]->scale_figure(); //Масштабируем фигуру
	figure[0]->setRotateAngle(270); //Задаем угол поворота в градусах
	figure[0]->rotate_figure(); //Поворачиваем фигуру
	figure[0]->setScaleFactor(0.5); //Задаем масштабный фактор (уменьшение) 
	figure[0]->scale_figure(); //Масштабируем фигуру

					 
							  
	closegraph();
	return 0;
}