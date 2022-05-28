#pragma once

#include "VirtualFunction.h"
#include <cmath>

class Rectangle : public IFigureUnion {
private:
    CVector2D a{};
    CVector2D b{};
    double Mass;
    std::string name = "Rectangle";
    CVector2D pos{};
public:

    Rectangle();
    Rectangle(CVector2D&, CVector2D&, double, CVector2D&);
    ~Rectangle();


    double square() override;
    double perimeter() override;
    double mass() const override;
    CVector2D position() override;
    bool operator==(const IPhysObject &ob) override;

    void initFromDialog() override;
    std::string classname() const override;
    void show_() override;
    unsigned int size() const override;

};
