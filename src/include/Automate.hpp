#ifndef AUTOMATE_H
#define AUTOMATE_H

#include <iostream>

class Automate
{
    public:

        virtual ~Automate();
        virtual void draw();
        virtual bool loadFromFile(std::string filePath);

    private:

};

#endif
