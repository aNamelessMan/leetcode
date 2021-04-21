create view ViewPractice5_1(product_name, sale_price, regist_date) 
as 
select product_name, sale_price, regist_date from Product where (sale_price >= 1000) and (regist_date = '2009-9-20');
select * from ViewPractice5_1;