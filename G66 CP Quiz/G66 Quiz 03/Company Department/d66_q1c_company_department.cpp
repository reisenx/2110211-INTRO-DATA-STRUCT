#include<iostream>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
int N,M;
map<string, string> employeeInfo;
map<string, set<string>> departmentInfo;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    // Input
    cin >> N >> M;

    // Input employee information
    while(N--)
    {
        string department, employee;
        cin >> employee >> department;
        employeeInfo[employee] = department;
        departmentInfo[department].insert(employee);
    }

    // Operations
    while(M--)
    {
        int command;
        cin >> command;
        // Operation 1: Move department
        if(command == 1)
        {
            // Input information
            string employee, newDepartment;
            cin >> employee >> newDepartment;
            string oldDepartment = employeeInfo[employee];

            // Move department
            employeeInfo[employee] = newDepartment;
            departmentInfo[oldDepartment].erase(employee);
            departmentInfo[newDepartment].insert(employee);
        }

        // Operation 2: Merge department
        if(command == 2)
        {
            // Input information
            string oldDepartment, newDepartment;
            cin >> oldDepartment >> newDepartment;

            // Merge department
            for(auto &employee : departmentInfo[oldDepartment])
            {
                employeeInfo[employee] = newDepartment;
                departmentInfo[newDepartment].insert(employee);
            }
            departmentInfo.erase(oldDepartment);
        }
    }

    // Output
    for(auto &[department, employeeSet] : departmentInfo)
    {
        cout << department << ": ";
        for(auto &employee : employeeSet)
        {
            cout << employee << " ";
        }
        cout << "\n";
    }
    return 0;
}