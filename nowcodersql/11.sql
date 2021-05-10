select dept_emp.emp_no, dept_manager.emp_no as manager 
from dept_emp inner join dept_manager on dept_emp.dept_no = dept_manager.dept_no
where dept_emp.emp_no not in (select emp_no from dept_manager)