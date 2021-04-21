/*
CREATE TABLE ProductMargin
(product_id CHAR(4) not null,
product_name VARCHAR(100) not null,
sale_price INTEGER,
purchase_price INTEGER,
margin INTEGER,
PRIMARY KEY(product_id));
*/
insert into ProductMargin
(product_id, product_name, sale_price, purchase_price, margin)
select product_id, product_name, sale_price, purchase_price, sale_price - purchase_price from Product;
