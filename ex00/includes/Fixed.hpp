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

	// Copy assignment operator
	Fixed& 				operator=(const Fixed& other);

	// Destructor
	~Fixed();

	// Getters
	int					getRawBits(void) const;

	// Setters
	void				setRawBits(int const raw);
};

std::ostream& 			operator<<(std::ostream& os, const Fixed & other);
#endif