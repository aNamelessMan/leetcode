select sum(case when sale_price <= 1000 then 1 else 0 end) as low_price,
sum(case when sale_price between 1001 and 3000 then 1 else 0 end) as mid_price,
sum(case when sale_price >= 3001 then 1 else 0 end) as high_price 
from Product;
 /*
 可以理解成每个case语句对每一行进行处理输出一个值形成一个新的列，sum对这个新的列
 */