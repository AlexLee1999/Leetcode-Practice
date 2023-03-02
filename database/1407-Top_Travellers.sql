Select Users.name, sum(IFNULL(Rides.distance, 0)) as 'travelled_distance'
From Users
Left Join Rides
on Users.id = Rides.user_id
Group by Users.name, Users.id
Order by travelled_distance DESC, Users.name;