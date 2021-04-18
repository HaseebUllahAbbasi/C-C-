#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    
    cout << "\t \\\"Food Stuff Grocery Shop\"/"<<endl;
    cout << "Customer Name: Salim" << endl;
    cout << "ITEM \t\tPRICE \t\tSales Tax+ VAT \t\t\tSub-Total" << endl;
    cout << "-------- \t--------- \t----------------------- \t----------------" << endl;
    cout << "Fresh Milk \t1.0 \t\tOMR 0.05 \t\t\t 1.05 OMR" << endl;
    cout << "Apple \t\t2.0 \t\tOMR 0.10 \t\t\t2.10 OMR " << endl;
    cout << "Bread \t\t0.8 \t\tOMR 0.05 \t\t\t1.30 OMR" << endl;
    cout << "Coffee \t\t2.5 \t\tOMR 0.15 \t\t\t2.65 OMR" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t\tGross Bill ------------ 7.1 OMR" << endl;
    cout << "\t\t\t\t\tDiscount ------------- 5%" << endl;
    cout << "\t\t\t\t\tNet Bill --------------- 6.745 OMR" << endl;
    
    cout << setw(38) <<" \\\"Food Stuff Grocery Shop\"/"<< endl;
    cout << "Customer Name: Salim" << endl;
    cout << "ITEM "<<setw(15)<<"PRICE " << setw(20) << " Sales Tax+ VAT " << setw(15) << " Sub-Total" << endl;
    cout << "--------" << setw(15) << " --------- " << setw(20) << " -----------------------" << setw(15) << " ----------------" << endl;

    cout << "Fresh Milk " << setw(10) << " 1.0 OMR " << setw(15) << "  0.05" << setw(20) << " 1.05 OMR" << endl;

    cout <<setw(5)<< " Apple" << setw(15) << " 2.0 OMR " << setw(15) << "  0.10" << setw(20) << " 2.10 OMR" << endl;
    cout << setw(5)<< " Bread" << setw(15) << " 0.8 OMR " << setw(15) << "  0.05" << setw(20) << " 1.30 OMR" << endl;
    cout << setw(6) << "Coffee" << setw(15) << " 2.5 OMR " << setw(15) << "  0.15" << setw(20) << " 2.65 OMR" << endl;    

    cout <<setw(70)<< "Gross Bill ------------ 7.1 OMR" << endl;
    cout << setw(64) << "Discount ------------- 5%" << endl;
    cout << setw(73) <<"Net Bill --------------- 6.745 OMR" << endl;
}