SELECT
    Employee.name as 'Employee'
From
    Employee
Join
    Employee e
On
    Employee.managerId = e.id and Employee.salary > e.salary;