#pragma once

#include "VirtualFunction.h"

class Segment : public IFigureUnion {
private:
    double A;
    double B;
    double Mass;
    std::string name = "Segment";
    CVector2D pos{};
public:

    Segment();
    Segment(double, double, double, const CVector2D&);
    Segment(const Segment& segment);
    ~Segment();

    double square() override;
    double perimeter() override;
    double mass() const override;
    bool operator==(const IPhysObject &ob) override;
    CVector2D position() override;
    void show_() override;
    void initFromDialog() override;

    std::string classname() const override;
    unsigned int size() const override;

};
