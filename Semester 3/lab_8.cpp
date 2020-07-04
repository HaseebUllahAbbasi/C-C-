#include<iostream>
using namespace std;
class I_Sort
{
    public:
    int best,worst;
    int *array;
    int i;
    I_Sort()
    {
        array = new int[120];
        i=0;
    }
    void insert(int n)
    {
        if(i==0)
        {
            best = n;
            worst = n;
        }
        else
        {
            if(best>n)
            {
                best = n;
            }
            if(worst<n)
            {
                worst = n;
            }
        }
        array[i] = n;
        //cout<<array[i]<<endl;
        i++;
    }
    void display()
    {   for(int j=0; j<i; j++)
        cout<<array[i]<<" ";
        cout<<endl;
    }
    double average()
    {
        int sum=0;
        for(int j=0; j<120; j++)
        {
            sum+=array[j];
        }
        cout<<sum<<endl;
        return sum;
    }
    void all_cases()
    {
        cout<<"worst case is :"<<worst<<endl;
        cout<<"average case is :"<<average()<<endl;
        cout<<"best case is :"<<best<<endl;
    }

};
class B_Sort
{
    public:
    int best,worst;
    int *array;
    int i;
    B_Sort()
    {
        array = new int[120];
        i=0;
    }
    void insert(int n)
    {
        if(i==0)
        {
            best = n;
            worst = n;
        }
        else
        {
            if(best>n)
            {
                best = n;
            }
            if(worst<n)
            {
                worst = n;
            }
        }
        array[i] = n;
        //cout<<array[i]<<endl;
        i++;
    }
    void display()
    {   for(int j=0; j<i; j++)
        cout<<array[j]<<" ";
        cout<<endl;
    }
    double average()
    {
        int sum=0;
        for(int j=0; j<120; j++)
        {
            sum+=array[j];
        }

        return sum/120.0;
    }
    void all_cases()
    {
        cout<<"worst case is :"<<worst<<endl;
        cout<<"average case is :"<<average()<<endl;
        cout<<"best case is :"<<best<<endl;
    }

};
int Bubble_Sort(int a[])
{
        bool check = true;
        int swap = 0;
        int comp = 0;
		for (int i = 5-1; i> 1; i--)
        //for(int i=0; i<5; i++)
		{
            check = true;
			for (int j = 0; j < i; j++)
			//for(int j=0; j<4-i; j++)
			{
                comp++;
				if(a[j]>a[j+1])
				{
                    //swap++;
					int temp = a[j];
					a[j] = a[j+1];
					a[j+1] = temp;
					check = false;
				}
				/* code */
			}
			if(check)
			break;
			/* code */
		}
	//	for(int i=0; i<5; i++)
		//{
          //  cout<<a[i]<<" ";
		//}
		//cout<<endl;
		//cout<<"no of comparisions :"<<comp<<endl;
		//cout<<"no of swaping :"<<swap<<endl;
        return comp;
}
int insertion_sort(int a[])
{

    int inner,outer,comp = 0;
    for (int outer = 1; outer < 5; outer++)
    {
        if((a[outer]<a[outer-1]))
        {
            int temp = a[outer];
            inner = outer;
            do
            {
                comp++;
                a[inner] = a[inner-1];
                inner--;
            }
            while(inner>0&&a[inner-1]>=temp);
            a[inner] = temp;
        }

    }
    cout<<comp<<endl;
    return comp;
}
int main()
{
    int array[120][5] = {
{5,4,3,2,1},
{5,4,3,1,2},
{5,4,2,3,1},
{5,4,2,1,3},
{5,4,1,3,2},
{5,4,1,2,3},
{5,3,4,2,1},
{5,3,4,1,2},
{5,3,2,4,1},
{5,3,2,1,4},
{5,3,1,4,2},
{5,3,1,2,4},
{5,2,4,3,1},
{5,2,4,1,3},
{5,2,3,4,1},
{5,2,3,1,4},
{5,2,1,4,3},
{5,2,1,3,4},
{5,1,4,3,2},
{5,1,4,2,3},
{5,1,3,4,2},
{5,1,3,2,4},
{5,1,2,4,3},
{5,1,2,3,4},
{4,5,3,2,1},
{4,5,3,1,2},
{4,5,2,3,1},
{4,5,2,1,3},
{4,5,1,3,2},
{4,5,1,2,3},
{4,3,5,2,1},
{4,3,5,1,2},
{4,3,2,5,1},
{4,3,2,1,5},
{4,3,1,5,2},
{4,3,1,2,5},
{4,2,5,3,1},
{4,2,5,1,3},
{4,2,3,5,1},
{4,2,3,1,5},
{4,2,1,5,3},
{4,2,1,3,5},
{4,1,5,3,2},
{4,1,5,2,3},
{4,1,3,5,2},
{4,1,3,2,5},
{4,1,2,5,3},
{4,1,2,3,5},
{3,5,4,2,1},
{3,5,4,1,2},
{3,5,2,4,1},
{3,5,2,1,4},
{3,5,1,4,2},
{3,5,1,2,4},
{3,4,5,2,1},
{3,4,5,1,2},
{3,4,2,5,1},
{3,4,2,1,5},
{3,4,1,5,2},
{3,4,1,2,5},
{3,2,5,4,1},
{3,2,5,1,4},
{3,2,4,5,1},
{3,2,4,1,5},
{3,2,1,5,4},
{3,2,1,4,5},
{3,1,5,4,2},
{3,1,5,2,4},
{3,1,4,5,2},
{3,1,4,2,5},
{3,1,2,5,4},
{3,1,2,4,5},
{2,5,4,3,1},
{2,5,4,1,3},
{2,5,3,4,1},
{2,5,3,1,4},
{2,5,1,4,3},
{2,5,1,3,4},
{2,4,5,3,1},
{2,4,5,1,3},
{2,4,3,5,1},
{2,4,3,1,5},
{2,4,1,5,3},
{2,4,1,3,5},
{2,3,5,4,1},
{2,3,5,1,4},
{2,3,4,5,1},
{2,3,4,1,5},
{2,3,1,5,4},
{2,3,1,4,5},
{2,1,5,4,3},
{2,1,5,3,4},
{2,1,4,5,3},
{2,1,4,3,5},
{2,1,3,5,4},
{2,1,3,4,5},
{1,5,4,3,2},
{1,5,4,2,3},
{1,5,3,4,2},
{1,5,3,2,4},
{1,5,2,4,3},
{1,5,2,3,4},
{1,4,5,3,2},
{1,4,5,2,3},
{1,4,3,5,2},
{1,4,3,2,5},
{1,4,2,5,3},
{1,4,2,3,5},
{1,3,5,4,2},
{1,3,5,2,4},
{1,3,4,5,2},
{1,3,4,2,5},
{1,3,2,5,4},
{1,3,2,4,5},
{1,2,5,4,3},
{1,2,5,3,4},
{1,2,4,5,3},
    {1,2,4,3,5},
    {1,2,3,5,4},
    {1,2,3,4,5}
    };
    /*
    I_Sort obj1;
    B_Sort obj;
    for(int i=0; i<sizeof(array)/sizeof(array[0]); i++)
    {
        for(int j=0; j<sizeof(array[0])/sizeof(array[0][0]); j++)
        {
            //cout<<j;
            //cout<<endl;
            //cout<<array[i][j]<<" ";

        }
        obj.insert(Bubble_Sort(array[i]));
       // obj1.insert(insertion_sort(array[i]));
    }
   // obj1.all_cases();
    obj.all_cases();
    cout<<obj.average();
    obj.display();
	*/
}

