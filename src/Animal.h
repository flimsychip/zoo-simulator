#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>

enum Species { // TEST COMMENT
	None,
	Chimpanzee,
	Red_Panda,
	Otter,
	Wolf,
	Bear,
	Lion,
	Elephant,
	Penguin,
	Toucan,
	Hamster,
	Gorilla
};

struct Animal {
	public:
		Animal();
		Animal(Species species);
		void makeSound() const;
		void eat() const;

		// Getters
		Species getSpecies() const;
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