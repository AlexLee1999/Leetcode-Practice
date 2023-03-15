Select employee_id, count(team_id) over(partition by team_id) as 'team_size'
From Employee;