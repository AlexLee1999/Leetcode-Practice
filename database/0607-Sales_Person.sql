Select SalesPerson.name as 'name'
From SalesPerson
where SalesPerson.sales_id not in 
(
Select Orders.sales_id from Orders
Left Join Company 
on Orders.com_id = Company.com_id
Where Company.name = 'RED');