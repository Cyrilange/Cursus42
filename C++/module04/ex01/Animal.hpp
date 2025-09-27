#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>
#define GREEN_BOLD_ITALIC "\033[1;3;92m"
#define RESET "\033[0m"


class Animal {
    public :

    Animal();
    Animal(const Animal& other);
    Animal(const std::string& type);
    Animal& operator=(const Animal& other);
    const std::string& getType() const;
    void setType(const std::string& type);
    virtual void makeSound() const ;
    virtual ~Animal();
    protected:
        std::string type;
    
};

#endif