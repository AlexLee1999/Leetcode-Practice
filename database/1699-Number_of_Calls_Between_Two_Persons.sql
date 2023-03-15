Select Least(from_id, to_id) as 'person1',
greatest(from_id, to_id) as 'person2',
count(*) as 'call_count',
Sum(duration) as 'total_duration'
From Calls
Group by person1, person2;