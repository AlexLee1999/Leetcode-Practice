Select Customers.customer_id, Customers.customer_name
From Customers
Left Join Orders
on Customers.customer_id = Orders.customer_id
Group by Customers.customer_id
Having sum(Orders.product_name = 'A') > 0 and sum(Orders.product_name = 'B') > 0 and sum(Orders.product_name = 'C') = 0;