#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>

enum Species { // TEST COMMENT
	None,
	Chimpanzee,
	Otter,
	Wolf,
	Bear,
	Lion,
	Toucan,
	Hamster,
	Gorilla
};

struct Animal {
	public:
		Animal();
		Animal(Species species);
		Animal(Species species, std::string name);
		Animal(const Animal &copyAnimal);
		~Animal();
		void makeSound() const;
		void eat() const;
		Animal& operator=(const Animal &rhs); // need rule of 3 if being pushed_back in linkedlist

		// Getters
		Species getSpecies() const;
		std::string getSpeciesStr() const;
		std::string getName() const;
		void print();

		// Setters
		void setSpecies(Species toSpecies);
		void setName(std::string name);

	private:
		Species species;
		std::string name;
};

std::ostream& operator<<(std::ostream& os, const Animal& toPrint);

bool operator==(const Animal& lhs, const Animal& rhs);
bool operator!=(const Animal& lhs, const Animal& rhs);
bool operator<(const Animal& lhs, const Animal& rhs);
bool operator>(const Animal& lhs, const Animal& rhs);
bool operator<=(const Animal& lhs, const Animal& rhs);
bool operator>=(const Animal& lhs, const Animal& rhs);
#endif