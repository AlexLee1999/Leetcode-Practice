Select 
    min(p.x - Point.x) as 'shortest'
From 
    Point 
Inner Join 
    Point p
on p.x > Point.x;