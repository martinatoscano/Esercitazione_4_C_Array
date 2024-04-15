#include <iostream>
#include <fstream>
#include <sstream>
#include "Utils.hpp"

using namespace std;

int main()
{
    string inputFileName = "./data.csv";
    size_t n = 0;
    double S = 0;
    double* w = nullptr;
    double* r = nullptr;

    if(!ImportData(inputFileName, n, S, w, r))
    {
        cerr << "Something went wrong with import" << endl;
        return -1;
    }
    else
        cout << "Import successful: S = " << S << " n = " << n << " w = " << ArrayToString(n, w) << " r = " << ArrayToString(n, r) << endl;

    double rateOfReturn = RateOfReturn(n, w, r);
    cout << "rate of return: " << rateOfReturn << endl;

    double finalValue = (1 + rateOfReturn)*S;
    cout << "final value of portfolio: " << finalValue << endl;

    string outputFileName = "./result.txt";
    if (!ExportResult(outputFileName, S, n, w, r, rateOfReturn, finalValue))
    {
        cerr<< "Something goes wrong with export"<< endl;
        return -1;
    }
    else
        cout<< "Export successful"<< endl;

    delete[] w;
    delete[] r;

    return 0;
}

