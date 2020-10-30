#include <cmath>
#include <iostream>

class Wektor2D
{
private:
    Wektor2D(double a, double b)
    {
        x = a;
        y = b;
        std::cout << "Inny Konstruktor wspolrzedna x: " << x << "\t wspolrzedna y: " << y << "\n";
        numerWektorow++;
    };

    double     x;
    double     y;
    static int numerWektorow;

public:
    // setters
    void setX(double a) { x = a; }
    void setY(double b) { y = b; }
    // getters
    double     getX() { return x; }
    double     getY() { return y; }
    static int getNumerWektorow() { return numerWektorow; }
    // methods
    void norm() { std::cout << sqrt(x * x + y * y) << "\n"; }
    void print() { std::cout << "wspolrzedna x: " << x << "\t wspolrzedna y: " << y << "\n"; }

    static Wektor2D kart(double x, double y) { return Wektor2D{x, y}; }

    static Wektor2D bieg(double r, double alpha)
    {
        return Wektor2D{r * cos(alpha), r * sin(alpha)};
    }

    Wektor2D()
    {
        x = 0.;
        y = 0.;
        std::cout << "Podstawowy Konstruktor wspolrzedna x: " << x << "\t wspolrzedna y: " << y << "\n";
        numerWektorow++;
    };

    ~Wektor2D()
    {
        std::cout << "Destruktor wspolrzedna x: " << x << "\t wspolrzedna y: " << y << "\n";
        numerWektorow--;
    };
};

int Wektor2D::numerWektorow = 0;

Wektor2D operator+(Wektor2D& a, Wektor2D& b)
{
    return Wektor2D::kart(a.getX() + b.getX(), a.getY() + b.getY());
    // problem tutaj mialem taki, ze nie moge dodac 3 wartosci do siebie,
    // bo nie umie niejawnie przekonwertowac Wektor2D tymaczowego z pierwszej czesci na referencje -
    // wymaga jawnej konwersji
}

double operator*(Wektor2D& a, Wektor2D& b)
{
    return (a.getX() * b.getX() + a.getY() * b.getY());
}

std::ostream& operator<<(std::ostream& jadda, Wektor2D& a)
{
    return jadda << "[" << a.getX() << "," << a.getY() << "]";
}

int main()
{
    std::cout << "Hello World!\n";
    Wektor2D* newsyf = new Wektor2D{};
    Wektor2D  syf    = Wektor2D::kart(8., 6.);
    syf.norm();
    syf.print();
    Wektor2D syf2         = Wektor2D::kart(2., 3.);
    Wektor2D syfnadsyfami = (Wektor2D&)(syf + syf2) + syf;
    syfnadsyfami.print();
    std::cout << syfnadsyfami * syf2 << "\n";
    std::cout << syfnadsyfami << "\n" << syf << "\n";

    delete newsyf;
    syf.~Wektor2D();
    syf2.~Wektor2D();
    syfnadsyfami.~Wektor2D();

    std::cout << Wektor2D::getNumerWektorow() << "\n";

    // tutaj też ciekawostka - calluje destruktor pomimo jawnego usunięcia elementów
}