#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string a_input, b_input, c_output;
vector <long long> a_vect, b_vect, c_vect;

/*string product(string a, string b)
{
	string c = "0";
	
	for (int i = 0; i < a.length()*b.length(); i++) c += "0";
	
	for (int i = 0; i < a.length(); i++)
	for (int j = 0; j < b.length(); j++)
	{
		int ost = (a[i] - 48) * (b[j] - 48), index = i + j;
		
		while (ost>0)
		{
			//if (index >= c.length()) c += "0";
			ost += c[index] - 48;
			c[index] = ost % 10 + 48;
			ost /= 10;
			index++;
		}
	}
	return c;
}*/

void product_vect()
{
	for (int i = 0; i < 100000; i++) c_vect.push_back(0);

	for (int i = 0; i < a_vect.size(); i++)
	for (int j = 0; j < b_vect.size(); j++)
	{
		int ost = a_vect[i] * b_vect[j], index = i + j;

		while (ost>0)
		{
			//if (index >= c.length()) c += "0";
			ost += c_vect[index];
			c_vect[index] = ost % 10000;
			ost /= 10000;
			index++;
		}
	}
}

int main()
{
	cin >> a_input;

	for (int i = 0; i < a_input.length() / 2; i++)
		swap(a_input[i], a_input[a_input.length() - i - 1]);

	while (a_input.length() % 4 != 0) a_input += "0";

	for (int i = 0; i < a_input.length() / 4; i++)
	{
		long long tmp = 0;
		tmp = (a_input[i * 4] - 48) 
			+ 
			(a_input[i * 4 + 1] - 48) * 10 
			+ 
			(a_input[i * 4 + 2] - 48) * 100 
			+ 
			(a_input[i * 4 + 3] - 48) * 1000;

		a_vect.push_back(tmp);
	}

	//delete &a_input;

	cin >> a_input;

	for (int i = 0; i < a_input.length() / 2; i++)
		swap(a_input[i], a_input[a_input.length() - i - 1]);

	while (a_input.length() % 4 != 0) a_input += "0";

	for (int i = 0; i < a_input.length() / 4; i++)
	{
		long long tmp = 0;
		tmp = (a_input[i * 4] - 48)
			+
			(a_input[i * 4 + 1] - 48) * 10
			+
			(a_input[i * 4 + 2] - 48) * 100
			+
			(a_input[i * 4 + 3] - 48) * 1000;

		b_vect.push_back(tmp);
	}

	//delete &b_input;

	/*c_output = product(a_input, b_input);

	for (int i = 0; i < c_output.length() / 2; i++)
		swap(c_output[i], c_output[c_output.length() - i - 1]);

	bool first_zero = true;
	for (int i = 0; i < c_output.length(); i++)
	{
		if (c_output[i] != '0' || (c_output[i] == '0' && !first_zero))
		{
			first_zero = false;
			cout << c_output[i];
		}	
	}

	if (first_zero) cout << "0";*/

	product_vect();

	bool first_zero = true, first = false;
	for (int i = c_vect.size()-1; i >=0; i--)
	{
		if (!first && c_vect[i] != 0)
		{
			cout << c_vect[i];
			first = true;
			first_zero = false;
		}
		else if (c_vect[i] != 0 || (c_vect[i] == 0 && !first_zero))
		{
			first_zero = false;
			if (c_vect[i] < 10) cout << "000";
			else if (c_vect[i] < 100) cout << "00";
			else if (c_vect[i] < 1000) cout << "0";
			
			cout << c_vect[i];
		}
	}

	if (first_zero) cout << "0"; 

	cout << endl;
}