select product_id, product_name, product_type, sale_price, 
(select avg(sale_price) from Product as p2 where p1.product_type = p2.product_type) as avg_sale_price -- 关联子查询
from Product as p1;