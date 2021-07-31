select salaries.*, dept_no from salaries, dept_manager where salaries.emp_no = dept_manager.emp_no
/*选择要展示的列            从哪两个表                   联结(join)条件*/
select salaries.*, dept_manager.dept_no from salaries inner join dept_manager on salaries.emp_no = dept_manager.emp_no