Select Employee.name, Bonus.bonus
From Employee
Left Join Bonus
on Employee.empId = Bonus.empId
Where Bonus.bonus is Null or Bonus.bonus < 1000;