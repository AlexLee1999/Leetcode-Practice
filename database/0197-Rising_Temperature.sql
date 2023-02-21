Select 
    Weather.id as Id
From 
    Weather
INNER JOIN 
    Weather w 
on 
    DATEDIFF(Weather.recordDate, w.recordDate) = 1 AND Weather.Temperature > w.Temperature;