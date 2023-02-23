DELETE
FROM Person 
WHERE (
    id IN (
        SELECT *
        FROM (
            SELECT p1.id
            FROM Person p1
            Inner join Person p2
            on p1.email = p2.email AND p1.id > p2.id
        ) p
    )
);