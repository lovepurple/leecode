#include <iostream>
#include <unordered_map>

using namespace std;

class Employee
{
public:
	int id;
	int importance;
	vector<int> subordinates;
};

void getSubordinatesRecusive(unordered_map<int, Employee*> empolyeeMap, int id, vector<int>& subordinate)
{
	auto pEmpoyeeInfo = empolyeeMap.find(id);
	if (pEmpoyeeInfo != empolyeeMap.end())
	{
		vector<int> sub = (pEmpoyeeInfo->second)->subordinates;
		for (int i = 0; i < sub.size(); ++i)
			getSubordinatesRecusive(empolyeeMap, sub[i], subordinate);
	}
	subordinate.push_back(id);
}

int getImportance(vector<Employee*> employees, int id)
{
	unordered_map<int, Employee*> employeeMap;

	for (int i = 0; i < employees.size(); ++i)
	{
		Employee* pEmployee = employees[i];
		employeeMap.insert({ pEmployee->id,pEmployee });
	}

	vector<int> subordinate;
	getSubordinatesRecusive(employeeMap, id, subordinate);

	int importance = 0;
	for (int i = 0; i < subordinate.size(); ++i)
	{
		Employee* employeeInfo = employeeMap.find(subordinate[i])->second;
		importance += employeeInfo->importance;
	}

	return importance;

}

int main() {

	Employee* pEmployee0 = new Employee();
	pEmployee0->id = 1;
	pEmployee0->importance = 5;
	pEmployee0->subordinates = { 2,3 };

	Employee* pEmployee1 = new Employee();
	pEmployee1->id = 2;
	pEmployee1->importance = 3;
	pEmployee1->subordinates = {};


	cout << getImportance({ pEmployee0,pEmployee1 }, 2);
	return 0;
}

