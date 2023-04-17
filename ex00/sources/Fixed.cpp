#include <iostream>
#include "Fixed.hpp"

//Colors green, blue, ,red, yellow in bold and reset
#define GREEN "\033[1;32m"
#define BLUE "\033[1;34m"
#define RED "\033[1;31m"
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"

Fixed::Fixed() : _value(0)
{
	std::cout << GREEN << "[ ✓ ] Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : _value(other.getRawBits())
{
	std::cout << GREEN << "[ ✓ ] Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << GREEN << "\t[ ✓ ]" << BLUE << " Assignation '=' operator called" << std::endl;

	if (this != &other)
		this->_value = other.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << RED << "[ ✗ ] Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << YELLOW << "\t[ ? ]" << BLUE << " getRawBits member function called" << std::endl;
	return this->_value;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << YELLOW << "\t[ --> ]" << BLUE << " setRawBits member function called" << std::endl;
	std::cout << BLUE << "\t Actual value: " << this->_value << std::endl;
	std::cout << GREEN << "\t New value: " << raw << std::endl;
	this->_value = raw;	
}

std::ostream & operator<<(std::ostream & os, const Fixed & other)
{
	os << static_cast<float>(other.getRawBits()) / (1 << 8);
	return os;
}