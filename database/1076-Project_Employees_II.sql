Select
    Project.project_id
From
    Project
Left Join 
    Employee
on
    Project.employee_id = Employee.employee_id
Group by Project.project_id
Having count(Employee.employee_id) = (
    Select count(project_id)
        From
        Project
    Left Join 
        Employee
    on
        Project.employee_id = Employee.employee_id
    Group by Project.project_id
    Order by count(project_id) DESC
    Limit 1
);