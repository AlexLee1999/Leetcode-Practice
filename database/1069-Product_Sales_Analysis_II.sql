Select product_id, sum(quantity) as 'total_quantity'
From Sales
Group by product_id;