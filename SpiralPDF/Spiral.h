#include <iostream>
using namespace std;

// A class that when incremented will produce a spiral
class Spiral {
private:
    double centerX_;
    double centerY_;
    double radius_;
    double angle_;
    double startingRadius_;
    double angleIncrementSize_;

public:
    // Constructor
    Spiral(double centerX, double centerY, double startingRadius, double startingAngle);

    // Overloaded increment operators
    Spiral& operator++();
    Spiral operator++(int);

    // Getters for x, y pos and spiral, text angle
    double getTextX();
    double getTextY();
    double getSpiralAngle();
    double getTextAngle();

    // Overloaded output operator for printing the object
    friend ostream& operator<<(ostream& output, Spiral spiral);
};