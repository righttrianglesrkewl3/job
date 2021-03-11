#ifndef CIRCLE_H
#define CIRCLE_H //  these make sure we dont define more than one header



// declarations go in header
class Circle: public Shape{

public:
    Circle();
    Circle(double width);
    virtual ~Circle();
    double Area();

protected:

private:

};

#endif /* CIRCLE_H */