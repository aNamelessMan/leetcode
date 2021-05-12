-- 先联结，再分组即可
select titles.title, avg(salary) 
from titles inner join salaries on titles.emp_no = salaries.emp_no 
group by titles.title;