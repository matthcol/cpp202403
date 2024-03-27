// ImageIO.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <tuple>

#include "pixel.h"

void demoPixel() {
    std::cout << "Start demo pixel" << std::endl;
    rgba_t rgba{1.0, 0.0, 0.0, 0.5};
    double r, g, b, a;
    std::tie(r, g, b, a) = rgba;
    std::cout << "r (get)=" << std::get<0>(rgba)
        << ", r=" << r
        << ", g=" << g
        << ", b=" << b
        << ", a=" << a
        << std::endl;

    Pixel pixel1;
    Pixel pixel2(2.0, 3.0, rgba);
    Pixel pixel3(2.0, 4.0, { 1.0, 0.0, 0.0, 0.5 });
    std::cout << "End demo pixel" << std::endl;
}

int main()
{
    demoPixel();
}
