#include <iostream>
#include <cmath>
using namespace std;

class Figure
{
public:
	Figure();
	virtual ~Figure();
	virtual void show() = 0;
	virtual double calcArea() = 0;
};

class Circle : public Figure {
public:
	Circle();
	Circle(int);
	virtual ~Circle();
	virtual void show();
	virtual double calcArea();
	int get_R();
private:
	int* r;
};

class Rectangle : public Figure
{
public:
	Rectangle();
	Rectangle(int, int);
	virtual ~Rectangle();
	virtual void show();
	virtual double calcArea();
	int get_A();
	int get_B();
private:
	int* a, * b;
};
class Treangle : public Figure
{
public:
	Treangle();
	Treangle(int, int);
	virtual ~Treangle();
	virtual void show();
	virtual double calcArea();
	int get_A();
	int get_H();
private:
	int* a, * h;
};

double volumeFigure(Figure* F, int h);



Figure::Figure() { cout << "Вызван конструктор Figure();"; }
Figure::~Figure() { cout << "Вызван деструктор ~Figure();"; }

// Конструкторы Круга

Circle::Circle() : Figure() {
	cout << "Вызван конструктор Circle() : Figure();";
	r = new int;
}

Circle::Circle(int r1) : Figure() {
	cout << "Вызван конструктор Circle(int r1) : Figure();";
	r = new int;
	*r = r1;
}

Circle::~Circle() {
	delete r;
}

int Circle::get_R() {
	return *r;
}
void Circle::show() {
	cout << "\nCircleInfo:\n r - " << *r << endl;
}
double Circle::calcArea() {
	return 3.14 * pow(*r, 2);
}

// Конструкторы прямоугольника

Rectangle::Rectangle() : Figure() {
	cout << "Вызван конструктор Circle() : Figure();";
	a = new int;
	b = new int;
}

Rectangle::Rectangle(int a1, int b1) : Figure() {
	cout << "Вызван конструктор Rectangle(int a1, int b1) : Figure();";
	a = new int;
	b = new int;
	*a = a1;
	*b = b1;
}

Rectangle::~Rectangle() {
	delete a, b;
}

void Rectangle::show() {
	cout << "\nRectangleInfo:" << "\n a - " << *a << "\n b - " << *b << endl;
}
double Rectangle::calcArea() {
	return *a * *b;
}

// Конструкторы треугольника

Treangle::Treangle() : Figure() {
	cout << "Вызван конструктор Circle() : Figure();";
	a = new int;
	h = new int;
}

Treangle::Treangle(int a1, int h1) : Figure() {
	cout << "Вызван конструктор Treangle(int a1, int h1) : Figure();";
	a = new int;
	h = new int;
	*a = a1;
	*h = h1;
}

Treangle::~Treangle() {
	delete a, h;
}

void Treangle::show() {
	cout << "\nTreangleleInfo:" << "\n a - " << *a << "\n h - " << *h << endl;
}
double Treangle::calcArea() {
	return *a * *h * 0.5;
}

int Treangle::get_A() {
	return *a;
}

int Treangle::get_H() {
	return *h;
}

double volumeFigure(Figure* F, int h) {
	return F->calcArea() * h;
}

int main() {
	setlocale(LC_ALL, "rus");
	int s = 0;;
	Figure* F = nullptr; // ситуативно (!)
	cout << "Выберите нужный пункт: \n1. Круг\n2. Прямоугольник\n3. Треугольник" << endl;
	cin >> s;
	switch (s) {
	case 1: F = new Circle(5);
		F->show();
		cout << "Площадь выбранной вами фигуры: " << F->calcArea() << endl;
		cout << "Объем выбранной фигуры: " << volumeFigure(F, 3) << endl; 	
		break;
	case 2: F = new Rectangle(3, 4);
		F->show();
		cout << "Площадь выбранной вами фигуры:  " << F->calcArea() << endl;
		cout << "Объем выбранной фигуры: " << volumeFigure(F, 3) << endl; 	
		break;
	case 3: F = new Treangle(3, 5);
		F->show();
		cout << "Площадь выбранной фигуры:  " << F->calcArea() << endl;
		cout << "Объем выбранной фигуры: " << volumeFigure(F, 3) << endl; 
		break;
	default:
		cout << "Ошибка, неверный пункт!" << endl;
		break;
	}
}