select product_id, product_name, product_type, sale_price, 
(select avg(sale_price) from Product) as sale_price_all -- 使用标量子查询，相当于常数
from Product;