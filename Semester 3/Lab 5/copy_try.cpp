#include<iostream>

using namespace std;
int main()
{
}

void evaluateExpression(ifstream& inpF, ofstream& outF,
stackType<double>& stack,
char& ch, bool& isExpOk)
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
if (!stack.isFullStack())
stack.push(num);
else
{
cout << "Stack overflow. "
<< "Program terminates!" << endl;
exit(0); //terminate the program
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
} //end while (!= '=')
}
