
#include "filter.h"
 
std::tuple<std::vector<double>, std::vector<double>> filter(std::vector<double> b, std::vector<double> a, const std::vector<double> x,std::vector<double> z)
{
    int na = a.size();
    int nb = b.size();
    int n = 0;

    if (na > nb)
    {
    
        for (size_t i = 0; i < na-nb; i++)
        {
            b.push_back(0);
        }
        
        n = na;
    }
    else if (na < nb)
    {
        for (size_t i = 0; i < nb-na; i++)
        {
            a.push_back(0);
        }

        n = nb;
    }
    else
    {
        n = na;
    }


    if (z.size() < n-1)
    {
        z[n-2] = 0;
    }

    for (size_t i = 0; i < n; i++)
    {
        b[i] /= a[0];
        a[i] /= a[0];
    }

    std::vector<double> y =  {};   

    for (size_t i = 0; i < x.size(); i++)
    {
        y.push_back(0);
    }

    for (size_t m = 0; m < y.size(); m++)
    {
        double xm = x[m];

        y[m] = b[0] * xm + z[0];

        double ym = y[m];
        for (size_t i = 1; i < n-1; i++)
        {
            z[i-1] = b[i] * xm + z[i] - a[i] * ym;

        }
        z[n-2] = b[n-1] * xm - a[n-1] * ym;
    }
    
    return  std::make_tuple(y,z);
}
 
