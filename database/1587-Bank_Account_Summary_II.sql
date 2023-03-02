Select name, sum(amount) as 'balance'
From Users
Left Join Transactions
on Users.account = Transactions.account
Group by name
Having sum(amount) > 10000;