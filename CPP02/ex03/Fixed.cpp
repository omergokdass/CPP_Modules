#include "Fixed.hpp"

// Constructors and destructor
Fixed::Fixed( void ) : _rawBits(0) {
}

Fixed::Fixed( int const value ) : _rawBits(value << _fractionalBits) {
}

Fixed::Fixed( float const value ) : _rawBits(roundf(value * (1 << _fractionalBits))) {
}

Fixed::Fixed( Fixed const &src ) {
	*this = src;
}

Fixed &Fixed::operator=( Fixed const &rhs ) {
	if (this != &rhs)
		this->_rawBits = rhs.getRawBits();
	return *this;
}

Fixed::~Fixed( void ) {
}

// Raw bits accessors
int Fixed::getRawBits( void ) const {
	return this->_rawBits;
}

void Fixed::setRawBits( int const raw ) {
	this->_rawBits = raw;
}

// Conversion functions
float Fixed::toFloat( void ) const {
	return (float)this->_rawBits / (1 << _fractionalBits);
}

int Fixed::toInt( void ) const {
	return this->_rawBits >> _fractionalBits;
}

// Comparison operators
bool Fixed::operator>( Fixed const &rhs ) const {
	return this->_rawBits > rhs._rawBits;
}

bool Fixed::operator<( Fixed const &rhs ) const {
	return this->_rawBits < rhs._rawBits;
}

bool Fixed::operator>=( Fixed const &rhs ) const {
	return this->_rawBits >= rhs._rawBits;
}

bool Fixed::operator<=( Fixed const &rhs ) const {
	return this->_rawBits <= rhs._rawBits;
}

bool Fixed::operator==( Fixed const &rhs ) const {
	return this->_rawBits == rhs._rawBits;
}

bool Fixed::operator!=( Fixed const &rhs ) const {
	return this->_rawBits != rhs._rawBits;
}

// Arithmetic operators
Fixed Fixed::operator+( Fixed const &rhs ) const {
	return Fixed( this->toFloat() + rhs.toFloat() );
}

Fixed Fixed::operator-( Fixed const &rhs ) const {
	return Fixed( this->toFloat() - rhs.toFloat() );
}

Fixed Fixed::operator*( Fixed const &rhs ) const {
	return Fixed( this->toFloat() * rhs.toFloat() );
}

Fixed Fixed::operator/( Fixed const &rhs ) const {
	return Fixed( this->toFloat() / rhs.toFloat() );
}

// Increment and Decrement operators
Fixed &Fixed::operator++( void ) {
	this->_rawBits++;
	return *this;
}

Fixed Fixed::operator++( int ) {
	Fixed tmp( *this );
	this->_rawBits++;
	return tmp;
}

Fixed &Fixed::operator--( void ) {
	this->_rawBits--;
	return *this;
}

Fixed Fixed::operator--( int ) {
	Fixed tmp( *this );
	this->_rawBits--;
	return tmp;
}

// Min and Max static functions
Fixed &Fixed::min( Fixed &a, Fixed &b ) {
	return (a < b) ? a : b;
}

Fixed const &Fixed::min( Fixed const &a, Fixed const &b ) {
	return (a < b) ? a : b;
}

Fixed &Fixed::max( Fixed &a, Fixed &b ) {
	return (a > b) ? a : b;
}

Fixed const &Fixed::max( Fixed const &a, Fixed const &b ) {
	return (a > b) ? a : b;
}

// Stream insertion operator
std::ostream &operator<<( std::ostream &o, Fixed const &rhs ) {
	o << rhs.toFloat();
	return o;
}
