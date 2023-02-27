Select s1.sub_id as 'post_id',
count(distinct s2.sub_id) as 'number_of_comments'
From Submissions s1
Left Join Submissions s2
on s1.sub_id = s2.parent_id
Where s1.parent_id is Null
Group by s1.sub_id;