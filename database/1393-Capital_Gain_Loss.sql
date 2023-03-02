Select stock_name, Sum(If(operation = 'Buy', -1, 1) * price) as 'capital_gain_loss'
From Stocks
Group by stock_name;