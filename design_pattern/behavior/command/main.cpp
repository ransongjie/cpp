#include "cmd.h"

int main()
{
    Solider solider("xcrj");

    ShootPlane shootPlane(solider);
    ShootTank shootTank(solider);

    Officer officer;

    officer.add(&shootPlane);
    officer.add(&shootPlane);
    officer.add(&shootPlane);
    officer.add(&shootTank);
    officer.add(&shootTank);

    officer.del(&shootPlane);

    officer.make();
}