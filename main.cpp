#include<iostream>
#include<string>
#include<sstream>
class HeartRate
{
	std::string m_first_name;
	std::string m_last_name;
	int m_year,m_month,m_day;
	
public:
	HeartRate() : m_first_name(""), m_last_name(""), m_year(0), m_month(0), m_day(0) {};
	
	HeartRate(std::string first_name,std::string last_name,int year,int month, int day) 
		:m_first_name(first_name)
		,m_last_name(last_name)
		,m_year(year)
		,m_month(month)
		,m_day(day)
	{

	}
	template <typename T>
	std::string toString(T val)
	{
		std::ostringstream oss;
		oss << val;
		return oss.str();
	}
	std::string get_first_name()
	{
		return m_first_name;
	}
	std::string get_last_name()
	{
		return m_last_name;
	}
	void set_first(std::string first_name)
	{
		m_first_name = first_name;
	}
	void set_last_name(const std::string& last_name)
	{
		m_last_name = last_name;
	}
	void set_year(int year)
	{
		m_year = year;
	}
	void set_month(int month)
	{
		m_month = month;
	}
	void set_day(int day)
	{
		m_day = day;
	}
	int cal_age()
	{
		int age = 2024 - m_year;
			return age;
	}

	int max_hear_rate ()
	{
		int max = 220 - cal_age();
		return max;
	}
	std::string target_hear_rate()
	{
		float first = (50.0f * max_hear_rate()) / 100.0f;
		float last = (85.0f * max_hear_rate()) / 100.0f;

		return (toString(first) + "-" + toString(last));
		
	}
	void get_result()
	{
		std::cout << get_first_name()<< " "<< get_last_name()<< " "<< cal_age()<< " "<< max_hear_rate()
			<< " "<< target_hear_rate()<< "\n";
	}

};
bool get_input(const std::string& prompt, std::string& input)
{
	std::cout << prompt;
	std::cin >> input;
	return input != "q";
}
bool get_input(const std::string& prompt, int& input )
{
	std::string temp;
	if (!get_input(prompt, temp))
	{
		return false;
	}
	input = std::stoi(temp);
	return true;
}
int main(int argc,char* argv[])
{
	std::string input;
	HeartRate person1;
	while (true)
	{
		

		std::string first_name;
		if (!get_input("Enter first name (or 'q' to quit): ", first_name))
			break;
		person1.set_first(first_name);

		std::string last_name;
		if (!get_input("Enter last name (or 'q' to quit): ", last_name))
			break;
		person1.set_last_name(last_name);

		int year;
		if (!get_input("Enter year of birth (or 'q' to quit): ", year))
			break;
		person1.set_year(year);

		int month;
		if (!get_input("Enter month of birth (or 'q' to quit): ", month))
			break;
		person1.set_month(month);

		int day;
		if (!get_input("Enter day of birth (or 'q' to quit): ", day))
			break;
		person1.set_day(day);

		person1.get_result();
		
		
	}
	return 0;
}