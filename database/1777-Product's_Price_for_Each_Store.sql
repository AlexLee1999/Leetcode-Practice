Select product_id,
sum(case when store="store1" then price end) as "store1",
sum(case when store="store2" then price end) as "store2",
sum(case when store="store3" then price end) as "store3"
From Products
group by product_id;