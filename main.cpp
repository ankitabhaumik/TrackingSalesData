#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // For std::accumulate
using namespace std;

// Struct to represent a product
struct Product {
    double price;
    double discount;   // Discount as a percentage (e.g., 0.2 for 20%)
    int quantitySold;
};

void calculate_revenue_each_prod(vector<double> &revenues, vector<Product> products)
{
   transform(products.begin(),products.end(),revenues.begin(),[](auto& a){
        return ((a.price - (a.price * a.discount)) * a.quantitySold);
   });
}

int calculate_total_revenue(vector<double> revenues)
{
   int res = accumulate(revenues.begin(),revenues.end(),0,[](int sum,auto elem){
                return sum+elem;});
                
    return res;
}

int main() {
    // Vector of products sold
    vector<Product> products = {
        {100.0, 0.10, 50},  // Product 1: Price = 100, 10% discount, 50 units sold
        {200.0, 0.15, 30},  // Product 2: Price = 200, 15% discount, 30 units sold
        {300.0, 0.20, 20},  // Product 3: Price = 300, 20% discount, 20 units sold
        {150.0, 0.05, 40}   // Product 4: Price = 150, 5% discount, 40 units sold
    };

    // Vector to store the revenue for each product
    vector<double> revenues(products.size());
    calculate_revenue_each_prod(revenues,products);

    cout<<"Total Revenue Generated for wach Product"<<endl;
    cout<<"----------------------------------------"<<endl;
    for(auto itr : revenues)
    {
        cout<<itr<<" ";
    }
    cout<<endl<<endl;

    int res = calculate_total_revenue(revenues);
    cout<<"Total Revenue for the entire store : "<<res<<endl;


}