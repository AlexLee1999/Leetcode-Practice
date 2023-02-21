SELECT
    EmployeeUNI.unique_id as 'unique_id',
    Employees.name as 'name'
From 
    Employees 
Left Join EmployeeUNI
on Employees.id = EmployeeUNI.id;