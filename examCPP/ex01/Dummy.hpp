#ifndef DUMMY_HPP
# define DUMMY_HPP
#include <iostream>
#include "ATarget.hpp"



class Dummy : public ATarget
{
    public:
        Dummy():ATarget("Target Practice Dummy") {}
        Dummy(const Dummy & dummy) :ATarget(dummy) {*this = dummy;}
        virtual ~Dummy() {};
        Dummy & operator=(const Dummy & dummy)
        {
            ATarget::operator=(dummy);
            return *this;
        }
        ATarget * clone() const
        {
            return new Dummy(*this);
        }
};

#endif