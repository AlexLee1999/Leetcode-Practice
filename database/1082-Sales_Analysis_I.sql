Select seller_id
From Sales
Group by seller_id
Having Sum(price) = (
    Select Sum(price)
    From Sales
    Group by seller_id
    Order by Sum(price) DESC
    Limit 1
);
