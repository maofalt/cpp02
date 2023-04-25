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
	
	// Destructor
	~Fixed();

/*================================================================================**
 * 								OPERATORS OVERLOADS							      **
 *================================================================================*/

/*============================== COMPARISON OPERATORS =============================*/
	// Copy assignment operator
	Fixed& 				operator=(const Fixed& other);

	// > operator
	bool				operator>(const Fixed& other) const;

	// < operator
	bool				operator<(const Fixed& other) const;

	// >= operator
	bool				operator>=(const Fixed& other) const;

	// <= operator
	bool				operator<=(const Fixed& other) const;

	// == operator
	bool				operator==(const Fixed& other) const;

	// != operator
	bool				operator!=(const Fixed& other) const;

/*============================== ARITHMETHIC OPERATORS =============================*/

	// + operator
	Fixed				operator+(const Fixed & other) const;

	// - operator
	Fixed				operator-(const Fixed & other) const;

	// * operator
	Fixed				operator*(const Fixed & other) const;

	// / operator
	Fixed				operator/(const Fixed & other) const;

/*============================== INCREMENT/DECREMENT OPERATORS =============================*/

	// ++ Pre-increment operator
	Fixed&				operator++();

	// -- Pre-decrement operator
	Fixed&				operator--();

	// ++ Post-increment operator
	Fixed				operator++(int);

	// -- Post-decrement operator
	Fixed				operator--(int);

/*============================== MIN/MAX OPERATORS =============================*/

	// min function
	static Fixed&		min(Fixed& a, Fixed& b);

	// max function
	static Fixed&		max(Fixed& a, Fixed& b);

	// min function
	static const Fixed&	min(const Fixed& a, const Fixed& b);

	// max function
	static const Fixed&	max(const Fixed& a, const Fixed& b);

/*================================================================================**
 * 								MEMBER FUNCTIONS								  **
 *================================================================================*/

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