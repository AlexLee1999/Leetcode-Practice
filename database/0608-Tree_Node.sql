Select Tree.id, 
CASE 
    When Tree.p_id is Null Then 'Root'
    When t.id is Null Then 'Leaf'
    Else 'Inner'
END 
As 'type'
From Tree
Left Join Tree t
on Tree.id = t.p_id
Group by Tree.id;