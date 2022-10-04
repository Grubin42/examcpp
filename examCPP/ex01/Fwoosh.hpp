#ifndef FWOOSH_HPP
# define FWOOSH_HPP
#include <iostream>
#include "ASpell.hpp"

class Fwoosh : public ASpell
{
    public:
        Fwoosh():ASpell("Fwoosh", "fwooshed") {}
        Fwoosh(const Fwoosh & fwoosh) : ASpell(fwoosh) {*this = fwoosh;}
        virtual ~Fwoosh() {};
        Fwoosh & operator=(const Fwoosh & fwoosh)
        {
            ASpell::operator=(fwoosh);
            return *this;
        }
        ASpell * clone() const
        {
            return new Fwoosh(*this);
        }
};

#endif