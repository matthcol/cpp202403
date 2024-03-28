#include "pch.h"

#include "../ImageIO/Pixel.cpp"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}



TEST(TestPixelInplacePlus, PlusRgba) {
	rgba_t rgba1{ 0.25, 0.5, 0.75, 1.0 };
	rgba_t rgba2{ 0.125, 0.25, 0.5, 0.625 };
	rgba_t expectedRgba2{ 0.375, 0.75, 1.25, 1.625 };
	Pixel pixel(1.0, 2.0, rgba1);
	pixel += rgba2;
	EXPECT_EQ(expectedRgba2, pixel.rgba());
}