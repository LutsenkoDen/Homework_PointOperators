#include <cmath>
#include<iostream>
using namespace std;

/*	TODO:	����������� ���������: -, -=, prefix --, ssuffix --, >>  */

//#define ENCAPSULATION
//#define DISTANCE_CHECK
//#define CONSTRUCTORS_CHECK
//#define ASSIGNMENT_CHECK
//#define ARITHMETIC_AND_ASSIGNMENTS_CHECK

class Point
{
	double x;
	double y;
public:
	const double& get_x() const
	{
		return x;
	}
	double& get_x()
	{
		return x;
	}
	const double& get_y() const
	{
		return y;
	}
	double& get_y()
	{
		return y;
	}
	void set_x(double x)
	{
		//if (x > 100)this->x = 100;
		//else
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
	//  Constructors
	//Point()
	//{
	//	//����������� �� ��������� ()
	//	x = y = double();
	//	cout << "DefaultConstructor:" << this << endl;
	//}
	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t " << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor: " << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t " << this << endl;
	}
	//Operators
	Point operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t " << this << endl;
		return *this;
	}
	Point& operator+(const Point& other)
	{
		Point temp;
		temp.x = this->x + other.x;
		temp.y = this->y + other.y;
		return temp;
	}
	Point& operator-(const Point& other)
	{
		Point temp;
		temp.x = this->x - other.x;
		temp.y = this->y - other.y;
		return temp;
	}
	Point& operator+=(const Point& other)
	{
		this->x += other.x;
		this->y += other.y;
		return *this;
	}
	Point& operator-=(const Point& other)
	{
		this->x -= other.x;
		this->y -= other.y;
		return *this;
	}
	//Increment/Decrement
	Point& operator++() // ����������
	{
		this->x++;
		this->y++;
		return *this;
	}
	Point operator++(int) // ����������� 
	{
		Point temp = *this;
		this->x++;
		this->y++;
		return temp;
	}
	Point& operator--() // ����������
	{
		this->x--;
		this->y--;
		return *this;
	}
	Point operator--(int) // ����������� 
	{
		Point temp = *this;
		this->x--;
		this->y--;
		return temp;
	}
	// Methods
	double distance(Point other) //����� ��������� ���������� �� ��������� �����
	{
		/*double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		return sqrt(x_distance*x_distance + y_distance*y_distance);*/
		//return sqrt(pow(this->x-other.x,2) + pow(this->y-other.y,2));
		return pow(pow(this->x - other.x, 2) + pow(this->y - other.y, 2), 0.5);
	}
	void print()
	{
		cout << "x= " << x << "\ty= " << y << endl;
	}
	friend istream& operator>>(istream& is, Point& obj);
};

Point operator+(const Point& left, const Point& right)
{
	/*Point temp(left.get_x() + right.get_x(), left.get_y() + right.get_y());*/
	/*temp.set_x(left.get_x() + right.get_x());
	temp.set_y(left.get_y() + right.get_y());*/
	return Point(left.get_x() + right.get_x(), left.get_y() + right.get_y());
}

Point operator-(const Point& left, const Point& right)
{
	/*Point temp(left.get_x() - right.get_x(), left.get_y() - right.get_y());*/
	/*temp.set_x(left.get_x() - right.get_x());
	temp.set_y(left.get_y() - right.get_y());*/
	return Point(left.get_x() - right.get_x(), left.get_y() - right.get_y());
}

ostream& operator<<(ostream& os, const Point& obj)
{
	os << "x= " << obj.get_x() << "\ty= " << obj.get_y();
	return os;
}

istream& operator>>(istream& is, Point& obj)
{
	/*double x, y;
	is >> x >> y;
	obj.set_x(x);
	obj.set_y(y);*/
	/*is >> obj.x >> obj.y;
	return is;*/
	return is >> obj.get_x() >> obj.get_y();
}

double distance(Point A, Point B)//������� ��������� ���������� �� ��������� �����
{
	/*double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	return sqrt(pow(x_distance, 2) + pow(y_distance, 2));*/
	return sqrt(pow(A.get_x() - B.get_x(), 2) + pow(A.get_y() - B.get_y(), 2));
}

int main()
{
	setlocale(LC_ALL, "Russian");
#ifdef ENCAPSULATION
	int a;
	Point A;
	double x, y;
	cout << "������� ���������� �����: "; cin >> x >> y;
	A.set_x(x);
	A.set_y(y);
	cout << A.get_x() << "\t" << A.get_y() << endl;

	Point* pA = &A;
	cout << pA->get_x() << "\t" << pA->get_y() << endl;
	//	. - �������� ������� ������� (Point operator);
	//	-> - �������� ���������� ������� (Arrow operator);

	Point B;
	B.set_x(55);
	B.set_y(77);
	cout << B.get_x() << "\t" << B.get_y() << endl;
	B.print();
#endif

#ifdef DISTANCE_CHECK
	cout << "\n--------------------------------------" << endl;

	cout << A.distance(B) << endl;
	cout << distance(A, B) << endl;
#endif // DISTANCE_CHECK

#ifdef CONSTRUCTORS_CHECK
	Point A; //Default constructor
	A.print();
	Point B(2, 3); //Constructor
	B.print();

	Point C = B; // CopyConstructor
	C.print();
#endif

#ifdef ASSIGNMENT_CHECK
	/*int a = 2;
	int b = 3;
	a = b;
	Point A(2, 3);
	Point B;
	B = A;*/

	int a, b, c;
	a = b = c = 0;
	Point A, B, C;
	A = B = C = Point(2, 3);
	/*Point D(2, 3);
	A = B = C = D;*/
#endif // ASSIGNMENT_CHECK

#ifdef ARITHMETIC_AND_ASSIGNMENTS_CHECK
	int a = 2;
	int b = 3;
	cout << a + b << endl;
	Point A(2, 3);
	A.print();
	Point B(4, 5);
	B.print();
	Point C = A + B;
	C.print();
	A += B; // ������� ����� ���������
	A.operator+=(B); //����� ����� ���������. �� ���������� ��� ������� ����� ��� ������� �
	A.print();
#endif

	Point A;
	/*A.print();
	Point B = A++;
	B.print();
	cout << B << endl;*/
	/*cout << A++ << endl;
	cout << A << endl;*/

	cout << "������� ���������� �����: "; cin >> A;
	cout << A-- << endl;
	cout << A << endl;
}

/*
//1. ������������ (Encapsulation); get/set-�������
private:
public:
protected:

get/set-������

//2. ������������ (Inheritance);
//3. �����������  (Polymorphism);
*/

//(Default constructor) - 

//UserStep