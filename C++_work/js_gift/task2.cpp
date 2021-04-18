#include <iostream>
#include <iomanip>
using namespace std;
int main()
{

    string customer;
    cout << "Enter Customer Name" << endl;
    cin >> customer;
    string name[5];
    float cost[5];
    float sales_tax[5];
    float vat[5];
    for (int d = 0; d < 1; d++)
    {
        cout << "Enter name of product" << endl;
        cin >> name[d];
        cout << "Enter cost of product" << endl;
        cin >> cost[d];
        cout << "Enter Sales Tax of product" << endl;
        cin >> sales_tax[d];
        cout << "Enter VAT of the Product" << endl;
        cin >> vat[d];
    }
    float sum = 0;
    cout << "\t \\\"Food Stuff Grocery Shop\"/" << endl;
    cout << "Customer Name: Salim" << endl;
    cout << "ITEM \t\tPRICE \t\tSales Tax+ VAT \t\t\tSub-Total" << endl;
    cout << "-------- \t--------- \t----------------------- \t----------------" << endl;
    for (int d = 0; d < 1; d++)
    {
        cout << name[d] << " \t\t" << cost[d] << " \t\t" << (sales_tax[d] + vat[d]) << " OMR" << " \t\t\t " << (cost[d] + sales_tax[d] + vat[d]) << " OMR" << endl;
        sum += (cost[d] + sales_tax[d] + vat[d]);
    }
    cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;

    cout << "\t\t\t\t\tGross Bill ------------ " << sum << " OMR" << endl;
    cout << "\t\t\t\t\tDiscount ------------- 5%" << endl;
    cout << "\t\t\t\t\tNet Bill --------------- " << (sum - (sum * 0.05)) << " OMR" << endl;


}