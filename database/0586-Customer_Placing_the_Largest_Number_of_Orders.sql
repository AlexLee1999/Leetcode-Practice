Select customer_number
From Orders
Group by customer_number
Having count(customer_number) = (
    Select count(customer_number)
    From Orders
    Group by customer_number
    Order by count(customer_number) DESC
    Limit 1
);