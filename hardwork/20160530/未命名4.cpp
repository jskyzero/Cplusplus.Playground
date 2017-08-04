#include <iostream>


using namespace std;
class Point;

class Vector {
	public:
		Vector() : x_(0),y_(0) {}
		Vector(int x , int y) : x_(x),y_(y) {}
		/* COPY constructor */
		Vector(const Vector &other) {
			this->x_ = other.x_;
			this->y_ = other.y_;
		}
		Vector operator+(const Vector &other) {
			Vector temp(this->x_ + other.x_,this->y_ + other.y_);
			return temp;
		}
		/* declare as friend function for class Vector */
		friend Point operator+(const Point & point , const Vector &other);
		/* overload operator < < , format : " 1 2 " */
		friend  ostream& operator<<(ostream &out , const Vector &vect);
	private:
		int x_;
		int y_;
};
ostream& operator<<(ostream &out , const Vector &vect) {
	out << vect.x_ << " " << vect.y_;
	return out;
}

class Point {
	public:
		Point() : x_(0),y_(0) {}
		Point(int x , int y): x_(x),y_(y) {}
		/* COPY constructor */
		Point(const Point &other) {
			this->x_ = other.x_;
			this->y_ = other.y_;
		}
		/* declare as friend function for class Point */
		friend Point operator+(const Point & point , const Vector &vect);
		/* overload operator < < , format : " 1 2 " */
		friend ostream& operator<<(ostream &out , const Point &point);

	private:
		int x_;
		int y_;
};
ostream& operator<<(ostream &out , const Point &point) {
	out << point.x_ << " " << point.y_;
	return out;
}
Point operator+(const Point & point , const Vector &other) {
			Point temp(point.x_ + other.x_,point.y_ + other.y_);
			return temp;
}

int main() {
	Vector a(1,2);
	Vector b(4,5);
	Point  c(1,2);
	cout << a <<endl;
	cout << b <<endl;
	cout << c <<endl;
	cout << a + b <<endl;
	cout << c + a <<endl;
}



