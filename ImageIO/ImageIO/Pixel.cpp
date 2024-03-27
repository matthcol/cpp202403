#include "Pixel.h"

Pixel::Pixel(double x, double y, rgba_t rgba):
	m_x(x), m_y(y), m_rgba(rgba)
{
}

double Pixel::x() const
{
	return 0.0;
}

void Pixel::setX(double x)
{
}

double Pixel::y() const
{
	return 0.0;
}

void Pixel::setY(double y)
{
}

rgba_t Pixel::rgba() const
{
	return rgba_t();
}

void Pixel::setRgba(rgba_t rgba)
{
}

double Pixel::r() const
{
	return 0.0;
}

double Pixel::g() const
{
	return 0.0;
}

double Pixel::b() const
{
	return 0.0;
}

double Pixel::a() const
{
	return 0.0;
}

std::string Pixel::toString() const
{
	return std::string();
}

std::ostream& operator<<(std::ostream& out, const Pixel& pixel)
{
	out << "P["
		<< "x=" << pixel.x()
		<< ", y=" << pixel.y()
		<< ", rgba=" << pixel.rgba()
		<< "]";
}
