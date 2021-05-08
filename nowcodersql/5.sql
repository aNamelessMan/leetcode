-- 将上一题的inner改成left即可
select last_name, first_name, dept_no 
from employees left outer join dept_emp /* 使用外联结，此处使用的是左联结，也就是包含join左边标的所有行 */
on employees.emp_no = dept_emp.emp_no