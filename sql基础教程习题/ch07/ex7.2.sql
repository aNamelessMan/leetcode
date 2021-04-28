select coalesce(sp.shop_id, '不确定') as shop_id, coalesce(sp.shop_name, '不确定') as shop_name, p.product_id, p.product_name, p.sale_price -- 把null替换为不确定
from ShopProduct as sp right outer join Product as p 
on sp.product_id = p.product_id 
order by shop_id;