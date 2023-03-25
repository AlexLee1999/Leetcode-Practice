Select Distinct page_id as 'recommended_page'
From Likes
Where page_id Not In (
    Select page_id 
    From Likes l
    Where user_id = 1
) And user_id In (
    Select user1_id 
    From Friendship
    Where user2_id = 1
    Union 
    Select user2_id
    From Friendship
    Where user1_id = 1
);