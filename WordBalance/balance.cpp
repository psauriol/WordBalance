//Paul Sauriol
//07/12/2015
//Word Balance

#include <iostream>;
#include <string>;

using namespace std;

void main()
{
	string input;
	string output = "";

	int leftWeight;
	int rightWeight;

	bool doesBalance = false;

	cout << "Input word: ";
	cin >> input;

	for (int i = 0; i < input.length(); i++)// this loop tests each possible balance point
	{
		leftWeight = 0;
		rightWeight = 0;

		for (int e = 0; e < input.length(); e++)// this loop finds the weight on each side of the tested point
		{
			if (e < i)
			{
				//torque += distance * letterWeight
				leftWeight += (i - e) * (input[e] - 64);
			}
			else if (e > i)
			{
				//torque += distance * letterWeight
				rightWeight += (e - i) * (input[e] - 64);
			}
			else // e==i
			{
				// do nothing //this is the tested balance point
			}

		}//end for e

		if (leftWeight == rightWeight)
		{
			//current i is balance point
			doesBalance = true;

			output += input.substr(0, i);
			output += " ";
			output += input.substr(i, 1);
			output += " ";
			output += input.substr(i + 1, input.length() - i);
			output += ", ";
			output += to_string(leftWeight);

		}

	}// end for i

	if (doesBalance)
	{
		cout << output << endl;
	}
	else
	{
		cout << "Does not balance." << endl;
	}
	
}