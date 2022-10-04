#ifndef WARLOCK_HPP
# define WARLOCK_HPP
#include <iostream>
#include <vector>
#include "ASpell.hpp"
#include "ATarget.hpp"

class Warlock
{
    private:
        std::string _name;
        std::string _title;
        std::vector<ASpell*> _TheBookOfSpell;
        Warlock() {}
        Warlock(const Warlock & warlock)
        {
            *this = warlock;
        }
        Warlock & operator=(const Warlock & warlock)
        {
            this->_name = warlock._name;
            this->_title = warlock._title;
            for (std::vector<ASpell*>::const_iterator it(this->_TheBookOfSpell.begin()); it != this->_TheBookOfSpell.end(); it++)
                delete *it;
            this->_TheBookOfSpell.clear();
            for (std::vector<ASpell*>::const_iterator it(warlock._TheBookOfSpell.begin()); it != warlock._TheBookOfSpell.end(); it++)
                this->_TheBookOfSpell.push_back((*it)->clone());
            return *this;
        }

    public:
        //constructor
        Warlock(const std::string &name, const std::string &title)
        :   _name(name),
            _title(title)
        {
            std::cout << this->_name << " : This looks like another boring day." << std::endl;
        }

        //destructor
        virtual ~Warlock()
        {
            std::cout << this->_name << " : My job here is done!" << std::endl;
            for (std::vector<ASpell*>::const_iterator it(this->_TheBookOfSpell.begin()); it != this->_TheBookOfSpell.end(); it++)
                delete *it;
        }

        //get
        const std::string & getName(void) const
        {
            return this->_name;
        }

        const std::string & getTitle(void) const
        {
            return this->_title;
        }

        //set
        void setTitle(const std::string &newTtile)
        {
            this->_title = newTtile;
        }

        //function membre
        void introduce() const
        {
            std::cout << this->_name << " : I am " << this->_name << ", " << this->_title << "!" << std::endl;
        }

        void learnSpell(ASpell * spell)
        {
            if (!spell)
                return;
            for (std::vector<ASpell*>::const_iterator it(this->_TheBookOfSpell.begin()); it != this->_TheBookOfSpell.end(); it++)
            {
                if (spell->getName() == (*it)->getName())
                    return;
            }
            this->_TheBookOfSpell.push_back(spell);
        }

        void forgetSpell(const std::string & nameSpell)
        {
            for (std::vector<ASpell*>::const_iterator it(this->_TheBookOfSpell.begin()); it != this->_TheBookOfSpell.end();)
            {
                if (nameSpell == (*it)->getName())
                {
                    delete *it;
                    it = this->_TheBookOfSpell.erase(it);
                }
                else
                    it++;
            }
        }

        void launchSpell(const std::string & spellName, const ATarget & target) const
        {
            for (std::vector<ASpell*>::const_iterator it(this->_TheBookOfSpell.begin()); it != this->_TheBookOfSpell.end(); it++)
            {
                if (spellName == (*it)->getName())
                    (*it)->launch(target);
            }
        }
        //class

    };

#endif