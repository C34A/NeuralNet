#include <iostream>
#include "Propogation.h"
#include "Scaffold.h"
int main()
{
    Scaffold::Input("Input.txt");
    Scaffold::InitNet();
   // Propogation::FeedForward(Scaffold::InWeights, Scaffold::HiddenWeights, Scaffold::OutWeights, 0);
    for (int i = 0; i < Scaffold::OutputCount; i++)
    {
        std::cout << Scaffold::OutputVal[i] << " ";
    }
    std::cout << "worked!";
    std::cin.get();
    return 0;
}