#include <iostream>
#include <cstdlib>
// KZ 3-11-21
// USAGE: g++ *.cpp -o output
// ./output

#include <string>
#include <limits>
#include <string>
#include <vector>
#include <sstream>
#include <numeric>
#include <ctime>
#include <cmath>

// include headers
#include "Shape.h"
#include "Circle.h"
using namespace std;


void ShowArea(Shape& shape);

void ShowArea2(Shape& shape, int& number);

void ShowArea3(Shape& shape, int* pNumber);

void ShowArea4(Shape& shape, int* pNumber);

void ChangeHeightSquare(Shape& shape,int newHeight);

int main()
{

    int height;
    height = 10;

    int* pHeight = &height;

    Shape square(10, 5);
    ShowArea(square);


    ShowArea2(square, height);
    cout << "height = " << height << endl;


    ShowArea3(square, pHeight);
    cout << "height = " << height << endl;

    ShowArea4(square, &height);
    cout << "height = " << height << endl;

    ChangeHeightSquare(square, 2);


}

void ShowArea(Shape& shape){
    cout << "Area : " << shape.Area() << endl;
}

void ShowArea2(Shape& shape, int& number){
    number = 25; 
}

void ShowArea3(Shape& shape, int* pNumber){
    *pNumber = 77; 
}

void ShowArea4(Shape& shape, int* pNumber){
    *pNumber = 77; 
}

void ChangeHeightSquare(Shape& shape, int newHeight){
    shape.SetHeight(newHeight); 
    cout << "Changed shape height = " 
        << shape.GetHeight() << endl;
}