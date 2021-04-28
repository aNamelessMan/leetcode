select *, sum(sale_price) 
over(order by regist_date) as sum_sale_price
from Product;