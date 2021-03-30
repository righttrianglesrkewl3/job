// Refer to the declarations in the header
#include "Shape.h"
 
// This file is called the implementation file


// constructors/destructor/static
Shape::Shape(double length){
    this->height = length;
    this->width = length;
}

Shape::Shape(double height, double width){
    this->height = height;
    this->width = width;
}

Shape::~Shape() = default;

int Shape::GetNumOfShapes() {return numOfShapes;}

int Shape::numOfShapes = 0;

// set/get
void Shape::SetHeight(double height){
    this->height = height;
}

double Shape::GetHeight() {return height;}

void Shape::SetWidth(double width) {
    this->width = width;
}

double Shape::GetWidth() {return width;}

double Shape::Area(){
    return height * width;
}
 
 
// virtual Area() function
// polymorphism
// any method marked as virtual can be used polymorphically
// basically, base class can "morph" into derived classes 
// i.e.; feature in which similar objects can be treated the same
// call rectangle/circle as shapes...however correct area function is called "on-demand" for that particlar "kind" of shape..thats the base class "morphing" into a circle to perform get Area for a circle (for example)