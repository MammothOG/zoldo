#ifndef ELEMENTFACTORY_H
#define ELEMENTFACTORY_H

#include <string>
#include <unordered_map>


#ifdef BUILD_DLL
#define DLL_INTERFACE __declspec(dllexport)
#else
#define DLL_INTERFACE __declspec(dllimport)
#endif

class Element;

typedef Element*(*elementInstanceGenerator)();

class ElementFactory
{
public:
    DLL_INTERFACE static ElementFactory& get();

    DLL_INTERFACE const char** elementList(int & count);
    DLL_INTERFACE Element* instanciateElement(const char* typeName);
    DLL_INTERFACE bool registerGenerator(
                            const char* typeName,
                            const elementInstanceGenerator& funcCreate);

private:
    ElementFactory();
    ElementFactory(const ElementFactory&);
    ~ElementFactory();

    std::unordered_map<std::string, elementInstanceGenerator> m_generators;
};
#endif // ELEMENTFACTORY_H
