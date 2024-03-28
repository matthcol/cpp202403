// ImageIO.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
#include <utility>
#include <memory>

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

    std::cout << pixel1 << std::endl
        << pixel2 << std::endl
        << pixel3 << std::endl;

    pixel2 += {0.1, 0.2, 0.3, 0.4};
    std::cout << "After add: " << pixel2 << std::endl;

    std::cout << "End demo pixel" << std::endl << std::endl;

    bool t1 = pixel1 < pixel2;
    bool t2 = pixel1 > pixel2;
    bool t3 = pixel1 <= pixel2;
    bool t4 = pixel1 >= pixel2;
    bool t5 = pixel1 == pixel2;
    bool t6 = pixel1 != pixel2;
}

void demoMemory() {
    std::cout << "Start demo memory" << std::endl;
    Pixel pixel(0.1, 0.2, { 0.4, 0.5, 0.6, 0.7 });
    auto pixel_ptr = &pixel;
    auto pixel_ptr_ptr = &pixel_ptr;
    auto pixel_ptr_ptr_ptr = &pixel_ptr_ptr;
    auto pixel_ptr_ptr_ptr_ptr = &pixel_ptr_ptr_ptr;
    auto pixel_ptr_ptr_ptr_ptr_ptr = &pixel_ptr_ptr_ptr_ptr;
    auto pixel_ptr_ptr_ptr_ptr_ptr_ptr = &pixel_ptr_ptr_ptr_ptr_ptr;
    std::cout << "pixel*:" << pixel_ptr << std::endl
        << "pixel**:" << pixel_ptr_ptr << std::endl
        << "pixel***:" << pixel_ptr_ptr_ptr << std::endl
        << "pixel****:" << pixel_ptr_ptr_ptr_ptr << std::endl
        << "pixel*****:" << pixel_ptr_ptr_ptr_ptr_ptr << std::endl
        << "pixel******:" << pixel_ptr_ptr_ptr_ptr_ptr_ptr << std::endl
        << "pixel*******:" << &pixel_ptr_ptr_ptr_ptr_ptr_ptr << std::endl
        << std::endl;

    double* x_ptr = (double*)(pixel_ptr);
    std::cout << *x_ptr << std::endl;
    *x_ptr = 0.99;
    std::cout << pixel << std::endl;
    std::cout << "End demo pixel" << std::endl << std::endl;
}

double gGetter(const Pixel& pixel) {
    return pixel.g();
}

void demoLoopVectorPixel() {
    size_t n = 1920 * 1080;
    std::vector<Pixel> pixels(n);
    double value = 0.0;
    double step = 0.0001;
    auto generate_pixel = [&value, step] {
        value += step;
        return Pixel(value, -value, { value, value, value, value });
    };
    // std::ranges::generate(pixels, generate_pixel);
    for (auto& pixel: pixels)
    {
        pixel = generate_pixel();

    }
    std::cout << pixels[0] << "..." 
        // << *(pixels.crbegin()) 
        << pixels[n-1]
        << std::endl;

    double sumX = 0.0;
    for (const auto& pixel : pixels) {
        sumX += pixel.x();
    }
    std::cout << "Sum X: " << sumX << std::endl;

    double sumY = 0.0;
    for (auto const& pixel : pixels) {
        sumY += pixel.x();
    }
    std::cout << "Sum Y: " << sumY << std::endl;

    double sumR = 0.0;
    for (auto& pixel : std::as_const(pixels)) {
        sumR += pixel.x();
    }
    std::cout << "Sum R: " << sumR << std::endl;

    // template parameter; InputIt = std::vector<Pixel>::iterator
    auto cmpRedDesc = [](const auto& p1, const auto& p2)
        {
            return p1.r() > p2.r();
        };
    std::sort(pixels.begin(), pixels.end(), cmpRedDesc);
    std::cout << pixels[0] << "..." << pixels[n - 1] << std::endl;

    // C++ 20: allow projection function
    std::ranges::sort(pixels.begin(), pixels.end(), {}, &Pixel::x);
    std::cout << pixels[0] << "..." << pixels[n - 1] << std::endl;
    std::ranges::sort(pixels.begin(), pixels.end(), {}, [](const auto& pixel) { return -pixel.x(); });
    std::cout << pixels[0] << "..." << pixels[n - 1] << std::endl;
    std::ranges::sort(pixels.begin(), pixels.end(), {}, &gGetter);
    std::cout << pixels[0] << "..." << pixels[n - 1] << std::endl;
    std::ranges::sort(pixels.begin(), pixels.end(), {}, [](const auto& pixel) { return std::make_pair(pixel.y(), pixel.x()); });
    std::cout << pixels[0] << "..." << pixels[n - 1] << std::endl;
    std::ranges::sort(pixels.begin(), pixels.end(), {}, [](const auto& pixel) { return std::make_pair(pixel.y(), pixel.x()); });
    std::cout << pixels[0] << "..." << pixels[n - 1] << std::endl;

    // sort with natural order
    std::sort(pixels.begin(), pixels.end());
    std::cout << "sort with internal < or <=>: " << pixels[0] << "..." << pixels[n - 1] << std::endl;
    
    /*std::ranges::sort(pixels, std::ranges::greater());
    std::cout << "ranges::sort with <=>: " << pixels[0] << "..." << pixels[n - 1] << std::endl;*/
}

void demoVectorSmartPixelPtr() {
    std::vector<std::unique_ptr<Pixel>> uniquePixelVector{
        std::move(std::make_unique<Pixel>()),
        std::move(std::make_unique<Pixel>()),
        std::move(std::make_unique<Pixel>()),
        std::move(std::make_unique<Pixel>())
    };

    auto& p0 = uniquePixelVector[0]; // ok by ref, KO by copy

    auto pixel_ptr = std::make_shared<Pixel>();
    std::cout << "Counter pixel: " << pixel_ptr.use_count() << std::endl;
    std::vector<std::shared_ptr<Pixel>> sharedPixelVector{
        pixel_ptr,
        std::make_shared<Pixel>(),
        std::make_shared<Pixel>(),
        std::make_shared<Pixel>()
    };
    std::cout << "Counter pixel: " << pixel_ptr.use_count() << std::endl;
    for (auto currentPixel_ptr : sharedPixelVector) {
        std::cout << "Counter current pixel: " << pixel_ptr.use_count() << std::endl;
    }
    std::cout << "Counter pixel: " << pixel_ptr.use_count() << std::endl;
    auto p1 = sharedPixelVector[0];
}

int main()
{
    /*demoPixel();
    demoMemory();
    demoLoopVectorPixel();*/
    demoVectorSmartPixelPtr();
}
