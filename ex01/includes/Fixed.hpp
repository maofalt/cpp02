#ifndef FIXED_HPP
#define FIXED_HPP

# include <iostream>

class Fixed {
private:
	// Private members
	int					_value;
	static const int	_fractionalBits = 8;
public:
	// Default constructor
	Fixed();

	// Copy constructor
	Fixed(const Fixed& other);

	// Constructor taking a constant integer 
	Fixed(const int i);

	//Constructor taking a constant floating-point float
	Fixed(const float f);

	// Copy assignment operator
	Fixed& 				operator=(const Fixed& other);

	// Destructor
	~Fixed();

	// Getters
	int					getRawBits(void) const;

	// Setters
	void				setRawBits(int const raw);

	//member functions

	//Converts the fixed point value to a floating point value
	float toFloat(void) const;

	//Convert fixed-point value to an integer value
	int toInt(void) const;
};

std::ostream& 			operator<<(std::ostream& os, const Fixed & other);
#endif