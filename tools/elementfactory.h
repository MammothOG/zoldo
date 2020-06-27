#ifndef ELEMENTFACTORY_H
#define ELEMENTFACTORY_H

#include <QString>


using namespace std;

class Element;

class ElementFactory
{
public:
    static Element * create(int name);

};
#endif // ELEMENTFACTORY_H
