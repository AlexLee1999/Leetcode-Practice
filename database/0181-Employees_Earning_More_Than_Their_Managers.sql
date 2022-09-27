Select a.Name AS 'Employee'
From Employee AS a, Employee AS b
Where a.ManagerId = b.Id AND a.Salary > b.Salary;