select product_name, purchase_price from Product where purchase_price not in (500, 2800, 5000);
/*
+--------------+----------------+
| product_name | purchase_price |
+--------------+----------------+
| 打孔器       |            320 |
| 擦菜板       |            790 |
+--------------+----------------+
*/
select product_name, purchase_price from Product where purchase_price not in (500, 2800, 5000, null);
/*
Empty set
*/