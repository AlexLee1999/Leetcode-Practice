Select Employees.employee_id From Employees Left Join Salaries
on Employees.employee_id = Salaries.employee_id
Where Salaries.salary is Null

Union

Select Salaries.employee_id From Salaries Left Join Employees
on Employees.employee_id = Salaries.employee_id
Where Employees.name is Null
Order by employee_id;