#include <string>
#include <iostream>
#include <Queue>

using namespace std;

class Solution
{
public:
	string Calculate(string input)
	{
		string m_Res;
		queue<char> m_Operator;
		queue<int> m_Operand;

		int prevNum = NULL;

		for (int i = 0; i < input.size(); i++)
		{
			char current;
			current = input[i];

			if (current == '*' || current == '/')
			{
				int	nextNum = input[++i];

				if (current == '*')
				{
					prevNum *= nextNum - '0';
				}
				else
				{
					if (nextNum - '0' == 0)	
						return "Impossible";

					prevNum /= nextNum - '0';
				}
			}
			else if (current == '+' || current == '-')
			{
				m_Operand.push(prevNum);
				m_Operator.push(current);
			}
			else
			{
				prevNum = current - '0';
			}
		}

		int tempRes = m_Operand.front();
		m_Operand.pop();

		while (!m_Operand.empty())
		{
			char tempOper = NULL;
			int tempNum = NULL;

			tempOper = m_Operator.front();
			m_Operator.pop(); 
			tempNum = m_Operand.front();
			m_Operand.pop();
			
			if (tempOper == '+')
				tempRes += tempNum;
			else
				tempRes -= tempNum;
		}

		m_Res = to_string(tempRes);

		return m_Res;
	}
};

int main()
{
	//string input = "3-5+7*6+4/0*5";
	string input = "3-5+7*6+4/2*5";
	string output;
	
	Solution s;
	output = s.Calculate(input);

	cout << "Output : " << output << endl;

	return 0;
}