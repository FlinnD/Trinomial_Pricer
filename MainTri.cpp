#include "TriModel.h"
#include "OptionsTri.h"
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
//omitted Binomial pricing. Only contains Trinomial variant

    double s_0, u, m, d, r, v;

    if (GetInputDataTri(s_0,u,m,d,r,v)==1) return 1;

    if (CheckArb(RiskNeutProb1(u,m,d,r,v),RiskNeutProb2(u,m,d,r,v),RiskNeutProb3(u,m,d,r,v))==1) return 1; //could be made far more efficient.

    double K;   //strike price
    int N;      //steps to expiry

    cout << "Enter call option data:" << endl;
    GetInputData(N,K);
    cout << "European call option price = "
        << PriceByCRRTri(s_0,u,m,d,r,v,N,K,CallPayoff)
        << endl << endl;

    cout << "Enter put option data:" << endl;
    GetInputData(N,K);
    cout << "European put option price =  "
        << PriceByCRRTri(s_0,u,m,d,r,v,N,K,PutPayoff)
        << endl << endl;



     cout << "Hit enter to close the program.";
     cin.ignore();
     cin.get();

    return 0;
}


