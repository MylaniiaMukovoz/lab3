#include "Dyhotomia_class.h"
#include <iostream>

using namespace std;

int main() {
    Dyhotomia_class * dyh = new Dyhotomia_class;
    dyh->setVolumes(0.9, 2);
    dyh->setTolerance(1e-9);

    cout << "Розв'язок рівняння (Дихотомія): " << dyh->Dyhotomia() << endl;;
    cout << "Розв'язок рівняння (Ньютона): " << dyh->Newton();

    return 0;
}