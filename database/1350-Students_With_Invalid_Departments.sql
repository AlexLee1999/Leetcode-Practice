Select 
    Students.id as 'id',
    Students.name as name
From Students
Left Join Departments
on Students.department_id = Departments.id
Where Departments.id is Null;