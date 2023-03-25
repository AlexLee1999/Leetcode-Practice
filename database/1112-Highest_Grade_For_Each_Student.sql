Select student_id, min(course_id) as course_id, grade
From Enrollments
Where (student_id, grade) in (
    Select student_id, max(grade) as 'grade'
    From Enrollments
    Group by Enrollments.student_id
) 
Group by student_id, grade
Order by student_id;
