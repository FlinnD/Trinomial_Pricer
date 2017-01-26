#include <iostream>
#include <cmath>
using namespace std;

double RiskNeutProb1(double u, double m, double d, double r, double v)
{
   return (2*m*d-(m+r)*(d+r)+pow(v,2))/((u-m)*(u-d));
}

double RiskNeutProb2(double u, double m, double d, double r, double v)
{
   return (2*u*d-(u+r)*(d+r)+pow(v,2))/((m-u)*(m-d));
}


double RiskNeutProb3(double u, double m, double d, double r, double v)
{
   return (2*u*m-(u+r)*(m+r)+pow(v,2))/((d-u)*(d-m));
}


double S(double s_0, double u, double m, double d, int n, int i, int j)
{
  // cout << s_0*pow(1+u,i)*pow(1+m,j)*pow(1+d,n-i-j) << endl;
   return s_0*pow(1+u,i)*pow(1+m,j)*pow(1+d,n-i-j);
}

int GetInputDataTri(double& s_0,
                 double& u, double& m, double& d, double& r, double& v)
{
   //entering data
   cout << "Enter S0: "; cin >> s_0;
   cout << "Enter U:  "; cin >> u;
   cout << "Enter M:  "; cin >> m;
   cout << "Enter D:  "; cin >> d;
   cout << "Enter R:  "; cin >> r;
   cout << "Enter V:"; cin >> v;
   cout << endl;

   //making sure that legal data range is submitted.
   if (s_0<=0.0 || u<=-1.0 || m<=-1.0 || d<=-1.0 || u<=d || m<=d || u<=m
                                     || r<=-1.0)
   {
      cout << "Illegal data ranges" << endl;
      cout << "Terminating program" << endl;
      return 1;
   }



   return 0;
}



