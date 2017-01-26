#ifndef TriModel_h
#define TriModel_h
//q_u
double RiskNeutProb1(double u, double m, double d, double r, double v);
//q_m
double RiskNeutProb2(double u, double m, double d, double r, double v);
//q_d
double RiskNeutProb3(double u, double m, double d, double r, double v);

int GetInputDataTri(double& s_0, double& u, double& m, double& d, double& r, double& v);

double S(double s_0, double u, double m, double d, int n, int i, int j);

#endif


