Select u.user_id, 
concat(upper(substr(name,1,1)),lower(substr(name,2))) 
as name 
From users u 
Order by u.user_id;