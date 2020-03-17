#include <iostream>
#include <exception>
using namespace std;

enum class Solver
{
    GoldenSplit, QuadraInterpolation
};

class Optimizer
{
private:
    double a = 0, b = 0, c = 0;
    double left = 0, right = 1, h = 1;
    // minimum interval for some method to stop
    double epsilon = 0.05;
    // calculate function value
    double f(double x)
    {
        return c + x*(b+a*x); // two multiplication rather than three
    }
    // use forward-backward method to find the interval where optima exists
    void forback();

public:
    Optimizer(double a, double b, double c)
    {
        if(a<0)
        {
            throw std::invalid_argument("Not a convex function: \'a\' must be greater than 0.");
        }
        this->a = a;
        this->b = b;
        this->c = c;
    }
    double solve(Solver solver)
    {
        forback();
        cout<<left<<" "<<right<<endl;
        switch (solver)
        {
        case Solver::GoldenSplit:
            return goldenSplit();
            break;
        case Solver::QuadraInterpolation:
            break;
        default:
            break;
        }
    }
    double goldenSplit();
};

