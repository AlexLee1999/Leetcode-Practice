Select e.name 
From Employee 
Left Join Employee e
on Employee.managerId = e.id
Group by Employee.managerId
Having Count(e.id) >= 5;