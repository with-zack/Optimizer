#include "optimizer1D.hpp"
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
    cout<<"Left: "<<left<<" Right: "<<right<<endl;
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
double Optimizer::quadraInterpolation()
{

}
double Optimizer::gridSearch(unsigned int m = 10)
{
    forback();
    double step = (right-left)/(m+1);
    double ans = left;
    while(epsilon<(2*step))
    {
        double minimum = f(left);
        unsigned int alpha = 0;
        for(unsigned int i=1;i<m;i++)
        {
            double temp = f(left+step*i);
            if(temp < minimum)
            {
                alpha = i;
                minimum = temp;
            }
        }
        ans = left + step*alpha;
        right = left + step*(alpha+1);
        left += step*(alpha-1);
        step = 2*step/(m+1);
    }
    return ans;
}