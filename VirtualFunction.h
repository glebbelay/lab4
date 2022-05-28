#pragma once


class IGeoFig {
public:
    virtual double square() = 0;
    virtual double perimeter() = 0;
};

class CVector2D {
public:
    double x, y;

    CVector2D() : x(0), y(0) {

    }

    CVector2D(double X, double Y) : x(X), y(Y) {

    }

    ~CVector2D() = default;

};


class IPhysObject {
public:
    virtual double mass() const = 0;
    virtual CVector2D position() = 0;
    virtual bool operator==(const IPhysObject &ob){
        return ob.mass() == mass();
    } ;
};



class IDialogInitiable {
public:
    virtual void initFromDialog() = 0;
};


class BaseCObject {
public:
    virtual std::string classname() const = 0;
    virtual unsigned int size() const = 0;
    virtual void show_(){
        std :: cout << "BaseFigure";
    };
};

class IFigureUnion : public IGeoFig, public CVector2D, public IPhysObject, public IDialogInitiable, public BaseCObject {

};

