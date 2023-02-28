Select user_id, max(time_stamp) as 'last_stamp'
From Logins
Where Year(time_stamp) = '2020'
Group by user_id;