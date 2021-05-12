select * from employees where last_name <> 'Mary' and 
emp_no <> (floor(emp_no / 2) * 2) --此处必须要有floor，否则结果为空
order by hire_date desc;