#ifndef OptionsTri_h
#define OptionsTri_h

//inputting and displaying option data
int GetInputData(int& N, double& K);

int CheckArb(double q_u, double q_m, double q_d);


double PriceByCRRTri(double s_0, double u, double m,
                  double d, double r, double v, int N, double K,
                  double (*Payoff)(double z, double K));
//computing call payoff
double CallPayoff(double z, double K);

//computing put payoff
double PutPayoff(double z, double K);

#endif


