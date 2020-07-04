#include<iostream>
#include <iomanip>
#include <fstream>
#include <stack>
using namespace std;
void evaluateExpression(ifstream& inpF, ofstream& outF,stack<double>& stack,char& ch, bool& isExpOk);
void evaluateOpr(ofstream& out, stack<double>& stack,char& ch, bool& isExpOk);
void discardExp(ifstream& in, ofstream& out, char& ch);
void evaluateExpression(ifstream& inpF, ofstream& outF,stack<double>& stack,char& ch, bool& isExpOk)
{
    double num;
    outF << ch;
    while (ch != '=')
    {
        switch (ch)
        {
            case '#':
            inpF >> num;
            outF << num << " ";
            if (1)//!stack.isFullStack())
            stack.push(num);
            else
            {
                cout << "Stack overflow. "<< "Program terminates!" << endl;
                terminate(); //terminate the program
            }
            break;
            default:
            evaluateOpr(outF, stack, ch, isExpOk);
        }//end switch
        if (isExpOk) //if no error
        {
            inpF >> ch;
            outF << ch;
            if (ch != '#')
            outF << " ";
        }
        else
        discardExp(inpF, outF, ch);
    }
         //end while (!= '=')
}
void evaluateOpr(ofstream& out, stack<double>& stack,
char& ch, bool& isExpOk)
{
    double op1, op2;
    if (stack.empty())
    {
        out << " (Not enough operands)";
        isExpOk = false;
    }
    else
    {
        op2 = stack.top();
        stack.pop();
        if (stack.empty())
        {
            out << " (Not enough operands)";
            isExpOk = false;
        }
        else
        {
            op1 = stack.top();
            stack.pop();
            switch (ch)
            {
                case '+':
                stack.push(op1 + op2);
                break;
                case '-':
                stack.push(op1 - op2);
                break;
                case '*':
                stack.push(op1 * op2);
                break;
                case '/':
                if (op2 != 0)
                stack.push(op1 / op2);
                else
                {
                    out << " (Division by 0)";
                    isExpOk = false;
                }
                break;
                default:
                    out << " (Illegal operator)";
                    isExpOk = false;
            }//end switch
        } //end else
    } //end else
}
void discardExp(ifstream& in, ofstream& out, char& ch)
{
    while (ch != '=')
    {
        in.get(ch);
        out << ch;
    }
}

void printResult(ofstream& outF, stack<double>& stack,bool isExpOk)
{
    double result;
    if (isExpOk) //if no error, print the result
    {
        if (!stack.empty())
        {
            result = stack.top();
            stack.pop();
            if(stack.empty())
            outF << result << endl;
            else
            outF << " (Error: Too many operands)" << endl;
        } //end if
        else
            outF << " (Error in the expression)" << endl;
        }
        else
            outF << " (Error in the expression)" << endl;
            outF << "_________________________________"
            << endl << endl;
}


int main()
{
    bool expressionOk;
    char ch;
    stack<int> stack_1(100);
    ifstream infile;
    ofstream outfile;
    infile.open("RpnData.txt");
    if(!infile)
    {
        cout << "Cannot open the input file. "<< "Program terminates!" << endl;
        return 1;
    }
    outfile.open("RpnOutput.txt");
    outfile << fixed << showpoint;
    outfile << setprecision(2);
    infile >> ch;
    while (infile)
    {
        stack_1.initializeStack();
        expressionOk = true;
        outfile << ch;
        evaluateExpression(infile, outfile, stack, ch,expressionOk);
        printResult(outfile, stack, expressionOk);
        infile >> ch; //begin processing the next expression

    }
 //end while
    infile.close();
    outfile.close();
    return 0;
} //end main
