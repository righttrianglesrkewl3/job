#ifndef SHAPE_H
#define SHAPE_H

class Shape {
    // this class or inherited can access protected fields/methods (aka if circle inherits shape...circle will have access to shapes protected methods)
    protected:
        double height;
        double width;

    public:
        // consturctors/static
        static int numOfShapes; // all objects will have same value here
        Shape(double length);
        Shape(double height, double width);
        Shape(); // not in shape.cpp
        //Shape(const Shape& orig);
        
        // deconstructor called anytime object deleted
        virtual ~Shape();

        // set/get
        void SetHeight(double height);
        double GetHeight();
        void SetWidth(double width);
        double GetWidth();
        static int GetNumOfShapes();
        virtual double Area(); // key to polymorphism
        
        // virtual because plan on overriding; each shape that inherits shape class with have its own Area function
        // plan on providing each shape that plans on inheriting from shape clas to have different area function
        // creating generic shape, then going to inherit height, width, get/set into another class called circle
        // circle will have very specific definition of Area particular to Circles

        

    // subclasses cannot access private memebers if shape gets inherited (so circle couldnt access shapes private memebers if it inherits shape)
    //private:

};


#endif /* SHAPE_H */