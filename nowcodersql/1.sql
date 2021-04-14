select * from employees order by hire_date desc limit 0,1
/*
请你查找employees里最晚入职员工的所有信息
select  *                   需要所有信息    因此为*表示所有列
from employees              表名
order by hire_date          最晚入职，因此需要按入职时间排序
desc                        降序排序，因此最晚入职的在最上面
limit 0,1                   从第0行开始取1条记录
*/
/* 如果考虑到最晚入职的员工不止一个，可以像下面这样写 */
SELECT * FROM employees WHERE hire_date = (SELECT MAX(hire_date) FROM employees)