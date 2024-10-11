
    // COMSC210 | Lab 20 | Winston Jose
    // IDE used : Visual Studio Code
    // Github link: https://github.com/winstonjose01/COMSC210-Lab20-Chair

    #include <iostream>
    #include <iomanip>
    #include <ctime>

    using namespace std;
    const int SIZE = 3;         // size of the price history array
    const int MIN = 10000;      // minimum value for random price generation
    const int MAX = 99999;      // maximum value for random price generation

    class Chair {
    private:
        int legs;           // number of legs the chair has
        double * prices;    // dynamic array to store price history
    public:
        // // Default constructor: initializes prices array and randomly sets number of legs
        Chair() {
            prices = new double[SIZE];
            int random = rand() % 2;
            // Randomly assign the chair either 3 or 4 legs
            if (random == 0)
                legs = 3;
            else
                legs = 4;
            // Initialize price history with random values within the range [MIN, MAX]
            for (int i = 0; i < SIZE; i++)
                //prices[i] = 0;
                prices[i] = (rand() % (MAX - MIN + 1) + MIN) / 100.0;
        }
        // Parameterized constructor: sets number of legs and initializes price history with given array
        Chair(int l, double prices[SIZE]) {
            this->prices = new double[SIZE];  // Allocate memory for price history array
            legs = l;
            for (int i = 0; i < SIZE; i++)
                //prices[i] = 0;
                this->prices[i] = prices[i];
        }

        // setters and getters
        void setLegs(int l)      { legs = l; }
        int getLegs()            { return legs; }
        // Setter for price history: takes individual prices and assigns them to the array
        void setPrices(double p1, double p2, double p3) { 
            prices[0] = p1; prices[1] = p2; prices[2] = p3; 
        }
        // Function to calculate and return the average price from the price history
        double getAveragePrices() {
            double sum = 0;
            for (int i = 0; i < SIZE; i++)
                sum += prices[i];
            return sum / SIZE;
        }
        // Function to print the chair details
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

        // Seed random number generator with the current time
        srand(std::time(0));
        cout << fixed << setprecision(2);

        //creating pointer to first chair object
        cout << "Displaying intial chair object: \n";
        // Dynamically create a Chair object using the default constructor
        Chair *chairPtr = new Chair;
        // Modify the chair's number of legs and price history
        chairPtr->setLegs(4);
        chairPtr->setPrices(121.21, 232.32, 414.14);
        chairPtr->print();

        //Clean up dynamically allocated memory for chairPtr
        delete[] chairPtr;
        chairPtr = nullptr;

        //creating dynamic chair object with constructor
        cout << "Displaying Chair object using parameter constructor: \n";
        // Create an array for the initial price history
        double init_prices[3] = {0,0,0};
        // Dynamically create a Chair object with specific leg count and price history
        Chair *livingChair = new Chair(3, init_prices);
        // Set new prices for this chair
        livingChair->setPrices(525.25, 434.34, 252.52);
        livingChair->print();

        //Clean up dynamically allocated memory for livingChair
        delete livingChair;
        livingChair = nullptr;

        //creating dynamic array of chair objects
        cout << "Displaying chair collection using default constructor: \n";
        Chair *collection = new Chair[SIZE];
        for (int i = 0; i < SIZE; i++)
            collection[i].print();

        // Clean up dynamically allocated memory for the chair collection
        delete[] collection;

        
        return 0;
    }