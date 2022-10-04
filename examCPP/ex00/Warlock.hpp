#ifndef WARLOCK_HPP
# define WARLOCK_HPP
#include <iostream>


class Warlock
{
    private:
        std::string _name;
        std::string _title;
        Warlock() {}
        Warlock(const Warlock & warlock)
        {
            *this = warlock;
        }
        Warlock & operator=(const Warlock & warlock)
        {
            this->_name = warlock._name;
            this->_title = warlock._title;
            return *this;
        }

    public:
        //constructor
        Warlock(const std::string name, const std::string title)
        :   _name(name),
            _title(title)
        {
            std::cout << this->_name << " : This looks like another boring day." << std::endl;
        }

        //destructor
        virtual ~Warlock()
        {
            std::cout << this->_name << " : My job here is done!" << std::endl;
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

        //class

    };

#endif