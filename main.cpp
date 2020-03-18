#include <iostream>
#include "optimizer.hpp"
using namespace std;
int main()
{
    Optimizer opt(2, 100, 3);
    // cout<<opt.goldenSplit()<<endl;
    cout<<opt.gridSearch(20);
}
