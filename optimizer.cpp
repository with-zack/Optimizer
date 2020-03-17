#include "optimizer.hpp"
void Optimizer::forback()
{
    double middle;
    if(f(left) <= f(right))
    {
        while (true)
        {
            h *= 2;
            left -= h;
            if(f(right) <= f(left))
            {
                break;
            }
        }
    }
    else
    {
        while (true)
        {
            h *= 2;
            right += h;
            if (f(left) <= f(right))
            {
                break;
            }
        }
    }
}
double Optimizer::goldenSplit()
{
    cout<<"Using Golden Split method."<<endl;
    while(epsilon < (right-left))
    {
        double alpha = 0.618*left + 0.382*right;
        double beta = 0.618*right + 0.382*left;
        if(f(alpha) < f(beta))
        {
            right = beta;
        }
        else
        {
            left = alpha;
        }
    }
    return (left+right)/2;
}