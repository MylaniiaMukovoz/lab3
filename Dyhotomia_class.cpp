#include "Dyhotomia_class.h"
#include <cmath>
#include <iostream>

using namespace std;

Dyhotomia_class::Dyhotomia_class(){}
Dyhotomia_class::~Dyhotomia_class(){}

void Dyhotomia_class::setVolumes (double vol_a, double vol_b)
{
    this->a = vol_a;
    this->b = vol_b;
}

void Dyhotomia_class::setTolerance (double vol_eps)
{
    this->eps = vol_eps;
}

double Dyhotomia_class::F(double x) 
{
    if (fabs(x) < eps) {
        cout << "Ділення на нуль неможливе." << endl;
        return 0;
    }
    else 
        return (x - 2 + sin(1/x));
}

double Dyhotomia_class::Dyhotomia()
{
    if (eps == 0){
        cout << "Висловлюю свою незадоволеність стосовно вашого eps" << endl;
        return 0;
    }
    if (F(a)*F(b) > 0) {
        cout << "Немає розв'язку на проміжку." << endl;
        return 0;
    }
    else {
        while (fabs(b - a) > eps){
            double c = (a+b)/2;
            if (F(a) * F(c) < 0){
                b = c;
            }
            else {
                a = c;
            }
        }
        double x = (a + b) / 2;
        return x;
    }
}

double Dyhotomia_class::pohidna(double x)
{
    double delta_x = eps;
    return (F(x + delta_x) - F(x)) / delta_x;
}

double Dyhotomia_class::Newton()
{
    if (eps == 0){
        cout << "Висловлюю свою незадоволеність стосовно вашого eps" << endl;
        return 0;
    }
    double x = b;
    if (F(a)*F(b) > 0) {
        cout << "Немає розв'язку на проміжку" << endl;
        return 0;
    }
    while (true){
        double xnew = x - (F(x)/ pohidna(x));
        if (fabs(xnew - x) < eps){
            break;
        }
        x = xnew;
    }
    return x;
}