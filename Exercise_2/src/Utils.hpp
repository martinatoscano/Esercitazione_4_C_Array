#pragma once
#include "iostream"

using namespace std;

// ImportData reads the input data from the input file in inputFileName
// n: number of assets
// S: invested amount
// w: vector whose component w(i) is fraction of the invested quantity S for the i-th asset
// r: vector whose component r(i) is the rate of return of the i-th asset
// return the result of the reading, true is success, false is error
bool ImportData(const string& inputFileName,
                size_t& n,
                double& S,
                double*& w,
                double*& r);

// Export a vector in a string
// n: size of the vector
// v: vector
// return the resulting string
string ArrayToString(const size_t& n,
                     const double* const& v);

// Return the rate of return of the portfolio calculeted through weighted average
// n: size of vectors
// w: first vector
// r: second vector
// return the resulting rate of return
double RateOfReturn(const size_t& n,
                    const double* const& w,
                    const double* const& r);

//ExportResult export the result obtained in outputFileName
// S: invested amount
// n: number of assets
// w: first vector
// r: second vector
// rateOfReturn: the rate of return
// finalValue: final value of the whole portfolio
// return the result of the export, true is success, false is error
bool ExportResult(const string& outputFileName,
                  const double S,
                  const size_t& n,
                  const double* const& w,
                  const double* const& r,
                  const double& rateOfReturn,
                  const double& finalValue);
