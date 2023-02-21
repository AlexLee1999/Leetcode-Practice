Select 
    employee_id, 
    if(employee_id % 2 != 0 and name NOT LIKE 'M%', salary, 0) as bonus
From 
    Employees
Order by
    employee_id;