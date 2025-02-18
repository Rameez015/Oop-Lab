// Real world use case - Product inventory
#include <iostream>
#include <string>
using namespace std;

struct inventory
{
    int productid;
    string name;
    int quantity;
    float price;
};

int main()
{
    inventory product;
    int n;
    cout << "enter the number of products: ";
    cin >> n;

    inventory *arr = new inventory[n];
    for (int i = 0; i < n; i++)
    {
        cout << "enter the details for product [" << i + 1 << "]: " << endl;
        cout << "name: ";
        cin >> arr[i].name;
        cout << "product id: ";
        cin >> arr[i].productid;
        cout << "quantity: ";
        cin >> arr[i].quantity;
        cout << "price: ";
        cin >> arr[i].price;
    }
    float totalvalue;
    for (int i = 0; i < n; i++)
    {
        float value = arr[i].quantity * arr[i].price;
        totalvalue += value;
    }
    cout << endl;
    cout << "the total value of the inventory is: " << totalvalue;
}