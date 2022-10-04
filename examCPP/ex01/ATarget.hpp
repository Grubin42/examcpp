#ifndef ATARGET_HPP
# define ATARGET_HPP
#include <iostream>
#include "ASpell.hpp"

class ATarget
{
    private:
        std::string _type;

    public:
        ATarget(): _type("") {}
        ATarget(const std::string &type): _type(type) {}
        ATarget(const ATarget & atarget)
        {
            *this = atarget;
        }
        ATarget & operator=(const ATarget & atarget)
        {
            this->_type = atarget._type;
            return *this;
        }
        virtual ~ATarget() {};

        const std::string & getType(void) const
        {
            return this->_type;
        }

        void getHitBySpell(const ASpell & aspell) const;

        virtual ATarget * clone() const = 0;
};

#endif