#ifndef REGISTER_H
#define REGISTER_H

#include "elementfactory.h"
#include "core/element.h"


namespace Register {

    template <typename T>
    class Register
    {
    public:
        Register(const char* id)
        {
            ElementFactory::get().registerGenerator(
                id,
                []() { return static_cast<Element*>(new T()); }
            );
        }
    };

}

#endif // REGISTER_H
