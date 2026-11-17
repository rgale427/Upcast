#include <iostream>
#include <cmath>
#include <memory> //low level memory management - smart pointers
// Abstract base class
class Circle {
protected:
    double m_radius;
    double m_area;

public:
    virtual ~Circle() = default;

    Circle(double radius) {
        if (radius > 0) {
            m_radius = radius;
        }
        else {
            m_radius = 1;
        }
        m_area = M_PI * pow(m_radius, 2);
    }
    virtual void calcVolume()=0;
    virtual double getVolume()=0;
};

class Cylinder: public Circle {
private:
    double m_volume;
    double m_height;
public:
    Cylinder(double radius, double height):Circle(radius) {
        if (height > 0) {
            m_height = height;
        }
        else {
            m_height = 1;
        }
        m_volume = 0;
    }
    void calcVolume() override {
        m_volume = m_area * m_height;
    }
    double getVolume() override {
        return m_volume;
    }
};

class Sphere: public Circle {
private:
    double m_volume;
public:
    Sphere(double radius):Circle(radius) {
        m_volume = 0;
    }
    void calcVolume() override {
        m_volume = (4.0/3.0) * M_PI * pow(m_radius, 3);
    }
    double getVolume() override {
        return m_volume;
    }
};

class Cone: public Circle {
private:
    double m_volume;
    double m_height;
public:
    Cone(double radius, double height):Circle(radius) {
        if (height > 0) {
            m_height = height;
        }
        else {
            m_height = 1;
        }
        m_volume = 0;
    }
    void calcVolume() override {
        m_volume = M_PI * pow(m_radius, 2) * (m_height / 3);
    }
    double getVolume() override {
        return m_volume;
    }
};

int main() {
    // sandbox for playing with objects
    std::unique_ptr<Circle> object;
    // created a snart pointer currently set to nullptr
    // deleted when the object it points to goes out of scope

    int choice;
    std:: cout<< "Select an Object: \n1.Cylinder\n2.cone\n3.sphere\nselects: ";
    std::cin >> choice;
    if (choice == 1)
    {
        double cylRadius, cylHeight;
        std:: cout<< "Enter cylinder radius: ";
        std::cin >> cylRadius;
        std::cout<< "Enter cylinder height: ";
        std::cin >> cylHeight;
          object = std::make_unique<Cylinder> (cylRadius, cylHeight);
// Instantiated a Cylinder object in the heap and passed radius and height
    //make_unique is the same as the new operator
    }
    else if (choice == 2)
    {
        double coneRadius, coneHeight;
        std:: cout<< "Enter cone radius: ";
        std::cin >> coneRadius;
        std::cout<< "Enter cone height: ";
        std::cin >> coneHeight;
        object = std::make_unique<Cone> (coneRadius, coneHeight);
    }
    else if (choice == 3)
    {
        double sphereRadius;
        std::cout << "Enter sphere radius: ";
      std::cin >> sphereRadius;
        object = std::make_unique<Sphere> (sphereRadius);
    }
    else
    {
        std:: cout<< "Invalid choice!" << std::endl;
    }
    //unified interface: we can interact with the object without knowing what shape it took
    object->calcVolume();
    std:: cout<< object->getVolume() << std::endl;

//memory safe because we used smart pointers


    /*object->calcVolume();
    std::cout<< object->getVolume() << std::endl;

    object = std::make_unique<Sphere> (4.5);
object->calcVolume();
    std::cout<< object->getVolume() << std::endl;

    object = std::make_unique<Cone> (4.5, 11.25);
    object->calcVolume();
    std::cout<< object->getVolume() << std::endl;*/


    return 0;
}
