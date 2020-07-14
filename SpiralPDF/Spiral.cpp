#include "Spiral.h"
#include <iostream>
#include <math.h>

using namespace std;

// Constructor to create spiral
Spiral::Spiral(double centerX, double centerY, double startingRadius, double startingAngle){
    centerX_ = centerX;
    centerY_ = centerY;

    // Ensure that a starting angle will start at 12 o'clock
    angle_ = -startingAngle;
     

    // Make sure radius is bigger than or equal to 55
    if(startingRadius <= 55){
        radius_ = 55;
        startingRadius_ = 55;
    }else{
        radius_ = startingRadius;
        startingRadius_ = startingRadius;
    }

    angleIncrementSize_ = -15*(55/radius_);  
}

// Adjust angle and radius each step
Spiral& Spiral::operator++(){
    angle_ += angleIncrementSize_*(startingRadius_/radius_);
    radius_ += 1*(startingRadius_/radius_);
    return *this;
}

Spiral Spiral::operator++(int){
    Spiral result(*this);
    ++(*this);
    return result;
}

// Return the x position for the text
double Spiral::getTextX(){
    return centerX_ + (cos((angle_+ 90) / 180 * M_PI) * radius_);
}

// Return the y position for the text
double Spiral::getTextY(){
    return centerY_ + (sin((angle_ + 90) / 180 * M_PI) * radius_);
}

// Return the current spiral angle
double Spiral::getSpiralAngle(){
    return angle_;
}

// Return the current text angle
double Spiral::getTextAngle(){
    // Adding -90 to move angle correct way so text faces inward
    return angle_;
}

// Overload what is outputted when the object is outputted
ostream& operator<<(ostream& output, Spiral spiral)
{
    output << "( Angle: " << -spiral.angle_ << " , Radius: " << spiral.radius_ << ")";
    return output;
}