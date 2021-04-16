select product_name, product_type, (0.9 * sale_price - purchase_price) as profit
from Product
where (0.9 * sale_price - purchase_price > 100) and (product_type = "办公用品" or product_type = "厨房用具");