Select
    Project.project_id,
    ROUND(AVG(Employee.experience_years), 2) as 'average_years'
From
    Project
Left Join Employee
on Project.employee_id = Employee.employee_id
Group By Project.project_id;