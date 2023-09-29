#include "Filtfilt.h"

/**
 *  \brief Received signal demodulation function
 * 
 *  \param[in] b,a function coefficients, specified as vectors. If you use an all-pole filter, enter 1 for b. If you use an all-zero (FIR) filter, enter 1 for a.
 *  \param[in] x Input signal, specified as a real-valued or complex-valued vector, matrix, or N-D array. x must be finite-valued. The length of x must be greater than three times the filter order, defined as max(length(B)-1, length(A)-1). The function operates along the first array dimension of x unless x is a row vector. If x is a row vector, then the function operates along the second dimension.
 * 
 *  \return demodulated signal
 * Performs zero-phase digital filtering by processing 
 * the input data x in both the forward and reverse 
 * directions. After filtering the data in the forward 
 * direction, the function matches initial conditions 
 * to minimize startup and ending transients, reverses 
 * the filtered sequence, and runs the reversed sequence 
 * back through the filter. 
 * 
 * 
*/
std::vector<double> Filtfilt(const std::vector<double> b, const std::vector<double> a, const std::vector<double> x){

    int Npts = x.size();
    int na = a.size();
    int nb = b.size();

    int nfilt = std::max(na,nb);
    int nfact = std::max(1,3*(nfilt-1));

    std::vector<double> rows;

    for (size_t i = 1; i < nfilt; i++)
    {
        rows.push_back(i) ;
    }
    for (size_t i = 2; i < nfilt; i++)
    {
        rows.push_back(i) ;
    }
    for (size_t i = 1; i < nfilt-1; i++)
    {
        rows.push_back(i) ;
    }

    std::vector<double> cols;

    for (size_t i = 1; i < nfilt; i++)
    {
        cols.push_back(1) ;
    }
    for (size_t i = 2; i < nfilt; i++)
    {
        cols.push_back(i) ;
    }
    for (size_t i = 2; i < nfilt; i++)
    {
        cols.push_back(i) ;
    }   

    std::vector<double> vals;

    vals.push_back(1+a[1]);

    for (size_t i = 2; i < nfilt; i++)
    {
        vals.push_back(a[i]) ;
    }
    for (size_t i = 1; i <= nfilt-2; i++)
    {
        vals.push_back(1) ;
    }
    for (size_t i = 1; i <= nfilt-2; i++)
    {
        vals.push_back(-1) ;
    }         

    std::vector<double> rhs;

    for (size_t i = 1; i < nfilt; i++)
    {
        rhs.push_back(b[i]-b[0]*a[i]) ;
    } 
  

    
    double A[10][10] = {}; 

    for (size_t i = 0; i < vals.size(); i++)
    {
       int temp_rows = rows[i];
       int temp_cols = cols[i];
       double temp_vals = vals[i];

       A[temp_rows-1][temp_cols-1] = A[temp_rows-1][temp_cols-1] + temp_vals;
    }
    
 
    int order = 10;
    
    double** I = inversion(A,order);

    std::vector<double> zi ;    

    for (int i = 0; i < 10; i++)
    {
        double temp = 0;
        for (int j = 0; j < 10; j++)
        {

            temp += I[i][j] * rhs[j];

        }
        zi.push_back(temp);
    }
    std::vector<double> xt = {};

    for (size_t i = nfact; i > 0; i--)
    {
        xt.push_back(-1*x[i]+2*x[0]);
    }
    
    std::vector<double> z1 = {};
    
    for (size_t i = 0; i < zi.size(); i++)
    {
        z1.push_back(zi[i]*xt[0]) ;
    }
    
    std::vector<double> y1 =  {};
    std::vector<double> z0 =  {};


    tie(y1, z0) =  filter(b,a,xt,z1);  

    std::vector<double> y2 =  {};

    tie(y2, z0) =  filter(b,a,x,z0); 


    xt.clear();

    for (size_t i = Npts-2; i > Npts-2-nfact; i--)
    {
        xt.push_back(-x[i]+2*x[Npts-1]);
    }

    std::vector<double> y3 =  {};

    tie(y3, z0) = filter(b, a, xt, z0);    

    xt.clear();
    for (int i = nfact-1; i >= 0; i--)
    {
        xt.push_back(y3[i]);
    }
   
    z1.clear();

    for (size_t i = 0; i < zi.size(); i++)
    {
        z1.push_back(zi[i]*y3[y3.size()-1]);
   
    }

    std::vector<double> y4 =  {};

    tie(y4, z0) = filter(b, a, xt, z1);


    std::vector<double> y5 =  {};

    xt.clear();

    for (int i = y2.size()-1; i >= 0; i--)
    {
        xt.push_back(y2[i]);
    }

    tie(y5, z0) = filter(b, a, xt, z0);

    std::vector<double> binarycode;

    for (int i = Npts-1; i >= 0; i--)
    {
        binarycode.push_back(y5[i]);
    }
    
    return binarycode;
}