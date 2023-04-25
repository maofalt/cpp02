#include <iostream>
#include <cmath>
#include <limits>
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

Fixed::Fixed(const int i) : _value(i << _fractionalBits)
{
	std::cout << GREEN << "[ ✓ ] Int constructor called" << std::endl;
}

Fixed::Fixed(const float f)
{
	// Determine the representable range of floating-point values for the Fixed class
    float max_float = static_cast<float>(std::numeric_limits<int>::max()) / (1 << _fractionalBits);
    float min_float = static_cast<float>(std::numeric_limits<int>::min()) / (1 << _fractionalBits);

    // Check if the input value is within the representable range and handle possible overflows
    float clamped_value;
    if (f >= max_float)
	{
        clamped_value = max_float;
		std::cout << YELLOW << "\t [ ? ] Warning: Input value out of range. Clamping to the nearest representable value : " << max_float << RESET << std::endl;
    } 
	else if (f <= min_float)
	{
        clamped_value = min_float;
		std::cout << YELLOW << "\t [ ? ] Warning: Input value out of range. Clamping to the nearest representable value : " << min_float << RESET << std::endl;
    } 
	else 
        clamped_value = f;

	/*
	 * The conversion from a floating-point value to a fixed-point representation consists of three steps:
	 * 1. Multiply the clamped floating-point value by 2 raised to the power of the number of fractional bits.
	 *    This shifts the decimal point to the right by the number of fractional bits, effectively converting
	 *    the floating-point value into a scaled integer.
	 * 2. Use the roundf() function to round the result of the multiplication to the nearest whole number.
	 *    This ensures that the fixed-point value is an integer with the closest possible representation
	 *    to the original floating-point value.
	 * 3. Finally, use a static_cast to convert the rounded float to an integer type, which is stored in the
	 *    _value member variable of the Fixed class.
	 */
    _value = static_cast<int>(roundf(clamped_value * (1 << _fractionalBits)));

	std::cout << GREEN << "[ ✓ ] Float constructor called" << std::endl;
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
	std::cout << RED << "[ ✗ ] Destructor called" << RESET <<std::endl;
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


// Convert fixed-point to floating-point
float Fixed::toFloat(void) const
{
	return (static_cast<float>(_value) / (1 << _fractionalBits));
}

//Convert fixed-point to integer
int Fixed::toInt(void) const
{
	return (_value >> _fractionalBits);
}

std::ostream & operator<<(std::ostream & os, const Fixed & other)
{
	os << other.toFloat();
	return os;
}