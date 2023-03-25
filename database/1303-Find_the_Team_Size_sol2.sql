Select employee_id, count_size.team_size as 'team_size'
From Employee
Join (
    Select team_id, count(team_id) as 'team_size'
    From Employee e
    Group by team_id
) count_size
on count_size.team_id = Employee.team_id;