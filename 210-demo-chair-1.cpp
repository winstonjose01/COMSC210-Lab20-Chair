
// COMSC210 | Lab 20 | Winston Jose
// IDE used : Visual Studio Code
// Github link: https://github.com/winstonjose01/COMSC210-Lab20-Chair

#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;
const int SIZE = 3;
const int MIN = 10000;
const int MAX = 99999;

class Chair {
private:
    int legs;
    double * prices;
public:
    // constructors
    Chair() {
        prices = new double[SIZE];
        int random = rand() % 2;
        //legs = 0;
        if (random == 0)
            legs = 3;
        else
            legs = 4;
        for (int i = 0; i < SIZE; i++)
            //prices[i] = 0;
            prices[i] = (rand() % (MAX - MIN + 1) + MIN) / 100.0;
    }
    Chair(int l, double prices[SIZE]) {
        this->prices = new double[SIZE];
        legs = l;
        for (int i = 0; i < SIZE; i++)
            //prices[i] = 0;
            this->prices[i] = prices[i];
    }

    // setters and getters
    void setLegs(int l)      { legs = l; }
    int getLegs()            { return legs; }

    void setPrices(double p1, double p2, double p3) { 
        prices[0] = p1; prices[1] = p2; prices[2] = p3; 
    }

    double getAveragePrices() {
        double sum = 0;
        for (int i = 0; i < SIZE; i++)
            sum += prices[i];
        return sum / SIZE;
    }

    void print() {
        cout << "\tCHAIR DATA - legs: " << legs << endl;
        cout << "\tPrice history: " ;
        for (int i = 0; i < SIZE; i++)
            cout << prices[i] << " ";
        cout << endl << "\tHistorical avg price: " << getAveragePrices();
        cout << endl << endl;
    }
};

int main() {
    srand(std::time(0));
    cout << fixed << setprecision(2);

    //creating pointer to first chair object
    cout << "Displaying intial chair object: \n";
    Chair *chairPtr = new Chair;
    chairPtr->setLegs(4);
    chairPtr->setPrices(121.21, 232.32, 414.14);
    chairPtr->print();

    //creating dynamic chair object with constructor
    cout << "Displaying Chair object using parameter constructor: \n";
    double init_prices[3] = {0,0,0};
    Chair *livingChair = new Chair(3, init_prices);
    livingChair->setPrices(525.25, 434.34, 252.52);
    livingChair->print();
    delete livingChair;
    livingChair = nullptr;

    //creating dynamic array of chair objects
    cout << "Displaying chair collection using default constructor: \n";
    Chair *collection = new Chair[SIZE];

    for (int i = 0; i < SIZE; i++)
        collection[i].print();

    delete[] collection;
    
    return 0;
}