select Distinct
    Cinema.seat_id as 'seat_id'
From
    Cinema
Inner Join Cinema c
on abs(Cinema.seat_id - c.seat_id) = 1 and Cinema.free = true and c.free = true
Order by Cinema.seat_id;