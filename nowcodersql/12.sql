SELECT d1.dept_no, d1.emp_no, s1.salary
FROM 

dept_emp as d1
INNER JOIN salaries as s1
ON d1.emp_no=s1.emp_no
AND d1.to_date='9999-01-01'
AND s1.to_date='9999-01-01'

WHERE s1.salary in 
-- 找出每个部门的最高薪员工
(
SELECT MAX(s2.salary)
FROM dept_emp as d2
INNER JOIN salaries as s2
ON d2.emp_no=s2.emp_no
AND d2.to_date='9999-01-01'
AND s2.to_date='9999-01-01'
AND d2.dept_no = d1.dept_no
)
ORDER BY d1.dept_no;