#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain default constructor" << std::endl;
}

Brain::Brain(const Brain& other)  {
    std::cout << "Brain copy constructor" << std::endl;
    *this = other;
}

Brain& Brain::operator=(const Brain& other) {
    if (this != &other) {
        for (int i = 0; i < 100; i++) {
            this->ideas[i] = other.ideas[i];
        }
    }
    return *this;
}

void Brain::setIdea(unsigned int i, std::string idea) {
   if (i < 100) {
    ideas[i] = idea;
   }
}

const std::string& Brain::getIdea(unsigned int i) const {
    if (i < 100) {
        return ideas[i];
    }
    static std::string empty = "";
    return empty;
}

Brain::~Brain() {
    std::cout << "Brain  destructor" << std::endl;
}