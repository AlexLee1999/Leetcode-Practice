Select Students.student_id, Students.student_name, Subjects.subject_name, COUNT(Examinations.student_id) as 'attended_exams'
From Students
Join Subjects
Left Join Examinations
on Students.student_id = Examinations.student_id and Subjects.subject_name = Examinations.subject_name
Group by Students.student_id, Subjects.subject_name
Order by Students.student_id, Subjects.subject_name;