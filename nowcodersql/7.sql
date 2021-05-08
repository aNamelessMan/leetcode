-- sql基础教程ch03聚合与排序  笔记
-- 先按员工号聚合，再筛选各个组
select emp_no, count(*) from salaries 
group by emp_no
having count(*) > 15