Select Sales.sale_date,
Sales.sold_num - s.sold_num as 'diff' 
From Sales 
Left Join Sales s
on Sales.sale_date = s.sale_date and Sales.fruit = 'apples' and s.fruit = 'oranges'
Group by Sales.sale_date;