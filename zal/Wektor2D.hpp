class Wektor2D
{
public:
    Wektor2D()
    {
        x = 0.;
        y = 0.;
    }
    Wektor2D(double a, double b)
    {
        x = a;
        y = b;
    }

private:
    double x;
    double y;

public:
    // setters
    void setX(double a) { x = a; }
    void setY(double b) { y = b; }
    // getters
    double getX() { return x; }
    double getY() { return y; }
    // methods
    void norm() { std::cout << sqrt(x * x + y * y) << "\n"; }
    void print() { std::cout << "wspolrzedna x:" << x << "\t wspolrzedna y:" << y << "\n"; }
};

Wektor2D operator+(Wektor2D a, Wektor2D b)
{
    return Wektor2D{a.getX() + b.getX(), a.getY() + b.getY()};
}

double operator*(Wektor2D a, Wektor2D b)
{
    return (a.getX() * b.getX() + a.getY() * b.getY());
}
