Select Prices.product_id, ROUND(SUM(UnitsSold.units * Prices.price) / SUM(UnitsSold.units), 2) as 'average_price'
From Prices
Inner Join UnitsSold
on Prices.start_date <= UnitsSold.purchase_date and UnitsSold.purchase_date <= Prices.end_date and Prices.product_id = UnitsSold.product_id
Group by Prices.product_id;