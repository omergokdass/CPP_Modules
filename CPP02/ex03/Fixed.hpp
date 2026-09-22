#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
private:
	int					_rawBits;
	static const int	_fractionalBits = 8;

public:
	// Constructors and destructor
	Fixed( void );
	Fixed( int const value );
	Fixed( float const value );
	Fixed( Fixed const &src );
	Fixed &operator=( Fixed const &rhs );
	~Fixed( void );

	// Raw bits accessors
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

	// Conversion functions
	float	toFloat( void ) const;
	int		toInt( void ) const;

	// Comparison operators
	bool	operator>( Fixed const &rhs ) const;
	bool	operator<( Fixed const &rhs ) const;
	bool	operator>=( Fixed const &rhs ) const;
	bool	operator<=( Fixed const &rhs ) const;
	bool	operator==( Fixed const &rhs ) const;
	bool	operator!=( Fixed const &rhs ) const;

	// Arithmetic operators
	Fixed	operator+( Fixed const &rhs ) const;
	Fixed	operator-( Fixed const &rhs ) const;
	Fixed	operator*( Fixed const &rhs ) const;
	Fixed	operator/( Fixed const &rhs ) const;

	// Increment and Decrement operators
	Fixed	&operator++( void );
	Fixed	operator++( int );
	Fixed	&operator--( void );
	Fixed	operator--( int );

	// Min and Max static functions
	static Fixed		&min( Fixed &a, Fixed &b );
	static Fixed const	&min( Fixed const &a, Fixed const &b );
	static Fixed		&max( Fixed &a, Fixed &b );
	static Fixed const	&max( Fixed const &a, Fixed const &b );
};

std::ostream &operator<<( std::ostream &o, Fixed const &rhs );

#endif
