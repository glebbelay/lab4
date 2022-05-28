#include <iostream>
#include "segment.h"

Segment::Segment() : A(0), B(0), Mass(0), pos(0, 0) {

}

void Segment::initFromDialog() {
    std::cout << "Enter the start and the end points of segment, mass and position coordinates: " << std::endl;
    std::cin >> A >> B >> Mass >> pos.x >> pos.y;
}

void Segment::show_(){
    std :: cout << "Side coordinates: " <<"{" << A << " " << B << "} \n";
    std :: cout << "Centre mass: " << mass() << "\n";
    std :: cout << "Position figure: {" << pos.x  << " " << pos.y << "}" << "\n";
};

std::string Segment::classname() const {
    return name;
}

unsigned int Segment::size() const {
    return sizeof(*this);
}

Segment::Segment(const double a, const double b, const double mass_, const CVector2D& pos_) : A(a), B(b), Mass(mass_), pos(pos_) {

}

double Segment::square() {
    return 0;
}

double Segment::perimeter() {
    return 0;
}

CVector2D Segment::position() {
    return pos;
}

double Segment::mass() const {
    return Mass;
}

bool Segment::operator==(const IPhysObject &ob){
    return ob.mass() == mass();
}

Segment::Segment(const Segment& segment)
        : A(segment.A)
        , B(segment.B)
        , Mass(segment.Mass)
        , pos(segment.pos)
{

}

Segment::~Segment() = default;
