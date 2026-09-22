#include "Fixed.hpp"

Fixed::Fixed( void ) : _rawBits(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( int const value ) : _rawBits(value << _fractionalBits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( float const value ) : _rawBits(roundf(value * (1 << _fractionalBits))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed( Fixed const &src ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed &Fixed::operator=( Fixed const &rhs ) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_rawBits = rhs.getRawBits();
	return *this;
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const {
	return this->_rawBits;
}

void Fixed::setRawBits( int const raw ) {
	this->_rawBits = raw;
}

float Fixed::toFloat( void ) const {
	return (float)this->_rawBits / (1 << _fractionalBits);
}

int Fixed::toInt( void ) const {
	return this->_rawBits >> _fractionalBits;
}

std::ostream &operator<<( std::ostream &o, Fixed const &rhs ) {
	o << rhs.toFloat();
	return o;
}
