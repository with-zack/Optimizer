#include <iostream>
#include "optimizer.hpp"
using namespace std;
int main()
{
    Optimizer opt(2, 100, 3);
    cout<<opt.solve(Solver::GoldenSplit)<<endl;
}
