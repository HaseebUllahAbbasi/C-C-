#include <iostream>
#include <time.h>
#include<fstream>
using namespace std;
void manual_height()
{
	cout << "please enter the height" << endl;
	unsigned int height;
	cin >> height;
	FILE* fp;				// Pointer to file
	fopen_s(&fp, "test.dat", "w"); // w=open for writing
	srand((unsigned)time(0));
	for (int i = 0; i < 100; i++)
	{
		unsigned int number = rand() % height;

		if (number<10)
		{
			cout << number << endl;;
			fprintf(fp, "%d\n", number); // Write the int16_t
		}
		else
		{
			cout << "Storm damage danger! Putting wind sensor blades into neutral" << endl;
		}
	}

	fclose(fp);
}
int main()
{


}
