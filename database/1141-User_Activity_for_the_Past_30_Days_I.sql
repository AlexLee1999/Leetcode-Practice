Select activity_date as 'day',
Count(Distinct user_id) as 'active_users'
From Activity
Where Datediff('2019-07-27', activity_date) < 30 and activity_date <= '2019-07-27'
Group by activity_date;