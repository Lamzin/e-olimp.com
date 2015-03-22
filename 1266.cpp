#include <iostream>
#include <fstream>
using namespace std;
#define SIZE 100

int n,m, mas[SIZE];
int stack[SIZE], i_paste, Sum, answer, stack_len, II;

bool check_paste()
{
	for (int j = stack[stack_len-1]+1; j<m; j++)
		if (Sum + mas[j] <= n) 
		{
			i_paste = j;
			return true;
		}
	return false;
}
void paste()
{
	stack_len++;
	stack[stack_len] = i_paste;
	Sum += mas[i_paste];
}
void del()
{
	stack[stack_len] = 0;
	Sum -= mas[stack[stack_len-1]];
	stack_len--;
}
void cut()
{
	del();
	paste();
}
int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");

	while (in)
	{
		in >> n >> m;
		for (int i = 0; i<m; i++) in >> mas[i];
		Sum = 0;
		answer = 0;

		stack_len = 1;
		stack[stack_len-1] = 0;
		Sum += mas[stack[stack_len-1]];
		
		while (stack_len != 0)
		{
			if (Sum > n)
			{
				if (check_paste()) paste();
				else 
				{

				}
			}
			if (Sum > answer) answer = Sum;
			if (check_paste())
			{

			}
			else
			{
				
			}
		}

		if (in) out << "sum:" << answer << endl;
	}
	in.close();
	out.close();
}