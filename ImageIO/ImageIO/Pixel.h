#ifndef _H_PIXEL_
#define _H_PIXEL_

// NB: use #pragma once instead of #ifndef ... #endif

#include <tuple>
#include <string>
#include <iostream>
#include <compare>

using rgba_t = std::tuple<double, double, double, double>;

class Pixel
{
private:
	double m_x;
	double m_y;
	rgba_t m_rgba;

public:
	Pixel() = default;
	Pixel(double x, double y, rgba_t rgba);
	virtual ~Pixel();

	double x() const;
	void setX(double x);

	double y() const;
	void setY(double y);

	rgba_t rgba() const;
	void setRgba(rgba_t rgba);

	double r() const;
	double g() const;
	double b() const;
	double a() const;

	// Hint: C++17: stringstream or stringbuf: https://en.cppreference.com/w/cpp/io 
	// C++20 Formatting: https://en.cppreference.com/w/cpp/utility/format
	std::string toString() const; 
	void normalize();

	Pixel& operator+=(rgba_t rgba); // left operand = this
	Pixel& operator+=(const Pixel& pixel);
	Pixel operator+(rgba_t rgba) const;
	Pixel operator+(const Pixel& pixel2) const;

	//bool operator<(const Pixel& other) const;
	bool operator==(const Pixel& other) const;
	std::partial_ordering operator<=>(const Pixel& other) const;
};

std::ostream& operator<<(std::ostream& out, const Pixel& pixel);
std::ostream& operator<<(std::ostream& out, rgba_t rgba);

#endif // !_H_PIXEL_



