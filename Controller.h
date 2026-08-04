#ifndef CONTROLLER_H
#define CONTROLLER_H

bool checkInside(float insideTemp);
bool checkOutside (float outsideTemp);
bool controlVentilation(float outsideTemp, float insideTemp);

#endif