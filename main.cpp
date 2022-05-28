#include <iostream>
#include "VirtualFunction.h"
#include "segment.h"
#include "rectangle.h"
#include <vector>
#include <algorithm>

int Menu() {
    int num = 0;
    std::cout << "Choose the command from the command list: " << std::endl;
    std::cout << "1. Show all figures." << std::endl;
    std::cout << "2. Get sum of squares." << std::endl;
    std::cout << "3. Get sum of perimeters." << std::endl;
    std::cout << "4. Get the mass center of the system." << std::endl;
    std::cout << "5. Get the sum of memory." << std::endl;
    std::cout << "6. Sort objects by mass and show their mass." << std::endl;
    std::cout << "7. Exit program." << std::endl;
    std::cin >> num;
    std::cout << std::endl;
    return num;
}

int main() {
    std::vector<IFigureUnion*> figures;
    std::string figureType;
    int i = 0;
    int comNum = 0;
    while (true) {
        std::cout << "Enter the type of the figure you want to add or press 0 to stop adding: " << std::endl;
        std::cin >> figureType;
        std::for_each(figureType.begin(), figureType.end(), [](char& c) {
            c = ::tolower(c);
        });
        if (figureType == "segment") {
            figures.push_back(new Segment());
        }
        else if (figureType == "rectangle") {
            figures.push_back(new Rectangle());
        }
        else if (figureType == "0") {
            break;
        }
        else {
            std::cout << "Enter valid type of figure (segment or rectangle)!" << std::endl;
            std::cin >> figureType;
        }
        figures[i]->initFromDialog();
        i++;
    }
    comNum = Menu();
    while (true) {
        if (comNum == 1) {
            for (auto& f : figures) {
                std::cout << f->classname() << std::endl;
                f->show_();
                std::cout << std::endl;
            }
            comNum = Menu();
        }
        else if (comNum == 2) {
            double sumSquares = 0;
            for (auto& f : figures) {
                sumSquares += f->square();
            }
            std::cout << "Sum of squares = " << sumSquares << std::endl;
            std::cout << std::endl;
            comNum = Menu();
        }
        else if (comNum == 3) {
            double sumPerimeters = 0;
            for (auto& f : figures) {
                sumPerimeters += f->perimeter();
            }
            std::cout << "Sum of squares = " << sumPerimeters << std::endl;
            std::cout << std::endl;
            comNum = Menu();
        }
        else if (comNum == 4) {
            CVector2D massCenter(0, 0);
            double massSum = 0;
            for (auto& f : figures) {
                massCenter.x += f->mass() * f->position().x;
                massCenter.y += f->mass() * f->position().y;
                massSum += f->mass();
            }
            massCenter.x = massCenter.x / massSum;
            massCenter.y = massCenter.y / massSum;
            std::cout << "Mass center: {" << massCenter.x << ", " << massCenter.y << "}" << std::endl;
            std::cout << std::endl;
            comNum = Menu();
        }
        else if (comNum == 5) {
            unsigned size = 0;
            for (auto& f : figures) {
                size += f->size();
            }
            std::cout << "Sum of memory = " << size << std::endl;
            std::cout << std::endl;
            comNum = Menu();
        }
        else if (comNum == 6) {
            std::sort(figures.begin(), figures.end(), [](IFigureUnion* a, IFigureUnion* b) {
                return a->mass() < b->mass();
            });
            for (auto& f : figures) {
                std::cout << f->mass() << " ";
            }
            std::cout << std::endl;
            std::cout << std::endl;
            comNum = Menu();
        }
        else if (comNum == 7) {
            std::cout << "Exiting program.." << std::endl;
            exit(0);
        }
        else {
            break;
        }
    }

    std:: cout << "comparing two figures using operating system overload: " << figures[0]->operator==(*figures[1]);
    return 0;
}