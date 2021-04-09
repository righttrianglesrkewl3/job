#include <iostream>
#include <cmath>
using namespace std;

/ / Point class definition
class Point {
public:
	Point(int xx = 0, int yy = 0) {/ / The constructor is defined, no need to implement outside the class
		x = xx;
		y = yy;
	}
	Point(Point &p);/ / Copy the constructor declaration
	int getX() { return x; }// member function
	int getY() { return y; }// member function
private:
	int x, y;
};

Point::Point(Point &p) {	/ / Copy the implementation of the constructor
	x = p.x;
	y = p.y;
	cout << "Calling the copy constructor of Point" << endl;
}

/ / class combination
class Line {	//Line class definition
public:
	Line(Point xp1, Point xp2);/ / The declaration of the constructor of the combination class Line (there are only the formal parameters required by the object (Point class object) member, there is no formal parameter required by the member of this class)
	Line(Line &l);/ / Copy the constructor declaration
	double getLen() { return len; }// member function
private://Among the private members, there are two object members p1 of the Point class.,p2
	Point p1, p2;	//Point object p1, p2
	double len;
};

/ / Combine class constructor
Line::Line(Point xp1, Point xp2) : p1(xp1), p2(xp2) {/ / The parameter table inside the real combination, generate two local Point class objects xp1 and xp2 (call the Point class copy constructor twice)
													/ / Then initialize the list, use the existing objects (xp1 and xp2) to initialize the new Point class object p1, p2 (call the Point class copy constructor again)
	cout << "Calling constructor of Line" << endl;
	double x = static_cast<double>(p1.getX() - p2.getX());
	double y = static_cast<double>(p1.getY() - p2.getY());
	len = sqrt(x * x + y * y);
}

/ / Combination class copy constructor
Line::Line(Line &l) : p1(l.p1), p2(l.p2) {/ / Use the existing Line class object l to initialize a new Line class object (l is a reference to the object line)
					/ / Initialize the list to follow the same rules as the composite class constructor! To list object 1 (parameters), object 2 (parameters),...
	cout << "Calling the copy constructor of Line" << endl;
	len = l.len;
}

/ / main function
int main() {
	Point myp1(1, 1), myp2(4, 5);	/ / Set up the object of the Point class
	Line line(myp1, myp2);	/ / Create a line class object
	Line line2(line);	/ / Use the copy constructor to create a new object
	cout << "The length of the line is: ";
	cout << line.getLen() << endl;
	cout << "The length of the line2 is: ";
	cout << line2.getLen() << endl;
	return 0;
}

