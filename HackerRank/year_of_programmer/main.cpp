#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

bool isleap(int year);
void int_to_char(char* month, int i);
string day_programmer(int year);
bool leap_not(int year);

int main(int argc, char* args[])
{
	int y;
	cout << "Enter a year:  ";
	cin >> y;

	if(y < 1700 || y > 2700)
		return -1;
	cout << "\n\n256 days after begining of year " << y << endl;
	cout << day_programmer(y) << endl;

	return 0;
}

string day_programmer(int year)
{
	int leap[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if(year >= 1919)
	{  ///Gregorian calendar

		if(isleap(year) == true)
		{
			int real_sum=0, sum_after=0, last_i;
			string m1 = "0";
				for(int i=0; sum_after < 256; ++i)
				{
					real_sum = sum_after;
					last_i = i;
					sum_after += leap[i];
				}
			string m2 = to_string(last_i+1);
			string mm = m1 + m2;
			int difference = 256 - real_sum;
			string dd = to_string(difference);
			string yy = to_string(year);
			string finale = dd +  "." + mm + "." + yy + ".";
			return finale;
		}
		else
		{
			int real_sum=0, sum_after=0, last_i;
			string m1 = "0";
				for(int i=0; sum_after < 256; ++i)
				{
					real_sum = sum_after;
					last_i = i;
					if(i == 1)
						sum_after += 28;
					else
						sum_after += leap[i];
				}
			string m2 = to_string(last_i+1);
			string mm = m1 + m2;
			int difference = 256 - real_sum;
			string dd = to_string(difference);
			string yy = to_string(year);
			string finale = dd +  "." + mm + "." + yy + ".";
			return finale;
		}
	}
	else
	{
		int leap[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		if(leap_not(year) == true)
		{
			int real_sum=0, sum_after=0, last_i;
			string m1 = "0";
				for(int i=0; sum_after < 256; ++i)
				{
					real_sum = sum_after;
					last_i = i;
					sum_after += leap[i];
				}
			string m2 = to_string(last_i+1);
			string mm = m1 + m2;
			int difference = 256 - real_sum;
			string dd = to_string(difference);
			string yy = to_string(year);
			string finale = dd +  "." + mm + "." + yy + ".";
			return finale;
		}
		else
		{
			int real_sum=0, sum_after=0, last_i;
			string m1 = "0";
				for(int i=0; sum_after < 256; ++i)
				{
					real_sum = sum_after;
					last_i = i;
					if(i == 1)
						sum_after += 28;
					else
						sum_after += leap[i];
				}
			string m2 = to_string(last_i+1);
			string mm = m1 + m2;
			int difference = 256 - real_sum;
			string dd = to_string(difference);
			string yy = to_string(year);
			string finale = dd +  "." + mm + "." + yy + ".";
			return finale;
		}
	}

}


bool isleap(int year)
{
	if(year % 4 == 0)
	{	
		///step2
		if(year % 100 == 0)
		{
			//step3
			if(year % 400 == 0)
				return true; //step4
			return false;

		}
		//step4
		return true;
	}
	///step5
	return false;
}


bool leap_not(int year)
{
	if(year % 4 == 0)
		return true;
	return false;
}