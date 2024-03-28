#include "Pixel.h"

Pixel& Pixel::operator+=(rgba_t rgba)
{
	std::get<0>(m_rgba) += std::get<0>(rgba);
	std::get<1>(m_rgba) += std::get<1>(rgba);
	std::get<2>(m_rgba) += std::get<2>(rgba);
	std::get<3>(m_rgba) += std::get<3>(rgba);
	return *this;
}

Pixel& Pixel::operator+=(const Pixel& pixel)
{
	return *this += pixel.rgba();
}

Pixel Pixel::operator+(rgba_t rgba) const
{
	auto newPixel(*this);
	newPixel += rgba;
	return newPixel;
}

Pixel Pixel::operator+(const Pixel& pixel2) const
{
	return *this + pixel2.rgba();
}

bool Pixel::operator==(const Pixel& other) const
{
	return std::is_eq(*this <=> other);
}

std::partial_ordering Pixel::operator<=>(const Pixel& other) const
{
	auto res = m_x <=> other.m_x;
	//if (res != std::partial_ordering::equivalent)
	if (std::is_neq(res)) return res;
	res = m_y <=> other.m_y;
	if (std::is_neq(res)) return res;
	res = m_rgba <=> other.m_rgba;
	return res;
}








//std::partial_ordering Pixel::operator<=>(const Pixel& other) const
//{
//	auto res = m_x <=> other.m_x;
//	if (std::is_neq(res)) return res;
//	res = m_y <=> other.m_y;
//	if (std::is_neq(res)) return res;
//	res = m_rgba <=> other.m_rgba;
//	return res;					
//}


//bool Pixel::operator<(const Pixel& other) const
//{
//	bool res =  m_x < other.m_x;
//	if (m_x < other.m_x) res = m_y < other.m_y;
//	return res;
//}

std::ostream& operator<<(std::ostream& out, const Pixel& pixel)
{
	return out << "P["
		<< "x=" << pixel.x()
		<< ", y=" << pixel.y()
		<< ", rgba=" << pixel.rgba()
		<< "]";
	return out;
}

std::ostream& operator<<(std::ostream& out, rgba_t rgba)
{
	return out
		<< std::get<0>(rgba)
		<< '|' << std::get<1>(rgba)
		<< '|' << std::get<2>(rgba)
		<< '|' << std::get<3>(rgba);
}
