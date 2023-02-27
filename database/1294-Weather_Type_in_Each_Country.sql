Select country_name, 
CASE
    When SUM(Weather.weather_state) / COUNT(Weather.country_id) <= 15 then 'Cold'
    When SUM(Weather.weather_state) / COUNT(Weather.country_id) >= 25 then 'Hot'
    ELSE 'Warm'
End as 'weather_type'
From Countries 
Left Join Weather
on Countries.country_id = Weather.country_id
WHERE day BETWEEN '2019-11-01' and '2019-11-30'
Group by Countries.country_id;