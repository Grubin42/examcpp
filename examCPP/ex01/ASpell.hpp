#ifndef ASPELL_HPP
# define ASPELL_HPP
#include <iostream>

class ATarget;

class ASpell
{
    private:
        std::string _name;
        std::string _effects;

    public:
        ASpell() {};
        ASpell(const std::string &name, const std::string &effects)
        :   _name(name), _effects(effects) {}
        ASpell(const ASpell & aspell)
        {
            *this = aspell;
        }
        ASpell & operator=(const ASpell & aspell)
        {
            this->_name = aspell._name;
            this->_effects = aspell._effects;
            return *this;
        }
        virtual ~ASpell() {};

        const std::string & getName(void) const
        {
            return this->_name;
        }

        const std::string & getEffects(void) const
        {
            return this->_effects;
        }

        void launch(const ATarget & atarget) const;

        virtual ASpell * clone() const = 0;
};

#endif