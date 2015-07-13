//Paul Sauriol
//07/12/2015
//Word Balance
//v2

#include <iostream>;
#include <string>;

using namespace std;

void main()
{
	string word;

	int leftWeight;
	int rightWeight;

	bool doesBalance = false;

	cout << "Input word: ";
	cin >> word;

	for (int i = 0; i < word.length(); i++)// this loop tests each possible balance point
	{
		leftWeight = 0;
		rightWeight = 0;

		for (int e = 0; e < word.length(); e++)// this loop finds the weight on each side of the tested point
		{
			if (e < i)
			{
				//torque += distance * letterWeight
				leftWeight += (i - e) * (word[e] - 64);
			}
			else if (e > i)
			{
				//torque += distance * letterWeight
				rightWeight += (e - i) * (word[e] - 64);
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

			word.insert(i + 1, " ");
			word.insert(i, " ");
			word += ", " + to_string(leftWeight);

		}

	}// end for i

	if (doesBalance)
	{
		cout << word << endl;
	}
	else
	{
		cout << "Does not balance." << endl;
	}
	
}