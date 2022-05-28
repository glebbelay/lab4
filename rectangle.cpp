#include <iostream>
#include "rectangle.h"

Rectangle::Rectangle()
        : a(0, 0)
        , b(0, 0)
        , Mass(0)
        , pos(0, 0)
{
}

Rectangle::Rectangle(CVector2D& a_, CVector2D& b_, double Mass_, CVector2D& pos_)
        : a(a_)
        , b(b_)
        , Mass(Mass_)
        , pos(pos_)
{
}

void Rectangle::show_(){
    std :: cout << "Side coordinates: " <<"{" << a.x << " " << a.y << "} {" << b.x <<" " << b.y <<  "}\n";
    std :: cout << "Centre mass: " << mass() << "\n";
    std :: cout << "Position figure: {" << pos.x  << " " << pos.y << "}" << "\n";
};

double Rectangle::square() {
    return ( std::abs(a.x - a.y) * std::abs(b.x - b.y));
}

double Rectangle::perimeter() {
    return (2 * (std::abs(a.x - a.y) + std::abs(b.x - b.y)));
}

double Rectangle::mass() const {
    return Mass;
}

CVector2D Rectangle::position() {
    return pos;
}

bool Rectangle::operator==(const IPhysObject &ob){
    return ob.mass() == mass();
}

void Rectangle::initFromDialog() {
    std::cout << "Enter x and y coordinates, end of side b coordinates (x and y), " << std::endl;
    std::cout << "end of side a coordinates (x and y), mass ans position coordinates lower left corner (x and y): " << std::endl;
    std::cin >> b.x >> b.y >> a.x >> a.y >> Mass >> pos.x >> pos.y;
}

std::string Rectangle::classname() const {
    return name;
}

unsigned int Rectangle::size() const {
    return sizeof(*this);
}

Rectangle::~Rectangle() = default;

