select emp_no from employees where emp_no not in (select emp_no from dept_manager)

-- 先from join联结，再where筛选，最后select输出
select employees.emp_no from 
employees left outer join dept_manager 
on employees.emp_no = dept_manager.emp_no 
where dept_no is null