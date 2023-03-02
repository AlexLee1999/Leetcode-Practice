Select Product.product_id, Product.product_name
From Product 
Left Join Sales 
on Product.product_id = Sales.product_id
Group by Product.product_id, Product.product_name
Having max(Sales.sale_date) <= '2019-03-31' and min(Sales.sale_date) >= '2019-01-01';