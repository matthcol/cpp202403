// Basics.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <string>
#include <cstdint>
#include <limits>
#include <iomanip>
#include <bitset>
#include <cstddef>

using namespace std;

void demoIntegers() {
    // types: char, short, int, long, long long (default signed, unsigned)
    int x = 3;
    int y;
    y = x + 3;
    std::cout << "x=" << x
        << ", y=" << y
        << std::endl;
    unsigned int w = 4000000000;
    int ww = 4000000000;
    std::cout << w << ", " << ww << std::endl;
    std::cout << "Size of int: " << sizeof(int) << std::endl;
}

void demoIntegersAlias() {
    // 8 bits integers i.e 1 byte (fr: octet)
    uint8_t xu8;
    int8_t x8;
    xu8 = 255;
    x8 = 65;
    std::cout << "signed 8 bits: " << (int) x8
        << ", unsigned 8 bits: "  << (unsigned int) xu8
        << std::endl;
    x8++;
    xu8++;
    ++xu8;
    x8 += 2; // = *= /= %=
    --x8;
    std::cout << "signed 8 bits: " << (int)x8
        << ", unsigned 8 bits: " << (unsigned int)xu8
        << std::endl;
    std::cout << "limits uint8_t: " << +std::numeric_limits<uint8_t>::min()
        << " - " << +std::numeric_limits<uint8_t>::max() << std::endl;
    std::cout << "limits int64_t: " << std::numeric_limits<int64_t>::min()
        << " - " << std::numeric_limits<int64_t>::max() << std::endl;
    // operatiors: + - * / %
    std::cout << "13 / 4: q=" << (13 / 4) << ", r=" << (13 % 4) << std::endl;
}

void demoFloats() {
    // <iomanip>: fixed, scientific, setprecision, boolalpha, endl
    float price = 0.1f;  // 0.00011001100110011001100..
    std::cout << std::setprecision(10) << "1 tagada: " << price << std::endl
        << "2 tagada: " << (2 * price) << std::endl
        << "3 tagada: " << (3 * price) << std::endl;
    std::cout << std::boolalpha << (0.3f == 3 * price) << std::endl;
    double bigDistance = 1.5E20;
    double smallDistance = 1.25E-20;
    std::cout << smallDistance << " " << bigDistance << std::endl;
    std::cout << "float: " << std::numeric_limits<float>::min()
        << " - " << std::numeric_limits<float>::max() << std::endl;
    std::cout << "double: " << std::numeric_limits<double>::min()
        << " - " << std::numeric_limits<double>::max() << std::endl;

    // binary: 111.111 (base2) = 7.875 (base10)
    // IEEE754: 1.11111 * 2^2
    double maxFinite = std::numeric_limits<double>::max();
    double inf = maxFinite * 2;
    double nan = inf / inf;
    std::cout << "Special floats: " << maxFinite << " " << inf << " " << nan << std::endl;
}

void demoComparisons() {
    // until C++20: == != < > <= >=
    int x = 123;
    std::cout << std::boolalpha << (x < 1000) << std::endl;

    // since C+20: <=>
    auto cmp = (x <=> 1000);
 
    // different shortcuts:
    std::cout << std::boolalpha << (std::cmp_less(x, 1000)) 
        << " " << std::is_lt(cmp) << std::endl;
}

void demoText() {
    // https://en.cppreference.com/w/cpp/string
    // https://en.cppreference.com/w/cpp/string/basic_string
    // https://en.cppreference.com/w/cpp/language/string_literal
    
    // C types
    char c = 'A';
    char text[] = "Cofee"; // i.e. char *
    // but also: wchar 

    // C++: std::basic_string<CharT>
    // - std::string (char)
    // - std::wstring (wchar)
    // - std::u8string (char8_t) => UTF-8
    // - std::u16string (char16_t) => UTF-16
    // - std::u32string (char32_t) => UTF-32

    std::string city = "Montpellier";
    std::cout << city << std::endl;

    std::wstring wCity = L"Montpellier";
    std::wcout << wCity << std::endl;

    std::u8string cityJap8 = u8"東京"; // \xe6\x9d\xb1\xe4\xba\xac
    std::u16string cityJap16 = u"東京";
    std::u32string cityJap32 = U"東京"; // \xff\xfe\x00\x00qg\x00\x00\xacN\x00\x00

    // TODO:  std::cout << cityJap << std::endl;
    for (auto c : cityJap8) {
        uint8_t byte = static_cast<uint8_t>(c);
        std::cout << std::dec << static_cast<uint16_t>(byte)
            << " " << std::bitset<8>(byte)
            << " " << std::hex << (uint16_t) byte << std::endl;
    }
    std::cout << std::endl;
}

int main()
{
    int x = 3;
    /*std::cout << "Hello Ubisoft"
        << ", soon coffee time: "
        << x
        << std::endl;*/
    cout << "Hello Ubisoft"
        << ", soon coffee time: "
        << x
        << endl;
    demoIntegers();
    demoIntegersAlias();
    demoFloats();
    demoComparisons();
    demoText();
    return 0;
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
