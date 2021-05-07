/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <functional>
#include <stdexcept>
#include<vector>
using namespace std;

std::vector<double> filter(std::vector<double>& sal, std::function<bool(double)> filterFunction)
{
    std::vector<double> filtered;
    for(int i = 0; i < sal.size(); i++)
    {
        if(filterFunction(sal[i]))
        {
            filtered.push_back(sal[i]);
        }
    }

    return filtered;
}

int main()
{
     std::vector<double> sal;
    sal.push_back(123.45);
    sal.push_back(256.8);
    sal.push_back(359.89); 
    sal.push_back(314.59);
    sal.push_back(666.6);
    sal.push_back(792.3);
    sal.push_back(442.5);
    sal.push_back(858.5);

    std::vector<double> filtered = filter(sal, [] (double x) -> bool {return x >= 500;});
    for(int i = 0; i < filtered.size(); i++)
    {
        std::cout << filtered[i] << " ";
    }
    std::cout << "\n";

    return 0;

}
