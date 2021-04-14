select employees.last_name, employees.first_name, dept_emp.dept_no 
from employees, dept_emp 
where employees.emp_no = dept_emp.emp_no
/* 目前为止所使用的的联结成为内部联结inner join，或者说等值联结，基于两个表之间的相等性测试 
   也可以这样写 */
select last_name, first_name, dept_no 
from employees inner join dept_emp 
on employees.emp_no = dept_emp.emp_no