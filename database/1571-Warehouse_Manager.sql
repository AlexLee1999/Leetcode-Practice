Select Warehouse.name as 'warehouse_name', sum(Products.Width * Products.Length * Products.Height * Warehouse.units) as 'volume'
From Warehouse
Left Join Products
on Warehouse.product_id = Products.product_id
Group by Warehouse.name;