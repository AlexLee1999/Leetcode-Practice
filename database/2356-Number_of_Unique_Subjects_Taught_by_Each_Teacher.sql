Select
    teacher_id,
    count(teacher_id) as 'cnt'
From (
    Select Distinct 
        teacher_id, subject_id
    From 
        Teacher
) t
Group by teacher_id;