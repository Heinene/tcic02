#include <iostream>
#include <iomanip>
#include <cmath>

double fu(int x)
{
    double fx = cos(x)*tanh(x);
    return fx;
}

double fumi(int x)
{
    double fmin = cos(x)*tanh(x)*sin(5 * x);
    return fmin;
}
int main()
{
    std::cout << "Zavis N ot P i Q" << std::endl;
    float P = 0.9, Q;
    std::cout << '|' << std::setw(5) << "Q/P" << std::setw(3) << '|';
    while (P <= 0.99) {
        std::cout << std::setw(6) << P << " |";
        P += 0.01;
    }
    std::cout << "\n" << std::string(89, '-');
    int n = 1;
    for (Q = 0.005; Q <= 0.105; Q += 0.005)
    {
        std::cout << "\n" << "| " << std::setw(5) << Q << " |";
        for (P = 0.9; P <= 0.999; P += 0.01)
        {
            while (n < log(1 - P) / log(1 - Q))
                n++;
            std::cout << std::setw(6) << n << " |";
            n = 1;
        }
    }

    std::cout <<"\n"<< "\nEcstremum F(x) ot P i Q " << std::endl;
    std::cout << '|' << std::setw(5) << "q/P" << std::setw(3) << '|';
    P = 0.90;
    while (P <= 0.99) {
        std::cout << std::setw(9) << P << " |";
        P += 0.01;
    }
    std::cout << "\n" << std::string(119, '-');
    n = 1;
    float min = 1000000.0, res;
    for (Q = 0.005; Q <= 0.105; Q += 0.005) {
        std::cout << "\n" << "| " << std::setw(5) << Q << " |";
        for (P = 0.9; P <= 0.999; P += 0.01) {
            while (n < log(1 - P) / log(1 - Q))
                n++;
            for (int i = 0; i < n; i++) {
                res = fu((float)(rand() % 25000) / 10000 + 1.5);
                if (res < min) min = res;
            }
            std::cout << std::setw(7) << min << " |";
            n = 1;
            min = 100000.0;
        }
    }





    std::cout << "\n" << "\nEcstremum f(x)*sin(5x) ot P i Q" << std::endl;
    std::cout << '|' << std::setw(5) << "q/P" << std::setw(3) << '|';
    P = 0.90;
    while (P <= 0.99) {
        std::cout << std::setw(9) << P << " |";
        P += 0.01;

    }
    std::cout << "\n" <<std::string(119, '-');

    n = 1;
    min = 1000000.0, res;
    for (Q = 0.005; Q <= 0.105; Q += 0.005) {
        std::cout << "\n" << "| " << std::setw(5) << Q << " |";

        for (P = 0.9; P <= 0.999; P += 0.01) {
            while (n < log(1 - P) / log(1 - Q))
                n++;
            for (int i = 0; i < n; i++) {
                res = fumi((float)(rand() % 2501) / 1000 + 1.32);
                if (res < min) min = res;
            }
            std::cout << std::setw(7) << min << " |";

            n = 1;
            min = 100000.0;

        }
    }
    return 0;
}