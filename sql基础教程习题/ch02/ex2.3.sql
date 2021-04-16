select product_name, sale_price, purchase_price 
from Product
where sale_price - purchase_price > 500;
-- 要输出书上的结果，改成>=即可，但会与描述不符