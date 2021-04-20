select product_type, sum(sale_price), sum(purchase_price) from Product group by product_type having sum(sale_price) > 1.5 * sum(purchase_price);
-- having子句里聚合函数是对分组后每组做统计
-- 先分组group by， 再用having筛选
-- 总体顺序为： from -> where -> group by -> having -> select