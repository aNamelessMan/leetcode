start transaction;
update ProductMargin set sale_price = 3000 where product_name = '运动T恤';
update ProductMargin set margin = sale_price - purchase_price where product_name = '运动T恤';
-- 可以用于调试，查看结果是否正确，并且不会改变数据库
-- select * from ProductMargin;
-- rollback;
commit;
