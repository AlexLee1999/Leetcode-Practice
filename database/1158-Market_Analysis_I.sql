Select Users.user_id as 'buyer_id', Users.join_date, count(Orders.order_id) as 'orders_in_2019'
From Users
Left Join Orders
on Orders.buyer_id = Users.user_id and Year(Orders.order_date) = '2019'
Group by Users.user_id, Users.join_date;