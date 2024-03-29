#include "Pixel.h"

Pixel::Pixel(double x, double y, rgba_t rgba):
	m_x(x), m_y(y), m_rgba(rgba)
{
}

//Pixel::Pixel(double x, double y, rgba_t&& rgba):
//	m_x(x), m_y(y), m_rgba(std::move(rgba))
//{
//}

// Custom copy
//Pixel::Pixel(const Pixel& pixel):
//	Pixel(pixel.m_x, pixel.m_y, pixel.m_rgba)
//{
//}

// Custom move
//Pixel::Pixel(Pixel&& pixel):
//	m_x(pixel.m_x), m_y(pixel.m_y), m_rgba(std::move(pixel.m_rgba))
//{
//	pixel.m_x = 0.0;
//	pixel.m_y = 0.0;
//}

// Custom destructor
//Pixel::~Pixel()
//{
//	std::clog << "Pixel destroyed: " << *this << std::endl;
//}

// Custom assignment by copy
//Pixel& Pixel::operator=(const Pixel& pixel)
//{
//	m_x = pixel.m_x;
//	m_y = pixel.m_y;
//	m_rgba = pixel.m_rgba;
//	return *this;
//}

// Custom assignment by move
//Pixel& Pixel::operator=(Pixel&& pixel)
//{
//	m_x = pixel.m_x;
//	m_y = pixel.m_y;
//	m_rgba = std::move(pixel.m_rgba);
//	pixel.m_x = 0.0;
//	pixel.m_y = 0.0;
//	return *this;
//}

double Pixel::x() const
{
	return m_x;
}

void Pixel::setX(double x)
{
	m_x = x;
}

double Pixel::y() const
{
	return m_y;
}

void Pixel::setY(double y)
{
	m_y = y;
}

rgba_t Pixel::rgba() const
{
	return m_rgba;
}

void Pixel::setRgba(rgba_t rgba)
{
	m_rgba = rgba;
}

//void Pixel::setRgba(rgba_t&& rgba)
//{
//	m_rgba = std::move(rgba);
//}

double Pixel::r() const
{
	return std::get<0>(m_rgba);
}

double Pixel::g() const
{
	return std::get<1>(m_rgba);
}

double Pixel::b() const
{
	return std::get<2>(m_rgba);
}

double Pixel::a() const
{
	return std::get<3>(m_rgba);
}

std::string Pixel::toString() const
{
	return std::string();
}

void Pixel::normalize()
{
	// TODO
}