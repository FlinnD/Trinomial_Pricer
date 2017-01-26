#include "OptionsTri.h"
#include "TriModel.h"
#include <iostream>
#include <cmath>
using namespace std;

int GetInputData(int& N, double& K)
{
   cout << "Enter steps to expiry N: "; cin >> N;
   cout << "Enter strike price K:    "; cin >> K;
   cout << endl;
   return 0;
}
//call: 61.7446 put: 0.298943
//new function that performs the backward induction
double PriceByCRRTri(double s_0, double u, double m, double d, double r, double v, int N, double K, double (*Payoff)(double z, double K))
{
    double q_u = RiskNeutProb1(u,m,d,r,v);
    //cout << q_u << endl;
    double q_m = RiskNeutProb2(u,m,d,r,v);
   // cout << q_m << endl;
    double q_d = RiskNeutProb3(u,m,d,r,v);
   // cout << q_d << endl;
    double PriceTri[N+1][N+1];
     //first set values of H(N,i,j)
    for(int i =0; i<=N; i++)
    {
        for(int j = 0; (i + j)<=N; j++)
        {
            PriceTri[i][j]=Payoff(S(s_0,u,m,d,N,i,j),K);
           //cout << PriceTri[i][j] << endl;

        }
    }
    //now we can find all other Payoffs at each node by iteration.
    for(int n=N-1; n>=0; n--)
    {
        for(int i =0; i<=n; i++)
        {
            for(int j=0; (i +j)<=n; j++)
            {
                PriceTri[i][j] = (q_u*PriceTri[i+1][j]+q_m*PriceTri[i][j+1]+q_d*PriceTri[i][j])/(1+r);
              // cout << PriceTri[i][j] << endl;
            }
        }
    }

    return PriceTri[0][0];
}
    int CheckArb(double q_u, double q_m, double q_d) //check arbitrage
    {

      if (q_u<=0 || q_u>=1 || q_m<=0 || q_m>=1 || q_d<=0 || q_d>=1)

        {
            cout << "Arbitrage exists" << endl;
            cout << "Terminating program" << endl;

            return 1;
        }

      cout << "Input data checked" << endl;
      cout << "There is no arbitrage" << endl << endl;

      return 0;

    }

double CallPayoff(double z, double K)
{
   if (z>K) return z-K;
   return 0.0;
}

double PutPayoff(double z, double K)
{
   if (z<K) return K-z;
   return 0.0;
}


